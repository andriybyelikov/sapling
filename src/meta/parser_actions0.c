/* This file was automatically generated. */

#include <libsapling/cc/parse_tree.h>
#include "aux/state_stack.h"
#include "aux/parse_tree_stack.h"
#include "data.h"
#include "meta/parser_actions.h"
#include "meta/meta_parser.h"

int meta__get_grammar_symbol_index_from_string(const char *str);

static
void parser_goto(node_t *state_stack, int gsym)
{
    internal_parser_t parser = get_meta_parser();

    switch (state_stack__access(state_stack)) {
    case 0:
        switch (gsym) {
        case 16:
            state_stack__insert(state_stack, 2);
            break;
        case 17:
            state_stack__insert(state_stack, 3);
            break;
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 1:
        switch (gsym) {
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
        case 16:
            state_stack__insert(state_stack, 5);
            break;
        case 17:
            state_stack__insert(state_stack, 3);
            break;
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 4:
        switch (gsym) {
        case 18:
            state_stack__insert(state_stack, 11);
            break;
        case 19:
            state_stack__insert(state_stack, 12);
            break;
        case 20:
            state_stack__insert(state_stack, 13);
            break;
        case 21:
            state_stack__insert(state_stack, 14);
            break;
        case 22:
            state_stack__insert(state_stack, 15);
            break;
        case 23:
            state_stack__insert(state_stack, 16);
            break;
        case 24:
            state_stack__insert(state_stack, 17);
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
        case 18:
            state_stack__insert(state_stack, 18);
            break;
        case 19:
            state_stack__insert(state_stack, 12);
            break;
        case 20:
            state_stack__insert(state_stack, 13);
            break;
        case 21:
            state_stack__insert(state_stack, 14);
            break;
        case 22:
            state_stack__insert(state_stack, 15);
            break;
        case 23:
            state_stack__insert(state_stack, 16);
            break;
        case 24:
            state_stack__insert(state_stack, 17);
            break;
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
    case 14:
        switch (gsym) {
        case 20:
            state_stack__insert(state_stack, 22);
            break;
        case 21:
            state_stack__insert(state_stack, 14);
            break;
        case 22:
            state_stack__insert(state_stack, 15);
            break;
        case 23:
            state_stack__insert(state_stack, 16);
            break;
        case 24:
            state_stack__insert(state_stack, 17);
            break;
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 15:
        switch (gsym) {
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 16:
        switch (gsym) {
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 17:
        switch (gsym) {
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 18:
        switch (gsym) {
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 19:
        switch (gsym) {
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 20:
        switch (gsym) {
        case 18:
            state_stack__insert(state_stack, 26);
            break;
        case 19:
            state_stack__insert(state_stack, 12);
            break;
        case 20:
            state_stack__insert(state_stack, 13);
            break;
        case 21:
            state_stack__insert(state_stack, 14);
            break;
        case 22:
            state_stack__insert(state_stack, 15);
            break;
        case 23:
            state_stack__insert(state_stack, 16);
            break;
        case 24:
            state_stack__insert(state_stack, 17);
            break;
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 21:
        switch (gsym) {
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 22:
        switch (gsym) {
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 23:
        switch (gsym) {
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 24:
        switch (gsym) {
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 25:
        switch (gsym) {
        default:
            internal_parser__error(state_stack__access(state_stack));
            break;
        }
        break;
    case 26:
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

void meta__parser_actions0(void *user_ptr, node_t *state_stack, terminal_t terminal)
{
    internal_parser_t parser = get_meta_parser();

    struct data_common *user = user_ptr;
    node_t *parse_tree_stack = &user->parse_tree_stack;

    int state = state_stack__access(state_stack);
    switch (state) {
    case 0:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 10:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 1);
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 1:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 4:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 4);
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 2:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 14:
                internal_parser__reduce(parser, 0);
                meta__post_reduce_action1(user_ptr, 0);
                meta__production_attibuted_actions2(user_ptr, 0);
                internal_parser__accept(parser);
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 3:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 10:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 1);
                break;
            case 14:
                internal_parser__reduce(parser, 2);
                meta__post_reduce_action1(user_ptr, 2);
                meta__production_attibuted_actions2(user_ptr, 2);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 4:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 5:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 6);
                break;
            case 8:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 7);
                break;
            case 10:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 8);
                break;
            case 11:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 9);
                break;
            case 12:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 10);
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 5:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 14:
                internal_parser__reduce(parser, 1);
                meta__post_reduce_action1(user_ptr, 1);
                meta__production_attibuted_actions2(user_ptr, 1);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 6:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                internal_parser__reduce(parser, 18);
                meta__post_reduce_action1(user_ptr, 18);
                meta__production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            case 3:
                internal_parser__reduce(parser, 18);
                meta__post_reduce_action1(user_ptr, 18);
                meta__production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            case 5:
                internal_parser__reduce(parser, 18);
                meta__post_reduce_action1(user_ptr, 18);
                meta__production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            case 6:
                internal_parser__reduce(parser, 18);
                meta__post_reduce_action1(user_ptr, 18);
                meta__production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 18);
                meta__post_reduce_action1(user_ptr, 18);
                meta__production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            case 8:
                internal_parser__reduce(parser, 18);
                meta__post_reduce_action1(user_ptr, 18);
                meta__production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            case 9:
                internal_parser__reduce(parser, 18);
                meta__post_reduce_action1(user_ptr, 18);
                meta__production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            case 10:
                internal_parser__reduce(parser, 18);
                meta__post_reduce_action1(user_ptr, 18);
                meta__production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            case 11:
                internal_parser__reduce(parser, 18);
                meta__post_reduce_action1(user_ptr, 18);
                meta__production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            case 12:
                internal_parser__reduce(parser, 18);
                meta__post_reduce_action1(user_ptr, 18);
                meta__production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            case 13:
                internal_parser__reduce(parser, 18);
                meta__post_reduce_action1(user_ptr, 18);
                meta__production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 7:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 5:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 6);
                break;
            case 8:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 7);
                break;
            case 10:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 8);
                break;
            case 11:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 9);
                break;
            case 12:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 10);
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 8:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                internal_parser__reduce(parser, 15);
                meta__post_reduce_action1(user_ptr, 15);
                meta__production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            case 3:
                internal_parser__reduce(parser, 15);
                meta__post_reduce_action1(user_ptr, 15);
                meta__production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            case 5:
                internal_parser__reduce(parser, 15);
                meta__post_reduce_action1(user_ptr, 15);
                meta__production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            case 6:
                internal_parser__reduce(parser, 15);
                meta__post_reduce_action1(user_ptr, 15);
                meta__production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 15);
                meta__post_reduce_action1(user_ptr, 15);
                meta__production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            case 8:
                internal_parser__reduce(parser, 15);
                meta__post_reduce_action1(user_ptr, 15);
                meta__production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            case 9:
                internal_parser__reduce(parser, 15);
                meta__post_reduce_action1(user_ptr, 15);
                meta__production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            case 10:
                internal_parser__reduce(parser, 15);
                meta__post_reduce_action1(user_ptr, 15);
                meta__production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            case 11:
                internal_parser__reduce(parser, 15);
                meta__post_reduce_action1(user_ptr, 15);
                meta__production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            case 12:
                internal_parser__reduce(parser, 15);
                meta__post_reduce_action1(user_ptr, 15);
                meta__production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            case 13:
                internal_parser__reduce(parser, 15);
                meta__post_reduce_action1(user_ptr, 15);
                meta__production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 9:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                internal_parser__reduce(parser, 16);
                meta__post_reduce_action1(user_ptr, 16);
                meta__production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            case 3:
                internal_parser__reduce(parser, 16);
                meta__post_reduce_action1(user_ptr, 16);
                meta__production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            case 5:
                internal_parser__reduce(parser, 16);
                meta__post_reduce_action1(user_ptr, 16);
                meta__production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            case 6:
                internal_parser__reduce(parser, 16);
                meta__post_reduce_action1(user_ptr, 16);
                meta__production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 16);
                meta__post_reduce_action1(user_ptr, 16);
                meta__production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            case 8:
                internal_parser__reduce(parser, 16);
                meta__post_reduce_action1(user_ptr, 16);
                meta__production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            case 9:
                internal_parser__reduce(parser, 16);
                meta__post_reduce_action1(user_ptr, 16);
                meta__production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            case 10:
                internal_parser__reduce(parser, 16);
                meta__post_reduce_action1(user_ptr, 16);
                meta__production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            case 11:
                internal_parser__reduce(parser, 16);
                meta__post_reduce_action1(user_ptr, 16);
                meta__production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            case 12:
                internal_parser__reduce(parser, 16);
                meta__post_reduce_action1(user_ptr, 16);
                meta__production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            case 13:
                internal_parser__reduce(parser, 16);
                meta__post_reduce_action1(user_ptr, 16);
                meta__production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 10:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                internal_parser__reduce(parser, 17);
                meta__post_reduce_action1(user_ptr, 17);
                meta__production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            case 3:
                internal_parser__reduce(parser, 17);
                meta__post_reduce_action1(user_ptr, 17);
                meta__production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            case 5:
                internal_parser__reduce(parser, 17);
                meta__post_reduce_action1(user_ptr, 17);
                meta__production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            case 6:
                internal_parser__reduce(parser, 17);
                meta__post_reduce_action1(user_ptr, 17);
                meta__production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 17);
                meta__post_reduce_action1(user_ptr, 17);
                meta__production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            case 8:
                internal_parser__reduce(parser, 17);
                meta__post_reduce_action1(user_ptr, 17);
                meta__production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            case 9:
                internal_parser__reduce(parser, 17);
                meta__post_reduce_action1(user_ptr, 17);
                meta__production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            case 10:
                internal_parser__reduce(parser, 17);
                meta__post_reduce_action1(user_ptr, 17);
                meta__production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            case 11:
                internal_parser__reduce(parser, 17);
                meta__post_reduce_action1(user_ptr, 17);
                meta__production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            case 12:
                internal_parser__reduce(parser, 17);
                meta__post_reduce_action1(user_ptr, 17);
                meta__production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            case 13:
                internal_parser__reduce(parser, 17);
                meta__post_reduce_action1(user_ptr, 17);
                meta__production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 11:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 6:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 19);
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 12:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 6:
                internal_parser__reduce(parser, 5);
                meta__post_reduce_action1(user_ptr, 5);
                meta__production_attibuted_actions2(user_ptr, 5);
                reduction_ocurred = 1;
                break;
            case 7:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 20);
                break;
            case 9:
                internal_parser__reduce(parser, 5);
                meta__post_reduce_action1(user_ptr, 5);
                meta__production_attibuted_actions2(user_ptr, 5);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 13:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 6:
                internal_parser__reduce(parser, 7);
                meta__post_reduce_action1(user_ptr, 7);
                meta__production_attibuted_actions2(user_ptr, 7);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 7);
                meta__post_reduce_action1(user_ptr, 7);
                meta__production_attibuted_actions2(user_ptr, 7);
                reduction_ocurred = 1;
                break;
            case 9:
                internal_parser__reduce(parser, 7);
                meta__post_reduce_action1(user_ptr, 7);
                meta__production_attibuted_actions2(user_ptr, 7);
                reduction_ocurred = 1;
                break;
            case 13:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 21);
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 14:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 5:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 6);
                break;
            case 6:
                internal_parser__reduce(parser, 9);
                meta__post_reduce_action1(user_ptr, 9);
                meta__production_attibuted_actions2(user_ptr, 9);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 9);
                meta__post_reduce_action1(user_ptr, 9);
                meta__production_attibuted_actions2(user_ptr, 9);
                reduction_ocurred = 1;
                break;
            case 8:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 7);
                break;
            case 9:
                internal_parser__reduce(parser, 9);
                meta__post_reduce_action1(user_ptr, 9);
                meta__production_attibuted_actions2(user_ptr, 9);
                reduction_ocurred = 1;
                break;
            case 10:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 8);
                break;
            case 11:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 9);
                break;
            case 12:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 10);
                break;
            case 13:
                internal_parser__reduce(parser, 9);
                meta__post_reduce_action1(user_ptr, 9);
                meta__production_attibuted_actions2(user_ptr, 9);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 15:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 5:
                internal_parser__reduce(parser, 10);
                meta__post_reduce_action1(user_ptr, 10);
                meta__production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            case 6:
                internal_parser__reduce(parser, 10);
                meta__post_reduce_action1(user_ptr, 10);
                meta__production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 10);
                meta__post_reduce_action1(user_ptr, 10);
                meta__production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            case 8:
                internal_parser__reduce(parser, 10);
                meta__post_reduce_action1(user_ptr, 10);
                meta__production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            case 9:
                internal_parser__reduce(parser, 10);
                meta__post_reduce_action1(user_ptr, 10);
                meta__production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            case 10:
                internal_parser__reduce(parser, 10);
                meta__post_reduce_action1(user_ptr, 10);
                meta__production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            case 11:
                internal_parser__reduce(parser, 10);
                meta__post_reduce_action1(user_ptr, 10);
                meta__production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            case 12:
                internal_parser__reduce(parser, 10);
                meta__post_reduce_action1(user_ptr, 10);
                meta__production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            case 13:
                internal_parser__reduce(parser, 10);
                meta__post_reduce_action1(user_ptr, 10);
                meta__production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 16:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 5:
                internal_parser__reduce(parser, 11);
                meta__post_reduce_action1(user_ptr, 11);
                meta__production_attibuted_actions2(user_ptr, 11);
                reduction_ocurred = 1;
                break;
            case 6:
                internal_parser__reduce(parser, 11);
                meta__post_reduce_action1(user_ptr, 11);
                meta__production_attibuted_actions2(user_ptr, 11);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 11);
                meta__post_reduce_action1(user_ptr, 11);
                meta__production_attibuted_actions2(user_ptr, 11);
                reduction_ocurred = 1;
                break;
            case 8:
                internal_parser__reduce(parser, 11);
                meta__post_reduce_action1(user_ptr, 11);
                meta__production_attibuted_actions2(user_ptr, 11);
                reduction_ocurred = 1;
                break;
            case 9:
                internal_parser__reduce(parser, 11);
                meta__post_reduce_action1(user_ptr, 11);
                meta__production_attibuted_actions2(user_ptr, 11);
                reduction_ocurred = 1;
                break;
            case 10:
                internal_parser__reduce(parser, 11);
                meta__post_reduce_action1(user_ptr, 11);
                meta__production_attibuted_actions2(user_ptr, 11);
                reduction_ocurred = 1;
                break;
            case 11:
                internal_parser__reduce(parser, 11);
                meta__post_reduce_action1(user_ptr, 11);
                meta__production_attibuted_actions2(user_ptr, 11);
                reduction_ocurred = 1;
                break;
            case 12:
                internal_parser__reduce(parser, 11);
                meta__post_reduce_action1(user_ptr, 11);
                meta__production_attibuted_actions2(user_ptr, 11);
                reduction_ocurred = 1;
                break;
            case 13:
                internal_parser__reduce(parser, 11);
                meta__post_reduce_action1(user_ptr, 11);
                meta__production_attibuted_actions2(user_ptr, 11);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 17:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 23);
                break;
            case 3:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 24);
                break;
            case 5:
                internal_parser__reduce(parser, 12);
                meta__post_reduce_action1(user_ptr, 12);
                meta__production_attibuted_actions2(user_ptr, 12);
                reduction_ocurred = 1;
                break;
            case 6:
                internal_parser__reduce(parser, 12);
                meta__post_reduce_action1(user_ptr, 12);
                meta__production_attibuted_actions2(user_ptr, 12);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 12);
                meta__post_reduce_action1(user_ptr, 12);
                meta__production_attibuted_actions2(user_ptr, 12);
                reduction_ocurred = 1;
                break;
            case 8:
                internal_parser__reduce(parser, 12);
                meta__post_reduce_action1(user_ptr, 12);
                meta__production_attibuted_actions2(user_ptr, 12);
                reduction_ocurred = 1;
                break;
            case 9:
                internal_parser__reduce(parser, 12);
                meta__post_reduce_action1(user_ptr, 12);
                meta__production_attibuted_actions2(user_ptr, 12);
                reduction_ocurred = 1;
                break;
            case 10:
                internal_parser__reduce(parser, 12);
                meta__post_reduce_action1(user_ptr, 12);
                meta__production_attibuted_actions2(user_ptr, 12);
                reduction_ocurred = 1;
                break;
            case 11:
                internal_parser__reduce(parser, 12);
                meta__post_reduce_action1(user_ptr, 12);
                meta__production_attibuted_actions2(user_ptr, 12);
                reduction_ocurred = 1;
                break;
            case 12:
                internal_parser__reduce(parser, 12);
                meta__post_reduce_action1(user_ptr, 12);
                meta__production_attibuted_actions2(user_ptr, 12);
                reduction_ocurred = 1;
                break;
            case 13:
                internal_parser__reduce(parser, 12);
                meta__post_reduce_action1(user_ptr, 12);
                meta__production_attibuted_actions2(user_ptr, 12);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 18:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 9:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 25);
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 19:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 10:
                internal_parser__reduce(parser, 3);
                meta__post_reduce_action1(user_ptr, 3);
                meta__production_attibuted_actions2(user_ptr, 3);
                reduction_ocurred = 1;
                break;
            case 14:
                internal_parser__reduce(parser, 3);
                meta__post_reduce_action1(user_ptr, 3);
                meta__production_attibuted_actions2(user_ptr, 3);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 20:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 5:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 6);
                break;
            case 8:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 7);
                break;
            case 10:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 8);
                break;
            case 11:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 9);
                break;
            case 12:
                meta__pre_shift_action1(user_ptr, terminal);
                internal_parser__shift(parser, 10);
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 21:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 6:
                internal_parser__reduce(parser, 6);
                meta__post_reduce_action1(user_ptr, 6);
                meta__production_attibuted_actions2(user_ptr, 6);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 6);
                meta__post_reduce_action1(user_ptr, 6);
                meta__production_attibuted_actions2(user_ptr, 6);
                reduction_ocurred = 1;
                break;
            case 9:
                internal_parser__reduce(parser, 6);
                meta__post_reduce_action1(user_ptr, 6);
                meta__production_attibuted_actions2(user_ptr, 6);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 22:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 6:
                internal_parser__reduce(parser, 8);
                meta__post_reduce_action1(user_ptr, 8);
                meta__production_attibuted_actions2(user_ptr, 8);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 8);
                meta__post_reduce_action1(user_ptr, 8);
                meta__production_attibuted_actions2(user_ptr, 8);
                reduction_ocurred = 1;
                break;
            case 9:
                internal_parser__reduce(parser, 8);
                meta__post_reduce_action1(user_ptr, 8);
                meta__production_attibuted_actions2(user_ptr, 8);
                reduction_ocurred = 1;
                break;
            case 13:
                internal_parser__reduce(parser, 8);
                meta__post_reduce_action1(user_ptr, 8);
                meta__production_attibuted_actions2(user_ptr, 8);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 23:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 5:
                internal_parser__reduce(parser, 13);
                meta__post_reduce_action1(user_ptr, 13);
                meta__production_attibuted_actions2(user_ptr, 13);
                reduction_ocurred = 1;
                break;
            case 6:
                internal_parser__reduce(parser, 13);
                meta__post_reduce_action1(user_ptr, 13);
                meta__production_attibuted_actions2(user_ptr, 13);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 13);
                meta__post_reduce_action1(user_ptr, 13);
                meta__production_attibuted_actions2(user_ptr, 13);
                reduction_ocurred = 1;
                break;
            case 8:
                internal_parser__reduce(parser, 13);
                meta__post_reduce_action1(user_ptr, 13);
                meta__production_attibuted_actions2(user_ptr, 13);
                reduction_ocurred = 1;
                break;
            case 9:
                internal_parser__reduce(parser, 13);
                meta__post_reduce_action1(user_ptr, 13);
                meta__production_attibuted_actions2(user_ptr, 13);
                reduction_ocurred = 1;
                break;
            case 10:
                internal_parser__reduce(parser, 13);
                meta__post_reduce_action1(user_ptr, 13);
                meta__production_attibuted_actions2(user_ptr, 13);
                reduction_ocurred = 1;
                break;
            case 11:
                internal_parser__reduce(parser, 13);
                meta__post_reduce_action1(user_ptr, 13);
                meta__production_attibuted_actions2(user_ptr, 13);
                reduction_ocurred = 1;
                break;
            case 12:
                internal_parser__reduce(parser, 13);
                meta__post_reduce_action1(user_ptr, 13);
                meta__production_attibuted_actions2(user_ptr, 13);
                reduction_ocurred = 1;
                break;
            case 13:
                internal_parser__reduce(parser, 13);
                meta__post_reduce_action1(user_ptr, 13);
                meta__production_attibuted_actions2(user_ptr, 13);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 24:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 5:
                internal_parser__reduce(parser, 14);
                meta__post_reduce_action1(user_ptr, 14);
                meta__production_attibuted_actions2(user_ptr, 14);
                reduction_ocurred = 1;
                break;
            case 6:
                internal_parser__reduce(parser, 14);
                meta__post_reduce_action1(user_ptr, 14);
                meta__production_attibuted_actions2(user_ptr, 14);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 14);
                meta__post_reduce_action1(user_ptr, 14);
                meta__production_attibuted_actions2(user_ptr, 14);
                reduction_ocurred = 1;
                break;
            case 8:
                internal_parser__reduce(parser, 14);
                meta__post_reduce_action1(user_ptr, 14);
                meta__production_attibuted_actions2(user_ptr, 14);
                reduction_ocurred = 1;
                break;
            case 9:
                internal_parser__reduce(parser, 14);
                meta__post_reduce_action1(user_ptr, 14);
                meta__production_attibuted_actions2(user_ptr, 14);
                reduction_ocurred = 1;
                break;
            case 10:
                internal_parser__reduce(parser, 14);
                meta__post_reduce_action1(user_ptr, 14);
                meta__production_attibuted_actions2(user_ptr, 14);
                reduction_ocurred = 1;
                break;
            case 11:
                internal_parser__reduce(parser, 14);
                meta__post_reduce_action1(user_ptr, 14);
                meta__production_attibuted_actions2(user_ptr, 14);
                reduction_ocurred = 1;
                break;
            case 12:
                internal_parser__reduce(parser, 14);
                meta__post_reduce_action1(user_ptr, 14);
                meta__production_attibuted_actions2(user_ptr, 14);
                reduction_ocurred = 1;
                break;
            case 13:
                internal_parser__reduce(parser, 14);
                meta__post_reduce_action1(user_ptr, 14);
                meta__production_attibuted_actions2(user_ptr, 14);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 25:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                internal_parser__reduce(parser, 19);
                meta__post_reduce_action1(user_ptr, 19);
                meta__production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            case 3:
                internal_parser__reduce(parser, 19);
                meta__post_reduce_action1(user_ptr, 19);
                meta__production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            case 5:
                internal_parser__reduce(parser, 19);
                meta__post_reduce_action1(user_ptr, 19);
                meta__production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            case 6:
                internal_parser__reduce(parser, 19);
                meta__post_reduce_action1(user_ptr, 19);
                meta__production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            case 7:
                internal_parser__reduce(parser, 19);
                meta__post_reduce_action1(user_ptr, 19);
                meta__production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            case 8:
                internal_parser__reduce(parser, 19);
                meta__post_reduce_action1(user_ptr, 19);
                meta__production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            case 9:
                internal_parser__reduce(parser, 19);
                meta__post_reduce_action1(user_ptr, 19);
                meta__production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            case 10:
                internal_parser__reduce(parser, 19);
                meta__post_reduce_action1(user_ptr, 19);
                meta__production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            case 11:
                internal_parser__reduce(parser, 19);
                meta__post_reduce_action1(user_ptr, 19);
                meta__production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            case 12:
                internal_parser__reduce(parser, 19);
                meta__post_reduce_action1(user_ptr, 19);
                meta__production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            case 13:
                internal_parser__reduce(parser, 19);
                meta__post_reduce_action1(user_ptr, 19);
                meta__production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    case 26:
        meta__pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 6:
                internal_parser__reduce(parser, 4);
                meta__post_reduce_action1(user_ptr, 4);
                meta__production_attibuted_actions2(user_ptr, 4);
                reduction_ocurred = 1;
                break;
            case 9:
                internal_parser__reduce(parser, 4);
                meta__post_reduce_action1(user_ptr, 4);
                meta__production_attibuted_actions2(user_ptr, 4);
                reduction_ocurred = 1;
                break;
            default:
                internal_parser__error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int gsym = meta__get_grammar_symbol_index_from_string(
                    *parse_tree__data(parse_tree_stack__access(
                        parse_tree_stack)));
                parser_goto(state_stack, gsym);
            }
        }
        meta__post_state_action1(user_ptr);
        break;
    }
}
