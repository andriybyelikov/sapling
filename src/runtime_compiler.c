#include <stdlib.h>
#include "runtime_compiler.h"

struct runtime_compiler {
    node_t *lexer;
    node_t *terminals; // Trie map (terminal string x int)
    node_t *nonterminals; // AVL map (nonterminal int x string)
    grammar_t grammar;
    action_table_t slr_at;
    goto_table_t slr_gt;
    node_t *ulisp_parse_trees; // AVL map (production index x parse tree)
};

runtime_compiler_t new_runtime_compiler(node_t *lexer, node_t *terminals,
    node_t *nonterminals, grammar_t grammar, action_table_t slr_at,
    goto_table_t slr_gt, node_t *ulisp_parse_trees)
{
    runtime_compiler_t runtime_compiler =
        malloc(sizeof(struct runtime_compiler));
    runtime_compiler->lexer = lexer;
    runtime_compiler->terminals = terminals;
    runtime_compiler->nonterminals = nonterminals;
    runtime_compiler->grammar = grammar;
    runtime_compiler->slr_at = slr_at;
    runtime_compiler->slr_gt = slr_gt;
    runtime_compiler->ulisp_parse_trees = ulisp_parse_trees;
    return runtime_compiler;
}

node_t *runtime_compiler__get_lexer(runtime_compiler_t runtime_compiler)
{
    return runtime_compiler->lexer;
}

node_t *runtime_compiler__get_terminals(runtime_compiler_t runtime_compiler)
{
    return runtime_compiler->terminals;
}

node_t *runtime_compiler__get_nonterminals(runtime_compiler_t runtime_compiler)
{
    return runtime_compiler->nonterminals;
}

grammar_t runtime_compiler__get_grammar(runtime_compiler_t runtime_compiler)
{
    return runtime_compiler->grammar;
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

node_t *runtime_compiler__get_ulisp_parse_trees(
    runtime_compiler_t runtime_compiler)
{
    return runtime_compiler->ulisp_parse_trees;
}
