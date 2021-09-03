/* This file was automatically generated. */

#include <stdio.h>
#include <libsapling/idiom.h>
#include "meta/terminals.h"
#include "internal_lexer.h"

static
int get_initial_state(void)
{
    return 0xa0b987f0;
}

static
int next_state(int current_state, char input)
{
    switch (current_state) {
    case 0xa0b987f0:
        switch (input) {
        case '\t':
            return 0xa0b98820;
        case '\n':
            return 0xa0b98820;
        case '\r':
            return 0xa0b98820;
        case ' ':
            return 0xa0b98820;
        case '\"':
            return 0xa0e12260;
        case '(':
            return 0xa0ba76b0;
        case ')':
            return 0xa0ba9750;
        case '*':
            return 0xa0b9e1d0;
        case '+':
            return 0xa0b9f400;
        case '-':
            return 0xa0b9c250;
        case '.':
            return 0xa0ba2450;
        case ';':
            return 0xa0ba3de0;
        case '<':
            return 0xa0e218c0;
        case '[':
            return 0xa0e1a400;
        case 'a':
            return 0xa0baba00;
        case 'b':
            return 0xa0baba00;
        case 'c':
            return 0xa0baba00;
        case 'd':
            return 0xa0baba00;
        case 'e':
            return 0xa0baba00;
        case 'f':
            return 0xa0baba00;
        case 'g':
            return 0xa0baba00;
        case 'h':
            return 0xa0baba00;
        case 'i':
            return 0xa0baba00;
        case 'j':
            return 0xa0baba00;
        case 'k':
            return 0xa0baba00;
        case 'l':
            return 0xa0baba00;
        case 'm':
            return 0xa0baba00;
        case 'n':
            return 0xa0baba00;
        case 'o':
            return 0xa0baba00;
        case 'p':
            return 0xa0baba00;
        case 'q':
            return 0xa0baba00;
        case 'r':
            return 0xa0baba00;
        case 's':
            return 0xa0baba00;
        case 't':
            return 0xa0baba00;
        case 'u':
            return 0xa0baba00;
        case 'v':
            return 0xa0baba00;
        case 'w':
            return 0xa0baba00;
        case 'x':
            return 0xa0baba00;
        case 'y':
            return 0xa0baba00;
        case 'z':
            return 0xa0baba00;
        case '|':
            return 0xa0ba5950;
        default:
            return -1;
        }
        break;
    case 0xa0ba76b0:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0xa0ba9750:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0xa0ba2450:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0xa0ba3de0:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0xa0ba5950:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0xa0baba00:
        switch (input) {
        case '0':
            return 0xa0baba00;
        case '1':
            return 0xa0baba00;
        case '2':
            return 0xa0baba00;
        case '3':
            return 0xa0baba00;
        case '4':
            return 0xa0baba00;
        case '5':
            return 0xa0baba00;
        case '6':
            return 0xa0baba00;
        case '7':
            return 0xa0baba00;
        case '8':
            return 0xa0baba00;
        case '9':
            return 0xa0baba00;
        case '_':
            return 0xa0baba00;
        case 'a':
            return 0xa0baba00;
        case 'b':
            return 0xa0baba00;
        case 'c':
            return 0xa0baba00;
        case 'd':
            return 0xa0baba00;
        case 'e':
            return 0xa0baba00;
        case 'f':
            return 0xa0baba00;
        case 'g':
            return 0xa0baba00;
        case 'h':
            return 0xa0baba00;
        case 'i':
            return 0xa0baba00;
        case 'j':
            return 0xa0baba00;
        case 'k':
            return 0xa0baba00;
        case 'l':
            return 0xa0baba00;
        case 'm':
            return 0xa0baba00;
        case 'n':
            return 0xa0baba00;
        case 'o':
            return 0xa0baba00;
        case 'p':
            return 0xa0baba00;
        case 'q':
            return 0xa0baba00;
        case 'r':
            return 0xa0baba00;
        case 's':
            return 0xa0baba00;
        case 't':
            return 0xa0baba00;
        case 'u':
            return 0xa0baba00;
        case 'v':
            return 0xa0baba00;
        case 'w':
            return 0xa0baba00;
        case 'x':
            return 0xa0baba00;
        case 'y':
            return 0xa0baba00;
        case 'z':
            return 0xa0baba00;
        default:
            return -1;
        }
        break;
    case 0xa0e12260:
        switch (input) {
        case '\"':
            return 0xa0e13f10;
        case '\\':
            return 0xa0e128b0;
        default:
            return 0xa0e12260;
        }
        break;
    case 0xa0b9e1d0:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0xa0b9f400:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0xa0e128b0:
        switch (input) {
        default:
            return 0xa0e12260;
        }
        break;
    case 0xa0e13f10:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0xa0e1a400:
        switch (input) {
        case ']':
            return 0xa0e1ab20;
        default:
            return 0xa0e1a400;
        }
        break;
    case 0xa0b9c250:
        switch (input) {
        case '-':
            return 0xa0b9c2b0;
        case '>':
            return 0xa0ba0930;
        default:
            return -1;
        }
        break;
    case 0xa0e1ab20:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0xa0b9c2b0:
        switch (input) {
        case '\n':
            return 0xa0b9c9d0;
        default:
            return 0xa0b9c2b0;
        }
        break;
    case 0xa0ba0930:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0xa0b9c9d0:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0xa0e218c0:
        switch (input) {
        case '>':
            return 0xa0e21fe0;
        default:
            return 0xa0e218c0;
        }
        break;
    case 0xa0b98820:
        switch (input) {
        case '\t':
            return 0xa0b98820;
        case '\n':
            return 0xa0b98820;
        case '\r':
            return 0xa0b98820;
        case ' ':
            return 0xa0b98820;
        default:
            return -1;
        }
        break;
    case 0xa0e21fe0:
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
    case 0xa0b987f0:
        return 0;
    case 0xa0ba76b0:
        return 1;
    case 0xa0ba9750:
        return 1;
    case 0xa0ba2450:
        return 1;
    case 0xa0ba3de0:
        return 1;
    case 0xa0ba5950:
        return 1;
    case 0xa0baba00:
        return 1;
    case 0xa0e12260:
        return 0;
    case 0xa0b9e1d0:
        return 1;
    case 0xa0b9f400:
        return 1;
    case 0xa0e128b0:
        return 0;
    case 0xa0e13f10:
        return 1;
    case 0xa0e1a400:
        return 0;
    case 0xa0b9c250:
        return 0;
    case 0xa0e1ab20:
        return 1;
    case 0xa0b9c2b0:
        return 0;
    case 0xa0ba0930:
        return 1;
    case 0xa0b9c9d0:
        return 1;
    case 0xa0e218c0:
        return 0;
    case 0xa0b98820:
        return 1;
    case 0xa0e21fe0:
        return 1;
    }
}

static
int get_class(int state)
{
    switch (state) {
    case 0xa0ba76b0:
        return t_lpar;
    case 0xa0ba9750:
        return t_rpar;
    case 0xa0ba2450:
        return t_any;
    case 0xa0ba3de0:
        return t_terminator;
    case 0xa0ba5950:
        return t_disjunction;
    case 0xa0baba00:
        return t_symbol;
    case 0xa0b9e1d0:
        return t_kleenestar;
    case 0xa0b9f400:
        return t_kleeneplus;
    case 0xa0e13f10:
        return t_literal;
    case 0xa0e1ab20:
        return t_class;
    case 0xa0ba0930:
        return t_rightarrow;
    case 0xa0b9c9d0:
        return t_gobble__linecomment;
    case 0xa0b98820:
        return t_gobble__blank;
    case 0xa0e21fe0:
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
