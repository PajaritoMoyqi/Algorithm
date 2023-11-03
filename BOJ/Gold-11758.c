#include <stdio.h>

int getCCW( int xA, int yA, int xB, int yB, int xC, int yC );

int main( void )
{
    int x1, y1, x2, y2, x3, y3;
    scanf( "%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3 );

    int res = getCCW( x1, y1, x2, y2, x3, y3 );

    if ( res > 0 ) printf( "1" );
    else if ( res < 0 ) printf( "-1" );
    else printf( "0" );

    return 0;
}

int getCCW( int xA, int yA, int xB, int yB, int xC, int yC )
{
    int xAB = (xB - xA);
    int yAB = (yB - yA);
    int xAC = (xC - xA); 
    int yAC = (yC - yA);
    int zAB = 0, zAC = 0;

    return xAB*yAC - xAC*yAB;
}