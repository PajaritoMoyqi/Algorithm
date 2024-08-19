#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

int DFS_Visited[MAX_LEN+1][MAX_LEN+1];
int Map[MAX_LEN+1][MAX_LEN+1];
int Ans[MAX_LEN*MAX_LEN];

int DFS( int row, int column, int size );

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i, j;
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= n; j++ )
        {
            scanf( "%d", &Map[i][j] );
        }
    }

    int max = 1;
    int k;
    for ( k = 1; k <= 100; k++ )
    {
        int cnt = 0;
        for ( i = 1; i <= n; i++ )
        {
            for ( j = 1; j <= n; j++ )
            {
                DFS_Visited[i][j] = 0;
            }
        }

        for ( i = 1; i <= n; i++ )
        {
            for ( j = 1; j <= n; j++ )
            {
                if ( !DFS_Visited[i][j] && Map[i][j] > k )
                {
                    DFS( i, j, k );
                    cnt++;
                }
            }
        }
        max = max > cnt ? max : cnt;
    }

    printf( "%d", max );

    return 0;
}

int DFS( int row, int column, int limit )
{
    DFS_Visited[row][column] = 1;

    if ( Map[row-1][column] > limit && !DFS_Visited[row-1][column] )
        DFS( row-1, column, limit );
    if ( Map[row][column-1] > limit && !DFS_Visited[row][column-1] )
        DFS( row, column-1, limit );
    if ( Map[row+1][column] > limit && !DFS_Visited[row+1][column] )
        DFS( row+1, column, limit );
    if ( Map[row][column+1] > limit && !DFS_Visited[row][column+1] )
        DFS( row, column+1, limit );
}