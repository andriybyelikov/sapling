#include <stdlib.h>
#include "runtime_compiler.h"

struct runtime_compiler {
    node_t *lexer;
    action_table_t slr_at;
    goto_table_t slr_gt;
    // uLisp routines
};

runtime_compiler_t new_runtime_compiler(node_t *lexer, action_table_t slr_at,
    goto_table_t slr_gt)
{
    runtime_compiler_t runtime_compiler =
        malloc(sizeof(struct runtime_compiler));
    runtime_compiler->lexer = lexer;
    runtime_compiler->slr_at = slr_at;
    runtime_compiler->slr_gt = slr_gt;
    return runtime_compiler;
}

node_t *runtime_compiler__get_lexer(runtime_compiler_t runtime_compiler)
{
    return runtime_compiler->lexer;
}

action_table_t runtime_compiler__get_action_table(
    runtime_compiler_t runtime_compiler)
{
    return runtime_compiler->slr_at;
}

goto_table_t runtime_compiler__get_goto_table(
    runtime_compiler_t runtime_compiler)
{
    return runtime_compiler->slr_gt;
}
