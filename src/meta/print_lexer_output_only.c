#include <math.h>
#include <stdio.h>
#include <string.h>
#include "meta/meta_lexer.h"
#include "meta/terminals.h"

void print_lexer_output_only(input_stream_t input_stream)
{
    FILE *output_file = stdout;
    internal_lexer_t lexer = get_meta_lexer();

    int longest_id = 0;
    for (int i = 0; i < NUM_TERMINALS; i++)
        if (strlen(terminal_string[i]) > longest_id)
            longest_id = strlen(terminal_string[i]);
    int id_digits = (int)(log10(NUM_TERMINALS - 1) + 1);
    fprintf(output_file, "%*s  %-*s  %s\n", id_digits, "id", longest_id, "symbol", "lexeme");
    fprintf(output_file, "%*s  %-*s  %s\n", id_digits, "--", longest_id, "------", "------");
    terminal_t terminal;
    do {
        terminal = internal_lexer__fetch_terminal(lexer, input_stream, NULL);
        fprintf(output_file, "%*d  %-*s  %s\n",
            id_digits, terminal__id(terminal),
            longest_id, terminal_string[terminal__id(terminal)],
            terminal__lexeme(terminal));
    } while (terminal__id(terminal) != t_eof);
}
