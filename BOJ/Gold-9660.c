#include <stdio.h>

int main( void )
{
    long long int i;
    scanf( "%lld", &i );

    if ( i == 1LL ) printf( "SK" );
    else if ( i == 2LL ) printf( "CY" );
    else
    {
        if ( i % 7LL == 0 || i % 7LL == 2 ) printf( "CY" );
        else printf( "SK" );
    }

    return 0;
}