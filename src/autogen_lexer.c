#include <stdio.h>
#include <libsapling/cc/terminal.h>
#include "lexer_action.h"
#include "autogen_terminals.h"

static
int next_state(int current_state, char c)
{
    switch (current_state) {
    case 0xf0924a70:
        switch (c) {
        case '\t':
            return 0xf0924aa0;
        case '\n':
            return 0xf0924aa0;
        case '\r':
            return 0xf0924aa0;
        case ' ':
            return 0xf0924aa0;
        case '\"':
            return 0xf0b9f8a0;
        case '(':
            return 0xf09345f0;
        case ')':
            return 0xf0936950;
        case '*':
            return 0xf092a690;
        case '+':
            return 0xf092ba00;
        case '-':
            return 0xf09285d0;
        case '.':
            return 0xf092ee90;
        case ';':
            return 0xf0930960;
        case '[':
            return 0xf0ba7c40;
        case 'a':
            return 0xf0938e40;
        case 'b':
            return 0xf0938e40;
        case 'c':
            return 0xf0938e40;
        case 'd':
            return 0xf0938e40;
        case 'e':
            return 0xf0938e40;
        case 'f':
            return 0xf0938e40;
        case 'g':
            return 0xf0938e40;
        case 'h':
            return 0xf0938e40;
        case 'i':
            return 0xf0938e40;
        case 'j':
            return 0xf0938e40;
        case 'k':
            return 0xf0938e40;
        case 'l':
            return 0xf0938e40;
        case 'm':
            return 0xf0938e40;
        case 'n':
            return 0xf0938e40;
        case 'o':
            return 0xf0938e40;
        case 'p':
            return 0xf0938e40;
        case 'q':
            return 0xf0938e40;
        case 'r':
            return 0xf0938e40;
        case 's':
            return 0xf0938e40;
        case 't':
            return 0xf0938e40;
        case 'u':
            return 0xf0938e40;
        case 'v':
            return 0xf0938e40;
        case 'w':
            return 0xf0938e40;
        case 'x':
            return 0xf0938e40;
        case 'y':
            return 0xf0938e40;
        case 'z':
            return 0xf0938e40;
        case '|':
            return 0xf09325d0;
        default:
            return -1;
        }
        break;
    case 0xf09345f0:
        switch (c) {
        default:
            return -1;
        }
        break;
    case 0xf092ee90:
        switch (c) {
        default:
            return -1;
        }
        break;
    case 0xf0930960:
        switch (c) {
        default:
            return -1;
        }
        break;
    case 0xf09325d0:
        switch (c) {
        default:
            return -1;
        }
        break;
    case 0xf0936950:
        switch (c) {
        default:
            return -1;
        }
        break;
    case 0xf0938e40:
        switch (c) {
        case '0':
            return 0xf0938e40;
        case '1':
            return 0xf0938e40;
        case '2':
            return 0xf0938e40;
        case '3':
            return 0xf0938e40;
        case '4':
            return 0xf0938e40;
        case '5':
            return 0xf0938e40;
        case '6':
            return 0xf0938e40;
        case '7':
            return 0xf0938e40;
        case '8':
            return 0xf0938e40;
        case '9':
            return 0xf0938e40;
        case '_':
            return 0xf0938e40;
        case 'a':
            return 0xf0938e40;
        case 'b':
            return 0xf0938e40;
        case 'c':
            return 0xf0938e40;
        case 'd':
            return 0xf0938e40;
        case 'e':
            return 0xf0938e40;
        case 'f':
            return 0xf0938e40;
        case 'g':
            return 0xf0938e40;
        case 'h':
            return 0xf0938e40;
        case 'i':
            return 0xf0938e40;
        case 'j':
            return 0xf0938e40;
        case 'k':
            return 0xf0938e40;
        case 'l':
            return 0xf0938e40;
        case 'm':
            return 0xf0938e40;
        case 'n':
            return 0xf0938e40;
        case 'o':
            return 0xf0938e40;
        case 'p':
            return 0xf0938e40;
        case 'q':
            return 0xf0938e40;
        case 'r':
            return 0xf0938e40;
        case 's':
            return 0xf0938e40;
        case 't':
            return 0xf0938e40;
        case 'u':
            return 0xf0938e40;
        case 'v':
            return 0xf0938e40;
        case 'w':
            return 0xf0938e40;
        case 'x':
            return 0xf0938e40;
        case 'y':
            return 0xf0938e40;
        case 'z':
            return 0xf0938e40;
        default:
            return -1;
        }
        break;
    case 0xf092a690:
        switch (c) {
        default:
            return -1;
        }
        break;
    case 0xf092ba00:
        switch (c) {
        default:
            return -1;
        }
        break;
    case 0xf0b9f8a0:
        switch (c) {
        case '\"':
            return 0xf0ba14d0;
        case '\\':
            return 0xf0b9feb0;
        default:
            return 0xf0b9f8a0;
        }
        break;
    case 0xf09285d0:
        switch (c) {
        case '-':
            return 0xf0928630;
        case '>':
            return 0xf092d070;
        default:
            return -1;
        }
        break;
    case 0xf0b9feb0:
        switch (c) {
        default:
            return 0xf0b9f8a0;
        }
        break;
    case 0xf0ba14d0:
        switch (c) {
        default:
            return -1;
        }
        break;
    case 0xf0928630:
        switch (c) {
        case '\n':
            return 0xf0928d50;
        default:
            return 0xf0928630;
        }
        break;
    case 0xf092d070:
        switch (c) {
        default:
            return -1;
        }
        break;
    case 0xf0928d50:
        switch (c) {
        default:
            return -1;
        }
        break;
    case 0xf0ba7c40:
        switch (c) {
        case ']':
            return 0xf0ba8360;
        default:
            return 0xf0ba7c40;
        }
        break;
    case 0xf0924aa0:
        switch (c) {
        case '\t':
            return 0xf0924aa0;
        case '\n':
            return 0xf0924aa0;
        case '\r':
            return 0xf0924aa0;
        case ' ':
            return 0xf0924aa0;
        default:
            return -1;
        }
        break;
    case 0xf0ba8360:
        switch (c) {
        default:
            return -1;
        }
        break;
        default:
            return -1;
    }
}

static
int is_accepting_state(int s)
{
    switch (s) {
    case 0xf0924a70:
        return 0;
    case 0xf09345f0:
        return 1;
    case 0xf092ee90:
        return 1;
    case 0xf0930960:
        return 1;
    case 0xf09325d0:
        return 1;
    case 0xf0936950:
        return 1;
    case 0xf0938e40:
        return 1;
    case 0xf092a690:
        return 1;
    case 0xf092ba00:
        return 1;
    case 0xf0b9f8a0:
        return 0;
    case 0xf09285d0:
        return 0;
    case 0xf0b9feb0:
        return 0;
    case 0xf0ba14d0:
        return 1;
    case 0xf0928630:
        return 0;
    case 0xf092d070:
        return 1;
    case 0xf0928d50:
        return 1;
    case 0xf0ba7c40:
        return 0;
    case 0xf0924aa0:
        return 1;
    case 0xf0ba8360:
        return 1;
    }
}

static
int get_class(int state)
{
    switch (state) {
    case 0xf09345f0:
        return t_lpar;
    case 0xf092ee90:
        return t_any;
    case 0xf0930960:
        return t_terminator;
    case 0xf09325d0:
        return t_disjunction;
    case 0xf0936950:
        return t_rpar;
    case 0xf0938e40:
        return t_symbol;
    case 0xf092a690:
        return t_kleenestar;
    case 0xf092ba00:
        return t_kleeneplus;
    case 0xf0ba14d0:
        return t_literal;
    case 0xf092d070:
        return t_rightarrow;
    case 0xf0928d50:
        return t_gobble__linecomment;
    case 0xf0924aa0:
        return t_gobble__blank;
    case 0xf0ba8360:
        return t_class;
    }
}

static
terminal_t build_terminal(char *buf, int bufc, int id)
{
    buf[bufc] = 0;
    return new_terminal(id, buf);
}

terminal_t fetch_terminal(FILE *input_file, void *user_ptr)
{
    char c;              // single character buffer
    int s = 0xf0924a70;  // state
    char buf[4096];      // lexeme buffer
    int bufc = 0;        // lexeme buffer cursor
    terminal_t terminal; // terminal buffer
    int class = -1;
    int overread = 0;
    int cont = 1;

    while (cont) {
        c = getc(input_file);
        if (c == EOF) {
            terminal = build_terminal(buf, bufc, t_eof);
            lexer_action(terminal, user_ptr);
            return terminal;
        } else {
            if (is_accepting_state(s)) {
                class = get_class(s);
                overread = 0;
            }
            s = next_state(s, c);
            buf[bufc++] = c;
            overread++;
            if (s == -1) {
                for (int i = 0; i < overread; i++) {
                    ungetc(c, input_file);
                    bufc--;
                }
                overread = 0;
                s = 0xf0924a70;
                if (1 && class != t_gobble__blank && class != t_gobble__linecomment)
                    cont = 0;
                else
                    bufc = 0;
            }
        }
    }
    if (class == -1)
        return NULL;
    terminal = build_terminal(buf, bufc, class);
    lexer_action(terminal, user_ptr);
    return terminal;
}
