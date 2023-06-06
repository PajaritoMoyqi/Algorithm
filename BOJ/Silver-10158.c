#include <stdio.h>
#include <math.h>

int main( void )
{
    int x, y;
    scanf( "%d %d", &x, &y );

    int initX, initY;
    scanf( "%d %d", &initX, &initY );

    int timeElapsed;
    scanf( "%d", &timeElapsed );

    x *= 2;
    y *= 2;

    int finalX, finalY;

    finalX = initX + timeElapsed;
    finalY = initY + timeElapsed;

    finalX %= x;
    finalY %= y;

    x /= 2;
    y /= 2;

    printf( "%d %d", x - abs( x - finalX ), y - abs( y - finalY ) );

    return 0;
}