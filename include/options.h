#ifndef OPTIONS
#define OPTIONS

enum {
    OPTION_FPRINT_LEXER_OUTPUT_ONLY,
    OPTION_FLOG_STATE_STACK,
    OPTION_FLOG_PRODUCTION_STACK,
    OPTION_FDUMP_PARSE_TREE,
    OPTION_FPRINT_TERMINALS,
    OPTION_FPRINT_NONTERMINALS,
    OPTION_FPRINT_PRODUCTIONS,
    OPTION_FDUMP_LEXER_AUTOMATON,
    NUM_OPTIONS
};

static
const char *option_str[] = {
    "-fprint-lexer-output-only",
    "-flog-state-stack",
    "-flog-production-stack",
    "-fdump-parse-tree",
    "-fprint-terminals",
    "-fprint-nonterminals",
    "-fprint-productions",
    "-fdump-lexer-automaton"
};

#endif
