#include <stdio.h>
#include <math.h>

int main( void )
{
    int width, height, x, y, players;
    scanf( "%d%d%d%d%d", &width, &height, &x, &y, &players );

    int radius = height / 2;

    int cnt = 0;
    while ( players-- )
    {
        int pX, pY;
        scanf( "%d%d", &pX, &pY );

        if ( pX < x - radius || pX > x + width + radius || pY < y || pY > y + height )
            continue;
        else
        {
            if ( x <= pX && pX <= x + width )
            {
                if ( y <= pY && pY <= y + height )
                    cnt++;
            }
            else
            {
                int cX, cY = y + radius;
                if ( pX < x )
                    cX = x;
                else
                    cX = x + width;

                double len = pow( cX - pX, 2.0 ) + pow( cY - pY, 2.0 );
                double rad = pow( radius, 2.0 );

                if ( len <= rad )
                    cnt++;
            }
        }
    }

    printf( "%d", cnt );

    return 0;
}