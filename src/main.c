#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libsapling/cc/terminal.h>

#include "options.h"

#include "lexer.h"
#include "parser.h"

#include "mangen_terminals.h"
#include "mangen_user_data.h"

static
const char *foption_get_file(const char *arg)
{
    const char *res = strchr(arg, '=');
    return res + (res == NULL ? 0 : 1);
}

static
void print_lexer_output(FILE *input_file, FILE *output_file)
{
    int longest_id = 0;
    for (int i = 0; i < NUM_TERMINALS; i++)
        if (strlen(terminal_str[i]) > longest_id)
            longest_id = strlen(terminal_str[i]);
    int id_digits = (int)(log10(NUM_TERMINALS - 1) + 1);
    fprintf(output_file, "%*s  %-*s  %s\n", id_digits, "id", longest_id, "symbol", "lexeme");
    fprintf(output_file, "%*s  %-*s  %s\n", id_digits, "--", longest_id, "------", "------");
    void *terminal;
    do {
        terminal = fetch_terminal(input_file, NULL);
        fprintf(output_file, "%*d  %-*s  %s\n",
            id_digits, terminal__id(terminal),
            longest_id, terminal_str[terminal__id(terminal)],
            terminal__lexeme(terminal));
    } while (terminal__id(terminal) != t_eof);
}


int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: sapling [-foption...] spec_file\n");
        printf("Options: [=file] optional file where to dump the output\n");
        printf("-fprint-lexer-output-only[=file]  Prints the lexer's output terminals without invoking the parser.\n");
        printf("-flog-state-stack                 Logs the parsing state stack during parsing.\n");
        printf("-flog-production-stack            Logs the production stack during parsing.\n");
        printf("-fdump-parse-tree[=file]          Dumps the parse tree of the specification file in DOT.\n");
        printf("-fprint-terminals                 Prints the specification's terminal symbols.\n");
        printf("-fprint-nonterminals              Prints the specification's nonterminal symbols.\n");
        printf("-fdump-lexer-automaton[=file]     Dumps the specification's lexer automaton in DOT.\n");
        exit(EXIT_SUCCESS);
    }

    int options[NUM_OPTIONS];
    int options_argi[NUM_OPTIONS];
    const char *foption_arguments[NUM_OPTIONS];
    for (int i = 0; i < NUM_OPTIONS; i++) {
        options[i] = options_argi[i] = 0;
        foption_arguments[i] = NULL;
    }

    char *spec_filename = NULL;

    for (int i = 1; i < argc; i++) {
        if (*argv[i] == '-') {
            for (int j = 0; j < NUM_OPTIONS; j++)
                if (!strncmp(argv[i], option_str[j], strlen(option_str[j]))) {
                    options[j] = 1;
                    options_argi[j] = i;
                }
        } else {
            spec_filename = argv[i];
        }
    }

    if (spec_filename == NULL) {
        fprintf(stderr, "sapling: error: no specification file\n");
        exit(EXIT_SUCCESS);
    }

    FILE *spec_file = fopen(spec_filename, "r");
    {
        struct user user = {
            .options = options,
            .in_terminals_section = 1,
            .parse_tree_stack = NULL,
            .build_regex = 1,
            .lexer_stack = NULL,
            .lexer_final = NULL,
            .productions = NULL
        };
        if (options[OPTION_FPRINT_LEXER_OUTPUT_ONLY]) {
            const char *output_filename = foption_get_file(argv[options_argi[OPTION_FPRINT_LEXER_OUTPUT_ONLY]]);
            FILE *output_file = output_filename == NULL ? stdout : fopen(output_filename, "w");
            print_lexer_output(spec_file, output_file);
            if (output_file != stdout)
                fclose(output_file);
        } else {
            user.parse_tree_filename = foption_get_file(argv[options_argi[OPTION_FDUMP_PARSE_TREE]]);
            user.lexer_automaton_filename = foption_get_file(argv[options_argi[OPTION_FDUMP_LEXER_AUTOMATON]]);
            parse(spec_file, &user);
            fprintf(stderr, "Parse successful!\n");
        }
    }
    fclose(spec_file);

    exit(EXIT_SUCCESS);
}
