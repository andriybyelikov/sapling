#include <libsapling/stack.h>

struct insert {
    size_t size;
    int data;
};

void stack_int__insert(void **ref, int val)
{
    struct insert info = { sizeof(int), val };
    stack__insert(ref, &info);
}

void stack_int__delete(void **ref)
{
    stack__delete(ref);
}

int stack_int__access(void **ref)
{
    return *(int *)stack__access(ref);
}
