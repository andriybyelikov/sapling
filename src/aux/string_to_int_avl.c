#include "aux/string_to_int_avl.h"

void idxstr__print(FILE *stream, const void *data)
{
    idxstr_t *a = (idxstr_t *)data;
    fprintf(stream, "(%d, \"%s\")", a->id, a->str);
}

static
void apply_get_str(idxstr_t *data, void *info)
{
    CAST_USER_INFO(idxstr_t *, idxstr, info);

    idxstr->str = data->str;
}

const char *idxstr_get_string(node_t *ref, int key)
{
    idxstr_t pair = { key, NULL };
    idxstr_avl__access(E_QT, ref, &pair, idxstr_avl__equ_predicate,
        apply_get_str);
    return pair.str;
}