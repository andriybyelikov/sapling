#include <libsapling/terminal.h>
#include <libsapling/typed_stack.h>
#include "parser_actions.h"
#include "mangen_terminals.h"
#include "mangen_productions.h"

define_typed_stack(int)

void parser_actions0(void *user_ptr, void **state_stack, void *terminal)
{
    int state = stack_int__access(state_stack);
    switch (state) {
    case 0:
        pre_state_action1(user_ptr, state_stack);
        switch (terminal__id(terminal)) {
        case t_symbol:
            pre_shift_action1(user_ptr, terminal);
            shift(10);
            break;
        default:
            error(stack_int__access(state_stack));
            break;
        }
        post_state_action1(user_ptr);
        break;
    case 10:
        pre_state_action1(user_ptr, state_stack);
        switch (terminal__id(terminal)) {
        case t_rightarrow:
            pre_shift_action1(user_ptr, terminal);
            shift(20);
            break;
        default:
            error(stack_int__access(state_stack));
            break;
        }
        post_state_action1(user_ptr);
        break;
    case 20:
        pre_state_action1(user_ptr, state_stack);
        switch (terminal__id(terminal)) {
        case t_symbol:
            pre_shift_action1(user_ptr, terminal);
            shift(30);
            break;
        case t_literal:
            pre_shift_action1(user_ptr, terminal);
            shift(31);
            break;
        case t_union:
            pre_shift_action1(user_ptr, terminal);
            shift(32);
            break;
        case t_any:
            pre_shift_action1(user_ptr, terminal);
            shift(33);
            break;
        case t_lpar:
            pre_shift_action1(user_ptr, terminal);
            shift(40);
            break;
        default:
            error(stack_int__access(state_stack));
            break;
        }
        post_state_action1(user_ptr);
        break;
    case 30:
        pre_state_action1(user_ptr, state_stack);
        {
            reduce(13);
            post_reduce_action1(user_ptr, 13);
            production_attibuted_actions2(user_ptr, 13);
            switch (stack_int__access(state_stack)) {
            case 20:
            case 40:
            case 100:
            case 130:
                stack_int__insert(state_stack, 50);
                break;
            default:
                error(stack_int__access(state_stack));
                break;
            }
        }
        post_state_action1(user_ptr);
        break;
    case 31:
        pre_state_action1(user_ptr, state_stack);
        {
            reduce(14);
            post_reduce_action1(user_ptr, 14);
            production_attibuted_actions2(user_ptr, 14);
            switch (stack_int__access(state_stack)) {
            case 20:
            case 40:
            case 100:
            case 130:
                stack_int__insert(state_stack, 50);
                break;
            default:
                error(stack_int__access(state_stack));
                break;
            }
        }
        post_state_action1(user_ptr);
        break;
    case 32:
        pre_state_action1(user_ptr, state_stack);
        {
            reduce(15);
            post_reduce_action1(user_ptr, 15);
            production_attibuted_actions2(user_ptr, 15);
            switch (stack_int__access(state_stack)) {
            case 20:
            case 40:
            case 100:
            case 130:
                stack_int__insert(state_stack, 50);
                break;
            default:
                error(stack_int__access(state_stack));
                break;
            }
        }
        post_state_action1(user_ptr);
        break;
    case 33:
        pre_state_action1(user_ptr, state_stack);
        {
            reduce(16);
            post_reduce_action1(user_ptr, 16);
            production_attibuted_actions2(user_ptr, 16);
            switch (stack_int__access(state_stack)) {
            case 20:
            case 40:
            case 100:
            case 130:
                stack_int__insert(state_stack, 50);
                break;
            default:
                error(stack_int__access(state_stack));
                break;
            }
        }
        post_state_action1(user_ptr);
        break;
    case 40:
        pre_state_action1(user_ptr, state_stack);
        switch (terminal__id(terminal)) {
        case t_symbol:
            pre_shift_action1(user_ptr, terminal);
            shift(30);
            break;
        case t_literal:
            pre_shift_action1(user_ptr, terminal);
            shift(31);
            break;
        case t_union:
            pre_shift_action1(user_ptr, terminal);
            shift(32);
            break;
        case t_any:
            pre_shift_action1(user_ptr, terminal);
            shift(33);
            break;
        case t_lpar:
            pre_shift_action1(user_ptr, terminal);
            shift(40);
            break;
        default:
            error(stack_int__access(state_stack));
            break;
        }
        post_state_action1(user_ptr);
        break;
    case 50:
        pre_state_action1(user_ptr, state_stack);
        switch (terminal__id(terminal)) {
        case t_kleenestar:
            pre_shift_action1(user_ptr, terminal);
            shift(60);
            break;
        case t_kleeneplus:
            pre_shift_action1(user_ptr, terminal);
            shift(70);
            break;
        default:
            {
                reduce(10);
                post_reduce_action1(user_ptr, 10);
                production_attibuted_actions2(user_ptr, 10);
                switch (stack_int__access(state_stack)) {
                case 20:
                case 40:
                case 100:
                case 130:
                    stack_int__insert(state_stack, 100);
                    break;
                default:
                    error(stack_int__access(state_stack));
                    break;
                }
            }
            break;
        }
        post_state_action1(user_ptr);
        break;
    case 60:
        pre_state_action1(user_ptr, state_stack);
        {
            reduce(11);
            post_reduce_action1(user_ptr, 11);
            production_attibuted_actions2(user_ptr, 11);
            switch (stack_int__access(state_stack)) {
            case 20:
            case 40:
            case 100:
            case 130:
                stack_int__insert(state_stack, 80);
                break;
            default:
                error(stack_int__access(state_stack));
                break;
            }
        }
        post_state_action1(user_ptr);
        break;
    case 70:
        pre_state_action1(user_ptr, state_stack);
        {
            reduce(12);
            post_reduce_action1(user_ptr, 12);
            production_attibuted_actions2(user_ptr, 12);
            switch (stack_int__access(state_stack)) {
            case 20:
            case 40:
            case 100:
            case 130:
                stack_int__insert(state_stack, 90);
                break;
            default:
                error(stack_int__access(state_stack));
                break;
            }
        }
        post_state_action1(user_ptr);
        break;
    case 80:
        pre_state_action1(user_ptr, state_stack);
        {
            reduce(8);
            post_reduce_action1(user_ptr, 8);
            production_attibuted_actions2(user_ptr, 8);
            switch (stack_int__access(state_stack)) {
            case 20:
            case 40:
            case 100:
            case 130:
                stack_int__insert(state_stack, 100);
                break;
            default:
                error(stack_int__access(state_stack));
                break;
            }
        }
        post_state_action1(user_ptr);
        break;
    case 90:
        pre_state_action1(user_ptr, state_stack);
        {
            reduce(9);
            post_reduce_action1(user_ptr, 9);
            production_attibuted_actions2(user_ptr, 9);
            switch (stack_int__access(state_stack)) {
            case 20:
            case 40:
            case 100:
            case 130:
                stack_int__insert(state_stack, 100);
                break;
            default:
                error(stack_int__access(state_stack));
                break;
            }
        }
        post_state_action1(user_ptr);
        break;
    case 100:
        pre_state_action1(user_ptr, state_stack);
        switch (terminal__id(terminal)) {
        case t_symbol:
            pre_shift_action1(user_ptr, terminal);
            shift(30);
            break;
        case t_literal:
            pre_shift_action1(user_ptr, terminal);
            shift(31);
            break;
        case t_union:
            pre_shift_action1(user_ptr, terminal);
            shift(32);
            break;
        case t_any:
            pre_shift_action1(user_ptr, terminal);
            shift(33);
            break;
        case t_lpar:
            pre_shift_action1(user_ptr, terminal);
            shift(40);
            break;
        default:
            {
                reduce(7);
                post_reduce_action1(user_ptr, 7);
                production_attibuted_actions2(user_ptr, 7);
                switch (stack_int__access(state_stack)) {
                case 20:
                case 40:
                case 130:
                    stack_int__insert(state_stack, 120);
                    break;
                case 100:
                    stack_int__insert(state_stack, 110);
                    break;
                default:
                    error(stack_int__access(state_stack));
                    break;
                }
            }
            break;
        }
        post_state_action1(user_ptr);
        break;
    case 110:
        pre_state_action1(user_ptr, state_stack);
        {
            reduce(6);
            post_reduce_action1(user_ptr, 6);
            production_attibuted_actions2(user_ptr, 6);
            switch (stack_int__access(state_stack)) {
            case 20:
            case 40:
            case 130:
                stack_int__insert(state_stack, 120);
                break;
            case 100:
                stack_int__insert(state_stack, 110);
                break;
            default:
                error(stack_int__access(state_stack));
                break;
            }
        }
        post_state_action1(user_ptr);
        break;
    case 120:
        pre_state_action1(user_ptr, state_stack);
        switch (terminal__id(terminal)) {
        case t_disjunction:
            pre_shift_action1(user_ptr, terminal);
            shift(130);
            break;
        default:
            {
                reduce(5);
                post_reduce_action1(user_ptr, 5);
                production_attibuted_actions2(user_ptr, 5);
                switch (stack_int__access(state_stack)) {
                case 20:
                    stack_int__insert(state_stack, 140);
                    break;
                case 130:
                    stack_int__insert(state_stack, 190);
                    break;
                case 40:
                    stack_int__insert(state_stack, 170);
                    break;
                default:
                    error(stack_int__access(state_stack));
                    break;
                }
            }
            break;
        }
        post_state_action1(user_ptr);
        break;
    case 130:
        pre_state_action1(user_ptr, state_stack);
        switch (terminal__id(terminal)) {
        case t_symbol:
            pre_shift_action1(user_ptr, terminal);
            shift(30);
            break;
        case t_literal:
            pre_shift_action1(user_ptr, terminal);
            shift(31);
            break;
        case t_union:
            pre_shift_action1(user_ptr, terminal);
            shift(32);
            break;
        case t_any:
            pre_shift_action1(user_ptr, terminal);
            shift(33);
            break;
        case t_lpar:
            pre_shift_action1(user_ptr, terminal);
            shift(40);
            break;
        default:
            error(stack_int__access(state_stack));
            break;
        }
        post_state_action1(user_ptr);
        break;
    case 140:
        pre_state_action1(user_ptr, state_stack);
        switch (terminal__id(terminal)) {
        case t_terminator:
            pre_shift_action1(user_ptr, terminal);
            shift(150);
            break;
        default:
            error(stack_int__access(state_stack));
            break;
        }
        post_state_action1(user_ptr);
        break;
    case 150:
        pre_state_action1(user_ptr, state_stack);
        {
            reduce(3);
            post_reduce_action1(user_ptr, 3);
            production_attibuted_actions2(user_ptr, 3);
            switch (stack_int__access(state_stack)) {
            case 0:
            case 160:
                stack_int__insert(state_stack, 160);
                break;
            default:
                error(stack_int__access(state_stack));
                break;
            }
        }
        post_state_action1(user_ptr);
        break;
    case 160:
        pre_state_action1(user_ptr, state_stack);
        switch (terminal__id(terminal)) {
        case t_symbol:
            pre_shift_action1(user_ptr, terminal);
            shift(10);
            break;
        default:
            {
                reduce(2);
                post_reduce_action1(user_ptr, 2);
                production_attibuted_actions2(user_ptr, 2);
                switch (stack_int__access(state_stack)) {
                case 160:
                    stack_int__insert(state_stack, 200);
                    break;
                default:
                    error(stack_int__access(state_stack));
                    break;
                }
            }
            break;
        }
        post_state_action1(user_ptr);
        break;
    case 170:
        pre_state_action1(user_ptr, state_stack);
        switch (terminal__id(terminal)) {
        case t_rpar:
            pre_shift_action1(user_ptr, terminal);
            shift(180);
            break;
        default:
            error(stack_int__access(state_stack));
            break;
        }
        post_state_action1(user_ptr);
        break;
    case 180:
        pre_state_action1(user_ptr, state_stack);
        {
            reduce(17);
            post_reduce_action1(user_ptr, 17);
            production_attibuted_actions2(user_ptr, 17);
            switch (stack_int__access(state_stack)) {
            case 20:
            case 40:
            case 100:
            case 130:
                stack_int__insert(state_stack, 50);
                break;
            default:
                error(stack_int__access(state_stack));
            }
        }
        post_state_action1(user_ptr);
        break;
    case 190:
        pre_state_action1(user_ptr, state_stack);
        {
            reduce(4);
            post_reduce_action1(user_ptr, 4);
            production_attibuted_actions2(user_ptr, 4);
            switch (stack_int__access(state_stack)) {
            case 20:
                stack_int__insert(state_stack, 140);
                break;
            case 130:
                stack_int__insert(state_stack, 190);
                break;
            case 40:
                stack_int__insert(state_stack, 170);
                break;
            default:
                error(stack_int__access(state_stack));
                break;
            }
        }
        post_state_action1(user_ptr);
        break;
    case 200:
        pre_state_action1(user_ptr, state_stack);
        {
            
            reduce(1);
            post_reduce_action1(user_ptr, 1);
            production_attibuted_actions2(user_ptr, 1);
            switch (stack_int__access(state_stack)) {
            case 0:
                stack_int__insert(state_stack, 210);
                break;
            case 160:
                stack_int__insert(state_stack, 200);
                break;
            default:
                error(stack_int__access(state_stack));
                break;
            }
        }
        post_state_action1(user_ptr);
        break;
    case 210:
        pre_state_action1(user_ptr, state_stack);
        {
            reduce(0);
            post_reduce_action1(user_ptr, 0);
            production_attibuted_actions2(user_ptr, 0);
            accept();
        }
        post_state_action1(user_ptr);
        break;
    }
}
