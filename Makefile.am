bin_PROGRAMS = sapling
sapling_LDADD = -lsapling
AM_CFLAGS = -std=c11 -pedantic -lm
AM_CPPFLAGS = -I$(srcdir)/include -I$(srcdir)/src
dist_man_MANS = sapling.1

# meta
noinst_HEADERS = ./src/meta/meta_parser.h ./src/meta/meta_lexer.h ./src/meta/nonterminals.h ./src/meta/parser_actions.h ./src/meta/productions.h ./src/meta/terminals.h ./src/composition/composition_parser.h ./src/composition/nonterminals.h ./src/composition/parser_actions.h ./src/composition/composition_lexer.h ./src/composition/productions.h ./src/composition/terminals.h ./include/options.h ./include/internal_lexer.h ./include/internal_parser.h ./include/aux/state_stack.h ./include/aux/parse_tree_stack.h ./include/data.h
sapling_SOURCES = src/internal_parser.c src/meta/print_lexer_output_only.c src/meta/get_grammar_symbol_index_from_string.c src/meta/parser_pre_shift_action1.c src/meta/meta_lexer.c src/meta/parser_pre_state_action1.c src/meta/parser_post_state_action1.c src/meta/lexer_actions.c src/meta/parser_actions0.c src/meta/parser_production_attributed_actions2.c src/meta/parser_post_reduce_action1.c src/meta/meta_parser.c src/internal_lexer.c src/composition/composition_lexer.c src/composition/get_grammar_symbol_index_from_string.c src/composition/parser_pre_shift_action1.c src/composition/parser_pre_state_action1.c src/composition/parser_post_state_action1.c src/composition/lexer_actions.c src/composition/parser_actions0.c src/composition/parser_production_attributed_actions2.c src/composition/composition_parser.c src/composition/parser_post_reduce_action1.c src/main.c
