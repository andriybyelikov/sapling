#ifndef EVAL_H
#define EVAL_H

#include <libsapling/dm/graph.h>
#include "output_stream.h"

void eval(node_t *ulisp_parse_tree, node_t *parse_tree_stack,
    output_stream_t out);

#endif
