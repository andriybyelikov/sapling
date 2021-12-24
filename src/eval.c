#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <libsapling/dm/queue.h>
#include <libsapling/cc/parse_tree.h>
#include "output_stream.h"
#include "aux/parse_tree_stack.h"

//#define ULISP_EXPLAIN_EVAL_ORDER
//#define ULISP_LOG_STACK
//#define ULISP_LOG_OUTPUTTED

#define child(ref, string) parse_tree__get_child_by_string(ref, string)
#define num_children(node) parse_tree__num_children(node)
#define id(node, string) (!strcmp(*parse_tree__data(node), #string))


enum {
    ATOM_STRING,
    ATOM_INT,
    ATOM_FUNCTION,
    ATOM_EMPTY_LIST
};

struct atom {
    int type;

    // ATOM_STRING
    char *string;

    // ATOM_INT
    int value;

    // ATOM_FUNCTION
    const char *name;
};

static
struct atom *new_int_atom(int value)
{
    struct atom *res = malloc(sizeof(struct atom));
    res->type = ATOM_INT;
    res->value = value;
    return res;
}

static
struct atom *new_string_atom(const char *string)
{
    struct atom *res = malloc(sizeof(struct atom));
    res->type = ATOM_STRING;
    res->string = (char *)string;
    return res;
}

static
struct atom *new_atom_from_atom(struct atom atom)
{
    if (atom.type == ATOM_INT) {
        return new_int_atom(atom.value);
    } else if (atom.type == ATOM_STRING) {
        return new_string_atom(atom.string);
    } else {
        assert(0);
    }
}

static
void atom__print(FILE *stream, const void *data)
{
    const struct atom *atom = data;
    if (atom->type == ATOM_STRING) {
        fprintf(stream, "\"%s\"", atom->string);
    } else if (atom->type == ATOM_INT) {
        fprintf(stream, "%d", atom->value);
    } else if (atom->type == ATOM_FUNCTION) {
        fprintf(stream, "%s()", atom->name);
    } else if (atom->type == ATOM_EMPTY_LIST) {
        fprintf(stream, "(nil)");
    }
}

// for bottom-up evaluation
IMPLEMENT_TYPED_STACK(arg_stack, struct atom, atom__print)

// for function execution
IMPLEMENT_TYPED_QUEUE(arg_list, struct atom, atom__print)


static
void prune_args(node_t *uargs);

static
void prune_nargs(int n, node_t *uargs)
{
    for (int i = 0; i < n; i++) {
        struct atom a = arg_stack__access(uargs);
        if (a.type == ATOM_FUNCTION) {
            prune_args(uargs);
        } else {
            arg_stack__delete(uargs);
        }
    }
}

static
void prune_args(node_t *uargs)
{
    struct atom a = arg_stack__delete(uargs);
    if (a.type == ATOM_FUNCTION) {
        const char *name = a.name;
        if (!strcmp(name, "if")) {
            prune_nargs(3, uargs);
        } else if (!strcmp(name, "strequ")) {
            prune_nargs(2, uargs);
        } else if (!strcmp(name, "strtol")) {
            prune_nargs(1, uargs);
        } else if (!strcmp(name, "lexeme")) {
            prune_nargs(2, uargs);
        } else if (!strcmp(name, "emit_byte")) {
            prune_nargs(1, uargs);
        } else if (!strcmp(name, "emit_line")) {
            prune_nargs(1, uargs);
        }
    }
}

static
struct atom *call_function(const char *name, node_t *pts, output_stream_t out,
    node_t *uargs);

static
struct atom fetch_arg(int type, node_t *pts, output_stream_t out,
    node_t *uargs)
{
    struct atom a = arg_stack__delete(uargs);
    if (a.type == ATOM_FUNCTION) {
        struct atom *result = call_function(a.name, pts, out, uargs);
        if (result != NULL) {
            arg_stack__insert(uargs, *result);
        }
        a = arg_stack__delete(uargs);
    }
    assert(a.type == type);
    return a;
}

static
struct atom *call_function(const char *name, node_t *pts, output_stream_t out,
    node_t *uargs)
{
    if (!strcmp(name, "if")) {
        struct atom cond = fetch_arg(ATOM_INT, pts, out, uargs);
        struct atom *rtn = NULL;
        if (cond.value) {
            struct atom a = arg_stack__delete(uargs);
            if (a.type == ATOM_FUNCTION) {
                rtn = call_function(a.name, pts, out, uargs);
            } else {
                rtn = new_atom_from_atom(a);
            }
            prune_args(uargs);
        } else {
            prune_args(uargs);
            struct atom a = arg_stack__delete(uargs);
            if (a.type == ATOM_FUNCTION) {
                rtn = call_function(a.name, pts, out, uargs);
            } else {
                rtn = new_atom_from_atom(a);
            }
        }
        return rtn;
    } else if (!strcmp(name, "strequ")) {
        struct atom str1 = fetch_arg(ATOM_STRING, pts, out, uargs);
        struct atom str2 = fetch_arg(ATOM_STRING, pts, out, uargs);
        return new_int_atom(!strcmp(str1.string, str2.string));
    } else if (!strcmp(name, "strtol")) {
        struct atom val = fetch_arg(ATOM_STRING, pts, out, uargs);
        char *ptr;
        return new_int_atom(strtol(val.string, &ptr, 0));
    } else if (!strcmp(name, "lexeme")) {
        struct atom symbol = fetch_arg(ATOM_STRING, pts, out, uargs);
        struct atom occurrence = fetch_arg(ATOM_INT, pts, out, uargs);

        node_t production_node = parse_tree_stack__access(pts);

        node_t symbol_node = NULL;
        for (int i = 0; i < parse_tree__num_children(production_node); i++) {
            symbol_node = parse_tree__get_child_by_position(&production_node,
                i);
            const char *nname = *parse_tree__data(symbol_node);
            if (!strcmp(nname, symbol.string) && --occurrence.value < 0) {
                break;
            } else {
                symbol_node = NULL;
            }
        }
        assert(symbol_node != NULL);
        node_t lexeme_node =
            parse_tree__get_child_by_position(&symbol_node, 0);
        const char *lexeme = *parse_tree__data(lexeme_node);

        return new_string_atom(lexeme);
    } else if (!strcmp(name, "emit_byte")) {
        struct atom val = fetch_arg(ATOM_INT, pts, out, uargs);
        output_stream__putc(out, val.value);
        return NULL;
    } else if (!strcmp(name, "emit_line")) {
        struct atom val = fetch_arg(ATOM_STRING, pts, out, uargs);
        for (int i = 0; i < strlen(val.string); i++)
            output_stream__putc(out, val.string[i]);
        output_stream__putc(out, '\n');
        return NULL;
    }
    return NULL;
}


static
void true_eval(node_t *t, node_t *pts, output_stream_t out, int *d,
    node_t *uargs)
{
    node_t node = *t;
    if (node == NULL)
        return;
    if (id(node, lists)) {
        #ifdef ULISP_EXPLAIN_EVAL_ORDER
        fprintf(stderr, "Evaluating <lists>\n");
        #endif
        node_t lists = child(t, "lists");
        node_t list = child(t, "list");
        true_eval(&lists, pts, out, d, uargs);
        true_eval(&list, pts, out, d, uargs);
    } else if (id(node, list)) {
        #ifdef ULISP_EXPLAIN_EVAL_ORDER
        fprintf(stderr, "Evaluating <list>\n");
        #endif
        node_t args = child(t, "args");
        node_t arg = child(&args, "arg");
        node_t type = parse_tree__get_child_by_position(&arg, 0);
        node_t lexeme_node = parse_tree__get_child_by_position(&type, 0);
        const char *lexeme = *parse_tree__data(lexeme_node);
        if (!strcmp(lexeme, "if")) {
            (*d)++;
        } else if (!strcmp(lexeme, "nil")) {
            arg_stack__insert(uargs, (struct atom){ ATOM_EMPTY_LIST });
            #ifdef ULISP_LOG_STACK
            arg_stack__print(stdout, uargs);
            fprintf(stdout, "\n");
            #endif
            return;
        }
        true_eval(&args, pts, out, d, uargs);
    } else if (id(node, args)) {
        #ifdef ULISP_EXPLAIN_EVAL_ORDER
        fprintf(stderr, "Evaluating <args>\n");
        #endif
        node_t args = child(t, "args");
        node_t arg = child(t, "arg");
        true_eval(&args, pts, out, d, uargs);
        true_eval(&arg, pts, out, d, uargs);
    } else if (id(node, arg)) {
        #ifdef ULISP_EXPLAIN_EVAL_ORDER
        fprintf(stderr, "Evaluating <arg>\n");
        #endif
        node_t type = parse_tree__get_child_by_position(t, 0);
        if (id(type, t_symbol)) {
            #ifdef ULISP_EXPLAIN_EVAL_ORDER
            fprintf(stderr, "Evaluating <t_symbol>\n");
            #endif
            // evaluate function
            node_t lexeme_node = parse_tree__get_child_by_position(&type, 0);
            const char *lexeme = *parse_tree__data(lexeme_node);
            if (!strcmp(lexeme, "if")) {
                (*d)--;
            }
            if (*d > 0) {
                arg_stack__insert(uargs,
                    (struct atom){ ATOM_FUNCTION, .name = lexeme });
                #ifdef ULISP_LOG_STACK
                arg_stack__print(stdout, uargs);
                fprintf(stdout, "\n");
                #endif
            }
            // call function
            if (*d == 0) {
                struct atom *result = call_function(lexeme, pts, out, uargs);
                if (result != NULL) {
                    arg_stack__insert(uargs, *result);
                    #ifdef ULISP_LOG_STACK
                    arg_stack__print(stdout, uargs);
                    fprintf(stdout, "\n");
                    #endif
                }
            }
        } else if (id(type, t_string)) {
            #ifdef ULISP_EXPLAIN_EVAL_ORDER
            fprintf(stderr, "Evaluating <t_string>\n");
            #endif
            node_t lexeme_node = parse_tree__get_child_by_position(&type, 0);
            const char *lexeme = *parse_tree__data(lexeme_node);
            char *string_object = malloc(strlen(lexeme) - 3);
            strncpy(string_object, lexeme + 2, strlen(lexeme) - 4);
            string_object[strlen(lexeme) - 4] = 0;
            // warning: TODO: unescape lexeme
            // debug: print strings
            // printf("%s\n", string_object);
            arg_stack__insert(uargs,
                (struct atom){ ATOM_STRING, .string = string_object });
            #ifdef ULISP_LOG_STACK
            arg_stack__print(stdout, uargs);
            fprintf(stdout, "\n");
            #endif
        } else if (id(type, t_integer)) {
            #ifdef ULISP_EXPLAIN_EVAL_ORDER
            fprintf(stderr, "Evaluating <t_integer>\n");
            #endif
            node_t lexeme_node = parse_tree__get_child_by_position(&type, 0);
            const char *lexeme = *parse_tree__data(lexeme_node);
            char *c;
            int val = strtol(lexeme, &c, 0);
            arg_stack__insert(uargs,
                (struct atom){ ATOM_INT, .value = val });
            #ifdef ULISP_LOG_STACK
            arg_stack__print(stdout, uargs);
            fprintf(stdout, "\n");
            #endif
        } else if (id(type, t_hexadecimal)) {
            #ifdef ULISP_EXPLAIN_EVAL_ORDER
            fprintf(stderr, "Evaluating <t_hexadecimal>\n");
            #endif
            node_t lexeme_node = parse_tree__get_child_by_position(&type, 0);
            const char *lexeme = *parse_tree__data(lexeme_node);
            char *c;
            int val = strtol(lexeme, &c, 0);
            arg_stack__insert(uargs,
                (struct atom){ ATOM_INT, .value = val });
            #ifdef ULISP_LOG_STACK
            arg_stack__print(stdout, uargs);
            fprintf(stdout, "\n");
            #endif
        } else { // lists
            true_eval(&type, pts, out, d, uargs);
        }
    }
}

void eval(node_t *ulisp_parse_tree, node_t *parse_tree_stack,
    output_stream_t out)
{
    node_t uargs = NULL; // argument stack
    int d = 0;

    #ifdef ULISP_LOG_STACK
    arg_stack__print(stdout, &uargs);
    fprintf(stdout, "\n");
    #endif

    // evaluate all lists
    node_t start = *ulisp_parse_tree;
    node_t lists = child(&start, "lists");
    while (lists != NULL) {
        node_t list = child(&lists, "list");
        true_eval(&list, parse_tree_stack, out, &d, &uargs);
        lists = child(&lists, "lists");
    }

    #ifdef ULISP_LOG_STACK
    arg_stack__print(stdout, &uargs);
    fprintf(stdout, "\n");
    #endif
}
