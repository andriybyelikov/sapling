#ifndef RUNTIME_COMPILER_H
#define RUNTIME_COMPILER_H

#include <libsapling/cc/parser/action_table.h>
#include <libsapling/cc/parser/goto_table.h>

typedef struct runtime_compiler *runtime_compiler_t;

runtime_compiler_t new_runtime_compiler(node_t *lexer, action_table_t slr_at,
    goto_table_t slr_gt);
node_t *runtime_compiler__get_lexer(runtime_compiler_t runtime_compiler);
action_table_t runtime_compiler__get_action_table(
    runtime_compiler_t runtime_compiler);
goto_table_t runtime_compiler__get_goto_table(
    runtime_compiler_t runtime_compiler);

#endif
