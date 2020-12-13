#include <stdlib.h>
#include <string.h>
#include <libsapling/parse_tree.h>
#include <libsapling/text.h>
#include <libsapling/typed_stack.h>
#include <libsapling/terminal.h>
#include "mangen_user_data.h"
#include "mangen_terminals.h"

typedef void *ptr;
define_typed_stack(ptr)

static
void push_terminal_to_parse_tree_stack(void *terminal, void **parse_tree_stack)
{
    void *node = parse_tree__create_node(terminal_str[terminal__id(terminal)]);
    char *buf = malloc(2 * (strlen(terminal__lexeme(terminal)) + 1));
    {
        text__escape(buf, terminal__lexeme(terminal));
        parse_tree__append_child(&node, parse_tree__create_node(buf));
    }
	free(buf);
	stack_ptr__insert(parse_tree_stack, node);
}

void pre_shift_action1(void *user_ptr, void *terminal)
{
    struct user *user = user_ptr;
    push_terminal_to_parse_tree_stack(terminal, &user->parse_tree_stack);
}
