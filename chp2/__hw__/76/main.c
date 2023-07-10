#include "../show_bytes.h"
#include "my_calloc.h"
#include <assert.h>

int main() {
    char * p = my_calloc(UINT64_MAX, 100);
    assert(p == NULL);
    p = my_calloc(100, 1);
    assert(p != NULL);
    p[0] = 'a';
    free(p);
}
  
