/* This file was automatically generated. */

#include <string.h>
#include "ulisp/terminals.h"
#include "ulisp/nonterminals.h"

int ulisp__get_grammar_symbol_index_from_string(const char *str)
{
    int i = 0;
    for (; i < NUM_TERMINALS; i++)
        if (!strcmp(str, terminal_string[i]))
            return i;
    for (; i - NUM_TERMINALS < NUM_NONTERMINALS; i++)
        if (!strcmp(str, nonterminal_string[i - NUM_TERMINALS]))
            return i;
}
