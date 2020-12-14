#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libsapling/parse_tree.h>
#include <libsapling/rea.h>
#include <libsapling/text.h>
#include <libsapling/typed_stack.h>
#include "options.h"
#include "mangen_user_data.h"
#include "mangen_productions.h"

typedef void *ptr;
define_typed_stack(ptr)

static
void fpd_str(FILE *fd, void **ref)
{
    void **data_ref = rea__node__data(ref);
    void *data_ptr = *data_ref;
    const char *val = data_ptr;
    fprintf(fd, "%s", val);
}

void production_attibuted_actions2(void *user_ptr, int pid)
{
    struct user *user = user_ptr;
    switch (pid) {
    case 0: // start -> productions;
        {
            if (user->options[OPTION_FDUMP_PARSE_TREE]) {
                FILE *output_file = user->parse_tree_filename == NULL ? stdout : fopen(user->parse_tree_filename, "w");
                {
                    void *root = stack_ptr__access(&user->parse_tree_stack);
                    parse_tree__dump_dot(output_file, &root);
                }
                if (output_file != stdout)
                    fclose(output_file);
            }
            if (user->options[OPTION_FDUMP_LEXER_AUTOMATON]) {
                FILE *output_file = user->lexer_automaton_filename == NULL ? stdout : fopen(user->lexer_automaton_filename, "w");
                {
                    rea__dump_dot(output_file, &user->final_rea, fpd_str);
                }
                if (output_file != stdout)
                    fclose(output_file);
            }
        }
        break;
    case 1: // productions -> production productions;
        break;
    case 2: // productions -> production;
        break;
    case 3: // production -> t_symbol t_rightarrow expr t_terminator;
        {
            // push expr automaton to symbol table indexed by t_symbol
            void *production = stack_ptr__access(&user->parse_tree_stack);
            void *t_symbol = parse_tree__get_child_by_string(&production, "t_symbol");
            void *lx = parse_tree__get_child_by_position(&t_symbol, 0); // lexeme
            const char *id = parse_tree__node__get_string(&lx);

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
                void *a = stack_ptr__access(&user->rea_stack);
                rea__set_accepting_states_data(&a, (void *)id);
                stack_ptr__delete(&user->rea_stack);
                if (user->final_rea == NULL)
                    user->final_rea = a;
                else
                    rea__union(&user->final_rea, &a);
            }

            if (user->options[OPTION_FPRINT_PRODUCTIONS]
                && !user->in_terminals_section) {
                void *expr = parse_tree__get_child_by_string(&production, "expr");
                while (expr != NULL) {
                    fprintf(stdout, "%s -> ", id);
                    void *expr_0 = parse_tree__get_child_by_string(&expr, "expr_0");
                    while (expr_0 != NULL) {
                        {
                            void *expr_1 = parse_tree__get_child_by_string(&expr_0, "expr_1");
                            void *expr_4 = parse_tree__get_child_by_string(&expr_1, "expr_4");
                            void *t_symbol = parse_tree__get_child_by_string(&expr_4, "t_symbol");
                            void *lexeme = parse_tree__get_child_by_position(&t_symbol, 0);
                            printf("%s ", parse_tree__node__get_string(&lexeme));
                        }
                        expr_0 = parse_tree__get_child_by_string(&expr_0, "expr_0");
                    }
                    printf("\n");
                    expr = parse_tree__get_child_by_string(&expr, "expr");
                }
            }
        }
        break;
    case 4: // expr -> expr_0 t_disjunction expr;
        {
            // apply union to expr_0 expr
            if (user->build_regex) {
                void *a1 = stack_ptr__access(&user->rea_stack);
                stack_ptr__delete(&user->rea_stack);
                void *a0 = stack_ptr__access(&user->rea_stack);
                stack_ptr__delete(&user->rea_stack);
                rea__union(&a0, &a1);
                stack_ptr__insert(&user->rea_stack, a0);
            }
        }
        break;
    case 5: // expr -> expr_0;
        break;
    case 6: // expr_0 -> expr_1 expr_0;
        {
            // apply concatenation to expr_1 expr_0
            if (user->build_regex) {
                void *a1 = stack_ptr__access(&user->rea_stack);
                stack_ptr__delete(&user->rea_stack);
                void *a0 = stack_ptr__access(&user->rea_stack);
                stack_ptr__delete(&user->rea_stack);
                rea__concatenation(&a0, &a1);
                stack_ptr__insert(&user->rea_stack, a0);
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
                void *a = stack_ptr__access(&user->rea_stack);
                rea__kleene_star(&a);
                stack_ptr__delete(&user->rea_stack);
                stack_ptr__insert(&user->rea_stack, a);
            }
        }
        break;
    case 12: // expr_3 -> expr_4 t_kleeneplus;
        {
            // apply kleene plus to expr_4 automaton
            if (user->build_regex) {
                void *a = stack_ptr__access(&user->rea_stack);
                rea__kleene_plus(&a);
                stack_ptr__delete(&user->rea_stack);
                stack_ptr__insert(&user->rea_stack, a);
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
                void *expr_4 = stack_ptr__access(&user->parse_tree_stack);
                void *t_literal = parse_tree__get_child_by_string(&expr_4, "t_literal");
                void *lxnode = parse_tree__get_child_by_position(&t_literal, 0);
                const char *lexeme = parse_tree__node__get_string(&lxnode);

                char *buf = malloc(2 * (strlen(lexeme) + 1));
                text__unescape(buf, lexeme);
                text__unescape(buf, buf);

                // build automaton and push it to rea_stack
                void *literal = NULL;
                rea__literal(&literal, buf);
                free(buf);
                stack_ptr__insert(&user->rea_stack, literal);
            }
        }
        break;
    case 15: // expr_4 -> t_union;
        {
            // build class automaton
            if (user->build_regex) {
                // retrieve lexeme
                void *expr_4 = stack_ptr__access(&user->parse_tree_stack);
                void *t_union = parse_tree__get_child_by_string(&expr_4, "t_union");
                void *lxnode = parse_tree__get_child_by_position(&t_union, 0);
                const char *lexeme = parse_tree__node__get_string(&lxnode);

                char *buf = malloc(2 * (strlen(lexeme) + 1));
                text__unescape(buf, lexeme);
                text__unescape(buf, buf);

                // build automaton and push it to rea_stack
                void *_union = NULL;
                rea__class(&_union, buf);
                free(buf);
                stack_ptr__insert(&user->rea_stack, _union);
            }
        }
        break;
    case 16: // expr_4 -> t_any;
        {
            // build anything automaton
            if (user->build_regex) {
                // retrieve lexeme -- no need

                // build automaton and push it to rea_stack
                void *anything = NULL;
                rea__anything(&anything);
                stack_ptr__insert(&user->rea_stack, anything);
            }
        }
        break;
    case 17: // expr_4 -> t_lpar expr t_rpar;
        break;
    default:
        break;
    }
}
