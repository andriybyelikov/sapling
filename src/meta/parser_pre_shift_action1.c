#include <stdlib.h>
#include <string.h>
#include <libsapling/cc/text.h>
#include <libsapling/cc/terminal.h>
#include "aux/parse_tree_stack.h"
#include "meta/terminals.h"
#include "data.h"

static
void push_terminal_to_parse_tree_stack(terminal_t terminal,
    node_t *parse_tree_stack)
{
    node_t node = parse_tree__create_node(
        terminal_string[terminal__id(terminal)]);
    char *buf = malloc(2 * (strlen(terminal__lexeme(terminal)) + 1));
    text__escape(buf, terminal__lexeme(terminal));
    parse_tree__append_child(&node, parse_tree__create_node(buf));
	parse_tree_stack__insert(parse_tree_stack, node);
}

void meta__pre_shift_action1(void *user_ptr, terminal_t terminal)
{
    struct data_common *user = user_ptr;
    push_terminal_to_parse_tree_stack(terminal, &user->parse_tree_stack);
}
