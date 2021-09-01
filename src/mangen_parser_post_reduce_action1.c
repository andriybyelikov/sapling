#include <libsapling/cc/parse_tree.h>
#include <libsapling/dm/stack.h>
#include "mangen_user_data.h"
#include "autogen_productions.h"

IMPLEMENT_TYPED_STACK(node_stack, node_t, NULL)

static
void push_production_to_parse_tree_stack(node_t *parse_tree_stack, int pid)
{
    node_t node = parse_tree__create_node(psym_str[psym[pid]]);
    
    // append n children in reverse order
    node_t reverse = NULL;
    for (int i = 0; i < pnsym[pid]; i++) {
        node_t child = node_stack__access(parse_tree_stack);
        node_stack__delete(parse_tree_stack);
        node_stack__insert(&reverse, child);
    }
    while (reverse != NULL) {
        node_t child = node_stack__access(&reverse);
        node_stack__delete(&reverse);
        parse_tree__append_child(&node, child);
    }
	node_stack__insert(parse_tree_stack, node);
}

void post_reduce_action1(void *user_ptr, int num_symbols)
{
    struct user *user = user_ptr;
    push_production_to_parse_tree_stack(&user->parse_tree_stack, num_symbols);
}
