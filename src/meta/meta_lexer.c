/* This file was automatically generated. */

#include <stdio.h>
#include <libsapling/idiom.h>
#include "meta/terminals.h"
#include "internal_lexer.h"

static
int get_initial_state(void)
{
    return 0x192af810;
}

static
int next_state(int current_state, char input)
{
    switch (current_state) {
    case 0x192af810:
        switch (input) {
        case '\t':
            return 0x192af840;
        case '\n':
            return 0x192af840;
        case '\r':
            return 0x192af840;
        case ' ':
            return 0x192af840;
        case '\"':
            return 0x19528c40;
        case '(':
            return 0x192be250;
        case ')':
            return 0x192c0270;
        case '*':
            return 0x192b5070;
        case '+':
            return 0x192b6220;
        case '-':
            return 0x192b31d0;
        case '.':
            return 0x192b9170;
        case ';':
            return 0x192baa80;
        case '<':
            return 0x19538040;
        case '[':
            return 0x19530c60;
        case 'a':
            return 0x192c24a0;
        case 'b':
            return 0x192c24a0;
        case 'c':
            return 0x192c24a0;
        case 'd':
            return 0x192c24a0;
        case 'e':
            return 0x192c24a0;
        case 'f':
            return 0x192c24a0;
        case 'g':
            return 0x192c24a0;
        case 'h':
            return 0x192c24a0;
        case 'i':
            return 0x192c24a0;
        case 'j':
            return 0x192c24a0;
        case 'k':
            return 0x192c24a0;
        case 'l':
            return 0x192c24a0;
        case 'm':
            return 0x192c24a0;
        case 'n':
            return 0x192c24a0;
        case 'o':
            return 0x192c24a0;
        case 'p':
            return 0x192c24a0;
        case 'q':
            return 0x192c24a0;
        case 'r':
            return 0x192c24a0;
        case 's':
            return 0x192c24a0;
        case 't':
            return 0x192c24a0;
        case 'u':
            return 0x192c24a0;
        case 'v':
            return 0x192c24a0;
        case 'w':
            return 0x192c24a0;
        case 'x':
            return 0x192c24a0;
        case 'y':
            return 0x192c24a0;
        case 'z':
            return 0x192c24a0;
        case '|':
            return 0x192bc570;
        default:
            return -1;
        }
        break;
    case 0x192be250:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0x192c0270:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0x192b9170:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0x192baa80:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0x192bc570:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0x192c24a0:
        switch (input) {
        case '0':
            return 0x192c24a0;
        case '1':
            return 0x192c24a0;
        case '2':
            return 0x192c24a0;
        case '3':
            return 0x192c24a0;
        case '4':
            return 0x192c24a0;
        case '5':
            return 0x192c24a0;
        case '6':
            return 0x192c24a0;
        case '7':
            return 0x192c24a0;
        case '8':
            return 0x192c24a0;
        case '9':
            return 0x192c24a0;
        case '_':
            return 0x192c24a0;
        case 'a':
            return 0x192c24a0;
        case 'b':
            return 0x192c24a0;
        case 'c':
            return 0x192c24a0;
        case 'd':
            return 0x192c24a0;
        case 'e':
            return 0x192c24a0;
        case 'f':
            return 0x192c24a0;
        case 'g':
            return 0x192c24a0;
        case 'h':
            return 0x192c24a0;
        case 'i':
            return 0x192c24a0;
        case 'j':
            return 0x192c24a0;
        case 'k':
            return 0x192c24a0;
        case 'l':
            return 0x192c24a0;
        case 'm':
            return 0x192c24a0;
        case 'n':
            return 0x192c24a0;
        case 'o':
            return 0x192c24a0;
        case 'p':
            return 0x192c24a0;
        case 'q':
            return 0x192c24a0;
        case 'r':
            return 0x192c24a0;
        case 's':
            return 0x192c24a0;
        case 't':
            return 0x192c24a0;
        case 'u':
            return 0x192c24a0;
        case 'v':
            return 0x192c24a0;
        case 'w':
            return 0x192c24a0;
        case 'x':
            return 0x192c24a0;
        case 'y':
            return 0x192c24a0;
        case 'z':
            return 0x192c24a0;
        default:
            return -1;
        }
        break;
    case 0x19528c40:
        switch (input) {
        case '\"':
            return 0x1952a7f0;
        case '\\':
            return 0x19529210;
        default:
            return 0x19528c40;
        }
        break;
    case 0x192b5070:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0x192b6220:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0x19529210:
        switch (input) {
        default:
            return 0x19528c40;
        }
        break;
    case 0x1952a7f0:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0x19530c60:
        switch (input) {
        case ']':
            return 0x19531320;
        default:
            return 0x19530c60;
        }
        break;
    case 0x192b31d0:
        switch (input) {
        case '-':
            return 0x192b3230;
        case '>':
            return 0x192b76d0;
        default:
            return -1;
        }
        break;
    case 0x19531320:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0x192b3230:
        switch (input) {
        case '\n':
            return 0x192b38f0;
        default:
            return 0x192b3230;
        }
        break;
    case 0x192b76d0:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0x192b38f0:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0x19538040:
        switch (input) {
        case '>':
            return 0x19538700;
        default:
            return 0x19538040;
        }
        break;
    case 0x192af840:
        switch (input) {
        case '\t':
            return 0x192af840;
        case '\n':
            return 0x192af840;
        case '\r':
            return 0x192af840;
        case ' ':
            return 0x192af840;
        default:
            return -1;
        }
        break;
    case 0x19538700:
        switch (input) {
        default:
            return -1;
        }
        break;
        default:
            return -1;
    }
}

static
int is_accepting_state(int state)
{
    switch (state) {
    case 0x192af810:
        return 0;
    case 0x192be250:
        return 1;
    case 0x192c0270:
        return 1;
    case 0x192b9170:
        return 1;
    case 0x192baa80:
        return 1;
    case 0x192bc570:
        return 1;
    case 0x192c24a0:
        return 1;
    case 0x19528c40:
        return 0;
    case 0x192b5070:
        return 1;
    case 0x192b6220:
        return 1;
    case 0x19529210:
        return 0;
    case 0x1952a7f0:
        return 1;
    case 0x19530c60:
        return 0;
    case 0x192b31d0:
        return 0;
    case 0x19531320:
        return 1;
    case 0x192b3230:
        return 0;
    case 0x192b76d0:
        return 1;
    case 0x192b38f0:
        return 1;
    case 0x19538040:
        return 0;
    case 0x192af840:
        return 1;
    case 0x19538700:
        return 1;
    }
}

static
int get_class(int state)
{
    switch (state) {
    case 0x192be250:
        return t_lpar;
    case 0x192c0270:
        return t_rpar;
    case 0x192b9170:
        return t_any;
    case 0x192baa80:
        return t_terminator;
    case 0x192bc570:
        return t_disjunction;
    case 0x192c24a0:
        return t_symbol;
    case 0x192b5070:
        return t_kleenestar;
    case 0x192b6220:
        return t_kleeneplus;
    case 0x1952a7f0:
        return t_literal;
    case 0x19531320:
        return t_class;
    case 0x192b76d0:
        return t_rightarrow;
    case 0x192b38f0:
        return t_gobble__linecomment;
    case 0x192af840:
        return t_gobble__blank;
    case 0x19538700:
        return t_ulisp_routine;
    }
}

static
int class_has_gobble_modifier(int class)
{
    switch (class) {
    case t_gobble__blank:
        return 1;
    case t_gobble__linecomment:
        return 1;
    default:
        return 0;
    }
}

static
int get_eof_class(void)
{
    return t_eof;
}

void meta__lexer_actions(terminal_t terminal, UNUSED void *user_ptr);

static
internal_lexer_t meta_lexer = NULL;

internal_lexer_t get_meta_lexer(void)
{
    if (meta_lexer == NULL) {
        meta_lexer = new_internal_lexer(get_initial_state, next_state,
            is_accepting_state, get_class, class_has_gobble_modifier,
            get_eof_class, meta__lexer_actions);
    }
    return meta_lexer;
}
