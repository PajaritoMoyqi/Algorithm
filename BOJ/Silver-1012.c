#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 50

int DFS_Visited[MAX_LEN+1][MAX_LEN+1];
int Map[MAX_LEN+1][MAX_LEN+1];
int Ans[MAX_LEN*MAX_LEN];

int DFS( int row, int column, int size );

int main( void )
{
    int n;
    scanf( "%d", &n );

    while ( n-- )
    {
        int i, j;
        for ( i = 1; i <= MAX_LEN; i++ )
        {
            for ( j = 1; j <= MAX_LEN; j++ )
            {
                Map[i][j] = 0;
                DFS_Visited[i][j] = 0;
            }
        }

        int row, col, num;
        scanf( "%d%d%d", &row, &col, &num );

        while ( num-- )
        {
            int pRow, pCol;
            scanf( "%d%d", &pRow, &pCol );

            Map[pRow+1][pCol+1] = 1;
        }

        int cnt = 0;
        for ( i = 1; i <= row; i++ )
        {
            for ( j = 1; j <= col; j++ )
            {
                if ( Map[i][j] == 1 && !DFS_Visited[i][j] )
                    Ans[cnt++] = DFS( i, j, 0 );
            }
        }

        printf( "%d\n", cnt );
    }

    return 0;
}

int DFS( int row, int column, int size )
{
    DFS_Visited[row][column] = 1;
    size++;

    if ( Map[row-1][column] && !DFS_Visited[row-1][column] )
        size = DFS( row-1, column, size );
    if ( Map[row][column-1] && !DFS_Visited[row][column-1] )
        size = DFS( row, column-1, size );
    if ( Map[row+1][column] && !DFS_Visited[row+1][column] )
        size = DFS( row+1, column, size );
    if ( Map[row][column+1] && !DFS_Visited[row][column+1] )
        size = DFS( row, column+1, size );

    return size;
}