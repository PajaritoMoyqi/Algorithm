#include <stdio.h>

int main( void )
{
    int i;
    scanf( "%d", &i );

    if ( i & 1 ) printf( "SK" );
    else printf( "CY" );

    return 0;
}