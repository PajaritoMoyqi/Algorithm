#include <stdio.h>

int main( void )
{
    int n, num;
    scanf( "%d", &n );

    int max = 0, min = 0;
    int i;
    for ( i = 0; i < n; i++ )
    {
        scanf( "%d", &num );

        if ( num < 0 )
            num = -num;

        max += num;
    }
    for ( i = 0; i < n; i++ )
    {
        scanf( "%d", &num );

        if ( num < 0 )
            num = -num;

        min += num;
    }

    printf( "%d", max + min );

    return 0;
}