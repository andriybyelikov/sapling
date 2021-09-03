/* This file was automatically generated. */

#include "internal_parser.h"
#include "meta/meta_lexer.h"
#include "meta/productions.h"
#include "meta/parser_actions.h"

static
internal_parser_t meta_parser = NULL;

internal_parser_t get_meta_parser(void)
{
    if (meta_parser == NULL) {
        meta_parser = new_internal_parser(get_meta_lexer(),
            production_length, meta__parser_actions0);
    }
    return meta_parser;
}
