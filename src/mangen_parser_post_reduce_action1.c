#include <libsapling/parse_tree.h>
#include <libsapling/typed_stack.h>
#include "mangen_user_data.h"
#include "mangen_productions.h"

typedef void *ptr;
define_typed_stack(ptr)

static
void push_production_to_parse_tree_stack(void **parse_tree_stack, int pid)
{
    void *node = parse_tree__create_node(psym_str[psym[pid]]);
    
    // append n children in reverse order
    void *reverse = NULL;
    for (int i = 0; i < pnsym[pid]; i++) {
        void *child = stack_ptr__access(parse_tree_stack);
        stack_ptr__delete(parse_tree_stack);
        stack_ptr__insert(&reverse, child);
    }
    while (reverse != NULL) {
        void *child = stack_ptr__access(&reverse);
        stack_ptr__delete(&reverse);
        parse_tree__append_child(&node, child);
    }
	stack_ptr__insert(parse_tree_stack, node);
}

void post_reduce_action1(void *user_ptr, int num_symbols)
{
    struct user *user = user_ptr;
    push_production_to_parse_tree_stack(&user->parse_tree_stack, num_symbols);
}
