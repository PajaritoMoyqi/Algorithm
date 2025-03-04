#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    uint32_t coef = (uint32_t)1 << 31;

    while ( n )
    {
        if ( n & 1 )
            ans += coef;

        coef >>= 1;
        n >>= 1;
    }

    return ans;
}