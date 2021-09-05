#ifndef ULISP_PARSE_TREE_LIST_H
#define ULISP_PARSE_TREE_LIST_H

#include <libsapling/dm/avl.h>

typedef struct {
    int prod_id;
    node_t ulisp_parse_tree;
} pidxpt_t;

IMPLEMENT_TYPED_AVL(ulisp_parse_tree_avl, pidxpt_t, int__compare, int__equals,
    NULL)

#endif
