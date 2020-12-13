#include <stdio.h>
#include <stdlib.h>
#include <libsapling/typed_stack.h>
#include "lexer.h"
#include <libsapling/terminal.h>
#include "mangen_productions.h"

#include "parser_actions.h"

define_typed_stack(int)

static int _cont;
static FILE *_input_file;
static void *_terminal;
static void *_state_stack;

void shift(int next_state)
{
	free(_terminal);
    _terminal = fetch_terminal(_input_file, NULL);
    stack_int__insert(&_state_stack, next_state);
}

void reduce(int pid)
{
	for (int i = 0; i < pnsym[pid]; i++)
        stack_int__delete(&_state_stack);
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
    stack_int__insert(&_state_stack, 0);
    while (_cont)
		parser_actions0(user_ptr, &_state_stack, _terminal);
}
