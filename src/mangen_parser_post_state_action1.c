#include <libsapling/dm/path.h>
#include <libsapling/cc/parse_tree.h>
#include "options.h"
#include "parse_tree_stack.h"
#include "mangen_user_data.h"

void post_state_action1(void *user_ptr)
{
    struct user *user = user_ptr;
    if (user->options[OPTION_FLOG_PARSE_TREE_STACK]) {
        parse_tree_stack__print_data(stdout, &user->parse_tree_stack);
        fprintf(stdout, "\n");
    }
}
