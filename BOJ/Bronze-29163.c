#include <stdio.h>

int main( void )
{
    int t;
    scanf( "%d", &t );

    int oCnt = 0, eCnt = 0, givenNum;
    while ( t-- )
    {
        scanf( "%d", &givenNum );
        if ( givenNum & 1 ) oCnt++;
        else eCnt++;
    }

    if ( eCnt > oCnt ) printf( "Happy" );
    else printf( "Sad" );

    return 0;
}