//
// Created by cmtheit on 23-7-9.
//

#include <stdio.h>
#include <stdint.h>

int div16(int a) {
    return -((-a) >> 4);
}

int main() {
    int32_t a = -50;
    // 通过移位除以 2 的幂在移位之前应该加上一个“biasing”，移动 k 位应该加上 2^k-1 。
    printf("%d %d\n", a / 4, (a + 3) >> 2);
    printf("%d %d\n", INT32_MIN / 4, INT32_MIN >> 2);
    printf("%d %d %d\n", a / 16, div16(a), a >> 4);
}