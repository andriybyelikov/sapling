#include "aux/parse_tree_stack.h"
#include "options.h"
#include "data.h"

void meta__post_state_action1(void *user_ptr)
{
    struct data_meta *user = user_ptr;
    if (user->options[OPTION_LOG_PARSE_TREE_STACK]) {
        parse_tree_stack__print(stdout, &user->parse_tree_stack);
        fprintf(stdout, "\n");
    }
}
