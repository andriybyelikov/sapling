/* This file was automatically generated. */

#include <libsapling/cc/parse_tree.h>
#include "aux/state_stack.h"
#include "aux/parse_tree_stack.h"
#include "data.h"
#include "ulisp/parser_actions.h"
#include "ulisp/ulisp_parser.h"

int ulisp__get_grammar_symbol_index_from_string(const char *str);

static
void parser_goto(node_t *state_stack, int gsym)
{
    internal_parser_t parser = get_ulisp_parser();

    switch (state_stack__access(state_stack)) {
    case 0:
        switch (gsym) {
        case 10:
            state_stack__insert(state_stack, 2);
            break;
        case 11:
            state_stack__insert(state_stack, 3);
            break;
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 1:
        switch (gsym) {
        case 10:
            state_stack__insert(state_stack, 8);
            break;
        case 11:
            state_stack__insert(state_stack, 3);
            break;
        case 12:
            state_stack__insert(state_stack, 9);
            break;
        case 13:
            state_stack__insert(state_stack, 10);
            break;
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 2:
        switch (gsym) {
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 3:
        switch (gsym) {
        case 10:
            state_stack__insert(state_stack, 11);
            break;
        case 11:
            state_stack__insert(state_stack, 3);
            break;
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 4:
        switch (gsym) {
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 5:
        switch (gsym) {
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 6:
        switch (gsym) {
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 7:
        switch (gsym) {
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 8:
        switch (gsym) {
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 9:
        switch (gsym) {
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 10:
        switch (gsym) {
        case 10:
            state_stack__insert(state_stack, 8);
            break;
        case 11:
            state_stack__insert(state_stack, 3);
            break;
        case 12:
            state_stack__insert(state_stack, 13);
            break;
        case 13:
            state_stack__insert(state_stack, 10);
            break;
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 11:
        switch (gsym) {
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 12:
        switch (gsym) {
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 13:
        switch (gsym) {
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    default:
        internal_parser__error(state_stack__access(state_stack));
        break;
    }
}

void ulisp__parser_actions0(void *user_ptr, node_t *state_stack, terminal_t terminal)
{
    internal_parser_t parser = get_ulisp_parser();

    struct data_common *user = user_ptr;
    node_t *parse_tree_stack = &user->parse_tree_stack;

    int state = state_stack__access(state_stack);
    switch (state) {
    case 0:
        ulisp__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                ulisp__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 1);
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = ulisp__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        ulisp__post_state_action1(user_ptr);
        break;
    case 1:
        ulisp__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                ulisp__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 1);
                break;
            case 4:
                ulisp__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 4);
                break;
            case 5:
                ulisp__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 5);
                break;
            case 6:
                ulisp__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 6);
                break;
            case 7:
                ulisp__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 7);
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = ulisp__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        ulisp__post_state_action1(user_ptr);
        break;
    case 2:
        ulisp__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 8:
                internal_parser__reduce(parser, 0);
                ulisp__post_reduce_action1(user_ptr, 0);
                ulisp__production_attibuted_actions2(user_ptr, 0);
                internal_parser__accept(parser);
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = ulisp__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        ulisp__post_state_action1(user_ptr);
        break;
    case 3:
        ulisp__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                internal_parser__reduce(parser, 2);
                ulisp__post_reduce_action1(user_ptr, 2);
                ulisp__production_attibuted_actions2(user_ptr, 2);
                reduction_ocurred = 1;
                break;
            case 3:
                internal_parser__reduce(parser, 2);
                ulisp__post_reduce_action1(user_ptr, 2);
                ulisp__production_attibuted_actions2(user_ptr, 2);
                reduction_ocurred = 1;
                break;
            case 4:
                internal_parser__reduce(parser, 2);
                ulisp__post_reduce_action1(user_ptr, 2);
                ulisp__production_attibuted_actions2(user_ptr, 2);
                reduction_ocurred = 1;
                break;
            case 5:
                internal_parser__reduce(parser, 2);
                ulisp__post_reduce_action1(user_ptr, 2);
                ulisp__production_attibuted_actions2(user_ptr, 2);
                reduction_ocurred = 1;
                break;
            case 6:
                internal_parser__reduce(parser, 2);
                ulisp__post_reduce_action1(user_ptr, 2);
                ulisp__production_attibuted_actions2(user_ptr, 2);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 2);
                ulisp__post_reduce_action1(user_ptr, 2);
                ulisp__production_attibuted_actions2(user_ptr, 2);
                reduction_ocurred = 1;
                break;
            case 8:
                internal_parser__reduce(parser, 2);
                ulisp__post_reduce_action1(user_ptr, 2);
                ulisp__production_attibuted_actions2(user_ptr, 2);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = ulisp__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        ulisp__post_state_action1(user_ptr);
        break;
    case 4:
        ulisp__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                internal_parser__reduce(parser, 6);
                ulisp__post_reduce_action1(user_ptr, 6);
                ulisp__production_attibuted_actions2(user_ptr, 6);
                reduction_ocurred = 1;
                break;
            case 3:
                internal_parser__reduce(parser, 6);
                ulisp__post_reduce_action1(user_ptr, 6);
                ulisp__production_attibuted_actions2(user_ptr, 6);
                reduction_ocurred = 1;
                break;
            case 4:
                internal_parser__reduce(parser, 6);
                ulisp__post_reduce_action1(user_ptr, 6);
                ulisp__production_attibuted_actions2(user_ptr, 6);
                reduction_ocurred = 1;
                break;
            case 5:
                internal_parser__reduce(parser, 6);
                ulisp__post_reduce_action1(user_ptr, 6);
                ulisp__production_attibuted_actions2(user_ptr, 6);
                reduction_ocurred = 1;
                break;
            case 6:
                internal_parser__reduce(parser, 6);
                ulisp__post_reduce_action1(user_ptr, 6);
                ulisp__production_attibuted_actions2(user_ptr, 6);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 6);
                ulisp__post_reduce_action1(user_ptr, 6);
                ulisp__production_attibuted_actions2(user_ptr, 6);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = ulisp__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        ulisp__post_state_action1(user_ptr);
        break;
    case 5:
        ulisp__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                internal_parser__reduce(parser, 7);
                ulisp__post_reduce_action1(user_ptr, 7);
                ulisp__production_attibuted_actions2(user_ptr, 7);
                reduction_ocurred = 1;
                break;
            case 3:
                internal_parser__reduce(parser, 7);
                ulisp__post_reduce_action1(user_ptr, 7);
                ulisp__production_attibuted_actions2(user_ptr, 7);
                reduction_ocurred = 1;
                break;
            case 4:
                internal_parser__reduce(parser, 7);
                ulisp__post_reduce_action1(user_ptr, 7);
                ulisp__production_attibuted_actions2(user_ptr, 7);
                reduction_ocurred = 1;
                break;
            case 5:
                internal_parser__reduce(parser, 7);
                ulisp__post_reduce_action1(user_ptr, 7);
                ulisp__production_attibuted_actions2(user_ptr, 7);
                reduction_ocurred = 1;
                break;
            case 6:
                internal_parser__reduce(parser, 7);
                ulisp__post_reduce_action1(user_ptr, 7);
                ulisp__production_attibuted_actions2(user_ptr, 7);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 7);
                ulisp__post_reduce_action1(user_ptr, 7);
                ulisp__production_attibuted_actions2(user_ptr, 7);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = ulisp__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        ulisp__post_state_action1(user_ptr);
        break;
    case 6:
        ulisp__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                internal_parser__reduce(parser, 8);
                ulisp__post_reduce_action1(user_ptr, 8);
                ulisp__production_attibuted_actions2(user_ptr, 8);
                reduction_ocurred = 1;
                break;
            case 3:
                internal_parser__reduce(parser, 8);
                ulisp__post_reduce_action1(user_ptr, 8);
                ulisp__production_attibuted_actions2(user_ptr, 8);
                reduction_ocurred = 1;
                break;
            case 4:
                internal_parser__reduce(parser, 8);
                ulisp__post_reduce_action1(user_ptr, 8);
                ulisp__production_attibuted_actions2(user_ptr, 8);
                reduction_ocurred = 1;
                break;
            case 5:
                internal_parser__reduce(parser, 8);
                ulisp__post_reduce_action1(user_ptr, 8);
                ulisp__production_attibuted_actions2(user_ptr, 8);
                reduction_ocurred = 1;
                break;
            case 6:
                internal_parser__reduce(parser, 8);
                ulisp__post_reduce_action1(user_ptr, 8);
                ulisp__production_attibuted_actions2(user_ptr, 8);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 8);
                ulisp__post_reduce_action1(user_ptr, 8);
                ulisp__production_attibuted_actions2(user_ptr, 8);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = ulisp__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        ulisp__post_state_action1(user_ptr);
        break;
    case 7:
        ulisp__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                internal_parser__reduce(parser, 9);
                ulisp__post_reduce_action1(user_ptr, 9);
                ulisp__production_attibuted_actions2(user_ptr, 9);
                reduction_ocurred = 1;
                break;
            case 3:
                internal_parser__reduce(parser, 9);
                ulisp__post_reduce_action1(user_ptr, 9);
                ulisp__production_attibuted_actions2(user_ptr, 9);
                reduction_ocurred = 1;
                break;
            case 4:
                internal_parser__reduce(parser, 9);
                ulisp__post_reduce_action1(user_ptr, 9);
                ulisp__production_attibuted_actions2(user_ptr, 9);
                reduction_ocurred = 1;
                break;
            case 5:
                internal_parser__reduce(parser, 9);
                ulisp__post_reduce_action1(user_ptr, 9);
                ulisp__production_attibuted_actions2(user_ptr, 9);
                reduction_ocurred = 1;
                break;
            case 6:
                internal_parser__reduce(parser, 9);
                ulisp__post_reduce_action1(user_ptr, 9);
                ulisp__production_attibuted_actions2(user_ptr, 9);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 9);
                ulisp__post_reduce_action1(user_ptr, 9);
                ulisp__production_attibuted_actions2(user_ptr, 9);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = ulisp__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        ulisp__post_state_action1(user_ptr);
        break;
    case 8:
        ulisp__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                internal_parser__reduce(parser, 10);
                ulisp__post_reduce_action1(user_ptr, 10);
                ulisp__production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            case 3:
                internal_parser__reduce(parser, 10);
                ulisp__post_reduce_action1(user_ptr, 10);
                ulisp__production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            case 4:
                internal_parser__reduce(parser, 10);
                ulisp__post_reduce_action1(user_ptr, 10);
                ulisp__production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            case 5:
                internal_parser__reduce(parser, 10);
                ulisp__post_reduce_action1(user_ptr, 10);
                ulisp__production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            case 6:
                internal_parser__reduce(parser, 10);
                ulisp__post_reduce_action1(user_ptr, 10);
                ulisp__production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 10);
                ulisp__post_reduce_action1(user_ptr, 10);
                ulisp__production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = ulisp__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        ulisp__post_state_action1(user_ptr);
        break;
    case 9:
        ulisp__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 3:
                ulisp__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 12);
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = ulisp__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        ulisp__post_state_action1(user_ptr);
        break;
    case 10:
        ulisp__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                ulisp__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 1);
                break;
            case 3:
                internal_parser__reduce(parser, 5);
                ulisp__post_reduce_action1(user_ptr, 5);
                ulisp__production_attibuted_actions2(user_ptr, 5);
                reduction_ocurred = 1;
                break;
            case 4:
                ulisp__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 4);
                break;
            case 5:
                ulisp__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 5);
                break;
            case 6:
                ulisp__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 6);
                break;
            case 7:
                ulisp__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 7);
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = ulisp__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        ulisp__post_state_action1(user_ptr);
        break;
    case 11:
        ulisp__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                internal_parser__reduce(parser, 1);
                ulisp__post_reduce_action1(user_ptr, 1);
                ulisp__production_attibuted_actions2(user_ptr, 1);
                reduction_ocurred = 1;
                break;
            case 3:
                internal_parser__reduce(parser, 1);
                ulisp__post_reduce_action1(user_ptr, 1);
                ulisp__production_attibuted_actions2(user_ptr, 1);
                reduction_ocurred = 1;
                break;
            case 4:
                internal_parser__reduce(parser, 1);
                ulisp__post_reduce_action1(user_ptr, 1);
                ulisp__production_attibuted_actions2(user_ptr, 1);
                reduction_ocurred = 1;
                break;
            case 5:
                internal_parser__reduce(parser, 1);
                ulisp__post_reduce_action1(user_ptr, 1);
                ulisp__production_attibuted_actions2(user_ptr, 1);
                reduction_ocurred = 1;
                break;
            case 6:
                internal_parser__reduce(parser, 1);
                ulisp__post_reduce_action1(user_ptr, 1);
                ulisp__production_attibuted_actions2(user_ptr, 1);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 1);
                ulisp__post_reduce_action1(user_ptr, 1);
                ulisp__production_attibuted_actions2(user_ptr, 1);
                reduction_ocurred = 1;
                break;
            case 8:
                internal_parser__reduce(parser, 1);
                ulisp__post_reduce_action1(user_ptr, 1);
                ulisp__production_attibuted_actions2(user_ptr, 1);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = ulisp__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        ulisp__post_state_action1(user_ptr);
        break;
    case 12:
        ulisp__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                internal_parser__reduce(parser, 3);
                ulisp__post_reduce_action1(user_ptr, 3);
                ulisp__production_attibuted_actions2(user_ptr, 3);
                reduction_ocurred = 1;
                break;
            case 3:
                internal_parser__reduce(parser, 3);
                ulisp__post_reduce_action1(user_ptr, 3);
                ulisp__production_attibuted_actions2(user_ptr, 3);
                reduction_ocurred = 1;
                break;
            case 4:
                internal_parser__reduce(parser, 3);
                ulisp__post_reduce_action1(user_ptr, 3);
                ulisp__production_attibuted_actions2(user_ptr, 3);
                reduction_ocurred = 1;
                break;
            case 5:
                internal_parser__reduce(parser, 3);
                ulisp__post_reduce_action1(user_ptr, 3);
                ulisp__production_attibuted_actions2(user_ptr, 3);
                reduction_ocurred = 1;
                break;
            case 6:
                internal_parser__reduce(parser, 3);
                ulisp__post_reduce_action1(user_ptr, 3);
                ulisp__production_attibuted_actions2(user_ptr, 3);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 3);
                ulisp__post_reduce_action1(user_ptr, 3);
                ulisp__production_attibuted_actions2(user_ptr, 3);
                reduction_ocurred = 1;
                break;
            case 8:
                internal_parser__reduce(parser, 3);
                ulisp__post_reduce_action1(user_ptr, 3);
                ulisp__production_attibuted_actions2(user_ptr, 3);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = ulisp__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        ulisp__post_state_action1(user_ptr);
        break;
    case 13:
        ulisp__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 3:
                internal_parser__reduce(parser, 4);
                ulisp__post_reduce_action1(user_ptr, 4);
                ulisp__production_attibuted_actions2(user_ptr, 4);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = ulisp__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        ulisp__post_state_action1(user_ptr);
        break;
    }
}
