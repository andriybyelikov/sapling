#include <libsapling/terminal.h>
#include "mangen_terminals.h"
#include "mangen_user_data.h"

void lexer_action(void *terminal, void *user_ptr)
{
    struct user *user = user_ptr;
    switch (terminal__id(terminal)) {
    case t_eof:
        break;
    case t_blank:
        break;
    case t_linecomment:
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
    case t_union:
        break;
    }
}
