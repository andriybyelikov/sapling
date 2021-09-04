#ifndef STRING_LIST_H
#define STRING_LIST_H

#include <libsapling/dm/queue.h>

IMPLEMENT_TYPED_PATH(string_path, const char *, string__print, dummy_cmp)
IMPLEMENT_TYPED_QUEUE(string_queue, const char *, string__print)

#endif
