#include <libsapling/dm/stack.h>
#include <libsapling/cc/terminal.h>
#include <libsapling/cc/parse_tree.h>
#include "parser_actions.h"
#include "parse_tree_stack.h"
#include "state_stack.h"
#include "autogen_terminals.h"
#include "autogen_productions.h"
#include "mangen_combined_ids.h"
#include "mangen_user_data.h"

static
void parser_goto(node_t *state_stack, int A)
{
    switch (state_stack__access(state_stack)) {
    case 0:
        switch (A) {
        case 16:
            state_stack__insert(state_stack, 2);
            break;
        case 17:
            state_stack__insert(state_stack, 3);
            break;
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 1:
        switch (A) {
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 2:
        switch (A) {
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 3:
        switch (A) {
        case 16:
            state_stack__insert(state_stack, 5);
            break;
        case 17:
            state_stack__insert(state_stack, 3);
            break;
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 4:
        switch (A) {
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
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 5:
        switch (A) {
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 6:
        switch (A) {
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 7:
        switch (A) {
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
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 8:
        switch (A) {
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 9:
        switch (A) {
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 10:
        switch (A) {
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 11:
        switch (A) {
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 12:
        switch (A) {
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 13:
        switch (A) {
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 14:
        switch (A) {
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
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 15:
        switch (A) {
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 16:
        switch (A) {
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 17:
        switch (A) {
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 18:
        switch (A) {
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 19:
        switch (A) {
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 20:
        switch (A) {
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
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 21:
        switch (A) {
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 22:
        switch (A) {
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 23:
        switch (A) {
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 24:
        switch (A) {
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 25:
        switch (A) {
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    case 26:
        switch (A) {
        default:
            error(state_stack__access(state_stack));
            break;
        }
        break;
    default:
        error(state_stack__access(state_stack));
        break;
    }
}

void parser_actions0(void *user_ptr, node_t *state_stack, terminal_t terminal)
{
    struct user *user = user_ptr;
    node_t *parse_tree_stack = &user->parse_tree_stack;

    int state = state_stack__access(state_stack);
    switch (state) {
    case 0:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 10:
                pre_shift_action1(user_ptr, terminal);
                shift(1);
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 1:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 4:
                pre_shift_action1(user_ptr, terminal);
                shift(4);
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 2:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 14:
                reduce(0);
                post_reduce_action1(user_ptr, 0);
                production_attibuted_actions2(user_ptr, 0);
                accept();
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 3:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 10:
                pre_shift_action1(user_ptr, terminal);
                shift(1);
                break;
            case 14:
                reduce(2);
                post_reduce_action1(user_ptr, 2);
                production_attibuted_actions2(user_ptr, 2);
                reduction_ocurred = 1;
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 4:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 5:
                pre_shift_action1(user_ptr, terminal);
                shift(6);
                break;
            case 8:
                pre_shift_action1(user_ptr, terminal);
                shift(7);
                break;
            case 10:
                pre_shift_action1(user_ptr, terminal);
                shift(8);
                break;
            case 11:
                pre_shift_action1(user_ptr, terminal);
                shift(9);
                break;
            case 12:
                pre_shift_action1(user_ptr, terminal);
                shift(10);
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 5:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 14:
                reduce(1);
                post_reduce_action1(user_ptr, 1);
                production_attibuted_actions2(user_ptr, 1);
                reduction_ocurred = 1;
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 6:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                reduce(18);
                post_reduce_action1(user_ptr, 18);
                production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            case 3:
                reduce(18);
                post_reduce_action1(user_ptr, 18);
                production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            case 5:
                reduce(18);
                post_reduce_action1(user_ptr, 18);
                production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            case 6:
                reduce(18);
                post_reduce_action1(user_ptr, 18);
                production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            case 7:
                reduce(18);
                post_reduce_action1(user_ptr, 18);
                production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            case 8:
                reduce(18);
                post_reduce_action1(user_ptr, 18);
                production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            case 9:
                reduce(18);
                post_reduce_action1(user_ptr, 18);
                production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            case 10:
                reduce(18);
                post_reduce_action1(user_ptr, 18);
                production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            case 11:
                reduce(18);
                post_reduce_action1(user_ptr, 18);
                production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            case 12:
                reduce(18);
                post_reduce_action1(user_ptr, 18);
                production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            case 13:
                reduce(18);
                post_reduce_action1(user_ptr, 18);
                production_attibuted_actions2(user_ptr, 18);
                reduction_ocurred = 1;
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 7:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 5:
                pre_shift_action1(user_ptr, terminal);
                shift(6);
                break;
            case 8:
                pre_shift_action1(user_ptr, terminal);
                shift(7);
                break;
            case 10:
                pre_shift_action1(user_ptr, terminal);
                shift(8);
                break;
            case 11:
                pre_shift_action1(user_ptr, terminal);
                shift(9);
                break;
            case 12:
                pre_shift_action1(user_ptr, terminal);
                shift(10);
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 8:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                reduce(15);
                post_reduce_action1(user_ptr, 15);
                production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            case 3:
                reduce(15);
                post_reduce_action1(user_ptr, 15);
                production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            case 5:
                reduce(15);
                post_reduce_action1(user_ptr, 15);
                production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            case 6:
                reduce(15);
                post_reduce_action1(user_ptr, 15);
                production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            case 7:
                reduce(15);
                post_reduce_action1(user_ptr, 15);
                production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            case 8:
                reduce(15);
                post_reduce_action1(user_ptr, 15);
                production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            case 9:
                reduce(15);
                post_reduce_action1(user_ptr, 15);
                production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            case 10:
                reduce(15);
                post_reduce_action1(user_ptr, 15);
                production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            case 11:
                reduce(15);
                post_reduce_action1(user_ptr, 15);
                production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            case 12:
                reduce(15);
                post_reduce_action1(user_ptr, 15);
                production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            case 13:
                reduce(15);
                post_reduce_action1(user_ptr, 15);
                production_attibuted_actions2(user_ptr, 15);
                reduction_ocurred = 1;
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 9:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                reduce(16);
                post_reduce_action1(user_ptr, 16);
                production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            case 3:
                reduce(16);
                post_reduce_action1(user_ptr, 16);
                production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            case 5:
                reduce(16);
                post_reduce_action1(user_ptr, 16);
                production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            case 6:
                reduce(16);
                post_reduce_action1(user_ptr, 16);
                production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            case 7:
                reduce(16);
                post_reduce_action1(user_ptr, 16);
                production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            case 8:
                reduce(16);
                post_reduce_action1(user_ptr, 16);
                production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            case 9:
                reduce(16);
                post_reduce_action1(user_ptr, 16);
                production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            case 10:
                reduce(16);
                post_reduce_action1(user_ptr, 16);
                production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            case 11:
                reduce(16);
                post_reduce_action1(user_ptr, 16);
                production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            case 12:
                reduce(16);
                post_reduce_action1(user_ptr, 16);
                production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            case 13:
                reduce(16);
                post_reduce_action1(user_ptr, 16);
                production_attibuted_actions2(user_ptr, 16);
                reduction_ocurred = 1;
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 10:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                reduce(17);
                post_reduce_action1(user_ptr, 17);
                production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            case 3:
                reduce(17);
                post_reduce_action1(user_ptr, 17);
                production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            case 5:
                reduce(17);
                post_reduce_action1(user_ptr, 17);
                production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            case 6:
                reduce(17);
                post_reduce_action1(user_ptr, 17);
                production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            case 7:
                reduce(17);
                post_reduce_action1(user_ptr, 17);
                production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            case 8:
                reduce(17);
                post_reduce_action1(user_ptr, 17);
                production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            case 9:
                reduce(17);
                post_reduce_action1(user_ptr, 17);
                production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            case 10:
                reduce(17);
                post_reduce_action1(user_ptr, 17);
                production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            case 11:
                reduce(17);
                post_reduce_action1(user_ptr, 17);
                production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            case 12:
                reduce(17);
                post_reduce_action1(user_ptr, 17);
                production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            case 13:
                reduce(17);
                post_reduce_action1(user_ptr, 17);
                production_attibuted_actions2(user_ptr, 17);
                reduction_ocurred = 1;
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 11:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 6:
                pre_shift_action1(user_ptr, terminal);
                shift(19);
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 12:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 6:
                reduce(5);
                post_reduce_action1(user_ptr, 5);
                production_attibuted_actions2(user_ptr, 5);
                reduction_ocurred = 1;
                break;
            case 7:
                pre_shift_action1(user_ptr, terminal);
                shift(20);
                break;
            case 9:
                reduce(5);
                post_reduce_action1(user_ptr, 5);
                production_attibuted_actions2(user_ptr, 5);
                reduction_ocurred = 1;
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 13:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 6:
                reduce(7);
                post_reduce_action1(user_ptr, 7);
                production_attibuted_actions2(user_ptr, 7);
                reduction_ocurred = 1;
                break;
            case 7:
                reduce(7);
                post_reduce_action1(user_ptr, 7);
                production_attibuted_actions2(user_ptr, 7);
                reduction_ocurred = 1;
                break;
            case 9:
                reduce(7);
                post_reduce_action1(user_ptr, 7);
                production_attibuted_actions2(user_ptr, 7);
                reduction_ocurred = 1;
                break;
            case 13:
                pre_shift_action1(user_ptr, terminal);
                shift(21);
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 14:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 5:
                pre_shift_action1(user_ptr, terminal);
                shift(6);
                break;
            case 6:
                reduce(9);
                post_reduce_action1(user_ptr, 9);
                production_attibuted_actions2(user_ptr, 9);
                reduction_ocurred = 1;
                break;
            case 7:
                reduce(9);
                post_reduce_action1(user_ptr, 9);
                production_attibuted_actions2(user_ptr, 9);
                reduction_ocurred = 1;
                break;
            case 8:
                pre_shift_action1(user_ptr, terminal);
                shift(7);
                break;
            case 9:
                reduce(9);
                post_reduce_action1(user_ptr, 9);
                production_attibuted_actions2(user_ptr, 9);
                reduction_ocurred = 1;
                break;
            case 10:
                pre_shift_action1(user_ptr, terminal);
                shift(8);
                break;
            case 11:
                pre_shift_action1(user_ptr, terminal);
                shift(9);
                break;
            case 12:
                pre_shift_action1(user_ptr, terminal);
                shift(10);
                break;
            case 13:
                reduce(9);
                post_reduce_action1(user_ptr, 9);
                production_attibuted_actions2(user_ptr, 9);
                reduction_ocurred = 1;
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 15:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 5:
                reduce(10);
                post_reduce_action1(user_ptr, 10);
                production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            case 6:
                reduce(10);
                post_reduce_action1(user_ptr, 10);
                production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            case 7:
                reduce(10);
                post_reduce_action1(user_ptr, 10);
                production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            case 8:
                reduce(10);
                post_reduce_action1(user_ptr, 10);
                production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            case 9:
                reduce(10);
                post_reduce_action1(user_ptr, 10);
                production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            case 10:
                reduce(10);
                post_reduce_action1(user_ptr, 10);
                production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            case 11:
                reduce(10);
                post_reduce_action1(user_ptr, 10);
                production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            case 12:
                reduce(10);
                post_reduce_action1(user_ptr, 10);
                production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            case 13:
                reduce(10);
                post_reduce_action1(user_ptr, 10);
                production_attibuted_actions2(user_ptr, 10);
                reduction_ocurred = 1;
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 16:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 5:
                reduce(11);
                post_reduce_action1(user_ptr, 11);
                production_attibuted_actions2(user_ptr, 11);
                reduction_ocurred = 1;
                break;
            case 6:
                reduce(11);
                post_reduce_action1(user_ptr, 11);
                production_attibuted_actions2(user_ptr, 11);
                reduction_ocurred = 1;
                break;
            case 7:
                reduce(11);
                post_reduce_action1(user_ptr, 11);
                production_attibuted_actions2(user_ptr, 11);
                reduction_ocurred = 1;
                break;
            case 8:
                reduce(11);
                post_reduce_action1(user_ptr, 11);
                production_attibuted_actions2(user_ptr, 11);
                reduction_ocurred = 1;
                break;
            case 9:
                reduce(11);
                post_reduce_action1(user_ptr, 11);
                production_attibuted_actions2(user_ptr, 11);
                reduction_ocurred = 1;
                break;
            case 10:
                reduce(11);
                post_reduce_action1(user_ptr, 11);
                production_attibuted_actions2(user_ptr, 11);
                reduction_ocurred = 1;
                break;
            case 11:
                reduce(11);
                post_reduce_action1(user_ptr, 11);
                production_attibuted_actions2(user_ptr, 11);
                reduction_ocurred = 1;
                break;
            case 12:
                reduce(11);
                post_reduce_action1(user_ptr, 11);
                production_attibuted_actions2(user_ptr, 11);
                reduction_ocurred = 1;
                break;
            case 13:
                reduce(11);
                post_reduce_action1(user_ptr, 11);
                production_attibuted_actions2(user_ptr, 11);
                reduction_ocurred = 1;
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 17:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                pre_shift_action1(user_ptr, terminal);
                shift(23);
                break;
            case 3:
                pre_shift_action1(user_ptr, terminal);
                shift(24);
                break;
            case 5:
                reduce(12);
                post_reduce_action1(user_ptr, 12);
                production_attibuted_actions2(user_ptr, 12);
                reduction_ocurred = 1;
                break;
            case 6:
                reduce(12);
                post_reduce_action1(user_ptr, 12);
                production_attibuted_actions2(user_ptr, 12);
                reduction_ocurred = 1;
                break;
            case 7:
                reduce(12);
                post_reduce_action1(user_ptr, 12);
                production_attibuted_actions2(user_ptr, 12);
                reduction_ocurred = 1;
                break;
            case 8:
                reduce(12);
                post_reduce_action1(user_ptr, 12);
                production_attibuted_actions2(user_ptr, 12);
                reduction_ocurred = 1;
                break;
            case 9:
                reduce(12);
                post_reduce_action1(user_ptr, 12);
                production_attibuted_actions2(user_ptr, 12);
                reduction_ocurred = 1;
                break;
            case 10:
                reduce(12);
                post_reduce_action1(user_ptr, 12);
                production_attibuted_actions2(user_ptr, 12);
                reduction_ocurred = 1;
                break;
            case 11:
                reduce(12);
                post_reduce_action1(user_ptr, 12);
                production_attibuted_actions2(user_ptr, 12);
                reduction_ocurred = 1;
                break;
            case 12:
                reduce(12);
                post_reduce_action1(user_ptr, 12);
                production_attibuted_actions2(user_ptr, 12);
                reduction_ocurred = 1;
                break;
            case 13:
                reduce(12);
                post_reduce_action1(user_ptr, 12);
                production_attibuted_actions2(user_ptr, 12);
                reduction_ocurred = 1;
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 18:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 9:
                pre_shift_action1(user_ptr, terminal);
                shift(25);
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 19:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 10:
                reduce(3);
                post_reduce_action1(user_ptr, 3);
                production_attibuted_actions2(user_ptr, 3);
                reduction_ocurred = 1;
                break;
            case 14:
                reduce(3);
                post_reduce_action1(user_ptr, 3);
                production_attibuted_actions2(user_ptr, 3);
                reduction_ocurred = 1;
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 20:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 5:
                pre_shift_action1(user_ptr, terminal);
                shift(6);
                break;
            case 8:
                pre_shift_action1(user_ptr, terminal);
                shift(7);
                break;
            case 10:
                pre_shift_action1(user_ptr, terminal);
                shift(8);
                break;
            case 11:
                pre_shift_action1(user_ptr, terminal);
                shift(9);
                break;
            case 12:
                pre_shift_action1(user_ptr, terminal);
                shift(10);
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 21:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 6:
                reduce(6);
                post_reduce_action1(user_ptr, 6);
                production_attibuted_actions2(user_ptr, 6);
                reduction_ocurred = 1;
                break;
            case 7:
                reduce(6);
                post_reduce_action1(user_ptr, 6);
                production_attibuted_actions2(user_ptr, 6);
                reduction_ocurred = 1;
                break;
            case 9:
                reduce(6);
                post_reduce_action1(user_ptr, 6);
                production_attibuted_actions2(user_ptr, 6);
                reduction_ocurred = 1;
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 22:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 6:
                reduce(8);
                post_reduce_action1(user_ptr, 8);
                production_attibuted_actions2(user_ptr, 8);
                reduction_ocurred = 1;
                break;
            case 7:
                reduce(8);
                post_reduce_action1(user_ptr, 8);
                production_attibuted_actions2(user_ptr, 8);
                reduction_ocurred = 1;
                break;
            case 9:
                reduce(8);
                post_reduce_action1(user_ptr, 8);
                production_attibuted_actions2(user_ptr, 8);
                reduction_ocurred = 1;
                break;
            case 13:
                reduce(8);
                post_reduce_action1(user_ptr, 8);
                production_attibuted_actions2(user_ptr, 8);
                reduction_ocurred = 1;
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 23:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 5:
                reduce(13);
                post_reduce_action1(user_ptr, 13);
                production_attibuted_actions2(user_ptr, 13);
                reduction_ocurred = 1;
                break;
            case 6:
                reduce(13);
                post_reduce_action1(user_ptr, 13);
                production_attibuted_actions2(user_ptr, 13);
                reduction_ocurred = 1;
                break;
            case 7:
                reduce(13);
                post_reduce_action1(user_ptr, 13);
                production_attibuted_actions2(user_ptr, 13);
                reduction_ocurred = 1;
                break;
            case 8:
                reduce(13);
                post_reduce_action1(user_ptr, 13);
                production_attibuted_actions2(user_ptr, 13);
                reduction_ocurred = 1;
                break;
            case 9:
                reduce(13);
                post_reduce_action1(user_ptr, 13);
                production_attibuted_actions2(user_ptr, 13);
                reduction_ocurred = 1;
                break;
            case 10:
                reduce(13);
                post_reduce_action1(user_ptr, 13);
                production_attibuted_actions2(user_ptr, 13);
                reduction_ocurred = 1;
                break;
            case 11:
                reduce(13);
                post_reduce_action1(user_ptr, 13);
                production_attibuted_actions2(user_ptr, 13);
                reduction_ocurred = 1;
                break;
            case 12:
                reduce(13);
                post_reduce_action1(user_ptr, 13);
                production_attibuted_actions2(user_ptr, 13);
                reduction_ocurred = 1;
                break;
            case 13:
                reduce(13);
                post_reduce_action1(user_ptr, 13);
                production_attibuted_actions2(user_ptr, 13);
                reduction_ocurred = 1;
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 24:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 5:
                reduce(14);
                post_reduce_action1(user_ptr, 14);
                production_attibuted_actions2(user_ptr, 14);
                reduction_ocurred = 1;
                break;
            case 6:
                reduce(14);
                post_reduce_action1(user_ptr, 14);
                production_attibuted_actions2(user_ptr, 14);
                reduction_ocurred = 1;
                break;
            case 7:
                reduce(14);
                post_reduce_action1(user_ptr, 14);
                production_attibuted_actions2(user_ptr, 14);
                reduction_ocurred = 1;
                break;
            case 8:
                reduce(14);
                post_reduce_action1(user_ptr, 14);
                production_attibuted_actions2(user_ptr, 14);
                reduction_ocurred = 1;
                break;
            case 9:
                reduce(14);
                post_reduce_action1(user_ptr, 14);
                production_attibuted_actions2(user_ptr, 14);
                reduction_ocurred = 1;
                break;
            case 10:
                reduce(14);
                post_reduce_action1(user_ptr, 14);
                production_attibuted_actions2(user_ptr, 14);
                reduction_ocurred = 1;
                break;
            case 11:
                reduce(14);
                post_reduce_action1(user_ptr, 14);
                production_attibuted_actions2(user_ptr, 14);
                reduction_ocurred = 1;
                break;
            case 12:
                reduce(14);
                post_reduce_action1(user_ptr, 14);
                production_attibuted_actions2(user_ptr, 14);
                reduction_ocurred = 1;
                break;
            case 13:
                reduce(14);
                post_reduce_action1(user_ptr, 14);
                production_attibuted_actions2(user_ptr, 14);
                reduction_ocurred = 1;
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 25:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 2:
                reduce(19);
                post_reduce_action1(user_ptr, 19);
                production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            case 3:
                reduce(19);
                post_reduce_action1(user_ptr, 19);
                production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            case 5:
                reduce(19);
                post_reduce_action1(user_ptr, 19);
                production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            case 6:
                reduce(19);
                post_reduce_action1(user_ptr, 19);
                production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            case 7:
                reduce(19);
                post_reduce_action1(user_ptr, 19);
                production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            case 8:
                reduce(19);
                post_reduce_action1(user_ptr, 19);
                production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            case 9:
                reduce(19);
                post_reduce_action1(user_ptr, 19);
                production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            case 10:
                reduce(19);
                post_reduce_action1(user_ptr, 19);
                production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            case 11:
                reduce(19);
                post_reduce_action1(user_ptr, 19);
                production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            case 12:
                reduce(19);
                post_reduce_action1(user_ptr, 19);
                production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            case 13:
                reduce(19);
                post_reduce_action1(user_ptr, 19);
                production_attibuted_actions2(user_ptr, 19);
                reduction_ocurred = 1;
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    case 26:
        pre_state_action1(user_ptr, state_stack);
        {
            int reduction_ocurred = 0;
            /* handle terminals (ACTION table) */
            switch (terminal__id(terminal)) {
            case 6:
                reduce(4);
                post_reduce_action1(user_ptr, 4);
                production_attibuted_actions2(user_ptr, 4);
                reduction_ocurred = 1;
                break;
            case 9:
                reduce(4);
                post_reduce_action1(user_ptr, 4);
                production_attibuted_actions2(user_ptr, 4);
                reduction_ocurred = 1;
                break;
            default:
                error(state_stack__access(state_stack));
                break;
            }
            /* handle nonterminals (GOTO table) */
            if (reduction_ocurred) {
                int A = psym_str_idx(
                    *parse_tree__data(parse_tree_stack__access(parse_tree_stack)));
                parser_goto(state_stack, A);
            }
        }
        post_state_action1(user_ptr);
        break;
    }
}
