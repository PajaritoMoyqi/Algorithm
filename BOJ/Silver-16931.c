#include <stdio.h>

char Tower[1 + 100 + 1][1 + 100 + 1];

int main( void )
{
    int n, m;
    scanf( "%d%d", &n, &m );

    int i, j;
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= m; j++ )
            scanf( "%d", &Tower[i][j] );

    int ans = 2*n*m;
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= m; j++ )
        {
            if ( Tower[i-1][j] < Tower[i][j] )
                ans += (Tower[i][j] - Tower[i-1][j]);
            if ( Tower[i+1][j] < Tower[i][j] )
                ans += (Tower[i][j] - Tower[i+1][j]);
            if ( Tower[i][j-1] < Tower[i][j] )
                ans += (Tower[i][j] - Tower[i][j-1]);
            if ( Tower[i][j+1] < Tower[i][j] )
                ans += (Tower[i][j] - Tower[i][j+1]);
        }

    printf( "%d", ans );

    return 0;
}