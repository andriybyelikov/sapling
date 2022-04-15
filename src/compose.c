#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libsapling/dm/graph.h>
#include <libsapling/cc/text.h>
#include <libsapling/cc/parse_tree.h>
#include <libsapling/cc/parser/defs/production_set.h>
#include "input_stream.h"
#include "output_stream.h"
#include "aux/string_list.h"
#include "aux/compiler_cache.h"
#include "meta/meta_parser.h"
#include "data.h"
#include "aux/int_trie.h"
#include "aux/state_stack.h"
#include "aux/parse_tree_stack.h"
#include "aux/string_to_int_avl.h"
#include "aux/ulisp_parse_tree_list.h"
#include "eval.h"

static node_t compiler_cache = NULL;


static
runtime_compiler_t compile_compiler(const char *spec_filename, void *user_ptr)
{
    struct data_common *data_common = user_ptr;

    // init meta parser user data
    struct data_meta user = {
        .options = data_common->options,
        .in_terminals_section = 1,
        .parse_tree_stack = NULL,
        .build_regex = 1,
        .lexer_stack = NULL,
        .lexer_final = NULL,
        .cnt_term = 0,
        .terminals = NULL,
        .terminals2 = NULL,
        .cnt_nonterm = 0,
        .nonterminals = NULL,
        .nonterminals2 = NULL,
        .productions = NULL,
        .composition_mode = 1,
        .ulisp_parse_trees = NULL,
        .gsym_strtoi = NULL,
        .cnt_prod = 0,
        .last_prod = -1
    };
    // run meta parser
    FILE *spec_file = fopen(spec_filename, "r");
    internal_parser__parse(get_meta_parser(),
        new_input_stream(INPUT_STREAM_MODE_FILE, spec_file, NULL), &user);
    fclose(spec_file);

    return user.runtime_compiler;
}


static
void compile_compilers_apply(const char **data, void *info)
{
    CAST_USER_INFO(void *, user_ptr, info);

    fprintf(stderr, "Checking cache for compiler from spec file [%s]... ",
        *data);
    if (!compiler_cache__in(&compiler_cache, *data)) {
        fprintf(stderr, "MISS\n");
        fprintf(stderr, "Compiling compiler from spec file [%s]... ", *data);

        runtime_compiler_t compiler = compile_compiler(*data, user_ptr);
        compiler_cache__insert(&compiler_cache, *data, compiler);

        fprintf(stderr, "DONE\n");
    } else {
        fprintf(stderr, "HIT\n");
    }
}


struct lexer_output {
    int id;
    const char *symbol;
    const char *lexeme;
    int is_gobble;
};

static
struct lexer_output runtime_lexer_fetch_terminal(node_t *lexer,
    struct lexer_state *lsta, node_t *terminals)
{
    const char **res = *(const char ***)lexer__next_terminal(lexer, lsta);
    //const char *key = (!lsta->end) ? *res : "t_eof";
    int id = -1;
    int_trie__access(E_QT, terminals, *res, &id,
        int_trie__predicate_1, apply_get_id);
    int is_gobble = !strncmp(*res, "t_gobble__", strlen("t_gobble__"));

    return (struct lexer_output){ id, *res, lsta->lexeme, is_gobble };
}

static
struct lexer_output next_terminal(node_t *lexer, struct lexer_state *lsta,
    node_t *terminals)
{
    struct lexer_output lo;
    do {
        lo = runtime_lexer_fetch_terminal(lexer, lsta, terminals);
        if (lsta->end) {
            int id = -1;
            int_trie__access(E_QT, terminals, "t_eof", &id,
                int_trie__predicate_1, apply_get_id);
            lo.id = id;
            lo.symbol = malloc(strlen("t_eof") + 1);
            strcpy((char *)lo.symbol, "t_eof");
            lo.lexeme = NULL;
            lo.is_gobble = 0;
        }
    } while (lo.is_gobble);

    // debug log
    /*char *esc_lexeme = malloc(2 * strlen(lsta->lexeme));
    text__escape(esc_lexeme, lsta->lexeme);
    fprintf(stderr, "(%d, \"%s\", \"%s\", %d)\n", lo.id, lo.symbol,
        (strcmp(lo.symbol, "t_eof") != 0) ? esc_lexeme: "",
        lo.is_gobble);
    free(esc_lexeme);*/

    return lo;
}


//
static
void push_terminal_to_parse_tree_stack(node_t *parse_tree_stack,
    const char *symbol, const char *lexeme)
{
    node_t node = parse_tree__create_node((char *)symbol);
    size_t size = (strlen(lexeme) + 1) * sizeof(char);
    char *buf = malloc(size);
    memcpy(buf, lexeme, size);
    parse_tree__append_child(&node, parse_tree__create_node(buf));
	parse_tree_stack__insert(parse_tree_stack, node);
}

static
void push_production_to_parse_tree_stack(node_t *parse_tree_stack,
    const char *symbol, int prod_len)
{
    node_t node = parse_tree__create_node((char *)symbol);
    
    // append n children in reverse order
    node_t reverse = NULL;
    for (int i = 0; i < prod_len; i++) {
        node_t child = parse_tree_stack__access(parse_tree_stack);
        parse_tree_stack__delete(parse_tree_stack);
        parse_tree_stack__insert(&reverse, child);
    }
    while (reverse != NULL) {
        node_t child = parse_tree_stack__access(&reverse);
        parse_tree_stack__delete(&reverse);
        parse_tree__append_child(&node, child);
    }
	parse_tree_stack__insert(parse_tree_stack, node);
}
//


static
void get_ulisp_parse_tree(pidxpt_t *data, void *info)
{
    CAST_USER_INFO(pidxpt_t *, user, info);

    user->ulisp_parse_tree = data->ulisp_parse_tree;
}

static
void run_ulisp_parse_tree(node_t *ulisp_parse_trees, int prod_idx,
    node_t *parse_tree_stack, output_stream_t out, node_t *symtab)
{
    pidxpt_t key = { prod_idx, NULL };
    ulisp_parse_tree_avl__access(E_QT, ulisp_parse_trees, &key,
        ulisp_parse_tree_avl__equ_predicate, get_ulisp_parse_tree);
    node_t uroot = key.ulisp_parse_tree;
    if (uroot == NULL)
        return;

    // debug: dump ulisp parse tree
    //parse_tree__dump_dot(stdout, &uroot);

    eval(&uroot, parse_tree_stack, out, symtab);
}


struct info_frag_io {
    input_stream_t in;
    output_stream_t out;
};

static
void compile_fragment_apply(const char **data, void *info)
{
    CAST_USER_INFO(struct info_frag_io *, user, info);

    user->out = new_output_stream(OUTPUT_STREAM_MODE_BINARY_ARRAY, NULL,
        malloc(4096));

    runtime_compiler_t compiler =
        compiler_cache__get_compiler(&compiler_cache, *data);
    node_t *lexer = runtime_compiler__get_lexer(compiler);
    node_t *terminals = runtime_compiler__get_terminals(compiler);
    node_t *nonterminals = runtime_compiler__get_nonterminals(compiler);
    grammar_t g = runtime_compiler__get_grammar(compiler);
    action_table_t at = runtime_compiler__get_action_table(compiler);
    goto_table_t gt = runtime_compiler__get_goto_table(compiler);
    node_t *ulisp_parse_trees =
        runtime_compiler__get_ulisp_parse_trees(compiler);
    node_t *productions = grammar__productions(g);

    struct lexer_state lsta;
    lexer__init(&lsta, input_stream__get_array(user->in));
    struct lexer_output lo = next_terminal(lexer, &lsta, terminals);

    node_t state_stack = NULL;
    state_stack__insert(&state_stack, 0);

    node_t parse_tree_stack = NULL;

    node_t fragment_symtab = NULL;

    int cont = 1;
    while (cont) {
        int s = state_stack__access(&state_stack);
        if (action_table__get_action(at, g, s, lo.id)
                == PARSER_ACTION_SHIFT) {
            state_stack__insert(&state_stack,
                action_table__get_action_info(at, g, s, lo.id));
            //assert(strcmp(lo.symbol, "t_eof") != 0);
            push_terminal_to_parse_tree_stack(&parse_tree_stack,
                lo.symbol, lo.lexeme);
            lo = next_terminal(lexer, &lsta, terminals);
        } else if (action_table__get_action(at, g, s, lo.id)
                == PARSER_ACTION_REDUCE) {
            int prod_idx = action_table__get_action_info(at, g, s, lo.id);
            production_t prod =
                *production_path__position(productions, prod_idx);
            int prod_len = production__len(prod);
            const char *symbol = idxstr_get_string(nonterminals,
                production__id(prod) - trie__length(terminals));
            push_production_to_parse_tree_stack(&parse_tree_stack, symbol,
                prod_len);
            for (int i = 0; i < prod_len; i++)
                state_stack__delete(&state_stack);
            s = state_stack__access(&state_stack);
            state_stack__insert(&state_stack,
                goto_table__get_state(gt, g, s, production__id(prod)));
            // run action
            run_ulisp_parse_tree(ulisp_parse_trees, prod_idx,
                &parse_tree_stack, user->out, &fragment_symtab);
        } else if (action_table__get_action(at, g, s, lo.id)
                == PARSER_ACTION_ACCEPT) {
            cont = 0;
        } else {
            fprintf(stderr, "sapling: parsing error\n");
            exit(EXIT_FAILURE);
        }
    }

    // debug: dump fragment parse tree
    /*node_t root = parse_tree_stack__access(&parse_tree_stack);
    parse_tree__dump_dot(stdout, &root);*/

    user->in = output_stream__to_input_stream(user->out);
}


void compose(const char *fragment_buffer, node_t *spec_list, FILE *output_file,
    void *user_ptr)
{
    // compile compilers for this fragment unless they are already in the cache
    string_path__access(U_QT, spec_list, user_ptr, string_path__predicate_1,
        compile_compilers_apply);

    // compile fragment through all languages of the language stack
    // fragment_buffer -> array input stream
    struct info_frag_io ifio = {
        .in = new_input_stream(INPUT_STREAM_MODE_ARRAY, NULL, fragment_buffer)
    };
    string_path__access(U_QT, spec_list, &ifio, string_path__predicate_1,
        compile_fragment_apply);
    // array output stream -> file output stream
    output_stream_t final_out = new_output_stream(OUTPUT_STREAM_MODE_FILE,
        output_file, NULL);
    char c;
    while (!input_stream__end(ifio.in))
        output_stream__putc(final_out, input_stream__getc(ifio.in));
}
