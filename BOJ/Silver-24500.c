#include <stdio.h>
#include <string.h>

int main( void )
{
    long long N;
    scanf( "%lld", &N );

    long long cmpN = 2; 
    while ( 1 )
    {
        if ( cmpN > N )
            break;

        cmpN *= 2;
    }

    if ( N == cmpN - 1 )
    {
        printf( "1\n" );
        printf( "%lld", N );
        return 0;
    }

    long long partNer = (cmpN-1) ^ N;
    printf( "2\n" );
    if ( partNer > N )
    {
        printf( "%lld\n", N );
        printf( "%lld", partNer );
    }
    else
    {
        printf( "%lld\n", partNer );
        printf( "%lld", N );
    }

    return 0;
}