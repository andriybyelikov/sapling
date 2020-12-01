#ifndef TOKEN
#define TOKEN

void *mktk(int id, const char *lx);
int tkid(void *tk);
const char *tklx(void *tk);

#endif
