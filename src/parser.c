#include <stdio.h>
#include <stdlib.h>
#include <libsapling/dm/avl.h>
#include <libsapling/dm/trie.h>
#include <libsapling/dm/typed/typed_common.h>
#include <libsapling/cc/terminal.h>
#include "lexer.h"
#include "state_stack.h"
#include "autogen_productions.h"
#include "parser_actions.h"
#include "mangen_user_data.h"

typedef struct {
    int id;
    const char *str;
} idxstr_t;

static
void fpd_idxstr(FILE *stream, const void *data)
{
    idxstr_t *a = (idxstr_t *)data;
    fprintf(stream, "(%d, \"%s\")", a->id, a->str);
}

IMPLEMENT_TYPED_AVL(idxstr_avl, idxstr_t, int__compare, int__equals, fpd_idxstr)
IMPLEMENT_TYPED_TRIE(int_trie, int, int__print)


static int _cont;
static FILE *_input_file;
static terminal_t _terminal;
static node_t _state_stack;

void error(int state)
{
    fprintf(stderr, "Parsing error on state %d! Aborting...\n", state);
    exit(EXIT_FAILURE);
}

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
