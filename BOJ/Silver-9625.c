#include <stdio.h>

long long fib[45+1];

int main( void )
{
    int k;
    scanf( "%d", &k );

    fib[1] = 1;
    fib[2] = 1;

    int i;
    for ( i = 3; i <= k; i++ )
        fib[i] = fib[i-1] + fib[i-2];

    printf( "%lld %lld", fib[k-1], fib[k] );

    return 0;
}