#ifndef STATE_STACK_H
#define STATE_STACK_H

#include <libsapling/dm/stack.h>

static
void fprintf_int(FILE *stream, const void *data)
{
    fprintf(stream, "%d", *(int *)data);
}

IMPLEMENT_TYPED_STACK(state_stack, int, fprintf_int)

#endif
