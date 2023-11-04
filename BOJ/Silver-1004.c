#include <stdio.h>
#include <math.h>

double distance( int xP, int yP, int x, int y );

int main( void )
{
    int xS, yS, xE, yE;
    int x, y, r, n, cnt;

    scanf( "%d", &n );
    
    while ( n-- )
    {
        cnt = 0;
        int m;
        scanf( "%d%d%d%d", &xS, &yS, &xE, &yE );
        scanf( "%d", &m );

        while ( m-- )
        {
            scanf( "%d%d%d", &x, &y, &r );
            double distS = distance( xS, yS, x, y );
            double distE = distance( xE, yE, x, y );

            if ( ( distS > r && distE < r ) 
                || ( distE > r && distS < r ) )
                cnt++;
            
            // printf( "distS: %f, distE: %f, r: %d, cnt: %d\n", distS, distE, r, cnt );
        }

        printf( "%d\n", cnt );
    }

    return 0;
}

double distance( int xP, int yP, int x, int y )
{
    return sqrt( (xP - x) * (xP - x) + (yP - y) * (yP - y) );
}