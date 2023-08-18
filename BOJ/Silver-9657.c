#include <stdio.h>

int main( void )
{
    int i;
    scanf( "%d", &i );

    if ( i == 1) printf( "SK" );
    else if ( i == 2 ) printf( "CY" );
    else
    {
        if ( i % 7 == 0 || i % 7 == 2 ) printf( "CY" );
        else printf( "SK" );
    }

    return 0;
}