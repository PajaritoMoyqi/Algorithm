#include <stdio.h>

int main( void )
{
    long long x, k, sum = 0;
    scanf( "%lld%lld", &x, &k );

    int i, j;
    for ( i = 0, j = 0; j < 32; i++, j++ )
    {
        while ( (1LL << i) & x )
            i++;

        if ( (1LL << j) & k )
            sum += (1LL << i);
    }

    printf( "%lld", sum );

    return 0;
}