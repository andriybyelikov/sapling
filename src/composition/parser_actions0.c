/* This file was automatically generated. */

#include <libsapling/cc/parse_tree.h>
#include "aux/state_stack.h"
#include "aux/parse_tree_stack.h"
#include "data.h"
#include "composition/parser_actions.h"
#include "composition/composition_parser.h"

int composition__get_grammar_symbol_index_from_string(const char *str);

static
void parser_goto(node_t *state_stack, int gsym)
{
    internal_parser_t parser = get_composition_parser();

    switch (state_stack__access(state_stack)) {
    case 0:
        switch (gsym) {
        case 6:
            state_stack__insert(state_stack, 2);
            break;
        case 7:
            state_stack__insert(state_stack, 3);
            break;
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 1:
        switch (gsym) {
        case 8:
            state_stack__insert(state_stack, 5);
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
        case 6:
            state_stack__insert(state_stack, 6);
            break;
        case 7:
            state_stack__insert(state_stack, 3);
            break;
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 4:
        switch (gsym) {
        case 8:
            state_stack__insert(state_stack, 7);
            break;
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
    default:
        internal_parser__error(state_stack__access(state_stack));
        break;
    }
}

void composition__parser_actions0(void *user_ptr, node_t *state_stack, terminal_t terminal)
{
    internal_parser_t parser = get_composition_parser();

    struct data_common *user = user_ptr;
    node_t *parse_tree_stack = &user->parse_tree_stack;

    int state = state_stack__access(state_stack);
    switch (state) {
    case 0:
        composition__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                composition__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 1);
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = composition__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        composition__post_state_action1(user_ptr);
        break;
    case 1:
        composition__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                composition__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 4);
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = composition__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        composition__post_state_action1(user_ptr);
        break;
    case 2:
        composition__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 4:
                internal_parser__reduce(parser, 0);
                composition__post_reduce_action1(user_ptr, 0);
                composition__production_attibuted_actions2(user_ptr, 0);
                internal_parser__accept(parser);
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = composition__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        composition__post_state_action1(user_ptr);
        break;
    case 3:
        composition__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                composition__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 1);
                break;
            case 4:
                internal_parser__reduce(parser, 2);
                composition__post_reduce_action1(user_ptr, 2);
                composition__production_attibuted_actions2(user_ptr, 2);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = composition__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        composition__post_state_action1(user_ptr);
        break;
    case 4:
        composition__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                composition__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 4);
                break;
            case 3:
                internal_parser__reduce(parser, 5);
                composition__post_reduce_action1(user_ptr, 5);
                composition__production_attibuted_actions2(user_ptr, 5);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = composition__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        composition__post_state_action1(user_ptr);
        break;
    case 5:
        composition__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 3:
                composition__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 8);
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = composition__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        composition__post_state_action1(user_ptr);
        break;
    case 6:
        composition__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 4:
                internal_parser__reduce(parser, 1);
                composition__post_reduce_action1(user_ptr, 1);
                composition__production_attibuted_actions2(user_ptr, 1);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = composition__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        composition__post_state_action1(user_ptr);
        break;
    case 7:
        composition__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 3:
                internal_parser__reduce(parser, 4);
                composition__post_reduce_action1(user_ptr, 4);
                composition__production_attibuted_actions2(user_ptr, 4);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = composition__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        composition__post_state_action1(user_ptr);
        break;
    case 8:
        composition__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                internal_parser__reduce(parser, 3);
                composition__post_reduce_action1(user_ptr, 3);
                composition__production_attibuted_actions2(user_ptr, 3);
                reduction_ocurred = 1;
                break;
            case 4:
                internal_parser__reduce(parser, 3);
                composition__post_reduce_action1(user_ptr, 3);
                composition__production_attibuted_actions2(user_ptr, 3);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = composition__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        composition__post_state_action1(user_ptr);
        break;
    }
}
