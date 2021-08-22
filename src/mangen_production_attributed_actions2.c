#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libsapling/dm/path.h>
#include <libsapling/dm/stack.h>
#include <libsapling/dm/queue.h>
#include <libsapling/dm/avl.h>
#include <libsapling/dm/trie.h>
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
void print_production(FILE *stream, const void *data)
{
    production_t prod = *(production_t *)data;

    fprintf(stream, "[%d -> ", production__id(prod));
    int i;
    for (i = 0; i < production__len(prod) - 1; i++) {
        fprintf(stream, "%d ", *production__get(prod, i));
    }
    fprintf(stream, "%d]", *production__get(prod, i));
}

IMPLEMENT_TYPED_PATH(prod_path, production_t, print_production, dummy_cmp)
IMPLEMENT_TYPED_QUEUE(prod_queue, production_t, print_production)
IMPLEMENT_TYPED_STACK(state_node_stack, node_t, NULL)
IMPLEMENT_TYPED_QUEUE(pbody_queue, int, fpfdata_int)
IMPLEMENT_TYPED_PATH(str_path, const char *, fpfdata_str, dummy_cmp)
IMPLEMENT_TYPED_QUEUE(str_queue, const char *, fpfdata_str)

IMPLEMENT_TYPED_TRIE(int_trie, int, fpfdata_int)


static
int cmpi(const void *a, const void *b)
{
    return *(int *)a <= *(int *)b;
}

static
int equi(const void *a, const void *b)
{
    return *(int *)a == *(int *)b;
}

typedef struct {
    int id;
    const char *str;
} idxstr_t;

static
void fpd_idxstr(FILE *stream, const void *data)
{
    idxstr_t *a = (idxstr_t *)data;
    fprintf(stream, "(%d, \"%s\")", a->id, a->str);
}

IMPLEMENT_TYPED_AVL(idxstr_avl, idxstr_t, cmpi, equi, fpd_idxstr)

struct info_pphr {
    FILE *stream;
    node_t *terminals;
    node_t *nonterminals;
};


static
void apply_get_int(int *data, void *info)
{
    CAST_USER_INFO(int *, id, info);

    *id = **(int **)data;
}


static
void apply_get_str(idxstr_t *data, void *info)
{
    CAST_USER_INFO(idxstr_t *, idxstr, info);

    idxstr->str = data->str;
}

static
void apply_print_production(production_t *data, void *info)
{
    CAST_USER_INFO(struct info_pphr *, user, info);
    FILE *stream = user->stream;
    node_t *terminals = user->terminals; // avl
    node_t *nonterminals = user->nonterminals; // avl

    production_t prod = *data;

    idxstr_t idxstr = {
        production__id(prod) - idxstr_avl__length(terminals), NULL };
    idxstr_avl__access(E_QT, nonterminals, &idxstr, idxstr_avl__equ_predicate,
        apply_get_str);

    fprintf(stream, "%s -> ", idxstr.str);

    int i;
    for (i = 0; i < production__len(prod) - 1; i++) {
        int id = *production__get(prod, i);
        idxstr.id = id;
        idxstr.str = NULL;
        if (id < idxstr_avl__length(terminals)) {
            idxstr_avl__access(E_QT, terminals, &idxstr,
                idxstr_avl__equ_predicate, apply_get_str);
        } else {
            idxstr.id -= idxstr_avl__length(terminals);
            idxstr_avl__access(E_QT, nonterminals, &idxstr,
                idxstr_avl__equ_predicate, apply_get_str);
        }
        fprintf(stream, "%s ", idxstr.str);
    }
    int id = *production__get(prod, i);
    idxstr.id = id;
    idxstr.str = NULL;
    if (id < idxstr_avl__length(terminals)) {
        idxstr_avl__access(E_QT, terminals, &idxstr,
            idxstr_avl__equ_predicate, apply_get_str);
    } else {
        idxstr.id -= idxstr_avl__length(terminals);
        idxstr_avl__access(E_QT, nonterminals, &idxstr,
            idxstr_avl__equ_predicate, apply_get_str);
    }
    fprintf(stream, "%s\n", idxstr.str);
}

static
void print_production_human_readable(FILE *stream, node_t *productions,
    node_t *terminals, node_t *nonterminals)
{
    struct info_pphr info = { stream, terminals, nonterminals };
    prod_path__access(U_QT, productions, &info, prod_path__predicate_1,
        apply_print_production);
}


static
void apply_print_avl_str_line_by_line(idxstr_t *data, void *info)
{
    CAST_USER_INFO(FILE *, stream, info);

    fprintf(stream, "%s\n", data->str);
}

static
void print_avl_str_line_by_line(FILE *stream, node_t *ref)
{
    idxstr_avl__access(U_QT, ref, stream, idxstr_avl__predicate_1,
        apply_print_avl_str_line_by_line);
}


static
void apply_get_id(int *data, void *info)
{
    CAST_USER_INFO(int *, id, info);

    *id = **(int **)data;
}

static
int get_or_assign_id_to_grammar_symbol(const char *symstr, node_t *terminals,
    node_t *nonterminals, node_t *nonterminals2, int *cnt_nonterm)
{
    if (strlen(symstr) >= 2 && symstr[0] == 't' && symstr[1] == '_') {
        int id = -1;
        int_trie__access(E_QT, terminals, symstr, &id, int_trie__predicate_1,
            apply_get_id);
        return id;
    } else {
        if (int_trie__in(nonterminals, symstr)) {
            int id = -1;
            int_trie__access(E_QT, nonterminals, symstr, &id,
                int_trie__predicate_1, apply_get_id);
            return id;
        } else {
            int_trie__insert(nonterminals, symstr, *cnt_nonterm);
            idxstr_avl__insert(nonterminals2,
                (idxstr_t){ *cnt_nonterm, symstr }, idxstr_avl__cmp_predicate);
            return (*cnt_nonterm)++;
        }
    }
}


void production_attibuted_actions2(void *user_ptr, int pid)
{
    struct user *user = user_ptr;
    switch (pid) {
    case 0: // start -> productions;
        {
            if (user->options[OPTION_FPRINT_TERMINALS]) {
                print_avl_str_line_by_line(stdout, &user->terminals2);
                /*fprintf(stdout, "TERMINALS\n");
                fprintf(stdout, "[trie] terminal x id = ");
                int_trie__print_data(stdout, &user->terminals);
                fprintf(stdout, "\n");
                fprintf(stdout, "[avl] id x terminal = ");
                idxstr_avl__print_data(stdout, &user->terminals2);
                fprintf(stdout, "\n");
                fprintf(stdout, "\n");*/
            }
            if (user->options[OPTION_FPRINT_NONTERMINALS]) {
                print_avl_str_line_by_line(stdout, &user->nonterminals2);
                /*fprintf(stdout, "NONTERMINALS\n");
                fprintf(stdout, "[trie] nonterminal x id = ");
                int_trie__print_data(stdout, &user->nonterminals);
                fprintf(stdout, "\n");
                fprintf(stdout, "[avl] id x nonterminal = ");
                idxstr_avl__print_data(stdout, &user->nonterminals2);
                fprintf(stdout, "\n");
                fprintf(stdout, "\n");*/
            }
            if (user->options[OPTION_FPRINT_PRODUCTIONS]) {
                print_production_human_readable(stdout, &user->productions,
                    &user->terminals2, &user->nonterminals2);
                /*fprintf(stdout, "productions = ");
                prod_queue__print_data(stdout, &user->productions);
                fprintf(stdout, "\n");*/
            }
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
                    lexer__dump_dot(output_file, &user->lexer_final, fpfdata_str);
                }
                if (output_file != stdout)
                    fclose(output_file);
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
            const char *id = *parse_tree__data(lx);

            if (!strcmp(id, "start")) {
                user->in_terminals_section = 0;
                user->build_regex = 0;
            }

            if (user->in_terminals_section) {
                if (user->options[OPTION_FPRINT_TERMINALS]
                    || user->options[OPTION_FPRINT_PRODUCTIONS]) {
                        int_trie__insert(&user->terminals, id, user->cnt_term);
                        idxstr_avl__insert(&user->terminals2,
                            (idxstr_t){ user->cnt_term, id },
                            idxstr_avl__cmp_predicate);
                        user->cnt_term++;
                    }
            } else {
                if (user->options[OPTION_FPRINT_NONTERMINALS]
                    || user->options[OPTION_FPRINT_PRODUCTIONS]) {
                    get_or_assign_id_to_grammar_symbol(id, &user->terminals,
                        &user->nonterminals, &user->nonterminals2,
                        &user->cnt_nonterm);
                }
            }

            if (user->build_regex) {
                node_t a = state_node_stack__access(&user->lexer_stack);
                // copy id to heap before it is deleted on the stack
                char **state_data = malloc(sizeof(char *));
                *state_data = (char *)id;
                lexer__set_accepting_states_data(&a, (void *)state_data);
                state_node_stack__delete(&user->lexer_stack);
                if (user->lexer_final == NULL)
                    user->lexer_final = a;
                else
                    lexer__union(&user->lexer_final, &a);
            }

            if (!user->in_terminals_section
                && user->options[OPTION_FPRINT_PRODUCTIONS]) {
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

                            int int_id = get_or_assign_id_to_grammar_symbol(
                                *parse_tree__data(lexeme), &user->terminals,
                                &user->nonterminals, &user->nonterminals2,
                                &user->cnt_nonterm);
                            int num_terminals = int_trie__length(&user->terminals);
                            const char *symstr = *parse_tree__data(lexeme);
                            if (strlen(symstr) >= 2 && symstr[0] == 't' && symstr[1] == '_') {
                                num_terminals = 0;
                            }
                            pbody_queue__insert(&body, int_id + num_terminals);
                        }
                        expr_0 = parse_tree__get_child_by_string(&expr_0, "expr_0");
                    }
                    int int_id = get_or_assign_id_to_grammar_symbol(
                                id, &user->terminals,
                                &user->nonterminals, &user->nonterminals2,
                                &user->cnt_nonterm);

                    production_t p = new_production(int_id + int_trie__length(&user->terminals), &body);
                    prod_queue__insert(&user->productions, p);

                    body = NULL;
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
                const char *lexeme = *parse_tree__data(lxnode);

                char *buf = malloc(2 * (strlen(lexeme) + 1));
                text__unescape(buf, lexeme);
                text__unescape(buf, buf);

                // build automaton and push it to lexer_stack
                node_t literal = NULL;
                lexer__literal(&literal, buf);
                state_node_stack__insert(&user->lexer_stack, literal);
            }
        }
        break;
    case 15: // expr_4 -> t_class;
        {
            // build class automaton
            if (user->build_regex) {
                // retrieve lexeme
                node_t expr_4 = state_node_stack__access(&user->parse_tree_stack);
                node_t t_class = parse_tree__get_child_by_string(&expr_4, "t_class");
                node_t lxnode = parse_tree__get_child_by_position(&t_class, 0);
                const char *lexeme = *parse_tree__data(lxnode);

                char *buf = malloc(2 * (strlen(lexeme) + 1));
                text__unescape(buf, lexeme);
                text__unescape(buf, buf);

                // build automaton and push it to lexer_stack
                node_t _union = NULL;
                lexer__class(&_union, buf);
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
