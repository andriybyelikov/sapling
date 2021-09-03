#include <stdlib.h>
#include <libsapling/dm/graph.h>
#include "internal_lexer.h"
#include "internal_parser.h"
#include "aux/state_stack.h"

struct internal_parser {
    internal_lexer_t internal_lexer;
    const int *production_length;
    void (*parser_actions0)(void *, node_t *, terminal_t);
    terminal_t terminal;
    FILE *input_file;
    node_t state_stack;
    int cont;
};


internal_parser_t new_internal_parser(internal_lexer_t internal_lexer,
    const int *production_length,
    void (*parser_actions0)(void *, node_t *, terminal_t))
{
    internal_parser_t internal_parser = malloc(sizeof(struct internal_parser));
    internal_parser->internal_lexer = internal_lexer;
    internal_parser->production_length = production_length;
    internal_parser->parser_actions0 = parser_actions0;
    return internal_parser;
}

void internal_parser__shift(internal_parser_t parser, int state)
{
    delete_terminal(parser->terminal);
    parser->terminal = internal_lexer__fetch_terminal(parser->internal_lexer,
        parser->input_file, NULL);
    state_stack__insert(&parser->state_stack, state);
}

void internal_parser__reduce(internal_parser_t parser, int production)
{
	for (int i = 0; i < parser->production_length[production]; i++)
        state_stack__delete(&parser->state_stack);
}

void internal_parser__accept(internal_parser_t parser)
{
	parser->cont = 0;
}

void internal_parser__error(int state)
{
    fprintf(stderr, "Parsing error on state %d! Aborting...\n", state);
    exit(EXIT_FAILURE);
}

void internal_parser__parse(internal_parser_t parser, FILE *input_file,
    void *user_ptr)
{
    parser->input_file = input_file;
    parser->state_stack = NULL;
    parser->terminal = internal_lexer__fetch_terminal(
        parser->internal_lexer, input_file, user_ptr);
    parser->cont = 1;

    state_stack__insert(&parser->state_stack, 0);
    while (parser->cont) {
        parser->parser_actions0(user_ptr, &parser->state_stack,
            parser->terminal);
    }
}
