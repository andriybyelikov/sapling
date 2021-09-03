#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "options.h"
#include "meta/meta_lexer.h"
#include "meta/meta_parser.h"
#include "composition/composition_parser.h"
#include "data.h"

static
void print_version(void)
{
    printf("sapling r11.e611c73\n");
    printf("Copyright (C) 2021 Andriy Byelikov\n");
}

static
void print_help(void)
{
    printf("Usage: sapling input_file [-o output_file]\n");
    printf("       sapling -m spec_file [meta mode options]\n");
    printf("Options:\n");
    printf("  --help     Display this information.\n");
    printf("  --version  Display version information.\n");
    printf("  -o <file>  Place the output into <file>.\n");
    printf("  -m         Enable meta mode (for diagnosing specs).\n");
    printf("\n");
    printf("Meta mode options:\n");
    printf("  -print-lexer-output-only  Prints terminals without invoking the parser.\n");
    printf("  -log-state-stack          Logs the parsing state stack during parsing.\n");
    printf("  -log-parse-tree-stack     Logs the production stack during parsing.\n");
    printf("  -dump-parse-tree          Dumps the parse tree of the specification file in DOT.\n");
    printf("  -print-terminals          Prints the specification's terminal symbols.\n");
    printf("  -print-nonterminals       Prints the specification's nonterminal symbols.\n");
    printf("  -print-productions        Prints the specification's productions.\n");
    printf("  -print-lexer_automaton    Prints the specification's lexer automaton as a set of states.\n");
    printf("  -dump-lexer-automaton     Dumps the specification's lexer automaton in DOT.\n");
    printf("  -print-slr-tables         Prints the specification's Simple LR parsing tables.\n");
}

void print_lexer_output_only(FILE *input_file);

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "sapling: error: no input file\n");
        exit(EXIT_SUCCESS);
    }

    int options[NUM_OPTIONS]; // option is present
    int options_argv_i[NUM_OPTIONS]; // option's index in argv

    for (int i = 0; i < NUM_OPTIONS; i++) {
        options[i] = 0;
        options_argv_i[i] = -1;
    }

    char *input_filename = NULL; // or spec file
    char *output_filename = NULL;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            for (int j = 0; j < NUM_OPTIONS; j++) {
                if (!strcmp(argv[i], option_string[j])) {
                    if (j == OPTION_OUTPUT_FILE) {
                        ++i;
                        if (i < argc && argv[i][0] != '-') {
                            output_filename = argv[i];
                        } else {
                            fprintf(stderr, "sapling: error: no output file specified\n");
                            exit(EXIT_SUCCESS);
                        }
                    }
                    options[j] = 1;
                    options_argv_i[j] = i;
                }
            }
        } else {
            input_filename = argv[i];
        }
    }

    if (options[OPTION_VERSION]) {
        print_version();
    } else if (options[OPTION_HELP]) {
        print_help();
    } else {
        if (input_filename == NULL) {
            fprintf(stderr, "sapling: error: no input file specified\n");
            exit(EXIT_SUCCESS);
        }
        FILE *input_file = fopen(input_filename, "r");
        if (options[OPTION_META_MODE]) {
            if (options[OPTION_PRINT_LEXER_OUTPUT_ONLY]) {
                print_lexer_output_only(input_file);            
            } else {
                // init meta parser user data
                struct data_meta user = {
                    .options = options,
                    .in_terminals_section = 1,
                    .parse_tree_stack = NULL,
                    .build_regex = 1,
                    .lexer_stack = NULL,
                    .lexer_final = NULL,
                    .cnt_term = 0,
                    .terminals = NULL,
                    .terminals2 = NULL,
                    .cnt_nonterm = 0,
                    .nonterminals = NULL,
                    .nonterminals2 = NULL,
                    .productions = NULL
                };
                // run meta parser
                internal_parser__parse(get_meta_parser(), input_file, &user);
                fprintf(stderr, "Parse successful!\n");
            }
        } else { // composition mode
            if (output_filename == NULL) {
                output_filename = "./a.out";
            }
            FILE *output_file = fopen(output_filename, "w");
            // init composition parser user data
            struct data_composition user = {
                .options = options,
                .parse_tree_stack = NULL,
                .output_file = output_file
            };
            // run composition parser
            internal_parser__parse(get_composition_parser(), input_file,
                &user);
            fclose(output_file);
        }
        fclose(input_file);
    }

    exit(EXIT_SUCCESS);
}
