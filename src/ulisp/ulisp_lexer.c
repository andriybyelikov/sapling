/* This file was automatically generated. */

#include <stdio.h>
#include <libsapling/idiom.h>
#include "ulisp/terminals.h"
#include "internal_lexer.h"

static
int get_initial_state(void)
{
    return 0xa511a840;
}

static
int next_state(int current_state, char input)
{
    switch (current_state) {
    case 0xa511a840:
        switch (input) {
        case '\t':
            return 0xa511a870;
        case '\n':
            return 0xa511a870;
        case '\r':
            return 0xa511a870;
        case ' ':
            return 0xa511a870;
        case '\"':
            return 0xa5386820;
        case '(':
            return 0xa5120090;
        case ')':
            return 0xa5121230;
        case '-':
            return 0xa511e200;
        case '0':
            return 0xa538d3f0;
        case '1':
            return 0xa538d3f0;
        case '2':
            return 0xa538d3f0;
        case '3':
            return 0xa538d3f0;
        case '4':
            return 0xa538d3f0;
        case '5':
            return 0xa538d3f0;
        case '6':
            return 0xa538d3f0;
        case '7':
            return 0xa538d3f0;
        case '8':
            return 0xa538d3f0;
        case '9':
            return 0xa538d3f0;
        case 'a':
            return 0xa5122640;
        case 'b':
            return 0xa5122640;
        case 'c':
            return 0xa5122640;
        case 'd':
            return 0xa5122640;
        case 'e':
            return 0xa5122640;
        case 'f':
            return 0xa5122640;
        case 'g':
            return 0xa5122640;
        case 'h':
            return 0xa5122640;
        case 'i':
            return 0xa5122640;
        case 'j':
            return 0xa5122640;
        case 'k':
            return 0xa5122640;
        case 'l':
            return 0xa5122640;
        case 'm':
            return 0xa5122640;
        case 'n':
            return 0xa5122640;
        case 'o':
            return 0xa5122640;
        case 'p':
            return 0xa5122640;
        case 'q':
            return 0xa5122640;
        case 'r':
            return 0xa5122640;
        case 's':
            return 0xa5122640;
        case 't':
            return 0xa5122640;
        case 'u':
            return 0xa5122640;
        case 'v':
            return 0xa5122640;
        case 'w':
            return 0xa5122640;
        case 'x':
            return 0xa5122640;
        case 'y':
            return 0xa5122640;
        case 'z':
            return 0xa5122640;
        default:
            return -1;
        }
        break;
    case 0xa5120090:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0xa5121230:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0xa5122640:
        switch (input) {
        case '0':
            return 0xa5122640;
        case '1':
            return 0xa5122640;
        case '2':
            return 0xa5122640;
        case '3':
            return 0xa5122640;
        case '4':
            return 0xa5122640;
        case '5':
            return 0xa5122640;
        case '6':
            return 0xa5122640;
        case '7':
            return 0xa5122640;
        case '8':
            return 0xa5122640;
        case '9':
            return 0xa5122640;
        case '_':
            return 0xa5122640;
        case 'a':
            return 0xa5122640;
        case 'b':
            return 0xa5122640;
        case 'c':
            return 0xa5122640;
        case 'd':
            return 0xa5122640;
        case 'e':
            return 0xa5122640;
        case 'f':
            return 0xa5122640;
        case 'g':
            return 0xa5122640;
        case 'h':
            return 0xa5122640;
        case 'i':
            return 0xa5122640;
        case 'j':
            return 0xa5122640;
        case 'k':
            return 0xa5122640;
        case 'l':
            return 0xa5122640;
        case 'm':
            return 0xa5122640;
        case 'n':
            return 0xa5122640;
        case 'o':
            return 0xa5122640;
        case 'p':
            return 0xa5122640;
        case 'q':
            return 0xa5122640;
        case 'r':
            return 0xa5122640;
        case 's':
            return 0xa5122640;
        case 't':
            return 0xa5122640;
        case 'u':
            return 0xa5122640;
        case 'v':
            return 0xa5122640;
        case 'w':
            return 0xa5122640;
        case 'x':
            return 0xa5122640;
        case 'y':
            return 0xa5122640;
        case 'z':
            return 0xa5122640;
        default:
            return -1;
        }
        break;
    case 0xa5386820:
        switch (input) {
        case '\"':
            return 0xa53883d0;
        case '\\':
            return 0xa5386df0;
        default:
            return 0xa5386820;
        }
        break;
    case 0xa511e200:
        switch (input) {
        case '-':
            return 0xa511e260;
        default:
            return -1;
        }
        break;
    case 0xa5386df0:
        switch (input) {
        default:
            return 0xa5386820;
        }
        break;
    case 0xa53883d0:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0xa511e260:
        switch (input) {
        case '\n':
            return 0xa511e920;
        default:
            return 0xa511e260;
        }
        break;
    case 0xa511e920:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0xa538d3f0:
        switch (input) {
        case '0':
            return 0xa538d3f0;
        case '1':
            return 0xa538d3f0;
        case '2':
            return 0xa538d3f0;
        case '3':
            return 0xa538d3f0;
        case '4':
            return 0xa538d3f0;
        case '5':
            return 0xa538d3f0;
        case '6':
            return 0xa538d3f0;
        case '7':
            return 0xa538d3f0;
        case '8':
            return 0xa538d3f0;
        case '9':
            return 0xa538d3f0;
        case 'x':
            return 0xa53af690;
        default:
            return -1;
        }
        break;
    case 0xa511a870:
        switch (input) {
        case '\t':
            return 0xa511a870;
        case '\n':
            return 0xa511a870;
        case '\r':
            return 0xa511a870;
        case ' ':
            return 0xa511a870;
        default:
            return -1;
        }
        break;
    case 0xa53af690:
        switch (input) {
        case '0':
            return 0xa53af690;
        case '1':
            return 0xa53af870;
        case '2':
            return 0xa53af870;
        case '3':
            return 0xa53af870;
        case '4':
            return 0xa53af870;
        case '5':
            return 0xa53af870;
        case '6':
            return 0xa53af870;
        case '7':
            return 0xa53af870;
        case '8':
            return 0xa53af870;
        case '9':
            return 0xa53af870;
        case 'A':
            return 0xa53af870;
        case 'B':
            return 0xa53af870;
        case 'C':
            return 0xa53af870;
        case 'D':
            return 0xa53af870;
        case 'E':
            return 0xa53af870;
        case 'F':
            return 0xa53af870;
        case 'a':
            return 0xa53af870;
        case 'b':
            return 0xa53af870;
        case 'c':
            return 0xa53af870;
        case 'd':
            return 0xa53af870;
        case 'e':
            return 0xa53af870;
        case 'f':
            return 0xa53af870;
        default:
            return -1;
        }
        break;
    case 0xa53af870:
        switch (input) {
        case '0':
            return 0xa53af870;
        case '1':
            return 0xa53af870;
        case '2':
            return 0xa53af870;
        case '3':
            return 0xa53af870;
        case '4':
            return 0xa53af870;
        case '5':
            return 0xa53af870;
        case '6':
            return 0xa53af870;
        case '7':
            return 0xa53af870;
        case '8':
            return 0xa53af870;
        case '9':
            return 0xa53af870;
        case 'A':
            return 0xa53af870;
        case 'B':
            return 0xa53af870;
        case 'C':
            return 0xa53af870;
        case 'D':
            return 0xa53af870;
        case 'E':
            return 0xa53af870;
        case 'F':
            return 0xa53af870;
        case 'a':
            return 0xa53af870;
        case 'b':
            return 0xa53af870;
        case 'c':
            return 0xa53af870;
        case 'd':
            return 0xa53af870;
        case 'e':
            return 0xa53af870;
        case 'f':
            return 0xa53af870;
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
    case 0xa511a840:
        return 0;
    case 0xa5120090:
        return 1;
    case 0xa5121230:
        return 1;
    case 0xa5122640:
        return 1;
    case 0xa5386820:
        return 0;
    case 0xa511e200:
        return 0;
    case 0xa5386df0:
        return 0;
    case 0xa53883d0:
        return 1;
    case 0xa511e260:
        return 0;
    case 0xa511e920:
        return 1;
    case 0xa538d3f0:
        return 1;
    case 0xa511a870:
        return 1;
    case 0xa53af690:
        return 0;
    case 0xa53af870:
        return 1;
    }
}

static
int get_class(int state)
{
    switch (state) {
    case 0xa5120090:
        return t_lpar;
    case 0xa5121230:
        return t_rpar;
    case 0xa5122640:
        return t_symbol;
    case 0xa53883d0:
        return t_string;
    case 0xa511e920:
        return t_gobble__linecomment;
    case 0xa538d3f0:
        return t_integer;
    case 0xa511a870:
        return t_gobble__blank;
    case 0xa53af870:
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
