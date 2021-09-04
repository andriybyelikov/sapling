/* This file was automatically generated. */

#include <stdio.h>
#include <libsapling/idiom.h>
#include "composition/terminals.h"
#include "internal_lexer.h"

static
int get_initial_state(void)
{
    return 0xaa6af810;
}

static
int next_state(int current_state, char input)
{
    switch (current_state) {
    case 0xaa6af810:
        switch (input) {
        case '\t':
            return 0xaa6af840;
        case '\n':
            return 0xaa6af840;
        case '\r':
            return 0xaa6af840;
        case ' ':
            return 0xaa6af840;
        case '.':
            return 0xaa6b31a0;
        case '/':
            return 0xaa6b31a0;
        case '0':
            return 0xaa6b31a0;
        case '1':
            return 0xaa6b31a0;
        case '2':
            return 0xaa6b31a0;
        case '3':
            return 0xaa6b31a0;
        case '4':
            return 0xaa6b31a0;
        case '5':
            return 0xaa6b31a0;
        case '6':
            return 0xaa6b31a0;
        case '7':
            return 0xaa6b31a0;
        case '8':
            return 0xaa6b31a0;
        case '9':
            return 0xaa6b31a0;
        case '<':
            return 0xab09def0;
        case 'A':
            return 0xaa6b31a0;
        case 'B':
            return 0xaa6b31a0;
        case 'C':
            return 0xaa6b31a0;
        case 'D':
            return 0xaa6b31a0;
        case 'E':
            return 0xaa6b31a0;
        case 'F':
            return 0xaa6b31a0;
        case 'G':
            return 0xaa6b31a0;
        case 'H':
            return 0xaa6b31a0;
        case 'I':
            return 0xaa6b31a0;
        case 'J':
            return 0xaa6b31a0;
        case 'K':
            return 0xaa6b31a0;
        case 'L':
            return 0xaa6b31a0;
        case 'M':
            return 0xaa6b31a0;
        case 'N':
            return 0xaa6b31a0;
        case 'O':
            return 0xaa6b31a0;
        case 'P':
            return 0xaa6b31a0;
        case 'Q':
            return 0xaa6b31a0;
        case 'R':
            return 0xaa6b31a0;
        case 'S':
            return 0xaa6b31a0;
        case 'T':
            return 0xaa6b31a0;
        case 'U':
            return 0xaa6b31a0;
        case 'V':
            return 0xaa6b31a0;
        case 'W':
            return 0xaa6b31a0;
        case 'X':
            return 0xaa6b31a0;
        case 'Y':
            return 0xaa6b31a0;
        case 'Z':
            return 0xaa6b31a0;
        case '\\':
            return 0xaa6b31a0;
        case ']':
            return 0xaa6b31a0;
        case '^':
            return 0xaa6b31a0;
        case '_':
            return 0xaa6b31a0;
        case 'a':
            return 0xaa6b31a0;
        case 'b':
            return 0xaa6b31a0;
        case 'c':
            return 0xaa6b31a0;
        case 'd':
            return 0xaa6b31a0;
        case 'e':
            return 0xaa6b31a0;
        case 'f':
            return 0xaa6b31a0;
        case 'g':
            return 0xaa6b31a0;
        case 'h':
            return 0xaa6b31a0;
        case 'i':
            return 0xaa6b31a0;
        case 'j':
            return 0xaa6b31a0;
        case 'k':
            return 0xaa6b31a0;
        case 'l':
            return 0xaa6b31a0;
        case 'm':
            return 0xaa6b31a0;
        case 'n':
            return 0xaa6b31a0;
        case 'o':
            return 0xaa6b31a0;
        case 'p':
            return 0xaa6b31a0;
        case 'q':
            return 0xaa6b31a0;
        case 'r':
            return 0xaa6b31a0;
        case 's':
            return 0xaa6b31a0;
        case 't':
            return 0xaa6b31a0;
        case 'u':
            return 0xaa6b31a0;
        case 'v':
            return 0xaa6b31a0;
        case 'w':
            return 0xaa6b31a0;
        case 'x':
            return 0xaa6b31a0;
        case 'y':
            return 0xaa6b31a0;
        case 'z':
            return 0xaa6b31a0;
        default:
            return -1;
        }
        break;
    case 0xaa6b31a0:
        switch (input) {
        case '.':
            return 0xaa6b31a0;
        case '/':
            return 0xaa6b31a0;
        case '0':
            return 0xaa6b31a0;
        case '1':
            return 0xaa6b31a0;
        case '2':
            return 0xaa6b31a0;
        case '3':
            return 0xaa6b31a0;
        case '4':
            return 0xaa6b31a0;
        case '5':
            return 0xaa6b31a0;
        case '6':
            return 0xaa6b31a0;
        case '7':
            return 0xaa6b31a0;
        case '8':
            return 0xaa6b31a0;
        case '9':
            return 0xaa6b31a0;
        case 'A':
            return 0xaa6b31a0;
        case 'B':
            return 0xaa6b31a0;
        case 'C':
            return 0xaa6b31a0;
        case 'D':
            return 0xaa6b31a0;
        case 'E':
            return 0xaa6b31a0;
        case 'F':
            return 0xaa6b31a0;
        case 'G':
            return 0xaa6b31a0;
        case 'H':
            return 0xaa6b31a0;
        case 'I':
            return 0xaa6b31a0;
        case 'J':
            return 0xaa6b31a0;
        case 'K':
            return 0xaa6b31a0;
        case 'L':
            return 0xaa6b31a0;
        case 'M':
            return 0xaa6b31a0;
        case 'N':
            return 0xaa6b31a0;
        case 'O':
            return 0xaa6b31a0;
        case 'P':
            return 0xaa6b31a0;
        case 'Q':
            return 0xaa6b31a0;
        case 'R':
            return 0xaa6b31a0;
        case 'S':
            return 0xaa6b31a0;
        case 'T':
            return 0xaa6b31a0;
        case 'U':
            return 0xaa6b31a0;
        case 'V':
            return 0xaa6b31a0;
        case 'W':
            return 0xaa6b31a0;
        case 'X':
            return 0xaa6b31a0;
        case 'Y':
            return 0xaa6b31a0;
        case 'Z':
            return 0xaa6b31a0;
        case '\\':
            return 0xaa6b31a0;
        case ']':
            return 0xaa6b31a0;
        case '^':
            return 0xaa6b31a0;
        case '_':
            return 0xaa6b31a0;
        case 'a':
            return 0xaa6b31a0;
        case 'b':
            return 0xaa6b31a0;
        case 'c':
            return 0xaa6b31a0;
        case 'd':
            return 0xaa6b31a0;
        case 'e':
            return 0xaa6b31a0;
        case 'f':
            return 0xaa6b31a0;
        case 'g':
            return 0xaa6b31a0;
        case 'h':
            return 0xaa6b31a0;
        case 'i':
            return 0xaa6b31a0;
        case 'j':
            return 0xaa6b31a0;
        case 'k':
            return 0xaa6b31a0;
        case 'l':
            return 0xaa6b31a0;
        case 'm':
            return 0xaa6b31a0;
        case 'n':
            return 0xaa6b31a0;
        case 'o':
            return 0xaa6b31a0;
        case 'p':
            return 0xaa6b31a0;
        case 'q':
            return 0xaa6b31a0;
        case 'r':
            return 0xaa6b31a0;
        case 's':
            return 0xaa6b31a0;
        case 't':
            return 0xaa6b31a0;
        case 'u':
            return 0xaa6b31a0;
        case 'v':
            return 0xaa6b31a0;
        case 'w':
            return 0xaa6b31a0;
        case 'x':
            return 0xaa6b31a0;
        case 'y':
            return 0xaa6b31a0;
        case 'z':
            return 0xaa6b31a0;
        default:
            return -1;
        }
        break;
    case 0xab09def0:
        switch (input) {
        case '>':
            return 0xab09e5b0;
        default:
            return 0xab09def0;
        }
        break;
    case 0xaa6af840:
        switch (input) {
        case '\t':
            return 0xaa6af840;
        case '\n':
            return 0xaa6af840;
        case '\r':
            return 0xaa6af840;
        case ' ':
            return 0xaa6af840;
        default:
            return -1;
        }
        break;
    case 0xab09e5b0:
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
    case 0xaa6af810:
        return 0;
    case 0xaa6b31a0:
        return 1;
    case 0xab09def0:
        return 0;
    case 0xaa6af840:
        return 1;
    case 0xab09e5b0:
        return 1;
    }
}

static
int get_class(int state)
{
    switch (state) {
    case 0xaa6b31a0:
        return t_symbol;
    case 0xaa6af840:
        return t_gobble__blank;
    case 0xab09e5b0:
        return t_frag_code;
    }
}

static
int class_has_gobble_modifier(int class)
{
    switch (class) {
    case t_gobble__blank:
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
