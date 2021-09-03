/* This file was automatically generated. */

#include "internal_parser.h"
#include "composition/composition_lexer.h"
#include "composition/productions.h"
#include "composition/parser_actions.h"

static
internal_parser_t composition_parser = NULL;

internal_parser_t get_composition_parser(void)
{
    if (composition_parser == NULL) {
        composition_parser = new_internal_parser(get_composition_lexer(),
            production_length, composition__parser_actions0);
    }
    return composition_parser;
}
