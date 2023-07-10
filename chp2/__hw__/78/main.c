#include "../show_bytes.h"
#include "divide_power2.h"

int main() {
    int a1 = -25, a2 = 25;
    printf("%d %d %d %d\n", a1 / 2, divide_power2(a1, 1), a2 / 2, divide_power2(a2, 1));
    printf("%d %d %d %d\n", a1 / 4, divide_power2(a1, 2), a2 / 4, divide_power2(a2, 2));
    printf("%d %d %d %d\n", a1 / 8, divide_power2(a1, 3), a2 / 8, divide_power2(a2, 3));
}
  
