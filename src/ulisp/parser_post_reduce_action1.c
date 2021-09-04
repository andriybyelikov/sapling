#include "aux/parse_tree_stack.h"
#include "ulisp/productions.h"
#include "data.h"

static
void push_production_to_parse_tree_stack(node_t *parse_tree_stack, int pid)
{
    node_t node = parse_tree__create_node(
        nonterminal_string[production_symbol[pid]]);
    
    // append n children in reverse order
    node_t reverse = NULL;
    for (int i = 0; i < production_length[pid]; i++) {
        node_t child = parse_tree_stack__access(parse_tree_stack);
        parse_tree_stack__delete(parse_tree_stack);
        parse_tree_stack__insert(&reverse, child);
    }
    while (reverse != NULL) {
        node_t child = parse_tree_stack__access(&reverse);
        parse_tree_stack__delete(&reverse);
        parse_tree__append_child(&node, child);
    }
	parse_tree_stack__insert(parse_tree_stack, node);
}

void ulisp__post_reduce_action1(void *user_ptr, int num_symbols)
{
    struct data_common *user = user_ptr;
    push_production_to_parse_tree_stack(&user->parse_tree_stack, num_symbols);
}
