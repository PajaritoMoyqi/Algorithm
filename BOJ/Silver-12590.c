#include <stdio.h>

int main( void )
{
    int t;
    scanf( "%d", &t );

    int i;
    for ( i = 1; i <= t; i++ )
    {
        int bit, n;
        scanf( "%d%d", &bit, &n );

        n++;

        if ( !(n % (1 << bit)) )
            printf( "Case #%d: ON\n", i );
        else
            printf( "Case #%d: OFF\n", i );
    }

    return 0;
}