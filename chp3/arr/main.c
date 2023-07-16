//
// Created by cmtheit on 23-7-15.
//

#include <stdio.h>
#include "../asm_define.h"

int var_arr(int a, int b, int c, int d, int e, int f, int n,
            int arr[n][n]  // 并非传入拷贝，而是传入指针。可能数组是在栈上分配的，但传入的一定是指针
) {
    arr[n / 2][n / 2] *= a + b + c + d + e + f;
    return arr[n / 2][n / 2];
}

void print_arr(int len, int a[len]) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

ASM_DEFINE(matrix_mul, int m, int n, int k, int a[m][k], int b[k][n], int c[m][n]) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int tot = 0;
            for (int u = 0; u < k; ++u) {
                tot += a[i][u] * b[u][j];
            }
            c[i][j] = tot;
        }
    }
    return 0;
}

void matrix_print(int m, int n, int mat[m][n]) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void matrix_clear(int m, int n, int mat[m][n]) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j] = 0;
        }
    }
}

int main(int argc, char ** argv) {
#define m 2
#define n 3
#define k 2
    int a[m][k] = {
        {1, 2},
        {3, 4},
    };
    int b[k][n] = {
        {2, 4, 1},
        {1, 1, 1},
    };
    int c[m][n];
    matrix_clear(m, n, c);
    asm_matrix_mul(m, n, k, a, b, c);
    matrix_print(m, n, c);
    return 0;
}