#include <stdio.h>

int fib[1000+1];

int main( void )
{
    fib[0] = 1;
    fib[1] = 1;

    int i;
    for ( i = 2; i <= 1000; i++ )
        fib[i] = (fib[i-1] + fib[i-2]) % 10007;

    int n;
    scanf( "%d", &n );
    
    printf( "%d", fib[n] );

    return 0;
}