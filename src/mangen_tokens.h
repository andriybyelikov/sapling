#ifndef GEN_TOKENS
#define GEN_TOKENS

enum {
    t_eof,
    // t_blank,
    // t_linecomment,
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
    t_union,
    num_tokens
};

static
const char *token_str[] = {
    "t_eof",
    // "t_blank",
    // "t_linecomment",
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
    "t_union"
};

#endif
