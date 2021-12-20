#include <stdlib.h>
#include <string.h>
#include "input_stream.h"

struct input_stream {
    int mode;
    FILE *file;
    const char *array;
    int cursor;
    size_t size;
};


input_stream_t new_input_stream(int mode, FILE *file, const char *array)
{
    input_stream_t input_stream = malloc(sizeof(struct input_stream));
    input_stream->mode = mode;
    input_stream->file = file;
    input_stream->array = array;
    input_stream->cursor = 0;
    return input_stream;
}

char input_stream__getc(input_stream_t input_stream)
{
    if (input_stream->mode == INPUT_STREAM_MODE_FILE) {
        return getc(input_stream->file);
    } else {
        if ((input_stream->mode == INPUT_STREAM_MODE_ARRAY
                    && input_stream->array[input_stream->cursor] == 0)
                || input_stream->mode == INPUT_STREAM_MODE_BINARY_ARRAY
                    && input_stream->cursor == input_stream->size)
            return EOF;
        else
            return input_stream->array[input_stream->cursor++];
    }
}

void input_stream__ungetc(input_stream_t input_stream, char c)
{
    if (input_stream->mode == INPUT_STREAM_MODE_FILE) {
        ungetc(c, input_stream->file);
    } else {
        input_stream->cursor--;
    }
}

const char *input_stream__get_array(input_stream_t input_stream)
{
    return input_stream->array;
}

int input_stream__end(input_stream_t input_stream)
{
    char c;
    switch (input_stream->mode) {
    case INPUT_STREAM_MODE_FILE:
        c = getc(input_stream->file);
        if (c == EOF) {
            return 1;
        } else {
            ungetc(c, input_stream->file);
            return 0;
        }
    case INPUT_STREAM_MODE_ARRAY:
        return input_stream->array[input_stream->cursor] == 0;
    case INPUT_STREAM_MODE_BINARY_ARRAY:
        return input_stream->cursor == input_stream->size;
    }
}