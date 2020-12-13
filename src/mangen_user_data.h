#ifndef MANGEN_USER_DATA
#define MANGEN_USER_DATA

struct user {
    int *options;
    int in_terminals_section;
    void *parse_tree_stack;
    int build_regex;
    void *rea_stack;
    void *final_rea;
    const char *parse_tree_filename;
    const char *lexer_automaton_filename;
};

#endif
