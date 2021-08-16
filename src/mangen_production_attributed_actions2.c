#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libsapling/dm/path.h>
#include <libsapling/dm/stack.h>
#include <libsapling/dm/queue.h>
#include <libsapling/cc/parse_tree.h>
#include <libsapling/cc/lexer.h>
#include <libsapling/cc/text.h>
#include <libsapling/cc/production.h>
#include <libsapling/dm/typed/typed_common.h>

#include "parse_tree_stack.h"

#include "options.h"
#include "mangen_user_data.h"
#include "mangen_productions.h"
#include "mangen_combined_ids.h"

static
void fpd_str(FILE *stream, const void *data)
{
    // data is pointer to data, need double dereference
    if (*(void **)data != NULL)
        fprintf(stream, "%s", *(const char **)data);
}

static
void print_production(FILE *stream, const void *data)
{
    production_t prod = *(production_t *)data;
    fprintf(stream, "%d -> ", production__id(prod));
    int i;
    for (i = 0; i < production__len(prod) - 1; i++)
        fprintf(stream, "%d ", production__get(prod, i));
    fprintf(stream, "%d\n", production__get(prod, i));
}

IMPLEMENT_TYPED_PATH(prod_path, production_t, print_production, dummy_cmp)
IMPLEMENT_TYPED_QUEUE(prod_queue, production_t, print_production)
IMPLEMENT_TYPED_STACK(state_node_stack, node_t, NULL)
IMPLEMENT_TYPED_QUEUE(pbody_queue, int, NULL)


void production_attibuted_actions2(void *user_ptr, int pid)
{
    struct user *user = user_ptr;
    switch (pid) {
    case 0: // start -> productions;
        {
            if (user->options[OPTION_FDUMP_PARSE_TREE]) {
                FILE *output_file = user->parse_tree_filename == NULL ? stdout : fopen(user->parse_tree_filename, "w");
                {
                    node_t root = parse_tree_stack__access(&user->parse_tree_stack);
                    parse_tree__dump_dot(output_file, &root);
                }
                if (output_file != stdout)
                    fclose(output_file);
            }
            if (user->options[OPTION_FDUMP_LEXER_AUTOMATON]) {
                FILE *output_file = user->lexer_automaton_filename == NULL ? stdout : fopen(user->lexer_automaton_filename, "w");
                {
                    lexer__dump_dot(output_file, &user->lexer_final, fpd_str);
                }
                if (output_file != stdout)
                    fclose(output_file);
            }
            if (user->options[OPTION_FPRINT_PRODUCTIONS]) {
                prod_path__print_data(stdout, &user->productions);
            }
            /*if (user->options[OPTION_FDUMP_PARSER_AUTOMATON]) {
                void *symbols = NULL; // strings
                for (int i = 0; i < NUM_TERMINALS; i++)
                    queue_ptr__insert(&symbols, terminal_str[i]);
                for (int i = 0; i < NUM_NONTERMINALS; i++)
                    queue_ptr__insert(&symbols, psym_str[i]);
                void *slr = NULL;
                slr__build(&slr, NULL, NUM_TERMINALS, NUM_TERMINALS + NUM_NONTERMINALS, &user->productions);
                slr__dot_dump(stdout, &slr, &symbols, NUM_TERMINALS, NULL);
            }*/
        }
        break;
    case 1: // productions -> production productions;
        break;
    case 2: // productions -> production;
        break;
    case 3: // production -> t_symbol t_rightarrow expr t_terminator;
        {
            // push expr automaton to symbol table indexed by t_symbol
            node_t _production = parse_tree_stack__access(&user->parse_tree_stack);
            node_t t_symbol = parse_tree__get_child_by_string(&_production, "t_symbol");
            node_t lx = parse_tree__get_child_by_position(&t_symbol, 0); // lexeme
            const char *id = parse_tree__data(lx);

            if (!strcmp(id, "start")) {
                user->in_terminals_section = 0;
                user->build_regex = 0;
            }

            if (user->in_terminals_section) {
                if (user->options[OPTION_FPRINT_TERMINALS])
                    fprintf(stdout, "%s\n", id);
            } else {
                if (user->options[OPTION_FPRINT_NONTERMINALS])
                    fprintf(stdout, "%s\n", id);
            }

            if (user->build_regex) {
                node_t a = state_node_stack__access(&user->lexer_stack);
                lexer__set_accepting_states_data(&a, (void *)id);
                state_node_stack__delete(&user->lexer_stack);
                if (user->lexer_final == NULL)
                    user->lexer_final = a;
                else
                    lexer__union(&user->lexer_final, &a);
            }

            if (!user->in_terminals_section) {
                node_t body = NULL;
                node_t expr = parse_tree__get_child_by_string(&_production, "expr");
                while (expr != NULL) {
                    node_t expr_0 = parse_tree__get_child_by_string(&expr, "expr_0");
                    while (expr_0 != NULL) {
                        {
                            node_t expr_1 = parse_tree__get_child_by_string(&expr_0, "expr_1");
                            node_t expr_4 = parse_tree__get_child_by_string(&expr_1, "expr_4");
                            node_t t_symbol = parse_tree__get_child_by_string(&expr_4, "t_symbol");
                            node_t lexeme = parse_tree__get_child_by_position(&t_symbol, 0);
                            pbody_queue__insert(&body, psym_str_idx(parse_tree__data(lexeme)));
                        }
                        expr_0 = parse_tree__get_child_by_string(&expr_0, "expr_0");
                    }
                    production_t p = new_production(psym_str_idx(id), &body);
                    prod_queue__insert(&user->productions, p);
                    path__delete(U_QT, &body, NULL, predicate_1);
                    expr = parse_tree__get_child_by_string(&expr, "expr");
                }
            }
        }
        break;
    case 4: // expr -> expr_0 t_disjunction expr;
        {
            // apply union to expr_0 expr
            if (user->build_regex) {
                node_t a1 = state_node_stack__access(&user->lexer_stack);
                state_node_stack__delete(&user->lexer_stack);
                node_t a0 = state_node_stack__access(&user->lexer_stack);
                state_node_stack__delete(&user->lexer_stack);
                lexer__union(&a0, &a1);
                state_node_stack__insert(&user->lexer_stack, a0);
            }
        }
        break;
    case 5: // expr -> expr_0;
        break;
    case 6: // expr_0 -> expr_1 expr_0;
        {
            // apply concatenation to expr_1 expr_0
            if (user->build_regex) {
                node_t a1 = state_node_stack__access(&user->lexer_stack);
                state_node_stack__delete(&user->lexer_stack);
                node_t a0 = state_node_stack__access(&user->lexer_stack);
                state_node_stack__delete(&user->lexer_stack);
                lexer__concatenation(&a0, &a1);
                state_node_stack__insert(&user->lexer_stack, a0);
            }
        }
        break;
    case 7: // expr_0 -> expr_1;
        break;
    case 8: // expr_1 -> expr_2;
        break;
    case 9: // expr_1 -> expr_3;
        break;
    case 10: // expr_1 -> expr_4;
        break;
    case 11: // expr_2 -> expr_4 t_kleenestar;
        {
            // apply kleene star to expr_4 automaton
            if (user->build_regex) {
                node_t a = state_node_stack__access(&user->lexer_stack);
                lexer__kleene_star(&a);
                state_node_stack__delete(&user->lexer_stack);
                state_node_stack__insert(&user->lexer_stack, a);
            }
        }
        break;
    case 12: // expr_3 -> expr_4 t_kleeneplus;
        {
            // apply kleene plus to expr_4 automaton
            if (user->build_regex) {
                node_t a = state_node_stack__access(&user->lexer_stack);
                lexer__kleene_plus(&a);
                state_node_stack__delete(&user->lexer_stack);
                state_node_stack__insert(&user->lexer_stack, a);
            }
        }
        break;
    case 13: // expr_4 -> t_symbol;
        break;
    case 14: // expr_4 -> t_literal;
        {
            // build literal automaton
            if (user->build_regex) {
                // retrieve lexeme
                node_t expr_4 = state_node_stack__access(&user->parse_tree_stack);
                node_t t_literal = parse_tree__get_child_by_string(&expr_4, "t_literal");
                node_t lxnode = parse_tree__get_child_by_position(&t_literal, 0);
                const char *lexeme = parse_tree__data(lxnode);

                char *buf = malloc(2 * (strlen(lexeme) + 1));
                text__unescape(buf, lexeme);
                text__unescape(buf, buf);

                // build automaton and push it to lexer_stack
                node_t literal = NULL;
                lexer__literal(&literal, buf);
                free(buf);
                state_node_stack__insert(&user->lexer_stack, literal);
            }
        }
        break;
    case 15: // expr_4 -> t_union;
        {
            // build class automaton
            if (user->build_regex) {
                // retrieve lexeme
                node_t expr_4 = state_node_stack__access(&user->parse_tree_stack);
                node_t t_union = parse_tree__get_child_by_string(&expr_4, "t_union");
                node_t lxnode = parse_tree__get_child_by_position(&t_union, 0);
                const char *lexeme = parse_tree__data(lxnode);

                char *buf = malloc(2 * (strlen(lexeme) + 1));
                text__unescape(buf, lexeme);
                text__unescape(buf, buf);

                // build automaton and push it to lexer_stack
                node_t _union = NULL;
                lexer__class(&_union, buf);
                free(buf);
                state_node_stack__insert(&user->lexer_stack, _union);
            }
        }
        break;
    case 16: // expr_4 -> t_any;
        {
            // build anything automaton
            if (user->build_regex) {
                // retrieve lexeme -- no need

                // build automaton and push it to lexer_stack
                node_t anything = NULL;
                lexer__anything(&anything);
                state_node_stack__insert(&user->lexer_stack, anything);
            }
        }
        break;
    case 17: // expr_4 -> t_lpar expr t_rpar;
        break;
    default:
        break;
    }
}
