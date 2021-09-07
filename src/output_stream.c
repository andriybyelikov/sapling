#include <stdlib.h>
#include <string.h>
#include "output_stream.h"

struct output_stream {
    int mode;
    FILE *file;
    char *array;
    int cursor;
    size_t size;
};


output_stream_t new_output_stream(int mode, FILE *file, char *array)
{
    output_stream_t output_stream = malloc(sizeof(struct output_stream));
    output_stream->mode = mode;
    output_stream->file = file;
    output_stream->array = array;
    output_stream->cursor = 0;
    return output_stream;
}

void output_stream__putc(output_stream_t output_stream, char c)
{
    if (output_stream->mode == OUTPUT_STREAM_MODE_FILE) {
        putc(c, output_stream->file);
    } else {
        output_stream->array[output_stream->cursor] = c;
        output_stream->cursor++;
    }
}

input_stream_t output_stream__to_input_stream(output_stream_t output_stream)
{
    // string terminator just in case
    if (output_stream->mode == OUTPUT_STREAM_MODE_ARRAY)
        output_stream__putc(output_stream, 0);
    if (output_stream->mode == OUTPUT_STREAM_MODE_BINARY_ARRAY)
        output_stream->size = output_stream->cursor;
    output_stream->cursor = 0;
    return (input_stream_t)output_stream;
}
