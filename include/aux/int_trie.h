#ifndef INT_TRIE_H
#define INT_TRIE_H

#include <libsapling/dm/trie.h>

IMPLEMENT_TYPED_TRIE(int_trie, int, int__print)

static
void apply_get_id(int *data, void *info)
{
    CAST_USER_INFO(int *, id, info);

    *id = **(int **)data;
}

#endif
