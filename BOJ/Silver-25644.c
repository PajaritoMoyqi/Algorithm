#include <stdio.h>
#define max(x,y) (x) > (y) ? (x) : (y)

int Stock[200000];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 0; i < n; i++ )
        scanf( "%d", &Stock[i] );

    int m = 0, ans = 0;
    for ( i = n-1; i >= 0; i-- )
    {
        m = max( m, Stock[i] );
        ans = max( ans, m - Stock[i] );
    }

    printf( "%d", ans );

    return 0;
}