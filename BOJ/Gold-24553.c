#include <stdio.h>

int main( void )
{
    int t;
    long long ll;
    scanf( "%d", &t );

    int i;
    for ( i = 0; i < t; i++ )
    {
        scanf( "%lld", &ll );
        if ( ll % 10LL ) printf( "0\n" );
        else printf( "1\n" );
    }

    return 0;
}