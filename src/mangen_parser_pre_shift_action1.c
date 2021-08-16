#include <stdlib.h>
#include <string.h>
#include <libsapling/cc/parse_tree.h>
#include <libsapling/cc/text.h>
#include <libsapling/dm/stack.h>
#include <libsapling/cc/terminal.h>
#include "mangen_user_data.h"
#include "mangen_terminals.h"

IMPLEMENT_TYPED_STACK(node_stack, node_t, NULL)

static
void push_terminal_to_parse_tree_stack(terminal_t terminal,
    node_t *parse_tree_stack)
{
    node_t node = parse_tree__create_node(terminal_str[terminal__id(terminal)]);
    char *buf = malloc(2 * (strlen(terminal__lexeme(terminal)) + 1));
    {
        text__escape(buf, terminal__lexeme(terminal));
        parse_tree__append_child(&node, parse_tree__create_node(buf));
    }
	free(buf);
	node_stack__insert(parse_tree_stack, node);
}

void pre_shift_action1(void *user_ptr, terminal_t terminal)
{
    struct user *user = user_ptr;
    push_terminal_to_parse_tree_stack(terminal, &user->parse_tree_stack);
}
