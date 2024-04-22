#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    int n;
    scanf( "%d", &n );

    int x, y, prevX, prevY, prevX2, prevY2, max = 0, prevLen, currLen, len = 0;
    int i;
    for ( i = 0; i < n; i++ )
    {
        scanf( "%d%d", &x, &y );

        if ( i )
        {
            currLen = abs( x - prevX ) + abs( y - prevY );
            len += currLen;

            int diff, jumpLen;
            if ( i > 1 )
            {
                jumpLen = abs( x - prevX2 ) + abs( y - prevY2 );
                diff = currLen + prevLen - jumpLen;

                max = diff > max ? diff : max;
            }
        }

        prevLen = currLen;
        prevX2 = prevX; prevY2 = prevY;
        prevX = x; prevY = y;
    }

    printf( "%d", len - max );

    return 0;
}