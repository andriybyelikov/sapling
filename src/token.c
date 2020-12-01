#include <stdlib.h>
#include <string.h>

static
int *tkid_ptr(void *tk)
{
    return (int *)tk;
}

static
char *tklx_ptr(void *tk)
{
    return (char *)tk + sizeof(int);
}


void *mktk(int id, const char *lx)
{
    void *tk = malloc(sizeof(int) + strlen(lx) + 1);
    *tkid_ptr(tk) = id;
    strcpy(tklx_ptr(tk), lx);
    return tk;
}

int tkid(void *tk)
{
    return *tkid_ptr(tk);
}

const char *tklx(void *tk)
{
    return tklx_ptr(tk);
}
