#include <stdio.h>

int main( void )
{
    int i;
    scanf( "%d", &i );

    if ( i % 7 == 1 || i % 7 == 3 ) printf( "CY" );
    else printf( "SK" );

    return 0;
}