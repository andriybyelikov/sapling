#include <stdio.h>
#include <libsapling/cc/terminal.h>
#include "lexer_action.h"
#include "autogen_terminals.h"

static
int next_state(int current_state, char c)
{
    switch (current_state) {
    case 0x559d47f0:
        switch (c) {
        case '\t':
            return 0x559d4820;
        case '\n':
            return 0x559d4820;
        case '\r':
            return 0x559d4820;
        case ' ':
            return 0x559d4820;
        case '\"':
            return 0x55c4e260;
        case '(':
            return 0x559e36b0;
        case ')':
            return 0x559e5750;
        case '*':
            return 0x559da1d0;
        case '+':
            return 0x559db400;
        case '-':
            return 0x559d8250;
        case '.':
            return 0x559de450;
        case ';':
            return 0x559dfde0;
        case '<':
            return 0x55c5d8c0;
        case '[':
            return 0x55c56400;
        case 'a':
            return 0x559e7a00;
        case 'b':
            return 0x559e7a00;
        case 'c':
            return 0x559e7a00;
        case 'd':
            return 0x559e7a00;
        case 'e':
            return 0x559e7a00;
        case 'f':
            return 0x559e7a00;
        case 'g':
            return 0x559e7a00;
        case 'h':
            return 0x559e7a00;
        case 'i':
            return 0x559e7a00;
        case 'j':
            return 0x559e7a00;
        case 'k':
            return 0x559e7a00;
        case 'l':
            return 0x559e7a00;
        case 'm':
            return 0x559e7a00;
        case 'n':
            return 0x559e7a00;
        case 'o':
            return 0x559e7a00;
        case 'p':
            return 0x559e7a00;
        case 'q':
            return 0x559e7a00;
        case 'r':
            return 0x559e7a00;
        case 's':
            return 0x559e7a00;
        case 't':
            return 0x559e7a00;
        case 'u':
            return 0x559e7a00;
        case 'v':
            return 0x559e7a00;
        case 'w':
            return 0x559e7a00;
        case 'x':
            return 0x559e7a00;
        case 'y':
            return 0x559e7a00;
        case 'z':
            return 0x559e7a00;
        case '|':
            return 0x559e1950;
        default:
            return -1;
        }
        break;
    case 0x559e36b0:
        switch (c) {
        default:
            return -1;
        }
        break;
    case 0x559e5750:
        switch (c) {
        default:
            return -1;
        }
        break;
    case 0x559de450:
        switch (c) {
        default:
            return -1;
        }
        break;
    case 0x559dfde0:
        switch (c) {
        default:
            return -1;
        }
        break;
    case 0x559e1950:
        switch (c) {
        default:
            return -1;
        }
        break;
    case 0x559e7a00:
        switch (c) {
        case '0':
            return 0x559e7a00;
        case '1':
            return 0x559e7a00;
        case '2':
            return 0x559e7a00;
        case '3':
            return 0x559e7a00;
        case '4':
            return 0x559e7a00;
        case '5':
            return 0x559e7a00;
        case '6':
            return 0x559e7a00;
        case '7':
            return 0x559e7a00;
        case '8':
            return 0x559e7a00;
        case '9':
            return 0x559e7a00;
        case '_':
            return 0x559e7a00;
        case 'a':
            return 0x559e7a00;
        case 'b':
            return 0x559e7a00;
        case 'c':
            return 0x559e7a00;
        case 'd':
            return 0x559e7a00;
        case 'e':
            return 0x559e7a00;
        case 'f':
            return 0x559e7a00;
        case 'g':
            return 0x559e7a00;
        case 'h':
            return 0x559e7a00;
        case 'i':
            return 0x559e7a00;
        case 'j':
            return 0x559e7a00;
        case 'k':
            return 0x559e7a00;
        case 'l':
            return 0x559e7a00;
        case 'm':
            return 0x559e7a00;
        case 'n':
            return 0x559e7a00;
        case 'o':
            return 0x559e7a00;
        case 'p':
            return 0x559e7a00;
        case 'q':
            return 0x559e7a00;
        case 'r':
            return 0x559e7a00;
        case 's':
            return 0x559e7a00;
        case 't':
            return 0x559e7a00;
        case 'u':
            return 0x559e7a00;
        case 'v':
            return 0x559e7a00;
        case 'w':
            return 0x559e7a00;
        case 'x':
            return 0x559e7a00;
        case 'y':
            return 0x559e7a00;
        case 'z':
            return 0x559e7a00;
        default:
            return -1;
        }
        break;
    case 0x55c4e260:
        switch (c) {
        case '\"':
            return 0x55c4ff10;
        case '\\':
            return 0x55c4e8b0;
        default:
            return 0x55c4e260;
        }
        break;
    case 0x559da1d0:
        switch (c) {
        default:
            return -1;
        }
        break;
    case 0x559db400:
        switch (c) {
        default:
            return -1;
        }
        break;
    case 0x55c4e8b0:
        switch (c) {
        default:
            return 0x55c4e260;
        }
        break;
    case 0x55c4ff10:
        switch (c) {
        default:
            return -1;
        }
        break;
    case 0x55c56400:
        switch (c) {
        case ']':
            return 0x55c56b20;
        default:
            return 0x55c56400;
        }
        break;
    case 0x559d8250:
        switch (c) {
        case '-':
            return 0x559d82b0;
        case '>':
            return 0x559dc930;
        default:
            return -1;
        }
        break;
    case 0x55c56b20:
        switch (c) {
        default:
            return -1;
        }
        break;
    case 0x559d82b0:
        switch (c) {
        case '\n':
            return 0x559d89d0;
        default:
            return 0x559d82b0;
        }
        break;
    case 0x559dc930:
        switch (c) {
        default:
            return -1;
        }
        break;
    case 0x559d89d0:
        switch (c) {
        default:
            return -1;
        }
        break;
    case 0x55c5d8c0:
        switch (c) {
        case '>':
            return 0x55c5dfe0;
        default:
            return 0x55c5d8c0;
        }
        break;
    case 0x559d4820:
        switch (c) {
        case '\t':
            return 0x559d4820;
        case '\n':
            return 0x559d4820;
        case '\r':
            return 0x559d4820;
        case ' ':
            return 0x559d4820;
        default:
            return -1;
        }
        break;
    case 0x55c5dfe0:
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
    case 0x559d47f0:
        return 0;
    case 0x559e36b0:
        return 1;
    case 0x559e5750:
        return 1;
    case 0x559de450:
        return 1;
    case 0x559dfde0:
        return 1;
    case 0x559e1950:
        return 1;
    case 0x559e7a00:
        return 1;
    case 0x55c4e260:
        return 0;
    case 0x559da1d0:
        return 1;
    case 0x559db400:
        return 1;
    case 0x55c4e8b0:
        return 0;
    case 0x55c4ff10:
        return 1;
    case 0x55c56400:
        return 0;
    case 0x559d8250:
        return 0;
    case 0x55c56b20:
        return 1;
    case 0x559d82b0:
        return 0;
    case 0x559dc930:
        return 1;
    case 0x559d89d0:
        return 1;
    case 0x55c5d8c0:
        return 0;
    case 0x559d4820:
        return 1;
    case 0x55c5dfe0:
        return 1;
    }
}

static
int get_class(int state)
{
    switch (state) {
    case 0x559e36b0:
        return t_lpar;
    case 0x559e5750:
        return t_rpar;
    case 0x559de450:
        return t_any;
    case 0x559dfde0:
        return t_terminator;
    case 0x559e1950:
        return t_disjunction;
    case 0x559e7a00:
        return t_symbol;
    case 0x559da1d0:
        return t_kleenestar;
    case 0x559db400:
        return t_kleeneplus;
    case 0x55c4ff10:
        return t_literal;
    case 0x55c56b20:
        return t_class;
    case 0x559dc930:
        return t_rightarrow;
    case 0x559d89d0:
        return t_gobble__linecomment;
    case 0x559d4820:
        return t_gobble__blank;
    case 0x55c5dfe0:
        return t_lisp_routine;
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
    int s = 0x559d47f0;  // state
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
                s = 0x559d47f0;
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
