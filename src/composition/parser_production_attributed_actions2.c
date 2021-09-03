#include "aux/parse_tree_stack.h"
#include "data.h"

void composition__production_attibuted_actions2(void *user_ptr, int pid)
{
    struct data_common *user = user_ptr;
    switch (pid) {
    case 0: // start -> fragments;
        break;
    case 1: // fragments -> fragment fragments;
        break;
    case 2: // fragments -> fragment;
        break;
    case 3: // fragment -> t_fragment translation_stack t_frag_code;
        {
            node_t fragment = parse_tree_stack__access(
                &user->parse_tree_stack);
            node_t t_frag_code = parse_tree__get_child_by_string(&fragment,
                "t_frag_code");
            node_t lx = parse_tree__get_child_by_position(&t_frag_code,
                0); // lexeme
            const char *code = *parse_tree__data(lx);
            printf("%s", code);
        }
        break;
    case 4: // translation_stack -> t_filename translation_stack;
        break;
    case 5: // translation_stack -> t_filename;
        break;
    }
}
