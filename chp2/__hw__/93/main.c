#include "../float_bits.h"
#include <math.h>

int main() {
    printf("%u, %u, %f, %f\n",
           float_absval(0xffffffff),
           float2bits(fabs(bits2float(0xffffffff))),
           bits2float(float_absval(float2bits(-0.333))),
           fabs(-0.333)
   );
}
  
