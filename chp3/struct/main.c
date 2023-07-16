//
// Created by cmtheit on 23-7-15.
//
#include <stdio.h>
#include "../asm_define.h"

struct s {
    int a;
    int b[2];
    struct s * c;
    char hello;
    int world;
};

struct link {
    struct link * next;
    long v;
};

ASM_DEFINE(link_sum, struct link * head) {
    long val = 0;
    while (head) {
        val += head->v;
        head = head->next;
    }
    return val;
}

ASM_DEFINE(link_delete, struct link ** head, size_t idx) {
    while (idx && *head) {
        idx--;
        head = &(*head)->next;
    }
    if (*head) {
        *head = (*head)->next;
    }
    return 0;
}

int main() {
    struct s m = {
        1, {2, 3}, NULL, '0', 99
    };
    printf("%d\n", m.a);
    struct link n1 = {NULL, 2};
    struct link n2 = {&n1, 3};
    struct link n3 = {&n2, 4};
    struct link head = {&n3, 5};
    printf("sum is: %ld <-> %ld\n", link_sum(&head), asm_link_sum(&head));
    struct link * headp = &head;
    asm_link_delete(&headp, 2lu);
    printf("after delete, sum is: %ld\n", link_sum(headp));
}