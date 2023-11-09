#include <stdio.h>

int main( void )
{
    int a, x, b, n;
    scanf( "%d", &n );

    while ( n-- )
    {
        scanf( "%d%d%d", &a, &b, &x );
        printf( "%d\n", a * (x - 1) + b );
    }
    
    return 0;
}