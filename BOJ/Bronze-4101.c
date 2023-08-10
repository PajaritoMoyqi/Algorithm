#include <stdio.h>

int main( void )
{
    int bigNum, smallNum;

    while ( 1 )
    {
        scanf( "%d%d", &bigNum, &smallNum );
        if ( !bigNum || !smallNum ) break;

        if ( bigNum - smallNum > 0 ) printf( "Yes\n" );
        else printf( "No\n" );
    }

    return 0;
}