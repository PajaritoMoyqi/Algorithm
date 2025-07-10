#include <stdio.h>

int main( void )
{
    int n, m;
    scanf( "%d%d", &n, &m );

    int Wanted[n][m];
    int Condition[n][m];

    int i, j;
    for ( i = 0; i < n; i++ )
    {
        getchar();
        for ( j = 0; j < m; j++ )
        {
            char c;
            scanf( "%c", &c );
            if ( c == 'R' )
                Wanted[i][j] = 1;
            else if ( c == 'G' )
                Wanted[i][j] = 2;
            else if ( c == 'B' )
                Wanted[i][j] = 4;
            else
                Wanted[i][j] = 0;
        }
    }

    for ( i = 0; i < n; i++ )
    {
        getchar();
        for ( j = 0; j < m; j++ )
        {
            scanf( "%1d", &Condition[i][j] );
        }
    }

    for ( i = 0; i < n; i++ )
    {
        for ( j = 0; j < m; j++ )
        {
            if ( Wanted[i][j] & Condition[i][j] || !Wanted[i][j] )
            {
                continue;
            }
            else
            {
                printf( "%s", "incorrect" );
                return 0;
            }
        }
    }

    printf( "%s", "correct" );
    return 0;
}