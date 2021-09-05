#include <libsapling/cc/parse_tree.h>
#include "aux/parse_tree_stack.h"
#include "data.h"

void ulisp__production_attibuted_actions2(void *user_ptr, int pid)
{
    struct data_common *user = user_ptr;
    switch (pid) {
    case 0: // start -> lists;
        break;
    case 1: // lists -> list lists;
        break;
    case 2: // lists -> list;
        break;
    case 3: // list -> t_lpar t_symbol args t_rpar;
        break;
    case 4: // args -> arg args;
        break;
    case 5: // args -> arg;
        break;
    case 6: // arg -> t_string;
        break;
    case 7: // arg -> t_integer;
        break;
    case 8: // arg -> t_hexadecimal;
        break;
    case 9: // arg -> list;
        break;
    }
}
