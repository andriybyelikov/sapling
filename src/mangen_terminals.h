#ifndef MANGEN_TERMINALS
#define MANGEN_TERMINALS

enum {
    t_eof,
    t_blank,
    t_linecomment,
    t_kleenestar,
    t_kleeneplus,
    t_rightarrow,
    t_any,
    t_terminator,
    t_disjunction,
    t_lpar,
    t_rpar,
    t_symbol,
    t_literal,
    t_class,
    NUM_TERMINALS
};

static
char *terminal_str[] = {
    "t_eof",
    "t_blank",
    "t_linecomment",
    "t_kleenestar",
    "t_kleeneplus",
    "t_rightarrow",
    "t_any",
    "t_terminator",
    "t_disjunction",
    "t_lpar",
    "t_rpar",
    "t_symbol",
    "t_literal",
    "t_class"
};

#endif
