#ifndef OPTIONS_H
#define OPTIONS_H

enum {
    OPTION_VERSION,
    OPTION_HELP,
    OPTION_OUTPUT_FILE,
    OPTION_META_MODE,
    OPTION_PRINT_LEXER_OUTPUT_ONLY,
    OPTION_LOG_STATE_STACK,
    OPTION_LOG_PARSE_TREE_STACK,
    OPTION_DUMP_PARSE_TREE,
    OPTION_PRINT_TERMINALS,
    OPTION_PRINT_NONTERMINALS,
    OPTION_PRINT_PRODUCTIONS,
    OPTION_PRINT_LEXER_AUTOMATON,
    OPTION_DUMP_LEXER_AUTOMATON,
    OPTION_PRINT_SLR_TABLES,
    NUM_OPTIONS
};

static
const char *option_string[] = {
    "--version",
    "--help",
    "-o",
    "-m",
    "-print-lexer-output-only",
    "-log-state-stack",
    "-log-parse-tree-stack",
    "-dump-parse-tree",
    "-print-terminals",
    "-print-nonterminals",
    "-print-productions",
    "-print-lexer-automaton",
    "-dump-lexer-automaton",
    "-print-slr-tables",
};

#endif
