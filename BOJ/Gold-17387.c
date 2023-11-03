#include <stdio.h>

int checkCCW( long long xA, long long yA, long long xB, long long yB, long long xC, long long yC );

int main( void )
{
    long long x1, y1, x2, y2, x3, y3, x4, y4;
    scanf( "%lld%lld%lld%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4 );

    int res1 = checkCCW( x1, y1, x2, y2, x3, y3 ) * checkCCW( x1, y1, x2, y2, x4, y4 ); 
    int res2 = checkCCW( x3, y3, x4, y4, x1, y1 ) * checkCCW( x3, y3, x4, y4, x2, y2 );

    if ( res1 == -1 && res2 == -1 ) printf( "1" );
    else
    {
        int flag = 0;

        if ( res1 == 0 )
        {
            if ( checkCCW( x1, y1, x2, y2, x3, y3 ) == 0 )
            {
                if ( ((x1 <= x3 && x3 <= x2) || (x1 >= x3 && x3 >= x2))
                    && ((y1 <= y3 && y3 <= y2) || (y1 >= y3 && y3 >= y2)) )
                {
                    flag = 1;
                    goto end;
                }
                else
                {
                    flag = 0;
                }
            }
            if ( checkCCW( x1, y1, x2, y2, x4, y4 ) == 0 )
            {
                if ( ((x1 <= x4 && x4 <= x2) || (x1 >= x4 && x4 >= x2))
                    && ((y1 <= y4 && y4 <= y2) || (y1 >= y4 && y4 >= y2)) )
                {
                    flag = 1;
                    goto end;
                }
                else
                {
                    flag = 0;
                }
            }
        }

        if ( res2 == 0 )
        {
            if ( checkCCW( x3, y3, x4, y4, x1, y1 ) == 0 )
            {
                if ( ((x3 <= x1 && x1 <= x4) || (x3 >= x1 && x1 >= x4))
                    && ((y3 <= y1 && y1 <= y4) || (y3 >= y1 && y1 >= y4)) )
                {
                    flag = 1;
                    goto end;
                }
                else
                {
                    flag = 0;
                }
            }
            if ( checkCCW( x3, y3, x4, y4, x2, y2 ) == 0 )
            {
                if ( ((x3 <= x2 && x2 <= x4) || (x3 >= x2 && x2 >= x4))
                    && ((y3 <= y2 && y2 <= y4) || (y3 >= y2 && y2 >= y4)) )
                {
                    flag = 1;
                    goto end;
                }
                else
                {
                    flag = 0;
                }
            }
        }

        end:
            printf( "%d", flag );
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