#include <stdio.h>

fib[40+1];

int main( void )
{
    int n;
    scanf( "%d", &n );

    fib[1] = 1;
    fib[2] = 1;

    int i;
    for ( i = 3; i <= 40; i++ )
        fib[i] = fib[i-1] + fib[i-2];

    printf( "%d %d", fib[n], n - 2 );

    return 0;
}