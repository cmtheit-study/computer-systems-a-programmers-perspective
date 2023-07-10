#include "../show_bytes.h"
#include "tsub_ok.h"

int main() {
    printf("%d %d %d %d\n", tsub_ok(1, 2), tsub_ok(-100, 1), tsub_ok(100, -1), tsub_ok(-1, -232323));
    printf("%d %d %d %d\n", tsub_ok(INT_MIN, INT_MIN), tsub_ok(INT_MIN, INT_MAX), tsub_ok(INT_MAX, INT_MIN), tsub_ok(INT_MAX, INT_MAX));
}
  
