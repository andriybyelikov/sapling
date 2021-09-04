/* This file was automatically generated. */

#include "internal_parser.h"
#include "ulisp/ulisp_lexer.h"
#include "ulisp/productions.h"
#include "ulisp/parser_actions.h"

static
internal_parser_t ulisp_parser = NULL;

internal_parser_t get_ulisp_parser(void)
{
    if (ulisp_parser == NULL) {
        ulisp_parser = new_internal_parser(get_ulisp_lexer(),
            production_length, ulisp__parser_actions0);
    }
    return ulisp_parser;
}
