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
void remove_atom_or_function_and_its_arguments(node_t *uargs)
{
    struct atom a = arg_stack__delete(uargs);
    #ifdef ULISP_LOG_STACK
    arg_stack__print(stdout, uargs);
    fprintf(stdout, "\n");
    #endif

    const char *name = a.name;
    if (a.type == ATOM_FUNCTION) {
        if (!strcmp(name, "if")) {
            // remove 3 arguments
            a = arg_stack__access(uargs);
            if (a.type == ATOM_FUNCTION) {
                remove_atom_or_function_and_its_arguments(uargs);
                #ifdef ULISP_LOG_STACK
                arg_stack__print(stdout, uargs);
                fprintf(stdout, "\n");
                #endif
            } else {
                arg_stack__delete(uargs);
            }
            a = arg_stack__access(uargs);
            if (a.type == ATOM_FUNCTION) {
                remove_atom_or_function_and_its_arguments(uargs);
                #ifdef ULISP_LOG_STACK
                arg_stack__print(stdout, uargs);
                fprintf(stdout, "\n");
                #endif
            } else {
                 arg_stack__delete(uargs);
            }
            a = arg_stack__access(uargs);
            if (a.type == ATOM_FUNCTION) {
                remove_atom_or_function_and_its_arguments(uargs);
                #ifdef ULISP_LOG_STACK
                arg_stack__print(stdout, uargs);
                fprintf(stdout, "\n");
                #endif
            } else {
                 arg_stack__delete(uargs);
            }
        } else if (!strcmp(name, "strequ")) {
            // remove 2 arguments
            a = arg_stack__access(uargs);
            if (a.type == ATOM_FUNCTION) {
                remove_atom_or_function_and_its_arguments(uargs);
                #ifdef ULISP_LOG_STACK
                arg_stack__print(stdout, uargs);
                fprintf(stdout, "\n");
                #endif
            } else {
                 arg_stack__delete(uargs);
            }
            a = arg_stack__access(uargs);
            if (a.type == ATOM_FUNCTION) {
                remove_atom_or_function_and_its_arguments(uargs);
                #ifdef ULISP_LOG_STACK
                arg_stack__print(stdout, uargs);
                fprintf(stdout, "\n");
                #endif
            } else {
                 arg_stack__delete(uargs);
            }
        } else if (!strcmp(name, "lexeme")) {
            // remove 1 argument
            // can only have string atoms by design
            arg_stack__delete(uargs);
        } else if (!strcmp(name, "emit_byte")) {
            // remove 1 argument
            a = arg_stack__access(uargs);
            if (a.type == ATOM_FUNCTION) {
                remove_atom_or_function_and_its_arguments(uargs);
                #ifdef ULISP_LOG_STACK
                arg_stack__print(stdout, uargs);
                fprintf(stdout, "\n");
                #endif
            } else {
                 arg_stack__delete(uargs);
            }
        } else if (!strcmp(name, "strtol")) {
            // remove 1 argument
            a = arg_stack__access(uargs);
            if (a.type == ATOM_FUNCTION) {
                remove_atom_or_function_and_its_arguments(uargs);
                #ifdef ULISP_LOG_STACK
                arg_stack__print(stdout, uargs);
                fprintf(stdout, "\n");
                #endif
            } else {
                 arg_stack__delete(uargs);
            }
        } else if (!strcmp(name, "emit_line")) {
            // remove 1 argument
            a = arg_stack__access(uargs);
            if (a.type == ATOM_FUNCTION) {
                remove_atom_or_function_and_its_arguments(uargs);
                #ifdef ULISP_LOG_STACK
                arg_stack__print(stdout, uargs);
                fprintf(stdout, "\n");
                #endif
            } else {
                 arg_stack__delete(uargs);
            }
        }
    }
}

static
struct atom *call_function(const char *name, node_t *pts, output_stream_t out,
    node_t *uargs)
{
    struct atom a;
    if (!strcmp(name, "if")) {
        // take 3 arguments
        struct atom cond;

        a = arg_stack__delete(uargs);
        #ifdef ULISP_LOG_STACK
        arg_stack__print(stdout, uargs);
        fprintf(stdout, "\n");
        #endif
        if (a.type == ATOM_FUNCTION) {
            struct atom *result = call_function(a.name, pts, out, uargs);
            if (result != NULL) {
                arg_stack__insert(uargs, *result);
            #ifdef ULISP_LOG_STACK
            arg_stack__print(stdout, uargs);
            fprintf(stdout, "\n");
            #endif
            }
            cond = arg_stack__delete(uargs);
            #ifdef ULISP_LOG_STACK
            arg_stack__print(stdout, uargs);
            fprintf(stdout, "\n");
            #endif
        } else {
            cond = a;
            assert(cond.type == ATOM_INT);
        }
        if (cond.value) {
            a = arg_stack__delete(uargs);
            #ifdef ULISP_LOG_STACK
            arg_stack__print(stdout, uargs);
            fprintf(stdout, "\n");
            #endif
            if (a.type == ATOM_FUNCTION) {
                struct atom *result = call_function(a.name, pts, out, uargs);
                if (result != NULL) {
                    arg_stack__insert(uargs, *result);
                    #ifdef ULISP_LOG_STACK
                    arg_stack__print(stdout, uargs);
                    fprintf(stdout, "\n");
                    #endif
                }
            }
            remove_atom_or_function_and_its_arguments(uargs);
        } else {
            remove_atom_or_function_and_its_arguments(uargs);
            a = arg_stack__delete(uargs);
            #ifdef ULISP_LOG_STACK
            arg_stack__print(stdout, uargs);
            fprintf(stdout, "\n");
            #endif
            if (a.type == ATOM_FUNCTION) {
                struct atom *result = call_function(a.name, pts, out, uargs);
                if (result != NULL) {
                    arg_stack__insert(uargs, *result);
                    #ifdef ULISP_LOG_STACK
                    arg_stack__print(stdout, uargs);
                    fprintf(stdout, "\n");
                    #endif
                }
            }
        }
        return NULL;
    } else if (!strcmp(name, "strequ")) {
        // take 2 arguments
        struct atom str1, str2;
        a = arg_stack__delete(uargs);
        #ifdef ULISP_LOG_STACK
        arg_stack__print(stdout, uargs);
        fprintf(stdout, "\n");
        #endif
        if (a.type == ATOM_FUNCTION) {
            struct atom *result = call_function(a.name, pts, out, uargs);
            if (result != NULL) {
                arg_stack__insert(uargs, *result);
                #ifdef ULISP_LOG_STACK
                arg_stack__print(stdout, uargs);
                fprintf(stdout, "\n");
                #endif
            }
            str1 = str1 = arg_stack__delete(uargs);
            #ifdef ULISP_LOG_STACK
            arg_stack__print(stdout, uargs);
            fprintf(stdout, "\n");
            #endif
        } else {
            str1 = a;
            assert(str1.type == ATOM_STRING);
        }
        a = arg_stack__delete(uargs);
        if (a.type == ATOM_FUNCTION) {
            struct atom *result = call_function(a.name, pts, out, uargs);
            if (result != NULL) {
                arg_stack__insert(uargs, *result);
                #ifdef ULISP_LOG_STACK
                arg_stack__print(stdout, uargs);
                fprintf(stdout, "\n");
                #endif
            }
            str2 = arg_stack__delete(uargs);
            #ifdef ULISP_LOG_STACK
            arg_stack__print(stdout, uargs);
            fprintf(stdout, "\n");
            #endif
        } else {
            str2 = a;
            assert(str2.type == ATOM_STRING);
        }
        struct atom *res = malloc(sizeof(struct atom));
        res->type = ATOM_INT;
        res->value = !strcmp(str1.string, str2.string);
        return res;
    } else if (!strcmp(name, "lexeme")) {
        // take 1 argument for now -- what if multiple occurences?
        struct atom symbol;
        a = arg_stack__delete(uargs);
        #ifdef ULISP_LOG_STACK
        arg_stack__print(stdout, uargs);
        fprintf(stdout, "\n");
        #endif
        if (a.type == ATOM_FUNCTION) {
            struct atom *result = call_function(a.name, pts, out, uargs);
            if (result != NULL) {
                arg_stack__insert(uargs, *result);
                #ifdef ULISP_LOG_STACK
                arg_stack__print(stdout, uargs);
                fprintf(stdout, "\n");
                #endif
            }
            symbol = arg_stack__delete(uargs);
            #ifdef ULISP_LOG_STACK
            arg_stack__print(stdout, uargs);
            fprintf(stdout, "\n");
            #endif
        } else {
            symbol = a;
            assert(symbol.type == ATOM_STRING);
        }
        node_t production_node = parse_tree_stack__access(pts);
        node_t symbol_node = child(&production_node, symbol.string);
        assert(symbol_node != NULL);
        node_t lexeme_node =
            parse_tree__get_child_by_position(&symbol_node, 0);
        const char *lexeme = *parse_tree__data(lexeme_node);
        struct atom *res = malloc(sizeof(struct atom));
        res->type = ATOM_STRING;
        res->string = (char *)lexeme;
        return res;
    } else if (!strcmp(name, "emit_byte")) {
        // take 1 argument
        struct atom val;

        a = arg_stack__delete(uargs);
        #ifdef ULISP_LOG_STACK
        arg_stack__print(stdout, uargs);
        fprintf(stdout, "\n");
        #endif
        if (a.type == ATOM_FUNCTION) {
            struct atom *result = call_function(a.name, pts, out, uargs);
            if (result != NULL) {
                arg_stack__insert(uargs, *result);
                #ifdef ULISP_LOG_STACK
                arg_stack__print(stdout, uargs);
                fprintf(stdout, "\n");
                #endif
            }
            val = arg_stack__delete(uargs);
            #ifdef ULISP_LOG_STACK
            arg_stack__print(stdout, uargs);
            fprintf(stdout, "\n");
            #endif
        } else {
            val = a;
            assert(val.type == ATOM_INT);
        }
        output_stream__putc(out, val.value);
        #ifdef ULISP_LOG_OUTPUTTED
        fprintf(stderr, "emit_byte %x\n", val.value);
        #endif
        return NULL;
    } else if (!strcmp(name, "strtol")) {
        // take 1 argument
        struct atom val;

        a = arg_stack__delete(uargs);
        #ifdef ULISP_LOG_STACK
        arg_stack__print(stdout, uargs);
        fprintf(stdout, "\n");
        #endif
        if (a.type == ATOM_FUNCTION) {
            struct atom *result = call_function(a.name, pts, out, uargs);
            if (result != NULL) {
                arg_stack__insert(uargs, *result);
                #ifdef ULISP_LOG_STACK
                arg_stack__print(stdout, uargs);
                fprintf(stdout, "\n");
                #endif
            }
            val = arg_stack__delete(uargs);
            #ifdef ULISP_LOG_STACK
            arg_stack__print(stdout, uargs);
            fprintf(stdout, "\n");
            #endif
        } else {
            val = a;
            assert(val.type == ATOM_STRING);
        }
        struct atom *res = malloc(sizeof(struct atom));
        res->type = ATOM_INT;
        char *ptr;
        res->value = strtol(val.string, &ptr, 0);
        return res;
    } else if (!strcmp(name, "emit_line")) {
        // take 1 argument
        struct atom val;

        a = arg_stack__delete(uargs);
        #ifdef ULISP_LOG_STACK
        arg_stack__print(stdout, uargs);
        fprintf(stdout, "\n");
        #endif
        if (a.type == ATOM_FUNCTION) {
            struct atom *result = call_function(a.name, pts, out, uargs);
            if (result != NULL) {
                arg_stack__insert(uargs, *result);
                #ifdef ULISP_LOG_STACK
                arg_stack__print(stdout, uargs);
                fprintf(stdout, "\n");
                #endif
            }
            val = arg_stack__delete(uargs);
            #ifdef ULISP_LOG_STACK
            arg_stack__print(stdout, uargs);
            fprintf(stdout, "\n");
            #endif
        } else {
            val = a;
            assert(val.type == ATOM_STRING);
        }
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
