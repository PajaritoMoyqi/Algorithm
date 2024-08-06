#include <stdio.h>
#include <stdlib.h>

int X[35];
int Y[35];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int x, y;
    int i;
    for ( i = 0; i < n; i++ )
        scanf( "%d%d", &X[i], &Y[i] );

    int area, maxArea = 0;
    int j, k;
    for ( i = 0; i < n; i++ )
    {
        for ( j = i+1; j < n; j++ )
        {
            for ( k = i+2; k < n; k++ )
            {
                area = abs(X[i]*Y[j] + X[j]*Y[k] + X[k]*Y[i] - X[j]*Y[i] - X[k]*Y[j] - X[i]*Y[k]);
                maxArea = maxArea > area ? maxArea : area;
            }
        }
    }

    if ( maxArea & 1 )
        printf( "%d.5", maxArea/2 );
    else
        printf( "%d", maxArea/2 );

    return 0;
}