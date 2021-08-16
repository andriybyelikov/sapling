#include <stdio.h>
#include <stdlib.h>
#include <libsapling/cc/terminal.h>
#include "lexer.h"
#include "state_stack.h"
#include "mangen_productions.h"
#include "parser_actions.h"

static int _cont;
static FILE *_input_file;
static terminal_t _terminal;
static node_t _state_stack;

void shift(int next_state)
{
	free(_terminal);
    _terminal = fetch_terminal(_input_file, NULL);
    state_stack__insert(&_state_stack, next_state);
}

void reduce(int pid)
{
	for (int i = 0; i < pnsym[pid]; i++)
        state_stack__delete(&_state_stack);
}

void error(int state)
{
    fprintf(stderr, "Parsing error on state %d! Aborting...\n", state);
    exit(EXIT_FAILURE);
}

void accept(void)
{
	_cont = 0;
}

void parse(FILE *input_file, void *user_ptr)
{
    _input_file = input_file;
    _terminal = fetch_terminal(_input_file, NULL);
    _state_stack = NULL;
    _cont = 1;
    state_stack__insert(&_state_stack, 0);
    while (_cont)
		parser_actions0(user_ptr, &_state_stack, _terminal);
}
