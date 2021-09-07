#ifndef STRING_TO_INT_AVL_H
#define STRING_TO_INT_AVL_H

#include <libsapling/dm/avl.h>

typedef struct {
    int id;
    const char *str;
} idxstr_t;

void idxstr__print(FILE *stream, const void *data);

IMPLEMENT_TYPED_AVL(idxstr_avl, idxstr_t, int__compare, int__equals,
    idxstr__print)

const char *idxstr_get_string(node_t *ref, int key);

#endif
