#ifndef PARSE_TREE_STACK_H
#define PARSE_TREE_STACK_H

#include <libsapling/dm/stack.h>
#include <libsapling/cc/parse_tree.h>

static
void fprintf_parse_tree_node(FILE *stream, const void *data)
{
    fprintf(stream, "%s", *parse_tree__data(*(node_t *)data));
}

IMPLEMENT_TYPED_STACK(parse_tree_stack, node_t, fprintf_parse_tree_node)

#endif
