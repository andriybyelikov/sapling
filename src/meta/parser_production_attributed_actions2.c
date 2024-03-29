#include <string.h>
#include <libsapling/dm/stack.h>
#include <libsapling/dm/queue.h>
#include <libsapling/dm/avl.h>
#include <libsapling/dm/trie.h>
#include <libsapling/cc/text.h>
#include <libsapling/cc/parse_tree.h>
#include <libsapling/cc/parser/defs/symbol_set.h>
#include <libsapling/cc/parser/defs/production_set.h>
#include <libsapling/cc/parser/slr.h>
#include "aux/parse_tree_stack.h"
#include "aux/string_list.h"
#include "options.h"
#include "data.h"
#include "ulisp/ulisp_parser.h"
#include "aux/ulisp_parse_tree_list.h"
#include "aux/int_trie.h"
#include "aux/string_to_int_avl.h"


static
void print_avl_str_line_by_line_apply(idxstr_t *data, void *info)
{
    CAST_USER_INFO(FILE *, stream, info);

    fprintf(stream, "%s\n", data->str);
}

static
void print_avl_str_line_by_line(FILE *stream, node_t *ref)
{
    idxstr_avl__access(U_QT, ref, stream, idxstr_avl__predicate_1,
        print_avl_str_line_by_line_apply);
}


struct info_dump_ulisp_parse_tree {
    int i;
    FILE *stream;
};

static
void dump_ulisp_parse_tree_apply(pidxpt_t *data, void *info)
{
    CAST_USER_INFO(struct info_dump_ulisp_parse_tree *, user, info);

    parse_tree__dump_dot(user->stream, &data->ulisp_parse_tree);
}

struct info_pphr {
    FILE *stream;
    node_t *terminals;
    node_t *nonterminals;
    node_t *ulisp_parse_trees;
    int i;
};

static
void print_production_apply(production_t *data, void *info)
{
    CAST_USER_INFO(struct info_pphr *, user, info);
    FILE *stream = user->stream;
    node_t *terminals = user->terminals; // avl
    node_t *nonterminals = user->nonterminals; // avl

    production_t prod = *data;

    fprintf(stream, "%s -> ", idxstr_get_string(nonterminals,
        production__id(prod) - idxstr_avl__length(terminals)));

    int i;
    for (i = 0; i < production__len(prod) - 1; i++) {
        int id = *production__get(prod, i);
        const char *str = NULL;
        if (id < idxstr_avl__length(terminals)) {
            str = idxstr_get_string(terminals, id);
        } else {
            id -= idxstr_avl__length(terminals);
            str = idxstr_get_string(nonterminals, id);
        }
        fprintf(stream, "%s ", str);
    }
    int id = *production__get(prod, i);
    const char *str = NULL;
    if (id < idxstr_avl__length(terminals)) {
        str = idxstr_get_string(terminals, id);
    } else {
        id -= idxstr_avl__length(terminals);
        str = idxstr_get_string(nonterminals, id);
    }
    fprintf(stream, "%s\n", str);

    // print uLisp parse tree for this production
    if ((user->ulisp_parse_trees) != NULL) {
        if (ulisp_parse_tree_avl__in(user->ulisp_parse_trees,
                (pidxpt_t){ .prod_id = user->i })) {
            struct info_dump_ulisp_parse_tree idupt = { user->i, stream };
            ulisp_parse_tree_avl__access(E_QT, user->ulisp_parse_trees, &idupt,
                ulisp_parse_tree_avl__equ_predicate,
                dump_ulisp_parse_tree_apply);
        } else {
            fprintf(stream, "\n");
        }
    }
    user->i++;
}

static
void print_production_human_readable(FILE *stream, node_t *productions,
    node_t *terminals, node_t *nonterminals, node_t *ulisp_parse_trees)
{
    struct info_pphr info = { stream, terminals, nonterminals,
        ulisp_parse_trees, 0 };
    production_path__access(U_QT, productions, &info,
        production_path__predicate_1, print_production_apply);
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


IMPLEMENT_TYPED_STACK(state_node_stack, node_t, NULL)
IMPLEMENT_TYPED_QUEUE(pbody_queue, int, int__print)


void meta__production_attibuted_actions2(void *user_ptr, int pid)
{
    struct data_meta *user = user_ptr;
    switch (pid) {
    case 0: // start -> productions;
        {
            if (user->options[OPTION_PRINT_TERMINALS]) {
                print_avl_str_line_by_line(stdout, &user->terminals2);
            }
            if (user->options[OPTION_PRINT_NONTERMINALS]) {
                print_avl_str_line_by_line(stdout, &user->nonterminals2);
            }
            if (user->options[OPTION_PRINT_PRODUCTIONS]) {
                print_production_human_readable(stdout, &user->productions,
                    &user->terminals2, &user->nonterminals2, NULL);
            }
            if (user->options[OPTION_DUMP_PARSE_TREE]) {
                node_t root =
                    parse_tree_stack__access(&user->parse_tree_stack);
                parse_tree__dump_dot(stdout, &root);
            }
            if (user->options[OPTION_DUMP_LEXER_AUTOMATON]) {
                lexer__dump_dot(stdout, &user->lexer_final, string__print);
            }
            if (user->options[OPTION_PRINT_LEXER_AUTOMATON]) {
                lexer__print(stdout, &user->lexer_final, string__print);
                fprintf(stdout, "\n");
            }
            if (user->options[OPTION_PRINT_SLR_TABLES]) {
                grammar_t g = new_grammar(&user->productions,
                    idxstr_avl__length(&user->terminals2),
                    idxstr_avl__length(&user->terminals2)
                        + idxstr_avl__length(&user->nonterminals2));
                node_t *C = slr__build_set_of_sets_of_lr0_items(g);
                
                action_table_t at = action_table__build(g, C);
                goto_table_t gt = goto_table__build(g, C);
                slr__print_tables(stdout, at, gt, C, g);
            }
            if (user->options[OPTION_DUMP_ULISP_PARSE_TREES]) {
                print_production_human_readable(stdout, &user->productions,
                    &user->terminals2, &user->nonterminals2,
                    &user->ulisp_parse_trees);
            }
            if (user->composition_mode) {
                node_t *lexer = malloc(sizeof(node_t));
                *lexer = user->lexer_final;

                node_t *terminals = malloc(sizeof(node_t));
                *terminals = user->terminals;

                node_t *nonterminals = malloc(sizeof(node_t));
                *nonterminals = user->nonterminals2;

                node_t *productions = malloc(sizeof(node_t));
                *productions = user->productions;

                grammar_t g = new_grammar(productions,
                    idxstr_avl__length(&user->terminals2),
                    idxstr_avl__length(&user->terminals2)
                        + idxstr_avl__length(&user->nonterminals2));
                node_t *C = slr__build_set_of_sets_of_lr0_items(g);

                action_table_t at = action_table__build(g, C);
                goto_table_t gt = goto_table__build(g, C);

                node_t *ulisp_parse_trees = malloc(sizeof(node_t));
                *ulisp_parse_trees = user->ulisp_parse_trees;

                user->runtime_compiler = new_runtime_compiler(lexer, terminals,
                    nonterminals, g, at, gt, ulisp_parse_trees);
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
            node_t _production =
                parse_tree_stack__access(&user->parse_tree_stack);
            node_t t_symbol =
                parse_tree__get_child_by_string(&_production,"t_symbol");
            // lexeme
            node_t lx = parse_tree__get_child_by_position(&t_symbol, 0);
            const char *id = *parse_tree__data(lx);

            if (!strcmp(id, "start")) {
                user->in_terminals_section = 0;
                user->build_regex = 0;

                int_trie__insert(&user->terminals, "t_eof", user->cnt_term);
                idxstr_avl__insert(&user->terminals2,
                    (idxstr_t){ user->cnt_term, "t_eof" },
                    idxstr_avl__cmp_predicate);
                user->cnt_term++;
            }

            if (user->in_terminals_section) {
                if (user->options[OPTION_PRINT_TERMINALS]
                    || user->options[OPTION_PRINT_PRODUCTIONS]
                    || user->options[OPTION_PRINT_SLR_TABLES]
                    || user->options[OPTION_DUMP_ULISP_PARSE_TREES]
                    || user->composition_mode) {
                        int_trie__insert(&user->terminals, id, user->cnt_term);
                        idxstr_avl__insert(&user->terminals2,
                            (idxstr_t){ user->cnt_term, id },
                            idxstr_avl__cmp_predicate);
                        user->cnt_term++;
                    }
            } else {
                if (user->options[OPTION_PRINT_NONTERMINALS]
                    || user->options[OPTION_PRINT_PRODUCTIONS]
                    || user->options[OPTION_PRINT_SLR_TABLES]
                    || user->options[OPTION_DUMP_ULISP_PARSE_TREES]
                    || user->composition_mode) {
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
                && (user->options[OPTION_PRINT_PRODUCTIONS]
                    || user->options[OPTION_PRINT_SLR_TABLES]
                    || user->options[OPTION_DUMP_ULISP_PARSE_TREES]
                    || user->composition_mode)) {
                node_t body = NULL;
                node_t expr = parse_tree__get_child_by_string(&_production, "expr");
                while (expr != NULL) {
                    node_t expr_a = parse_tree__get_child_by_string(&expr, "expr_a");
                    node_t expr_0 = parse_tree__get_child_by_string(&expr_a, "expr_0");
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

                    production_t p = new_production(int_id +
                        int_trie__length(&user->terminals), &body);
                    production_queue__insert(&user->productions, p);

                    body = NULL;
                    expr = parse_tree__get_child_by_string(&expr, "expr");
                }
            }
        }
        break;
    case 4: // expr -> expr_a t_disjunction expr;
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
    case 5: // expr -> expr_a;
        break;
    case 6: // expr_a -> expr_0 t_ulisp_routine;
        {
            if (user->options[OPTION_DUMP_ULISP_PARSE_TREES]
                    || user->composition_mode) {
                node_t expr_a =
                    parse_tree_stack__access(&user->parse_tree_stack);
                node_t t_ulisp_routine =
                    parse_tree__get_child_by_string(&expr_a,
                        "t_ulisp_routine");
                node_t lx =
                    parse_tree__get_child_by_position(&t_ulisp_routine, 0);
                const char *routine = *parse_tree__data(lx);

                // compile uLisp routine into parse tree
                char *buf = malloc(strlen(routine) + 1);
                text__unescape(buf, routine);
                char *buf_trimmed = buf + 1;
                buf_trimmed[strlen(buf_trimmed) - 1] = 0;
                struct data_common data_ulisp = {
                    .options = NULL,
                    .parse_tree_stack = NULL
                };
                internal_parser__parse(get_ulisp_parser(),
                    new_input_stream(INPUT_STREAM_MODE_ARRAY, NULL,
                        buf_trimmed), &data_ulisp);
                free(buf);

                
                int key =
                    ulisp_parse_tree_avl__length(&user->ulisp_parse_trees);

                ulisp_parse_tree_avl__insert(&user->ulisp_parse_trees,
                    (pidxpt_t) {
                        key,
                        parse_tree_stack__access(&data_ulisp.parse_tree_stack)
                    }, ulisp_parse_tree_avl__cmp_predicate);
            }
        }
        break;
    case 7: // expr_a -> expr_0;
        {
            if ((user->options[OPTION_DUMP_ULISP_PARSE_TREES]
                        || user->composition_mode)
                    && !user->in_terminals_section) {
                int key =
                    ulisp_parse_tree_avl__length(&user->ulisp_parse_trees);
                ulisp_parse_tree_avl__insert(&user->ulisp_parse_trees,
                    (pidxpt_t) { key, NULL },
                    ulisp_parse_tree_avl__cmp_predicate);
            }
        }
        break;
    case 8: // expr_0 -> expr_1 expr_0;
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
    case 9: // expr_0 -> expr_1;
        break;
    case 10: // expr_1 -> expr_2;
        break;
    case 11: // expr_1 -> expr_3;
        break;
    case 12: // expr_1 -> expr_4;
        break;
    case 13: // expr_2 -> expr_4 t_kleenestar;
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
    case 14: // expr_3 -> expr_4 t_kleeneplus;
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
    case 15: // expr_4 -> t_symbol;
        break;
    case 16: // expr_4 -> t_literal;
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
    case 17: // expr_4 -> t_class;
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
    case 18: // expr_4 -> t_any;
        {
            // build anything automaton
            if (user->build_regex) {
                // build automaton and push it to lexer_stack
                node_t anything = NULL;
                lexer__anything(&anything);
                state_node_stack__insert(&user->lexer_stack, anything);
            }
        }
        break;
    case 19: // expr_4 -> t_lpar expr t_rpar;
        break;
    }
}
