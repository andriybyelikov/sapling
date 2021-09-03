#include "aux/state_stack.h"
#include "options.h"
#include "data.h"

void meta__pre_state_action1(void *user_ptr, node_t *state_stack)
{
    struct data_meta *user = user_ptr;
    if (user->options[OPTION_LOG_STATE_STACK]) {
        state_stack__print(stdout, state_stack);
        fprintf(stdout, "\n");
    }
}
