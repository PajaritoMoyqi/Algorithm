#include <stdio.h>

int main( void )
{
    int n, min = 1000000000, max = 0, num;
    scanf( "%d", &n );

    int i;
    for ( i = 0; i < n; i++ )
    {
        scanf( "%d", &num );

        if ( num < min )
            min = num;
        if ( num > max )
            max = num;
    }

    printf( "%d", 2 * (max - min) );

    return 0;
}