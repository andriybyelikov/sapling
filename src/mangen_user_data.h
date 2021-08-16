#ifndef MANGEN_USER_DATA
#define MANGEN_USER_DATA

#include <libsapling/dm/graph.h>

struct user {
    int *options;

    int in_terminals_section;

    const char *parse_tree_filename;
    node_t parse_tree_stack;

    int build_regex;
    const char *lexer_automaton_filename;
    node_t lexer_stack;
    node_t lexer_final;

    node_t productions;
};

#endif
