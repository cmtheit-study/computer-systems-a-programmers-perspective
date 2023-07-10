#include "../show_bytes.h"
#include <stdlib.h>
#include <assert.h>

int main() {
    for (int i = 0; i < 100000000; ++i) {
        int a = random();
        int b = random();
        int c = random();
        double da = (double) a;
        double db = (double) b;
        double dc = (double) c;
        assert(da - db == (double) (a - b));
    }
}
  
