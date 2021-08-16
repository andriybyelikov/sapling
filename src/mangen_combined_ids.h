#ifndef MANGEN_COMBINED_IDS
#define MANGEN_COMBINED_IDS

#include "mangen_terminals.h"
#include "mangen_productions.h"

static
int psym_str_idx(const char *str)
{
    int i = 0;
    for (; i < NUM_TERMINALS; i++)
        if (!strcmp(str, terminal_str[i]))
            return i;
    for (; i - NUM_TERMINALS < NUM_NONTERMINALS; i++)
        if (!strcmp(str, psym_str[i - NUM_TERMINALS]))
            return i;
}

#endif
