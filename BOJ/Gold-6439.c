#include <stdio.h>

int checkCCW( long long xA, long long yA, long long xB, long long yB, long long xC, long long yC );

int main( void )
{
    int n;
    scanf( "%d", &n );

    while ( n-- )
    {
        int x1, y1, x2, y2, xA, yA, xB, yB;
        scanf( "%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &xA, &yA, &xB, &yB );

        int res1 = checkCCW( x1, y1, x2, y2, xA, yA );
        int res2 = checkCCW( x1, y1, x2, y2, xA, yB );
        int res3 = checkCCW( x1, y1, x2, y2, xB, yA );
        int res4 = checkCCW( x1, y1, x2, y2, xB, yB );

        int res5 = checkCCW( xA, yA, xA, yB, x1, y1 );
        int res6 = checkCCW( xA, yA, xB, yA, x1, y1 );
        int res7 = checkCCW( xA, yA, xB, yA, x2, y2 );
        int res8 = checkCCW( xA, yA, xA, yB, x2, y2 );
        int res9 = checkCCW( xA, yB, xB, yB, x1, y1 );
        int res10 = checkCCW( xA, yB, xB, yB, x2, y2 );
        int res11 = checkCCW( xB, yA, xB, yB, x1, y1 );
        int res12 = checkCCW( xB, yA, xB, yB, x2, y2 );

        // printf( "res1: %d, res2: %d, res3: %d, res4: %d\n", res1, res2, res3, res4 );

        // given line crosses to a line of square
        if ( ( res1 * res2 == -1 && res5 * res8 == -1 ) || ( res1 * res3 == -1 && res6 * res7 == -1  )
            || ( res2 * res4 == -1 && res9 * res10 == -1 ) || ( res3 * res4 == -1 && res11 * res12 == -1 ) )
        {
            printf( "T\n" );
        }
        // given line edges to a line of square
        else if ( (res1 == 0 && ((x1 <= xA && xA <= x2) || (x2 <= xA && xA <= x1)) && ((y1 <= yA && yA <= y2) || (y2 <= yA && yA <= y1)))
            || (res2 == 0 && ((x1 <= xA && xA <= x2) || (x2 <= xA && xA <= x1)) && ((y1 <= yB && yB <= y2) || (y2 <= yB && yB <= y1)))
            || (res3 == 0 && ((x1 <= xB && xB <= x2) || (x2 <= xB && xB <= x1)) && ((y1 <= yA && yA <= y2) || (y2 <= yA && yA <= y1)))
            || (res4 == 0 && ((x1 <= xB && xB <= x2) || (x2 <= xB && xB <= x1)) && ((y1 <= yB && yB <= y2) || (y2 <= yB && yB <= y1))) )
        {
            printf( "T\n" );
        }
        // given line is in the square
        else if ( (((xA <= x1 && x1 <= xB) || (xB <= x1 && x1 <= xA)) && ((xA <= x2 && x2 <= xB) || (xB <= x2 && x2 <= xA)))
                && (((yA <= y1 && y1 <= yB) || (yB <= y1 && y1 <= yA)) && ((yA <= y2 && y2 <= yB) || (yB <= y2 && y2 <= yA))) )
        {
            printf( "T\n" );
        }
        else
            printf( "F\n" );
    }

    return 0;
}

int checkCCW( long long xA, long long yA, long long xB, long long yB, long long xC, long long yC )
{
    long long xAB = (xB - xA);
    long long yAB = (yB - yA);
    long long xAC = (xC - xA); 
    long long yAC = (yC - yA);
    long long zAB = 0, zAC = 0;

    if ( xAB*yAC - xAC*yAB > 0 ) return 1;
    else if ( xAB*yAC - xAC*yAB < 0 ) return -1;
    else return 0;
}