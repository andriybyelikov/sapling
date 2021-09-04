#include <malloc.h>
#include "internal_lexer.h"

struct internal_lexer {
    int (*get_initial_state)(void);
    int (*next_state)(int current_state, char input);
    int (*is_accepting_state)(int state);
    int (*get_class)(int accepting_state);
    int (*class_has_gobble_modifier)(int class);
    int (*get_eof_class)(void);
    void (*lexer_actions)(terminal_t terminal, void *user_ptr);
};


internal_lexer_t new_internal_lexer(int (*get_initial_state)(void),
    int (*next_state)(int, char), int (*is_accepting_state)(int),
    int (*get_class)(int), int (*class_has_gobble_modifier)(int),
    int (*get_eof_class)(void), void (*lexer_actions)(terminal_t, void *))
{
    internal_lexer_t internal_lexer = malloc(sizeof(struct internal_lexer));
    internal_lexer->get_initial_state = get_initial_state;
    internal_lexer->next_state = next_state;
    internal_lexer->is_accepting_state = is_accepting_state;
    internal_lexer->get_class = get_class;
    internal_lexer->class_has_gobble_modifier = class_has_gobble_modifier;
    internal_lexer->get_eof_class = get_eof_class;
    internal_lexer->lexer_actions = lexer_actions;
    return internal_lexer;
}


static
terminal_t build_terminal(char *buf, int bufc, int id)
{
    buf[bufc] = 0;
    return new_terminal(id, buf);
}

terminal_t internal_lexer__fetch_terminal(internal_lexer_t internal_lexer,
    input_stream_t input_stream, void *user_ptr)
{
    char c;                                      // single character buffer
    int s = internal_lexer->get_initial_state(); // state
    char buf[4096];                              // lexeme buffer
    int bufc = 0;                                // lexeme buffer cursor
    terminal_t terminal;                         // terminal buffer
    int class = -1;
    int overread = 0;
    int cont = 1;

    while (cont) {
        c = input_stream__getc(input_stream);
        if (c == EOF) {
            terminal = build_terminal(buf, bufc,
                internal_lexer->get_eof_class());
            internal_lexer->lexer_actions(terminal, user_ptr);
            return terminal;
        } else {
            if (internal_lexer->is_accepting_state(s)) {
                class = internal_lexer->get_class(s);
                overread = 0;
            }
            s = internal_lexer->next_state(s, c);
            buf[bufc++] = c;
            overread++;
            if (s == -1) {
                for (int i = 0; i < overread; i++) {
                    input_stream__ungetc(input_stream, c);
                    bufc--;
                }
                overread = 0;
                s = internal_lexer->get_initial_state();
                if (!internal_lexer->class_has_gobble_modifier(class))
                    cont = 0;
                else
                    bufc = 0;
            }
        }
    }
    if (class == -1)
        return NULL;
    terminal = build_terminal(buf, bufc, class);
    internal_lexer->lexer_actions(terminal, user_ptr);
    return terminal;
}
