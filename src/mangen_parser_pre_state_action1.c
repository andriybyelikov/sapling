#include <libsapling/dm/path.h>
#include "options.h"
#include "state_stack.h"
#include "mangen_user_data.h"

void pre_state_action1(void *user_ptr, node_t *state_stack)
{
    struct user *user = user_ptr;
    if (user->options[OPTION_FLOG_STATE_STACK]) {
        state_stack__print_data(stdout, state_stack);
        fprintf(stdout, "\n");
    }
}
