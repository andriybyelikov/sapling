#include <libsapling/path.h>
#include "options.h"
#include "mangen_user_data.h"

static
void fpd_int(FILE *fd, void **ref)
{
    int *data = path__node__data(ref);
    fprintf(fd, "%d", *data);
}

void pre_state_action1(void *user_ptr, void **state_stack)
{
    struct user *user = user_ptr;
    if (user->options[OPTION_FLOG_STATE_STACK])
        path__print(stdout, state_stack, fpd_int, "$ ", " ", "\n");
}
