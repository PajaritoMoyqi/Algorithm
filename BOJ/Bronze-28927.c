#include <stdio.h>

enum elapsedTime
{
    TEASER = 3,
    SERIES = 20,
    MOVIE = 120
};

int main( void )
{
    int xT, xE, xF, lT, lE, lF;
    scanf( "%d%d%d %d%d%d", &xT, &xE, &xF, &lT, &lE, &lF );

    int xTotal = xT * TEASER + xE * SERIES + xF * MOVIE;
    int lTotal = lT * TEASER + lE * SERIES + lF * MOVIE;

    if ( xTotal > lTotal ) printf( "Max" );
    else if ( xTotal < lTotal ) printf( "Mel" );
    else printf( "Draw" );

    return 0;
}