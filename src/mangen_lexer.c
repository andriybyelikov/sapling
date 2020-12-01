#include <stdio.h>
#include "token.h"
#include "mangen_tokens.h"

static
void *emtk(char *buf, int bufc, int id)
{
    buf[bufc] = 0;
    return mktk(id, buf);
}

void *fetch_token(FILE *i)
{
	char c;         // single character buffer
	int s = 0;      // state
	char buf[4096]; // lexeme buffer
	int bufc = 0;   // lexeme buffer cursor

	while (1) {
		c = getc(i);
		switch (s) {
		case 0:
			switch (c) {
			case EOF:
				return emtk(buf, bufc, t_eof);
			case ' ': case '\t': case '\r': case '\n':
				continue;
			case '*':
				buf[bufc++] = c;
				return emtk(buf, bufc, t_kleenestar);
			case '+':
				buf[bufc++] = c;
				return emtk(buf, bufc, t_kleeneplus);
			case '-':
				buf[bufc++] = c;
				s = 10;
				continue;
			case '.':
				buf[bufc++] = c;
				return emtk(buf, bufc, t_any);
			case '[':
				buf[bufc++] = c;
				s = 30;
				continue;
			case ';':
				buf[bufc++] = c;
				return emtk(buf, bufc, t_terminator);
			case '"':
				buf[bufc++] = c;
				s = 40;
				continue;
			case '|':
				buf[bufc++] = c;
				return emtk(buf, bufc, t_disjunction);
			case '(':
				buf[bufc++] = c;
				return emtk(buf, bufc, t_lpar);
			case ')':
				buf[bufc++] = c;
				return emtk(buf, bufc, t_rpar);
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
				return emtk(buf, bufc, t_rightarrow);
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
				ungetc(c, i);
				return emtk(buf, bufc, t_symbol);
			}
		break;
		case 30:
			if (c == ']') {
				buf[bufc++] = c;
				return emtk(buf, bufc, t_union);
			}
			buf[bufc++] = c;
			continue;
		break;
		case 40:
			if (c == '\"') {
				buf[bufc++] = c;
				return emtk(buf, bufc, t_literal);
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
				s = 0;
				continue;
			}
		break;
		default:
			return NULL;
		}
	}
}
