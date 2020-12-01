#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "token.h"
#include "lexer.h"
#include "parser.h"

#include "mangen_tokens.h"

static
void print_tokens(FILE *input_file)
{
    int longest_id = 0;
    for (int i = 0; i < num_tokens; i++)
        if (strlen(token_str[i]) > longest_id)
            longest_id = strlen(token_str[i]);
    int id_digits = (int)(log10(num_tokens - 1) + 1);
    printf("%*s  %-*s  %s\n", id_digits, "id", longest_id, "symbol", "lexeme");
    printf("%*s  %-*s  %s\n", id_digits, "--", longest_id, "------", "------");
    void *tk;
    do {
        tk = fetch_token(input_file);
        printf("%*d  %-*s  %s\n",
            id_digits, tkid(tk),
            longest_id, token_str[tkid(tk)],
            tklx(tk));
    } while (tkid(tk) != t_eof);
}


int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: sapling lang_file\n");
        exit(EXIT_SUCCESS);
    }

    char *lang_filename = argv[1];
    FILE *lang_file = fopen(lang_filename, "r");

    //print_tokens(lang_file);
    parse(lang_file, NULL);

    fclose(lang_file);

    exit(EXIT_SUCCESS);
}
