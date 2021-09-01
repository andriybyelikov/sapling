#ifndef AUTOGEN_TERMINALS
#define AUTOGEN_TERMINALS

enum {
    t_gobble__blank,
    t_gobble__linecomment,
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
    t_lisp_routine,
    t_eof,
    NUM_TERMINALS
};

static
char *terminal_str[] = {
    "t_gobble__blank",
    "t_gobble__linecomment",
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
    "t_class",
    "t_lisp_routine",
    "t_eof",
};

#endif
