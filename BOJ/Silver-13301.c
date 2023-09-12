#include <stdio.h>

long long fib[80+1];
long long res[80+1];

int main( void )
{
    int i, n;
    scanf( "%d", &n );

    fib[1] = 1;
    for ( i = 2; i <= 80; i++ )
        fib[i] = fib[i-1] + fib[i-2];

    res[1] = 4;
    for ( i = 2; i <= 80; i++ )
        res[i] = res[i-1] + fib[i]*2;

    printf( "%lld", res[n] );

    return 0;
}