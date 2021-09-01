#ifndef OPTIONS
#define OPTIONS

enum {
    OPTION_FPRINT_LEXER_OUTPUT_ONLY,
    OPTION_FLOG_STATE_STACK,
    OPTION_FLOG_PARSE_TREE_STACK,
    OPTION_FDUMP_PARSE_TREE,
    OPTION_FPRINT_TERMINALS,
    OPTION_FPRINT_NONTERMINALS,
    OPTION_FPRINT_PRODUCTIONS,
    OPTION_FPRINT_LEXER_AUTOMATON,
    OPTION_FDUMP_LEXER_AUTOMATON,
    OPTION_FPRINT_SLR_TABLES,
    NUM_OPTIONS
};

static
const char *option_str[] = {
    "-fprint-lexer-output-only",
    "-flog-state-stack",
    "-flog-parse-tree-stack",
    "-fdump-parse-tree",
    "-fprint-terminals",
    "-fprint-nonterminals",
    "-fprint-productions",
    "-fprint-lexer-automaton",
    "-fdump-lexer-automaton",
    "-fprint-slr-tables"
};

#endif
