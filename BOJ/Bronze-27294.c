#include <stdio.h>

int main( void )
{
    int t, alcohol;
    scanf( "%d%d", &t, &alcohol );

    if ( t >= 12 && t <= 16 && alcohol == 0 )
        printf( "320" );
    else
        printf( "280\n" );

    return 0;
}