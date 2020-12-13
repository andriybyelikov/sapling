#include <libsapling/path.h>
#include <libsapling/parse_tree.h>
#include "options.h"
#include "mangen_user_data.h"

static
void fpd_nonterminal(FILE *fd, void **ref)
{
    void **data = path__node__data(ref);
    fprintf(fd, parse_tree__node__get_string(data));
}

void post_state_action1(void *user_ptr)
{
    struct user *user = user_ptr;
    if (user->options[OPTION_FLOG_PRODUCTION_STACK])
        path__print(stdout, &user->parse_tree_stack, fpd_nonterminal, "$ ", " ", "\n");
}
