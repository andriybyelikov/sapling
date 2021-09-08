/* This file was automatically generated. */

#include <stdio.h>
#include <libsapling/idiom.h>
#include "composition/terminals.h"
#include "internal_lexer.h"

static
int get_initial_state(void)
{
    return 0xcb397810;
}

static
int next_state(int current_state, char input)
{
    switch (current_state) {
    case 0xcb397810:
        switch (input) {
        case '\t':
            return 0xcb397840;
        case '\n':
            return 0xcb397840;
        case '\r':
            return 0xcb397840;
        case ' ':
            return 0xcb397840;
        case '-':
            return 0xcb39b1d0;
        case '.':
            return 0xcb39d050;
        case '/':
            return 0xcb39d050;
        case '0':
            return 0xcb39d050;
        case '1':
            return 0xcb39d050;
        case '2':
            return 0xcb39d050;
        case '3':
            return 0xcb39d050;
        case '4':
            return 0xcb39d050;
        case '5':
            return 0xcb39d050;
        case '6':
            return 0xcb39d050;
        case '7':
            return 0xcb39d050;
        case '8':
            return 0xcb39d050;
        case '9':
            return 0xcb39d050;
        case '<':
            return 0xcbd8b1e0;
        case 'A':
            return 0xcb39d050;
        case 'B':
            return 0xcb39d050;
        case 'C':
            return 0xcb39d050;
        case 'D':
            return 0xcb39d050;
        case 'E':
            return 0xcb39d050;
        case 'F':
            return 0xcb39d050;
        case 'G':
            return 0xcb39d050;
        case 'H':
            return 0xcb39d050;
        case 'I':
            return 0xcb39d050;
        case 'J':
            return 0xcb39d050;
        case 'K':
            return 0xcb39d050;
        case 'L':
            return 0xcb39d050;
        case 'M':
            return 0xcb39d050;
        case 'N':
            return 0xcb39d050;
        case 'O':
            return 0xcb39d050;
        case 'P':
            return 0xcb39d050;
        case 'Q':
            return 0xcb39d050;
        case 'R':
            return 0xcb39d050;
        case 'S':
            return 0xcb39d050;
        case 'T':
            return 0xcb39d050;
        case 'U':
            return 0xcb39d050;
        case 'V':
            return 0xcb39d050;
        case 'W':
            return 0xcb39d050;
        case 'X':
            return 0xcb39d050;
        case 'Y':
            return 0xcb39d050;
        case 'Z':
            return 0xcb39d050;
        case '\\':
            return 0xcb39d050;
        case ']':
            return 0xcb39d050;
        case '^':
            return 0xcb39d050;
        case '_':
            return 0xcb39d050;
        case 'a':
            return 0xcb39d050;
        case 'b':
            return 0xcb39d050;
        case 'c':
            return 0xcb39d050;
        case 'd':
            return 0xcb39d050;
        case 'e':
            return 0xcb39d050;
        case 'f':
            return 0xcb39d050;
        case 'g':
            return 0xcb39d050;
        case 'h':
            return 0xcb39d050;
        case 'i':
            return 0xcb39d050;
        case 'j':
            return 0xcb39d050;
        case 'k':
            return 0xcb39d050;
        case 'l':
            return 0xcb39d050;
        case 'm':
            return 0xcb39d050;
        case 'n':
            return 0xcb39d050;
        case 'o':
            return 0xcb39d050;
        case 'p':
            return 0xcb39d050;
        case 'q':
            return 0xcb39d050;
        case 'r':
            return 0xcb39d050;
        case 's':
            return 0xcb39d050;
        case 't':
            return 0xcb39d050;
        case 'u':
            return 0xcb39d050;
        case 'v':
            return 0xcb39d050;
        case 'w':
            return 0xcb39d050;
        case 'x':
            return 0xcb39d050;
        case 'y':
            return 0xcb39d050;
        case 'z':
            return 0xcb39d050;
        default:
            return -1;
        }
        break;
    case 0xcb39b1d0:
        switch (input) {
        case '-':
            return 0xcb39b230;
        default:
            return -1;
        }
        break;
    case 0xcb39d050:
        switch (input) {
        case '.':
            return 0xcb39d050;
        case '/':
            return 0xcb39d050;
        case '0':
            return 0xcb39d050;
        case '1':
            return 0xcb39d050;
        case '2':
            return 0xcb39d050;
        case '3':
            return 0xcb39d050;
        case '4':
            return 0xcb39d050;
        case '5':
            return 0xcb39d050;
        case '6':
            return 0xcb39d050;
        case '7':
            return 0xcb39d050;
        case '8':
            return 0xcb39d050;
        case '9':
            return 0xcb39d050;
        case 'A':
            return 0xcb39d050;
        case 'B':
            return 0xcb39d050;
        case 'C':
            return 0xcb39d050;
        case 'D':
            return 0xcb39d050;
        case 'E':
            return 0xcb39d050;
        case 'F':
            return 0xcb39d050;
        case 'G':
            return 0xcb39d050;
        case 'H':
            return 0xcb39d050;
        case 'I':
            return 0xcb39d050;
        case 'J':
            return 0xcb39d050;
        case 'K':
            return 0xcb39d050;
        case 'L':
            return 0xcb39d050;
        case 'M':
            return 0xcb39d050;
        case 'N':
            return 0xcb39d050;
        case 'O':
            return 0xcb39d050;
        case 'P':
            return 0xcb39d050;
        case 'Q':
            return 0xcb39d050;
        case 'R':
            return 0xcb39d050;
        case 'S':
            return 0xcb39d050;
        case 'T':
            return 0xcb39d050;
        case 'U':
            return 0xcb39d050;
        case 'V':
            return 0xcb39d050;
        case 'W':
            return 0xcb39d050;
        case 'X':
            return 0xcb39d050;
        case 'Y':
            return 0xcb39d050;
        case 'Z':
            return 0xcb39d050;
        case '\\':
            return 0xcb39d050;
        case ']':
            return 0xcb39d050;
        case '^':
            return 0xcb39d050;
        case '_':
            return 0xcb39d050;
        case 'a':
            return 0xcb39d050;
        case 'b':
            return 0xcb39d050;
        case 'c':
            return 0xcb39d050;
        case 'd':
            return 0xcb39d050;
        case 'e':
            return 0xcb39d050;
        case 'f':
            return 0xcb39d050;
        case 'g':
            return 0xcb39d050;
        case 'h':
            return 0xcb39d050;
        case 'i':
            return 0xcb39d050;
        case 'j':
            return 0xcb39d050;
        case 'k':
            return 0xcb39d050;
        case 'l':
            return 0xcb39d050;
        case 'm':
            return 0xcb39d050;
        case 'n':
            return 0xcb39d050;
        case 'o':
            return 0xcb39d050;
        case 'p':
            return 0xcb39d050;
        case 'q':
            return 0xcb39d050;
        case 'r':
            return 0xcb39d050;
        case 's':
            return 0xcb39d050;
        case 't':
            return 0xcb39d050;
        case 'u':
            return 0xcb39d050;
        case 'v':
            return 0xcb39d050;
        case 'w':
            return 0xcb39d050;
        case 'x':
            return 0xcb39d050;
        case 'y':
            return 0xcb39d050;
        case 'z':
            return 0xcb39d050;
        default:
            return -1;
        }
        break;
    case 0xcb39b230:
        switch (input) {
        case '\n':
            return 0xcb39b8f0;
        default:
            return 0xcb39b230;
        }
        break;
    case 0xcb39b8f0:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0xcbd8b1e0:
        switch (input) {
        case '>':
            return 0xcbd8b8a0;
        default:
            return 0xcbd8b1e0;
        }
        break;
    case 0xcb397840:
        switch (input) {
        case '\t':
            return 0xcb397840;
        case '\n':
            return 0xcb397840;
        case '\r':
            return 0xcb397840;
        case ' ':
            return 0xcb397840;
        default:
            return -1;
        }
        break;
    case 0xcbd8b8a0:
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
    case 0xcb397810:
        return 0;
    case 0xcb39b1d0:
        return 0;
    case 0xcb39d050:
        return 1;
    case 0xcb39b230:
        return 0;
    case 0xcb39b8f0:
        return 1;
    case 0xcbd8b1e0:
        return 0;
    case 0xcb397840:
        return 1;
    case 0xcbd8b8a0:
        return 1;
    }
}

static
int get_class(int state)
{
    switch (state) {
    case 0xcb39d050:
        return t_symbol;
    case 0xcb39b8f0:
        return t_gobble__linecomment;
    case 0xcb397840:
        return t_gobble__blank;
    case 0xcbd8b8a0:
        return t_frag_code;
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

void composition__lexer_actions(terminal_t terminal, UNUSED void *user_ptr);

static
internal_lexer_t composition_lexer = NULL;

internal_lexer_t get_composition_lexer(void)
{
    if (composition_lexer == NULL) {
        composition_lexer = new_internal_lexer(get_initial_state, next_state,
            is_accepting_state, get_class, class_has_gobble_modifier,
            get_eof_class, composition__lexer_actions);
    }
    return composition_lexer;
}
