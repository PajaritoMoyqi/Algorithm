#include <stdio.h>

int main( void )
{
    int len;
    scanf( "%d", &len );

    int bigNum, smallNum;
    while ( len-- )
    {
        scanf( "%d%d", &bigNum, &smallNum );
        if ( bigNum - smallNum < 0 ) printf( "NO BRAINS\n" );
        else printf( "MMM BRAINS\n" );
    }

    return 0;
}