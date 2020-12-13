#ifndef PARSER_ACTIONS0
#define PARSER_ACTIONS0

void parser_actions0(void *user_ptr, void **state_stack, void *terminal);
void pre_shift_action1(void *user_ptr, void *terminal);
void post_reduce_action1(void *user_ptr, int pid);
void pre_state_action1(void *user_ptr, void **state_stack);
void post_state_action1(void *user_ptr);
void production_attibuted_actions2(void *user_ptr, int pid);

void shift(int next_state);
void reduce(int pid); // production index
void error(int state);
void accept(void);

#endif
