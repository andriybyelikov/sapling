#include <stdlib.h>
#include <string.h>
#include "compose.h"
#include "aux/parse_tree_stack.h"
#include "aux/string_list.h"
#include "data.h"

void composition__production_attibuted_actions2(void *user_ptr, int pid)
{
    struct data_composition *user = user_ptr;
    switch (pid) {
    case 0: // start -> fragments;
        break;
    case 1: // fragments -> fragment fragments;
        break;
    case 2: // fragments -> fragment;
        break;
    case 3: // fragment -> t_symbol translation_stack t_frag_code;
        {
            // ensure t_symbol is keyword "fragment"
            node_t fragment =
                parse_tree_stack__access(&user->parse_tree_stack);
            node_t t_symbol =
                parse_tree__get_child_by_string(&fragment, "t_symbol");
            node_t t_symbol_lx =
                parse_tree__get_child_by_position(&t_symbol, 0);
            const char *fragment_keyword = *parse_tree__data(t_symbol_lx);
            if (strcmp(fragment_keyword, "fragment") != 0) {
                fprintf(stderr, "libsapling: error: expected fragment keyword where user wrote: %s\n", fragment_keyword);
                exit(EXIT_FAILURE);
            }

            // get fragment content from lexeme
            node_t t_frag_code = parse_tree__get_child_by_string(&fragment,
                "t_frag_code");
            node_t t_frag_code_lx =
                parse_tree__get_child_by_position(&t_frag_code, 0);
            char *code = (char*)*parse_tree__data(t_frag_code_lx);
            // trim <>
            code = code + 1;
            code[strlen(code) - 1] = 0;

            node_t spec_list = NULL;
            node_t translation_stack =
                parse_tree__get_child_by_string(&fragment,
                    "translation_stack");
            while (translation_stack != NULL) {
                t_symbol =
                    parse_tree__get_child_by_string(&translation_stack,
                        "t_symbol");
                t_symbol_lx = parse_tree__get_child_by_position(&t_symbol, 0);
                const char *filename = *parse_tree__data(t_symbol_lx);
                char *filename_heap = malloc(strlen(filename) + 1);
                strcpy(filename_heap, filename);
                string_queue__insert(&spec_list, filename_heap);
                translation_stack =
                    parse_tree__get_child_by_string(&translation_stack,
                        "translation_stack");
            }

            compose(code, &spec_list, user->output_file, user_ptr);
        }
        break;
    case 4: // translation_stack -> t_symbol translation_stack;
        break;
    case 5: // translation_stack -> t_symbol;
        break;
    }
}
