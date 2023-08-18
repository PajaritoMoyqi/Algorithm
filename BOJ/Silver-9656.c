#include <stdio.h>

int main( void )
{
    int i;
    scanf( "%d", &i );

    if ( i & 1 ) printf( "CY" );
    else printf( "SK" );

    return 0;
}