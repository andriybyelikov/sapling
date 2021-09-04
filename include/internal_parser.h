#ifndef INTERNAL_PARSER_H
#define INTERNAL_PARSER_H

#include <stdio.h>
#include <libsapling/dm/graph.h>
#include "internal_lexer.h"

typedef struct internal_parser *internal_parser_t;

internal_parser_t new_internal_parser(internal_lexer_t internal_lexer,
    const int *production_length,
    void (*parser_actions0)(void *, node_t *, terminal_t));
void internal_parser__shift(internal_parser_t parser, int state);
void internal_parser__reduce(internal_parser_t parser, int production);
void internal_parser__accept(internal_parser_t parser);
void internal_parser__error(int state);
void internal_parser__parse(internal_parser_t parser,
    input_stream_t input_stream, void *user_ptr);

#endif
