#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 50

int DFS_Visited[MAX_LEN+1][MAX_LEN+1];
int Map[MAX_LEN+1][MAX_LEN+1];
int Ans[MAX_LEN*MAX_LEN];

int DFS( int row, int column );

int main( void )
{
    while ( 1 )
    {
        int w, h;
        scanf( "%d%d", &w, &h );
        if ( !w && !h )
            break;

        int i, j;
        for ( i = 1; i <= h; i++ )
        {
            for ( j = 1; j <= w; j++ )
            {
                DFS_Visited[i][j] = 0;
                scanf( "%d", &Map[i][j] );
            }
        }

        int cnt = 0;
        for ( i = 1; i <= h; i++ )
        {
            for ( j = 1; j <= w; j++ )
            {
                if ( !DFS_Visited[i][j] && Map[i][j] == 1 )
                {
                    DFS( i, j );
                    cnt++;
                }
            }
        }

        printf( "%d\n", cnt );
    }


    return 0;
}

int DFS( int row, int column )
{
    DFS_Visited[row][column] = 1;

    if ( Map[row-1][column] == 1 && !DFS_Visited[row-1][column] )
        DFS( row-1, column );
    if ( Map[row][column-1] == 1 && !DFS_Visited[row][column-1] )
        DFS( row, column-1 );
    if ( Map[row+1][column] == 1 && !DFS_Visited[row+1][column] )
        DFS( row+1, column );
    if ( Map[row][column+1] == 1 && !DFS_Visited[row][column+1] )
        DFS( row, column+1 );
    if ( Map[row-1][column-1] == 1 && !DFS_Visited[row-1][column-1] )
        DFS( row-1, column-1 );
    if ( Map[row+1][column+1] == 1 && !DFS_Visited[row+1][column+1] )
        DFS( row+1, column+1 );
    if ( Map[row-1][column+1] == 1 && !DFS_Visited[row-1][column+1] )
        DFS( row-1, column+1 );
    if ( Map[row+1][column-1] == 1 && !DFS_Visited[row+1][column-1] )
        DFS( row+1, column-1 );
}