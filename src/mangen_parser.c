#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"

#include "token.h"
#include "stack_int.h"

#include "mangen_tokens.h"

static
void shift(void **token, FILE *i, void **state_stack, int next_state)
{
    free(*token);
    *token = fetch_token(i);
    stack_int__insert(state_stack, next_state);
}

static
void error(void)
{
    fprintf(stderr, "Parsing error. Aborting...\n");
    exit(EXIT_FAILURE);
}

void parse(FILE *i, void *user)
{
    void *tk = fetch_token(i); // token buffer
    void *ss = NULL; // state stack
    stack_int__insert(&ss, 0);
    while (1) {
        switch (stack_int__access(&ss)) {
		case 0:
			switch (tkid(tk)) {
			case t_symbol:
				shift(&tk, i, &ss, 10);
				break;
			default:
				error();
				break;
			}
			break;
		case 10:
			switch (tkid(tk)) {
			case t_rightarrow:
				shift(&tk, i, &ss, 20);
				break;
			default:
				error();
				break;
			}
			break;
		case 20:
			switch (tkid(tk)) {
			case t_symbol:
			case t_literal:
			case t_union:
			case t_any:
				shift(&tk, i, &ss, 30);
				break;
			case t_lpar:
				shift(&tk, i, &ss, 40);
				break;
			default:
				error();
				break;
			}
			break;
		case 30:
			{
				// void *node = mknode_str("expr_4");
				// node_append_child(node, // ns__pop());
				// ns__push(node);
				stack_int__delete(&ss);
				switch (stack_int__access(&ss)) {
				case 20:
				case 40:
				case 100:
				case 130:
					stack_int__insert(&ss, 50);
					break;
				default:
					error();
					break;
				}
			}
			break;
		case 40:
			switch (tkid(tk)) {
			case t_symbol:
			case t_literal:
			case t_union:
			case t_any:
				shift(&tk, i, &ss, 30);
				break;
			case t_lpar:
				shift(&tk, i, &ss, 40);
				break;
			default:
				error();
				break;
			}
			break;
		case 50:
			switch (tkid(tk)) {
			case t_kleenestar:
				shift(&tk, i, &ss, 60);
				break;
			case t_kleeneplus:
				shift(&tk, i, &ss, 70);
				break;
			default:
				{
					// void *node = mknode_str("expr_1");
					// node_append_child(node, // ns__pop());
					// ns__push(node);
					stack_int__delete(&ss);
					switch (stack_int__access(&ss)) {
					case 20:
					case 40:
					case 100:
					case 130:
						stack_int__insert(&ss, 100);
						break;
					default:
						error();
						break;
					}
				}
				break;
			}
			break;
		case 60:
			{
				// void *node = mknode_str("expr_2");
				// node_append_child(node, // ns__pop());
				// node_append_child(node, // ns__pop());
				// ns__push(node);
				stack_int__delete(&ss);
				stack_int__delete(&ss);
				switch (stack_int__access(&ss)) {
				case 20:
				case 40:
				case 100:
				case 130:
					stack_int__insert(&ss, 80);
					break;
				default:
					error();
					break;
				}
			}
			break;
		case 70:
			{
				// void *node = mknode_str("expr_3");
				// node_append_child(node, // ns__pop());
				// node_append_child(node, // ns__pop());
				// ns__push(node);
				stack_int__delete(&ss);
				stack_int__delete(&ss);
				switch (stack_int__access(&ss)) {
				case 20:
				case 40:
				case 100:
				case 130:
					stack_int__insert(&ss, 90);
					break;
				default:
					error();
					break;
				}
			}
			break;
		case 80:
			{
				// void *node = mknode_str("expr_1");
				// node_append_child(node, // ns__pop());
				// ns__push(node);
				stack_int__delete(&ss);
				switch (stack_int__access(&ss)) {
				case 20:
				case 40:
				case 100:
				case 130:
					stack_int__insert(&ss, 100);
					break;
				default:
					error();
					break;
				}
			}
			break;
		case 90:
			{
				// void *node = mknode_str("expr_1");
				// node_append_child(node, // ns__pop());
				// ns__push(node);
				stack_int__delete(&ss);
				switch (stack_int__access(&ss)) {
				case 20:
				case 40:
				case 100:
				case 130:
					stack_int__insert(&ss, 100);
					break;
				default:
					error();
					break;
				}
			}
			break;
		case 100:
			switch (tkid(tk)) {
			case t_symbol:
			case t_literal:
			case t_union:
			case t_any:
				shift(&tk, i, &ss, 30);
				break;
			case t_lpar:
				shift(&tk, i, &ss, 40);
				break;
			default:
				{
					// void *node = mknode_str("expr_0");
					// node_append_child(node, // ns__pop());
					// ns__push(node);
					stack_int__delete(&ss);
					switch (stack_int__access(&ss)) {
					case 20:
					case 40:
					case 130:
						stack_int__insert(&ss, 120);
						break;
					case 100:
						stack_int__insert(&ss, 110);
						break;
					default:
						error();
						break;
					}
				}
				break;
			}
			break;
		case 110:
			{
				// void *node = mknode_str("expr_0");
				// node_append_child(node, // ns__pop());
				// node_append_child(node, // ns__pop());
				// ns__push(node);
				stack_int__delete(&ss);
				stack_int__delete(&ss);
				switch (stack_int__access(&ss)) {
				case 20:
				case 40:
				case 130:
					stack_int__insert(&ss, 120);
					break;
				case 100:
					stack_int__insert(&ss, 110);
					break;
				default:
					error();
					break;
				}
			}
			break;
		case 120:
			switch (tkid(tk)) {
			case t_disjunction:
				shift(&tk, i, &ss, 130);
				break;
			default:
				{
					// void *node = mknode_str("expr");
					// node_append_child(node, // ns__pop());
					// ns__push(node);
					stack_int__delete(&ss);
					switch (stack_int__access(&ss)) {
					case 20:
						stack_int__insert(&ss, 140);
						break;
					case 130:
						stack_int__insert(&ss, 190);
						break;
					case 40:
						stack_int__insert(&ss, 170);
						break;
					default:
						error();
						break;
					}
				}
				break;
			}
			break;
		case 130:
			switch (tkid(tk)) {
			case t_symbol:
			case t_literal:
			case t_union:
			case t_any:
				shift(&tk, i, &ss, 30);
				break;
			case t_lpar:
				shift(&tk, i, &ss, 40);
				break;
			default:
				error();
				break;
			}
			break;
		case 140:
			switch (tkid(tk)) {
			case t_terminator:
				shift(&tk, i, &ss, 150);
				break;
			default:
				error();
				break;
			}
			break;
		case 150:
			{
				// void *node = mknode_str("production");
				// node_append_child(node, // ns__pop());
				// node_append_child(node, // ns__pop());
				// node_append_child(node, // ns__pop());
				// node_append_child(node, // ns__pop());
				// ns__push(node);
				// user_action(stack_int__access(&ss), node, user);
				stack_int__delete(&ss);
				stack_int__delete(&ss);
				stack_int__delete(&ss);
				stack_int__delete(&ss);
				switch (stack_int__access(&ss)) {
				case 0:
				case 160:
					stack_int__insert(&ss, 160);
					break;
				default:
					error();
					break;
				}
			}
			break;
		case 160:
			switch (tkid(tk)) {
			case t_symbol:
				shift(&tk, i, &ss, 10);
				break;
			default:
				{
					// void *node = mknode_str("start");
					// node_append_child(node, // ns__pop());
					// ns__push(node);
					stack_int__delete(&ss);
					switch (stack_int__access(&ss)) {
					case 160:
						stack_int__insert(&ss, 200);
						break;
					default:
						error();
						break;
					}
				}
				break;
			}
			break;
		case 170:
			switch (tkid(tk)) {
			case t_rpar:
				shift(&tk, i, &ss, 180);
				break;
			default:
				error();
				break;
			}
			break;
		case 180:
			{
				// void *node = mknode_str("expr_4");
				// node_append_child(node, // ns__pop());
				// node_append_child(node, // ns__pop());
				// node_append_child(node, // ns__pop());
				// ns__push(node);
				stack_int__delete(&ss);
				stack_int__delete(&ss);
				stack_int__delete(&ss);
				switch (stack_int__access(&ss)) {
				case 20:
				case 40:
				case 100:
				case 130:
					stack_int__insert(&ss, 50);
					break;
				default:
					error();
				}
			}
			break;
		case 190:
			{
				// void *node = mknode_str("expr");
				// node_append_child(node, // ns__pop());
				// node_append_child(node, // ns__pop());
				// node_append_child(node, // ns__pop());
				// ns__push(node);
				stack_int__delete(&ss);
				stack_int__delete(&ss);
				stack_int__delete(&ss);
				switch (stack_int__access(&ss)) {
				case 20:
					stack_int__insert(&ss, 140);
					break;
				case 130:
					stack_int__insert(&ss, 190);
					break;
				case 40:
					stack_int__insert(&ss, 170);
					break;
				default:
					error();
					break;
				}
			}
			break;
		case 200:
			{
				// void *node = mknode_str("start");
				// node_append_child(node, // ns__pop());
				// node_append_child(node, // ns__pop());
				// ns__push(node);
				stack_int__delete(&ss);
				stack_int__delete(&ss);
				switch (stack_int__access(&ss)) {
				case 0:
					stack_int__insert(&ss, 210);
					break;
				case 160:
					stack_int__insert(&ss, 200);
					break;
				default:
					error();
				}
			}
			break;
		case 210:
			// dump parse tree
            fprintf(stdout, "Parsed succesfully!\n");
			return;
		}
    }
}
