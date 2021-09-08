/* This file was automatically generated. */

#include <stdio.h>
#include <libsapling/idiom.h>
#include "ulisp/terminals.h"
#include "internal_lexer.h"

static
int get_initial_state(void)
{
    return 0x47f76810;
}

static
int next_state(int current_state, char input)
{
    switch (current_state) {
    case 0x47f76810:
        switch (input) {
        case '\t':
            return 0x47f76840;
        case '\n':
            return 0x47f76840;
        case '\r':
            return 0x47f76840;
        case ' ':
            return 0x47f76840;
        case '\"':
            return 0x481e27f0;
        case '(':
            return 0x47f7c060;
        case ')':
            return 0x47f7d200;
        case '-':
            return 0x47f7a1d0;
        case '0':
            return 0x481e93c0;
        case '1':
            return 0x481e93c0;
        case '2':
            return 0x481e93c0;
        case '3':
            return 0x481e93c0;
        case '4':
            return 0x481e93c0;
        case '5':
            return 0x481e93c0;
        case '6':
            return 0x481e93c0;
        case '7':
            return 0x481e93c0;
        case '8':
            return 0x481e93c0;
        case '9':
            return 0x481e93c0;
        case 'a':
            return 0x47f7e610;
        case 'b':
            return 0x47f7e610;
        case 'c':
            return 0x47f7e610;
        case 'd':
            return 0x47f7e610;
        case 'e':
            return 0x47f7e610;
        case 'f':
            return 0x47f7e610;
        case 'g':
            return 0x47f7e610;
        case 'h':
            return 0x47f7e610;
        case 'i':
            return 0x47f7e610;
        case 'j':
            return 0x47f7e610;
        case 'k':
            return 0x47f7e610;
        case 'l':
            return 0x47f7e610;
        case 'm':
            return 0x47f7e610;
        case 'n':
            return 0x47f7e610;
        case 'o':
            return 0x47f7e610;
        case 'p':
            return 0x47f7e610;
        case 'q':
            return 0x47f7e610;
        case 'r':
            return 0x47f7e610;
        case 's':
            return 0x47f7e610;
        case 't':
            return 0x47f7e610;
        case 'u':
            return 0x47f7e610;
        case 'v':
            return 0x47f7e610;
        case 'w':
            return 0x47f7e610;
        case 'x':
            return 0x47f7e610;
        case 'y':
            return 0x47f7e610;
        case 'z':
            return 0x47f7e610;
        default:
            return -1;
        }
        break;
    case 0x47f7c060:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0x47f7d200:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0x47f7e610:
        switch (input) {
        case '0':
            return 0x47f7e610;
        case '1':
            return 0x47f7e610;
        case '2':
            return 0x47f7e610;
        case '3':
            return 0x47f7e610;
        case '4':
            return 0x47f7e610;
        case '5':
            return 0x47f7e610;
        case '6':
            return 0x47f7e610;
        case '7':
            return 0x47f7e610;
        case '8':
            return 0x47f7e610;
        case '9':
            return 0x47f7e610;
        case '_':
            return 0x47f7e610;
        case 'a':
            return 0x47f7e610;
        case 'b':
            return 0x47f7e610;
        case 'c':
            return 0x47f7e610;
        case 'd':
            return 0x47f7e610;
        case 'e':
            return 0x47f7e610;
        case 'f':
            return 0x47f7e610;
        case 'g':
            return 0x47f7e610;
        case 'h':
            return 0x47f7e610;
        case 'i':
            return 0x47f7e610;
        case 'j':
            return 0x47f7e610;
        case 'k':
            return 0x47f7e610;
        case 'l':
            return 0x47f7e610;
        case 'm':
            return 0x47f7e610;
        case 'n':
            return 0x47f7e610;
        case 'o':
            return 0x47f7e610;
        case 'p':
            return 0x47f7e610;
        case 'q':
            return 0x47f7e610;
        case 'r':
            return 0x47f7e610;
        case 's':
            return 0x47f7e610;
        case 't':
            return 0x47f7e610;
        case 'u':
            return 0x47f7e610;
        case 'v':
            return 0x47f7e610;
        case 'w':
            return 0x47f7e610;
        case 'x':
            return 0x47f7e610;
        case 'y':
            return 0x47f7e610;
        case 'z':
            return 0x47f7e610;
        default:
            return -1;
        }
        break;
    case 0x481e27f0:
        switch (input) {
        case '\"':
            return 0x481e43a0;
        case '\\':
            return 0x481e2dc0;
        default:
            return 0x481e27f0;
        }
        break;
    case 0x47f7a1d0:
        switch (input) {
        case '-':
            return 0x47f7a230;
        default:
            return -1;
        }
        break;
    case 0x481e2dc0:
        switch (input) {
        default:
            return 0x481e27f0;
        }
        break;
    case 0x481e43a0:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0x47f7a230:
        switch (input) {
        case '\n':
            return 0x47f7a8f0;
        default:
            return 0x47f7a230;
        }
        break;
    case 0x47f7a8f0:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0x481e93c0:
        switch (input) {
        case '0':
            return 0x481e93c0;
        case '1':
            return 0x481e93c0;
        case '2':
            return 0x481e93c0;
        case '3':
            return 0x481e93c0;
        case '4':
            return 0x481e93c0;
        case '5':
            return 0x481e93c0;
        case '6':
            return 0x481e93c0;
        case '7':
            return 0x481e93c0;
        case '8':
            return 0x481e93c0;
        case '9':
            return 0x481e93c0;
        case 'x':
            return 0x4820b660;
        default:
            return -1;
        }
        break;
    case 0x47f76840:
        switch (input) {
        case '\t':
            return 0x47f76840;
        case '\n':
            return 0x47f76840;
        case '\r':
            return 0x47f76840;
        case ' ':
            return 0x47f76840;
        default:
            return -1;
        }
        break;
    case 0x4820b660:
        switch (input) {
        case '0':
            return 0x4820b660;
        case '1':
            return 0x4820b840;
        case '2':
            return 0x4820b840;
        case '3':
            return 0x4820b840;
        case '4':
            return 0x4820b840;
        case '5':
            return 0x4820b840;
        case '6':
            return 0x4820b840;
        case '7':
            return 0x4820b840;
        case '8':
            return 0x4820b840;
        case '9':
            return 0x4820b840;
        case 'A':
            return 0x4820b840;
        case 'B':
            return 0x4820b840;
        case 'C':
            return 0x4820b840;
        case 'D':
            return 0x4820b840;
        case 'E':
            return 0x4820b840;
        case 'F':
            return 0x4820b840;
        case 'a':
            return 0x4820b840;
        case 'b':
            return 0x4820b840;
        case 'c':
            return 0x4820b840;
        case 'd':
            return 0x4820b840;
        case 'e':
            return 0x4820b840;
        case 'f':
            return 0x4820b840;
        default:
            return -1;
        }
        break;
    case 0x4820b840:
        switch (input) {
        case '0':
            return 0x4820b840;
        case '1':
            return 0x4820b840;
        case '2':
            return 0x4820b840;
        case '3':
            return 0x4820b840;
        case '4':
            return 0x4820b840;
        case '5':
            return 0x4820b840;
        case '6':
            return 0x4820b840;
        case '7':
            return 0x4820b840;
        case '8':
            return 0x4820b840;
        case '9':
            return 0x4820b840;
        case 'A':
            return 0x4820b840;
        case 'B':
            return 0x4820b840;
        case 'C':
            return 0x4820b840;
        case 'D':
            return 0x4820b840;
        case 'E':
            return 0x4820b840;
        case 'F':
            return 0x4820b840;
        case 'a':
            return 0x4820b840;
        case 'b':
            return 0x4820b840;
        case 'c':
            return 0x4820b840;
        case 'd':
            return 0x4820b840;
        case 'e':
            return 0x4820b840;
        case 'f':
            return 0x4820b840;
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
    case 0x47f76810:
        return 0;
    case 0x47f7c060:
        return 1;
    case 0x47f7d200:
        return 1;
    case 0x47f7e610:
        return 1;
    case 0x481e27f0:
        return 0;
    case 0x47f7a1d0:
        return 0;
    case 0x481e2dc0:
        return 0;
    case 0x481e43a0:
        return 1;
    case 0x47f7a230:
        return 0;
    case 0x47f7a8f0:
        return 1;
    case 0x481e93c0:
        return 1;
    case 0x47f76840:
        return 1;
    case 0x4820b660:
        return 0;
    case 0x4820b840:
        return 1;
    }
}

static
int get_class(int state)
{
    switch (state) {
    case 0x47f7c060:
        return t_lpar;
    case 0x47f7d200:
        return t_rpar;
    case 0x47f7e610:
        return t_symbol;
    case 0x481e43a0:
        return t_string;
    case 0x47f7a8f0:
        return t_gobble__linecomment;
    case 0x481e93c0:
        return t_integer;
    case 0x47f76840:
        return t_gobble__blank;
    case 0x4820b840:
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
