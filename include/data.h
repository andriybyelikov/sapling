#ifndef DATA_H
#define DATA_H

#include <stdio.h>
#include <libsapling/dm/graph.h>
#include "runtime_compiler.h"

struct data_common {
    int *options;
    node_t parse_tree_stack;
};

struct data_meta {
    int *options;
    node_t parse_tree_stack;

    int in_terminals_section;
    int build_regex;
    node_t lexer_stack;
    node_t lexer_final;

    int cnt_term; // id factory
    node_t terminals; // terminal x id trie
    node_t terminals2; // id x terminal avl

    int cnt_nonterm; // id factory
    node_t nonterminals; // nonterminal x id trie
    node_t nonterminals2; // id x nonterminal avl

    node_t productions;


    int composition_mode;
    runtime_compiler_t runtime_compiler; // write compiler here
    node_t ulisp_parse_trees;
    node_t gsym_strtoi;
};

struct data_composition {
    int *options;
    node_t parse_tree_stack;
    FILE *output_file;
};

#endif
