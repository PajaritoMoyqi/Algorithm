#include <stdio.h>

long long fib[90+1];

int main( void )
{
    int n;
    scanf( "%d", &n );

    fib[0] = 0LL;
    fib[1] = 1LL;
    fib[2] = 1LL;

    int i;
    for ( i = 3; i <= n; i++ )
        fib[i] = fib[i-1] + fib[i-2];

    printf( "%lld", fib[n] );
    
    return 0;
}