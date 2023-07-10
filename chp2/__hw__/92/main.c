#include "../float_bits.h"
#include <limits.h>
#include <assert.h>
#include <pthread.h>

int all_tests = 32;
int unwrap_num = 8;

typedef struct {
    int number;
    pthread_t pid;
} test_routine_s;

void * test_routine(void * arg) {
    test_routine_s * test_arg = (test_routine_s *) arg;
    for (register unsigned long i = test_arg->number * unwrap_num; i < UINT_MAX; i += all_tests * unwrap_num) {
        printf("\x1b[%d;0H%d: 测试：i = %lu -> %lu", test_arg->number + 1, test_arg->number, i, i + unwrap_num - 1);
        assert(-bits2float(i) == bits2float(float_negate(i)));
        assert(-bits2float(i + 1) == bits2float(float_negate(i + 1)));
        assert(-bits2float(i + 2) == bits2float(float_negate(i + 2)));
        assert(-bits2float(i + 3) == bits2float(float_negate(i + 3)));
        assert(-bits2float(i + 4) == bits2float(float_negate(i + 4)));
        assert(-bits2float(i + 5) == bits2float(float_negate(i + 5)));
        assert(-bits2float(i + 6) == bits2float(float_negate(i + 6)));
        assert(-bits2float(i + 7) == bits2float(float_negate(i + 7)));
    }
}

int main() {
    test_routine_s trss[all_tests];
    for (register int i = 0; i < all_tests; ++i) {
        trss[i].number = i;
        pthread_create(&trss[i].pid, NULL, test_routine, trss + i);
    }
    for (register int i = 0; i < all_tests; ++i) {
        pthread_join(trss[i].pid, NULL);
    }
}
  
