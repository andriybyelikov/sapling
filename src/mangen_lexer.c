#include <stdio.h>
#include <libsapling/terminal.h>
#include "lexer_action.h"
#include "mangen_terminals.h"

static
void *build_terminal(char *buf, int bufc, int id)
{
    buf[bufc] = 0;
    return terminal(id, buf);
}

void *fetch_terminal(FILE *input_file, void *user_ptr)
{
	char c;         // single character buffer
	int s = 0;      // state
	char buf[4096]; // lexeme buffer
	int bufc = 0;   // lexeme buffer cursor
	void *terminal; // terminal buffer

	while (1) {
		c = getc(input_file);
		switch (s) {
		case 0:
			switch (c) {
			case EOF:
				terminal = build_terminal(buf, bufc, t_eof);
				lexer_action(terminal, user_ptr);
				return terminal;
			case ' ': case '\t': case '\r': case '\n':
				terminal = build_terminal(buf, bufc, t_blank);
				lexer_action(terminal, user_ptr);
				s = 0;
				continue;
			case '*':
				buf[bufc++] = c;
				terminal = build_terminal(buf, bufc, t_kleenestar);
				lexer_action(terminal, user_ptr);
				return terminal;
			case '+':
				buf[bufc++] = c;
				terminal = build_terminal(buf, bufc, t_kleeneplus);
				lexer_action(terminal, user_ptr);
				return terminal;
			case '-':
				buf[bufc++] = c;
				s = 10;
				continue;
			case '.':
				buf[bufc++] = c;
				terminal = build_terminal(buf, bufc, t_any);
				lexer_action(terminal, user_ptr);
				return terminal;
			case '[':
				buf[bufc++] = c;
				s = 30;
				continue;
			case ';':
				buf[bufc++] = c;
				terminal = build_terminal(buf, bufc, t_terminator);
				lexer_action(terminal, user_ptr);
				return terminal;
			case '"':
				buf[bufc++] = c;
				s = 40;
				continue;
			case '|':
				buf[bufc++] = c;
				terminal = build_terminal(buf, bufc, t_disjunction);
				lexer_action(terminal, user_ptr);
				return terminal;
			case '(':
				buf[bufc++] = c;
				terminal = build_terminal(buf, bufc, t_lpar);
				lexer_action(terminal, user_ptr);
				return terminal;
			case ')':
				buf[bufc++] = c;
				terminal = build_terminal(buf, bufc, t_rpar);
				lexer_action(terminal, user_ptr);
				return terminal;
			default:
				if (('a' <= c && c <= 'z')) {
					buf[bufc++] = c;
					s = 20;
					continue;
				}
			}
		break;
		case 10:
			switch (c) {
			case '>':
				buf[bufc++] = c;
				terminal = build_terminal(buf, bufc, t_rightarrow);
				lexer_action(terminal, user_ptr);
				return terminal;
			case '-':
				bufc--; // captured '-' is part of comment
				s = 60;
				continue;
			}
		break;
		case 20:
			if (('a' <= c && c <= 'z') || ('0' <= c && c <= '9') || c == '_') {
				buf[bufc++] = c;
				continue;
			} else {
				ungetc(c, input_file);
				terminal = build_terminal(buf, bufc, t_symbol);
				lexer_action(terminal, user_ptr);
				return terminal;
			}
		break;
		case 30:
			if (c == ']') {
				buf[bufc++] = c;
				terminal = build_terminal(buf, bufc, t_union);
				lexer_action(terminal, user_ptr);
				return terminal;
			}
			buf[bufc++] = c;
			continue;
		break;
		case 40:
			if (c == '\"') {
				buf[bufc++] = c;
				terminal = build_terminal(buf, bufc, t_literal);
				lexer_action(terminal, user_ptr);
				return terminal;
			} else if (c == '\\') {
				buf[bufc++] = c;
				s = 50;
				continue;
			}
			buf[bufc++] = c;
			continue;
		break;
		case 50:
			buf[bufc++] = c;
			s = 40;
			continue;
		break;
		case 60:
			if (c == '\n') {
				terminal = build_terminal(buf, bufc, t_linecomment);
				lexer_action(terminal, user_ptr);
				s = 0;
				continue;
			}
		break;
		default:
			return NULL;
		}
	}
}
