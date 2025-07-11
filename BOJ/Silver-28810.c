#include <stdio.h>

int main( void )
{
    long long n, a;
    scanf( "%lld%lld", &n, &a );

    long long max = (long long)1 << (n-1);

    long long maxAns = a, minAns = 0;
    while ( max )
    {
        if ( !( max & a ) && maxAns == a )
        {
            maxAns = a + max;
        }

        if ( ( max & a ) && !minAns )
        {
            minAns = a - max;
        }

        max >>= 1;
    }

    printf( "%lld %lld", minAns, maxAns );

    return 0;
}