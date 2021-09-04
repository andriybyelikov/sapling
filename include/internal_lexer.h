#ifndef INTERNAL_LEXER_H
#define INTERNAL_LEXER_H

#include <stdio.h>
#include <libsapling/cc/terminal.h>
#include "input_stream.h"

typedef struct internal_lexer *internal_lexer_t;

internal_lexer_t new_internal_lexer(
    int (*get_initial_state)(void),
    int (*next_state)(int, char),
    int (*is_accepting_state)(int),
    int (*get_class)(int),
    int (*class_has_gobble_modifier)(int),
    int (*get_eof_class)(void),
    void (*lexer_actions)(terminal_t, void *));
terminal_t internal_lexer__fetch_terminal(internal_lexer_t internal_lexer,
    input_stream_t input_stream, void *user_ptr);

#endif
