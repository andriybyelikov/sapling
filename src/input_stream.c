#include <stdlib.h>
#include <string.h>
#include "input_stream.h"

struct input_stream {
    int mode;
    FILE *file;
    const char *array;
    int cursor;
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
        if (input_stream->array[input_stream->cursor] == 0)
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
