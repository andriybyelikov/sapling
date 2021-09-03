/* This file was automatically generated. */

#include <stdio.h>
#include <libsapling/idiom.h>
#include "composition/terminals.h"
#include "internal_lexer.h"

static
int get_initial_state(void)
{
    return 0x4e0607f0;
}

static
int next_state(int current_state, char input)
{
    switch (current_state) {
    case 0x4e0607f0:
        switch (input) {
        case '\t':
            return 0x4e060820;
        case '\n':
            return 0x4e060820;
        case '\r':
            return 0x4e060820;
        case ' ':
            return 0x4e060820;
        case '-':
            return 0x4e064220;
        case '.':
            return 0x4e064220;
        case '0':
            return 0x4e064220;
        case '1':
            return 0x4e064220;
        case '2':
            return 0x4e064220;
        case '3':
            return 0x4e064220;
        case '4':
            return 0x4e064220;
        case '5':
            return 0x4e064220;
        case '6':
            return 0x4e064220;
        case '7':
            return 0x4e064220;
        case '8':
            return 0x4e064220;
        case '9':
            return 0x4e064220;
        case '<':
            return 0x4e949c60;
        case 'A':
            return 0x4e064220;
        case 'B':
            return 0x4e064220;
        case 'C':
            return 0x4e064220;
        case 'D':
            return 0x4e064220;
        case 'E':
            return 0x4e064220;
        case 'F':
            return 0x4e064220;
        case 'G':
            return 0x4e064220;
        case 'H':
            return 0x4e064220;
        case 'I':
            return 0x4e064220;
        case 'J':
            return 0x4e064220;
        case 'K':
            return 0x4e064220;
        case 'L':
            return 0x4e064220;
        case 'M':
            return 0x4e064220;
        case 'N':
            return 0x4e064220;
        case 'O':
            return 0x4e064220;
        case 'P':
            return 0x4e064220;
        case 'Q':
            return 0x4e064220;
        case 'R':
            return 0x4e064220;
        case 'S':
            return 0x4e064220;
        case 'T':
            return 0x4e064220;
        case 'U':
            return 0x4e064220;
        case 'V':
            return 0x4e064220;
        case 'W':
            return 0x4e064220;
        case 'X':
            return 0x4e064220;
        case 'Y':
            return 0x4e064220;
        case 'Z':
            return 0x4e064220;
        case '_':
            return 0x4e064220;
        case 'a':
            return 0x4e064220;
        case 'b':
            return 0x4e064220;
        case 'c':
            return 0x4e064220;
        case 'd':
            return 0x4e064220;
        case 'e':
            return 0x4e064220;
        case 'f':
            return 0x4e064220;
        case 'g':
            return 0x4e064220;
        case 'h':
            return 0x4e064220;
        case 'i':
            return 0x4e064220;
        case 'j':
            return 0x4e064220;
        case 'k':
            return 0x4e064220;
        case 'l':
            return 0x4e064220;
        case 'm':
            return 0x4e064220;
        case 'n':
            return 0x4e064220;
        case 'o':
            return 0x4e064220;
        case 'p':
            return 0x4e064220;
        case 'q':
            return 0x4e064220;
        case 'r':
            return 0x4e064220;
        case 's':
            return 0x4e064220;
        case 't':
            return 0x4e064220;
        case 'u':
            return 0x4e064220;
        case 'v':
            return 0x4e064220;
        case 'w':
            return 0x4e064220;
        case 'x':
            return 0x4e064220;
        case 'y':
            return 0x4e064220;
        case 'z':
            return 0x4e064220;
        default:
            return -1;
        }
        break;
    case 0x4e064220:
        switch (input) {
        case '-':
            return 0x4e064220;
        case '.':
            return 0x4e064220;
        case '0':
            return 0x4e064220;
        case '1':
            return 0x4e064220;
        case '2':
            return 0x4e064220;
        case '3':
            return 0x4e064220;
        case '4':
            return 0x4e064220;
        case '5':
            return 0x4e064220;
        case '6':
            return 0x4e064220;
        case '7':
            return 0x4e064220;
        case '8':
            return 0x4e064220;
        case '9':
            return 0x4e064220;
        case 'A':
            return 0x4e064220;
        case 'B':
            return 0x4e064220;
        case 'C':
            return 0x4e064220;
        case 'D':
            return 0x4e064220;
        case 'E':
            return 0x4e064220;
        case 'F':
            return 0x4e064220;
        case 'G':
            return 0x4e064220;
        case 'H':
            return 0x4e064220;
        case 'I':
            return 0x4e064220;
        case 'J':
            return 0x4e064220;
        case 'K':
            return 0x4e064220;
        case 'L':
            return 0x4e064220;
        case 'M':
            return 0x4e064220;
        case 'N':
            return 0x4e064220;
        case 'O':
            return 0x4e064220;
        case 'P':
            return 0x4e064220;
        case 'Q':
            return 0x4e064220;
        case 'R':
            return 0x4e064220;
        case 'S':
            return 0x4e064220;
        case 'T':
            return 0x4e064220;
        case 'U':
            return 0x4e064220;
        case 'V':
            return 0x4e064220;
        case 'W':
            return 0x4e064220;
        case 'X':
            return 0x4e064220;
        case 'Y':
            return 0x4e064220;
        case 'Z':
            return 0x4e064220;
        case '_':
            return 0x4e064220;
        case 'a':
            return 0x4e064220;
        case 'b':
            return 0x4e064220;
        case 'c':
            return 0x4e064220;
        case 'd':
            return 0x4e064220;
        case 'e':
            return 0x4e064220;
        case 'f':
            return 0x4e064220;
        case 'g':
            return 0x4e064220;
        case 'h':
            return 0x4e064220;
        case 'i':
            return 0x4e064220;
        case 'j':
            return 0x4e064220;
        case 'k':
            return 0x4e064220;
        case 'l':
            return 0x4e064220;
        case 'm':
            return 0x4e064220;
        case 'n':
            return 0x4e064220;
        case 'o':
            return 0x4e064220;
        case 'p':
            return 0x4e064220;
        case 'q':
            return 0x4e064220;
        case 'r':
            return 0x4e064220;
        case 's':
            return 0x4e064220;
        case 't':
            return 0x4e064220;
        case 'u':
            return 0x4e064220;
        case 'v':
            return 0x4e064220;
        case 'w':
            return 0x4e064220;
        case 'x':
            return 0x4e064220;
        case 'y':
            return 0x4e064220;
        case 'z':
            return 0x4e064220;
        default:
            return -1;
        }
        break;
    case 0x4e949c60:
        switch (input) {
        case '>':
            return 0x4e94a380;
        default:
            return 0x4e949c60;
        }
        break;
    case 0x4e060820:
        switch (input) {
        case '\t':
            return 0x4e060820;
        case '\n':
            return 0x4e060820;
        case '\r':
            return 0x4e060820;
        case ' ':
            return 0x4e060820;
        default:
            return -1;
        }
        break;
    case 0x4e94a380:
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
    case 0x4e0607f0:
        return 0;
    case 0x4e064220:
        return 1;
    case 0x4e949c60:
        return 0;
    case 0x4e060820:
        return 1;
    case 0x4e94a380:
        return 1;
    }
}

static
int get_class(int state)
{
    switch (state) {
    case 0x4e064220:
        return t_symbol;
    case 0x4e060820:
        return t_gobble__blank;
    case 0x4e94a380:
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
