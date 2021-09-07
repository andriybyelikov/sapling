#ifndef OUTPUT_STREAM_H
#define OUTPUT_STREAM_H

#include <stdio.h>
#include "input_stream.h"

enum {
    OUTPUT_STREAM_MODE_FILE,
    OUTPUT_STREAM_MODE_ARRAY,
    OUTPUT_STREAM_MODE_BINARY_ARRAY
};

typedef struct output_stream *output_stream_t;

output_stream_t new_output_stream(int mode, FILE *file, char *array);
void output_stream__putc(output_stream_t output_stream, char c);

// use only if output stream is array
input_stream_t output_stream__to_input_stream(output_stream_t output_stream);

#endif
