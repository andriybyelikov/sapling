#ifndef INPUT_STREAM_H
#define INPUT_STREAM_H

#include <stdio.h>

enum {
    INPUT_STREAM_MODE_FILE,
    INPUT_STREAM_MODE_ARRAY,
    INPUT_STREAM_MODE_BINARY_ARRAY
};

typedef struct input_stream *input_stream_t;

input_stream_t new_input_stream(int mode, FILE *file, const char *array);
char input_stream__getc(input_stream_t input_stream);
void input_stream__ungetc(input_stream_t input_stream, char c);
const char *input_stream__get_array(input_stream_t input_stream);

#endif
