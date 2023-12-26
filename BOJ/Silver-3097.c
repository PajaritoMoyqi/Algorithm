#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main( void )
{
    int n, i;
    scanf( "%d", &n );

    int Points[n][2];
    for ( i = 0; i < n; i++ )
        scanf( "%d%d", &Points[i][0], &Points[i][1] );

    int ansX = 0, ansY = 0;
    for ( i = 0; i < n; i++ )
    {
        ansX += Points[i][0];
        ansY += Points[i][1];
    }

    for ( i = 0; i < n; i++ )
    {
        Points[i][0] -= ansX;
        Points[i][1] -= ansY;
    }

    double ans = 0, candidate;
    for ( i = 0; i < n; i++ )
    {
        if ( i == 0 )
            ans = sqrt( pow( Points[i][1], 2 ) + pow( Points[i][0], 2 ) );
        else
        {
            candidate = sqrt( pow( Points[i][1], 2 ) + pow( Points[i][0], 2 ) );
            if ( candidate < ans )
                ans = candidate;
        }
    }

    printf( "%d %d\n%.2f", ansX, ansY, ans );

    return 0;
}