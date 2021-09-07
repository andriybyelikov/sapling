/* This file was automatically generated. */

#include <stdio.h>
#include <libsapling/idiom.h>
#include "composition/terminals.h"
#include "internal_lexer.h"

static
int get_initial_state(void)
{
    return 0x1bdb5810;
}

static
int next_state(int current_state, char input)
{
    switch (current_state) {
    case 0x1bdb5810:
        switch (input) {
        case '\t':
            return 0x1bdb5840;
        case '\n':
            return 0x1bdb5840;
        case '\r':
            return 0x1bdb5840;
        case ' ':
            return 0x1bdb5840;
        case '-':
            return 0x1bdb91d0;
        case '.':
            return 0x1bdbb050;
        case '/':
            return 0x1bdbb050;
        case '0':
            return 0x1bdbb050;
        case '1':
            return 0x1bdbb050;
        case '2':
            return 0x1bdbb050;
        case '3':
            return 0x1bdbb050;
        case '4':
            return 0x1bdbb050;
        case '5':
            return 0x1bdbb050;
        case '6':
            return 0x1bdbb050;
        case '7':
            return 0x1bdbb050;
        case '8':
            return 0x1bdbb050;
        case '9':
            return 0x1bdbb050;
        case '<':
            return 0x1c7a91e0;
        case 'A':
            return 0x1bdbb050;
        case 'B':
            return 0x1bdbb050;
        case 'C':
            return 0x1bdbb050;
        case 'D':
            return 0x1bdbb050;
        case 'E':
            return 0x1bdbb050;
        case 'F':
            return 0x1bdbb050;
        case 'G':
            return 0x1bdbb050;
        case 'H':
            return 0x1bdbb050;
        case 'I':
            return 0x1bdbb050;
        case 'J':
            return 0x1bdbb050;
        case 'K':
            return 0x1bdbb050;
        case 'L':
            return 0x1bdbb050;
        case 'M':
            return 0x1bdbb050;
        case 'N':
            return 0x1bdbb050;
        case 'O':
            return 0x1bdbb050;
        case 'P':
            return 0x1bdbb050;
        case 'Q':
            return 0x1bdbb050;
        case 'R':
            return 0x1bdbb050;
        case 'S':
            return 0x1bdbb050;
        case 'T':
            return 0x1bdbb050;
        case 'U':
            return 0x1bdbb050;
        case 'V':
            return 0x1bdbb050;
        case 'W':
            return 0x1bdbb050;
        case 'X':
            return 0x1bdbb050;
        case 'Y':
            return 0x1bdbb050;
        case 'Z':
            return 0x1bdbb050;
        case '\\':
            return 0x1bdbb050;
        case ']':
            return 0x1bdbb050;
        case '^':
            return 0x1bdbb050;
        case '_':
            return 0x1bdbb050;
        case 'a':
            return 0x1bdbb050;
        case 'b':
            return 0x1bdbb050;
        case 'c':
            return 0x1bdbb050;
        case 'd':
            return 0x1bdbb050;
        case 'e':
            return 0x1bdbb050;
        case 'f':
            return 0x1bdbb050;
        case 'g':
            return 0x1bdbb050;
        case 'h':
            return 0x1bdbb050;
        case 'i':
            return 0x1bdbb050;
        case 'j':
            return 0x1bdbb050;
        case 'k':
            return 0x1bdbb050;
        case 'l':
            return 0x1bdbb050;
        case 'm':
            return 0x1bdbb050;
        case 'n':
            return 0x1bdbb050;
        case 'o':
            return 0x1bdbb050;
        case 'p':
            return 0x1bdbb050;
        case 'q':
            return 0x1bdbb050;
        case 'r':
            return 0x1bdbb050;
        case 's':
            return 0x1bdbb050;
        case 't':
            return 0x1bdbb050;
        case 'u':
            return 0x1bdbb050;
        case 'v':
            return 0x1bdbb050;
        case 'w':
            return 0x1bdbb050;
        case 'x':
            return 0x1bdbb050;
        case 'y':
            return 0x1bdbb050;
        case 'z':
            return 0x1bdbb050;
        default:
            return -1;
        }
        break;
    case 0x1bdb91d0:
        switch (input) {
        case '-':
            return 0x1bdb9230;
        default:
            return -1;
        }
        break;
    case 0x1bdbb050:
        switch (input) {
        case '.':
            return 0x1bdbb050;
        case '/':
            return 0x1bdbb050;
        case '0':
            return 0x1bdbb050;
        case '1':
            return 0x1bdbb050;
        case '2':
            return 0x1bdbb050;
        case '3':
            return 0x1bdbb050;
        case '4':
            return 0x1bdbb050;
        case '5':
            return 0x1bdbb050;
        case '6':
            return 0x1bdbb050;
        case '7':
            return 0x1bdbb050;
        case '8':
            return 0x1bdbb050;
        case '9':
            return 0x1bdbb050;
        case 'A':
            return 0x1bdbb050;
        case 'B':
            return 0x1bdbb050;
        case 'C':
            return 0x1bdbb050;
        case 'D':
            return 0x1bdbb050;
        case 'E':
            return 0x1bdbb050;
        case 'F':
            return 0x1bdbb050;
        case 'G':
            return 0x1bdbb050;
        case 'H':
            return 0x1bdbb050;
        case 'I':
            return 0x1bdbb050;
        case 'J':
            return 0x1bdbb050;
        case 'K':
            return 0x1bdbb050;
        case 'L':
            return 0x1bdbb050;
        case 'M':
            return 0x1bdbb050;
        case 'N':
            return 0x1bdbb050;
        case 'O':
            return 0x1bdbb050;
        case 'P':
            return 0x1bdbb050;
        case 'Q':
            return 0x1bdbb050;
        case 'R':
            return 0x1bdbb050;
        case 'S':
            return 0x1bdbb050;
        case 'T':
            return 0x1bdbb050;
        case 'U':
            return 0x1bdbb050;
        case 'V':
            return 0x1bdbb050;
        case 'W':
            return 0x1bdbb050;
        case 'X':
            return 0x1bdbb050;
        case 'Y':
            return 0x1bdbb050;
        case 'Z':
            return 0x1bdbb050;
        case '\\':
            return 0x1bdbb050;
        case ']':
            return 0x1bdbb050;
        case '^':
            return 0x1bdbb050;
        case '_':
            return 0x1bdbb050;
        case 'a':
            return 0x1bdbb050;
        case 'b':
            return 0x1bdbb050;
        case 'c':
            return 0x1bdbb050;
        case 'd':
            return 0x1bdbb050;
        case 'e':
            return 0x1bdbb050;
        case 'f':
            return 0x1bdbb050;
        case 'g':
            return 0x1bdbb050;
        case 'h':
            return 0x1bdbb050;
        case 'i':
            return 0x1bdbb050;
        case 'j':
            return 0x1bdbb050;
        case 'k':
            return 0x1bdbb050;
        case 'l':
            return 0x1bdbb050;
        case 'm':
            return 0x1bdbb050;
        case 'n':
            return 0x1bdbb050;
        case 'o':
            return 0x1bdbb050;
        case 'p':
            return 0x1bdbb050;
        case 'q':
            return 0x1bdbb050;
        case 'r':
            return 0x1bdbb050;
        case 's':
            return 0x1bdbb050;
        case 't':
            return 0x1bdbb050;
        case 'u':
            return 0x1bdbb050;
        case 'v':
            return 0x1bdbb050;
        case 'w':
            return 0x1bdbb050;
        case 'x':
            return 0x1bdbb050;
        case 'y':
            return 0x1bdbb050;
        case 'z':
            return 0x1bdbb050;
        default:
            return -1;
        }
        break;
    case 0x1bdb9230:
        switch (input) {
        case '\n':
            return 0x1bdb98f0;
        default:
            return 0x1bdb9230;
        }
        break;
    case 0x1bdb98f0:
        switch (input) {
        default:
            return -1;
        }
        break;
    case 0x1c7a91e0:
        switch (input) {
        case '>':
            return 0x1c7a98a0;
        default:
            return 0x1c7a91e0;
        }
        break;
    case 0x1bdb5840:
        switch (input) {
        case '\t':
            return 0x1bdb5840;
        case '\n':
            return 0x1bdb5840;
        case '\r':
            return 0x1bdb5840;
        case ' ':
            return 0x1bdb5840;
        default:
            return -1;
        }
        break;
    case 0x1c7a98a0:
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
    case 0x1bdb5810:
        return 0;
    case 0x1bdb91d0:
        return 0;
    case 0x1bdbb050:
        return 1;
    case 0x1bdb9230:
        return 0;
    case 0x1bdb98f0:
        return 1;
    case 0x1c7a91e0:
        return 0;
    case 0x1bdb5840:
        return 1;
    case 0x1c7a98a0:
        return 1;
    }
}

static
int get_class(int state)
{
    switch (state) {
    case 0x1bdbb050:
        return t_symbol;
    case 0x1bdb98f0:
        return t_gobble__linecomment;
    case 0x1bdb5840:
        return t_gobble__blank;
    case 0x1c7a98a0:
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
