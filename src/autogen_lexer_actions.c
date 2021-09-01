#include <libsapling/cc/terminal.h>
#include "autogen_terminals.h"
#include "mangen_user_data.h"

void lexer_action(terminal_t terminal, void *user_ptr)
{
    struct user *user = user_ptr;
    switch (terminal__id(terminal)) {
    case t_gobble__blank:
        break;
    case t_gobble__linecomment:
        break;
    case t_kleenestar:
        break;
    case t_kleeneplus:
        break;
    case t_rightarrow:
        break;
    case t_any:
        break;
    case t_terminator:
        break;
    case t_disjunction:
        break;
    case t_lpar:
        break;
    case t_rpar:
        break;
    case t_symbol:
        break;
    case t_literal:
        break;
    case t_class:
        break;
    case t_eof:
        break;
    }
}
