#include <stdio.h>

int main( void )
{
    long long i;
    scanf( "%lld", &i );

    if ( i & 1LL ) printf( "SK" );
    else printf( "CY" );

    return 0;
}