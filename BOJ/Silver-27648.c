#include <stdio.h>

int main( void )
{
    int n, m, max;
    scanf( "%d%d%d", &n, &m, &max );

    if ( n + m - 1 <= max )
    {
        printf( "YES\n" );
        int i, j;
        for ( i = 1; i <= n; i++ )
        {
            for ( j = 0; j < m; j++ )
            {
                printf( "%d ", i + j );
            }

            printf( "\n" );
        }
    }
    else
        printf( "NO" );

    return 0;
}