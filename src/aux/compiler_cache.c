#include "aux/compiler_cache.h"

static
void get_compiler_apply(runtime_compiler_t *data, void *info)
{
    CAST_USER_INFO(runtime_compiler_t *, user, info);

    *user = **(runtime_compiler_t **)data;
}

runtime_compiler_t compiler_cache__get_compiler(node_t *cache,
    const char *key)
{
    runtime_compiler_t compiler = NULL;
    compiler_cache__access(E_QT, cache, key, &compiler,
        compiler_cache__predicate_1, get_compiler_apply);
    return compiler;
}
