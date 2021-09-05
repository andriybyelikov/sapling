#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libsapling/dm/graph.h>
#include <libsapling/cc/text.h>
#include "aux/string_list.h"
#include "aux/compiler_cache.h"
#include "meta/meta_parser.h"
#include "data.h"

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
        .ulisp_parse_trees = NULL
    };
    // run meta parser
    FILE *spec_file = fopen(spec_filename, "r");
    internal_parser__parse(get_meta_parser(),
        new_input_stream(INPUT_STREAM_MODE_FILE, spec_file, NULL), &user);
    fclose(spec_file);

    return user.runtime_compiler;
}


static
void spec_list_apply(const char **data, void *info)
{
    CAST_USER_INFO(void *, user_ptr, info);

    fprintf(stderr, "Checking cache for compiler from spec file [%s]... ",
        *data);
    if (!compiler_cache__in(&compiler_cache, *data)) {
        fprintf(stderr, "MISS\n");
        fprintf(stderr, "Compiling compiler from spec file [%s]... ", *data);

        compiler_cache__insert(&compiler_cache, *data,
            compile_compiler(*data, user_ptr));

        fprintf(stderr, "DONE\n");
    } else {
        fprintf(stderr, "HIT\n");
    }
}

void compose(const char *fragment_buffer, node_t *spec_list, FILE *output_file,
    void *user_ptr)
{
    string_path__access(U_QT, spec_list, user_ptr, string_path__predicate_1,
        spec_list_apply);
}
