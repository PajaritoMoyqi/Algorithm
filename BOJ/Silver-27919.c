#include <stdio.h>
#include <string.h>

char K[100000];

int main( void )
{
    scanf( "%s", K );
    int len = strlen( K );

    if ( !len )
    {
        printf( "C" );
        return 0;
    }

    int cntU = 0, cntD = 0;

    int i;
    for ( i = 0; i < len; i++ )
    {
        if ( K[i] == 'D' || K[i] == 'P' )
            cntD++;
        else
            cntU++;
    }

    if ( cntD >= 2*cntU - 1 )
        printf( "DP" );
    else if ( 2*cntD - 1 <= cntU && !cntD )
        printf( "U" );
    else
        printf( "UDP" );

    return 0;
}