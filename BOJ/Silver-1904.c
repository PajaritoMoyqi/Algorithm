#include <stdio.h>

int fib[1000000+1];

int main( void )
{
    int n;
    scanf( "%d", &n );

    fib[1] = 1;
    fib[2] = 2;

    int i;
    for( i = 3; i <= n; i++ )
        fib[i] = (fib[i-1] + fib[i-2]) % 15746;

    printf( "%d", fib[n] );

    return 0;
}