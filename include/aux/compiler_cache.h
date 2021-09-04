#ifndef COMPILER_CACHE_H
#define COMPILER_CACHE_H

#include <libsapling/dm/trie.h>
#include "runtime_compiler.h"

IMPLEMENT_TYPED_TRIE(compiler_cache, runtime_compiler_t, NULL)

#endif
