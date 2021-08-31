bin_PROGRAMS = sapling
sapling_LDADD = -lsapling
AM_CFLAGS = -std=c11 -pedantic -lm
AM_CPPFLAGS = -I$(srcdir)/include -I$(srcdir)/src
dist_man_MANS = sapling.1

# meta
noinst_HEADERS = ./src/mangen_user_data.h ./src/mangen_combined_ids.h ./src/mangen_terminals.h ./src/mangen_productions.h ./include/options.h ./include/state_stack.h ./include/parse_tree_stack.h ./include/lexer_action.h ./include/parser.h ./include/parser_actions.h ./include/lexer.h
sapling_SOURCES = src/mangen_parser_pre_state_action1.c src/parser.c src/mangen_lexer.c src/mangen_production_attributed_actions2.c src/mangen_parser_pre_shift_action1.c src/mangen_lexer_actions.c src/autogen_parser_actions0.c src/mangen_parser_post_reduce_action1.c src/mangen_parser_post_state_action1.c src/main.c
