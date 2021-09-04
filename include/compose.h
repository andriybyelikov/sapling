#ifndef COMPOSE_H
#define COMPOSE_H

#include <stdio.h>
#include <libsapling/dm/graph.h>

void compose(const char *fragment_buffer, node_t *spec_list,
    FILE *output_file, void *user_ptr);

#endif
