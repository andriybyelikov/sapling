/* This file was automatically generated. */

#include <stdio.h>
#include <libsapling/idiom.h>
#include "ulisp/terminals.h"
#include "internal_lexer.h"

static
int get_initial_state(void)
{
    return 0x27566840;
}

static
int next_state(int current_state, char input)
{
    switch (current_state) {
    case 0x27566840:
        switch (input) {
        case '\t':
            return 0x27566870;
        case '\n':
            return 0x27566870;
        case '\r':
            return 0x27566870;
        case ' ':
            return 0x27566870;
        case '\"':
            return 0x277d2820;
        case '(':
            return 0x2756c090;
        case ')':
            return 0x2756d230;
        case '-':
            return 0x2756a200;
        case '0':
            return 0x277d93f0;
        case '1':
            return 0x277d93f0;
        case '2':
            return 0x277d93f0;
        case '3':
            return 0x277d93f0;
        case '4':
            return 0x277d93f0;
        case '5':
            return 0x277d93f0;
        case '6':
            return 0x277d93f0;
        case '7':
            return 0x277d93f0;
        case '8':
            return 0x277d93f0;
        case '9':
            return 0x277d93f0;
        case 'a':
            return 0x2756e640;
        case 'b':
            return 0x2756e640;
        case 'c':
            return 0x2756e640;
        case 'd':
            return 0x2756e640;
        case 'e':
            return 0x2756e640;
        case 'f':
            return 0x2756e640;
        case 'g':
            return 0x2756e640;
        case 'h':
            return 0x2756e640;
        case 'i':
            return 0x2756e640;
        case 'j':
            return 0x2756e640;
        case 'k':
            return 0x2756e640;
        case 'l':
            return 0x2756e640;
        case 'm':
            return 0x2756e640;
        case 'n':
            return 0x2756e640;
        case 'o':
            return 0x2756e640;
        case 'p':
            return 0x2756e640;
        case 'q':
            return 0x2756e640;
        case 'r':
            return 0x2756e640;
        case 's':
            return 0x2756e640;
        case 't':
            return 0x2756e640;
        case 'u':
            return 0x2756e640;
        case 'v':
            return 0x2756e640;
        case 'w':
            return 0x2756e640;
        case 'x':
            return 0x2756e640;
        case 'y':
            return 0x2756e640;
        case 'z':
            return 0x2756e640;
        default:
            return -1;
        }
        break;
    case 0x2756c090:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0x2756d230:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0x2756e640:
        switch (input) {
        case '0':
            return 0x2756e640;
        case '1':
            return 0x2756e640;
        case '2':
            return 0x2756e640;
        case '3':
            return 0x2756e640;
        case '4':
            return 0x2756e640;
        case '5':
            return 0x2756e640;
        case '6':
            return 0x2756e640;
        case '7':
            return 0x2756e640;
        case '8':
            return 0x2756e640;
        case '9':
            return 0x2756e640;
        case '_':
            return 0x2756e640;
        case 'a':
            return 0x2756e640;
        case 'b':
            return 0x2756e640;
        case 'c':
            return 0x2756e640;
        case 'd':
            return 0x2756e640;
        case 'e':
            return 0x2756e640;
        case 'f':
            return 0x2756e640;
        case 'g':
            return 0x2756e640;
        case 'h':
            return 0x2756e640;
        case 'i':
            return 0x2756e640;
        case 'j':
            return 0x2756e640;
        case 'k':
            return 0x2756e640;
        case 'l':
            return 0x2756e640;
        case 'm':
            return 0x2756e640;
        case 'n':
            return 0x2756e640;
        case 'o':
            return 0x2756e640;
        case 'p':
            return 0x2756e640;
        case 'q':
            return 0x2756e640;
        case 'r':
            return 0x2756e640;
        case 's':
            return 0x2756e640;
        case 't':
            return 0x2756e640;
        case 'u':
            return 0x2756e640;
        case 'v':
            return 0x2756e640;
        case 'w':
            return 0x2756e640;
        case 'x':
            return 0x2756e640;
        case 'y':
            return 0x2756e640;
        case 'z':
            return 0x2756e640;
        default:
            return -1;
        }
        break;
    case 0x277d2820:
        switch (input) {
        case '\"':
            return 0x277d43d0;
        case '\\':
            return 0x277d2df0;
        default:
            return 0x277d2820;
        }
        break;
    case 0x2756a200:
        switch (input) {
        case '-':
            return 0x2756a260;
        default:
            return -1;
        }
        break;
    case 0x277d2df0:
        switch (input) {
        default:
            return 0x277d2820;
        }
        break;
    case 0x277d43d0:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0x2756a260:
        switch (input) {
        case '\n':
            return 0x2756a920;
        default:
            return 0x2756a260;
        }
        break;
    case 0x2756a920:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0x277d93f0:
        switch (input) {
        case '0':
            return 0x277d93f0;
        case '1':
            return 0x277d93f0;
        case '2':
            return 0x277d93f0;
        case '3':
            return 0x277d93f0;
        case '4':
            return 0x277d93f0;
        case '5':
            return 0x277d93f0;
        case '6':
            return 0x277d93f0;
        case '7':
            return 0x277d93f0;
        case '8':
            return 0x277d93f0;
        case '9':
            return 0x277d93f0;
        case 'x':
            return 0x277fb690;
        default:
            return -1;
        }
        break;
    case 0x27566870:
        switch (input) {
        case '\t':
            return 0x27566870;
        case '\n':
            return 0x27566870;
        case '\r':
            return 0x27566870;
        case ' ':
            return 0x27566870;
        default:
            return -1;
        }
        break;
    case 0x277fb690:
        switch (input) {
        case '0':
            return 0x277fb690;
        case '1':
            return 0x277fb870;
        case '2':
            return 0x277fb870;
        case '3':
            return 0x277fb870;
        case '4':
            return 0x277fb870;
        case '5':
            return 0x277fb870;
        case '6':
            return 0x277fb870;
        case '7':
            return 0x277fb870;
        case '8':
            return 0x277fb870;
        case '9':
            return 0x277fb870;
        case 'A':
            return 0x277fb870;
        case 'B':
            return 0x277fb870;
        case 'C':
            return 0x277fb870;
        case 'D':
            return 0x277fb870;
        case 'E':
            return 0x277fb870;
        case 'F':
            return 0x277fb870;
        case 'a':
            return 0x277fb870;
        case 'b':
            return 0x277fb870;
        case 'c':
            return 0x277fb870;
        case 'd':
            return 0x277fb870;
        case 'e':
            return 0x277fb870;
        case 'f':
            return 0x277fb870;
        default:
            return -1;
        }
        break;
    case 0x277fb870:
        switch (input) {
        case '0':
            return 0x277fb870;
        case '1':
            return 0x277fb870;
        case '2':
            return 0x277fb870;
        case '3':
            return 0x277fb870;
        case '4':
            return 0x277fb870;
        case '5':
            return 0x277fb870;
        case '6':
            return 0x277fb870;
        case '7':
            return 0x277fb870;
        case '8':
            return 0x277fb870;
        case '9':
            return 0x277fb870;
        case 'A':
            return 0x277fb870;
        case 'B':
            return 0x277fb870;
        case 'C':
            return 0x277fb870;
        case 'D':
            return 0x277fb870;
        case 'E':
            return 0x277fb870;
        case 'F':
            return 0x277fb870;
        case 'a':
            return 0x277fb870;
        case 'b':
            return 0x277fb870;
        case 'c':
            return 0x277fb870;
        case 'd':
            return 0x277fb870;
        case 'e':
            return 0x277fb870;
        case 'f':
            return 0x277fb870;
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
    case 0x27566840:
        return 0;
    case 0x2756c090:
        return 1;
    case 0x2756d230:
        return 1;
    case 0x2756e640:
        return 1;
    case 0x277d2820:
        return 0;
    case 0x2756a200:
        return 0;
    case 0x277d2df0:
        return 0;
    case 0x277d43d0:
        return 1;
    case 0x2756a260:
        return 0;
    case 0x2756a920:
        return 1;
    case 0x277d93f0:
        return 1;
    case 0x27566870:
        return 1;
    case 0x277fb690:
        return 0;
    case 0x277fb870:
        return 1;
    }
}

static
int get_class(int state)
{
    switch (state) {
    case 0x2756c090:
        return t_lpar;
    case 0x2756d230:
        return t_rpar;
    case 0x2756e640:
        return t_symbol;
    case 0x277d43d0:
        return t_string;
    case 0x2756a920:
        return t_gobble__linecomment;
    case 0x277d93f0:
        return t_integer;
    case 0x27566870:
        return t_gobble__blank;
    case 0x277fb870:
        return t_hexadecimal;
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

void ulisp__lexer_actions(terminal_t terminal, UNUSED void *user_ptr);

static
internal_lexer_t ulisp_lexer = NULL;

internal_lexer_t get_ulisp_lexer(void)
{
    if (ulisp_lexer == NULL) {
        ulisp_lexer = new_internal_lexer(get_initial_state, next_state,
            is_accepting_state, get_class, class_has_gobble_modifier,
            get_eof_class, ulisp__lexer_actions);
    }
    return ulisp_lexer;
}
