//
// Created by cmtheit on 23-7-10.
//

#ifndef COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_MY_CALLOC_H
#define COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_MY_CALLOC_H
#include <stdlib.h>
#include <memory.h>

// 不用 if 控制流程怎么做？
void * my_calloc(size_t nmenb, size_t size) {
    if (size && nmenb * size / size != nmenb) {
        return NULL;
    }
    size_t all_size = nmenb * size;
    void * p = malloc(all_size);
    if (!p) return p;
    memset(p, 0, all_size);
    return p;
}

#endif //COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_MY_CALLOC_H
