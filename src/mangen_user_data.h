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

    int cnt_term; // id factory
    node_t terminals; // terminal x id trie
    node_t terminals2; // id x terminal avl

    int cnt_nonterm; // id factory
    node_t nonterminals; // nonterminal x id trie
    node_t nonterminals2; // id x nonterminal avl

    node_t productions;
};

#endif
