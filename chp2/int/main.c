//
// Created by cmtheit on 23-7-9.
//

#include <stdio.h>
#include <stdint.h>

#define PRId32 "d"
#define PRUd32 "u"
#define PRId64 "l"
#define PRUd64 "lu"

int main() {
    uint32_t a = 10;
    uint64_t b = 20;
    printf("a is %" PRUd32 ", b is %" PRUd64, a, b);
    uint64_t c = INT32_MAX + 132323232u;
    printf("%d\n", (int32_t)c);
    INT32_MIN;
    printf("%d\n", -1 < 0u);    // -1 will be converted to UMax
    int16_t d = -123;
    a = d;
    b = (uint16_t) d;
    printf("%" PRUd32 "\n", a);
    printf("%" PRUd64 "\n", b);
    b = 0xcccccccccc;
    printf("%d", b);
}