#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

int DFS_Visited[MAX_LEN+1][MAX_LEN+1];
int DFS_B_Visited[MAX_LEN+1][MAX_LEN+1];
char Map[MAX_LEN+1][MAX_LEN+1];
int Ans[MAX_LEN*MAX_LEN];

int DFS( int row, int column, int size );
int DFS_Blind( int row, int column, int size );

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i, j;
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= n; j++ )
        {
            scanf( " %c", &Map[i][j] );
        }
    }

    int cnt = 0;
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= n; j++ )
        {
            if ( !DFS_Visited[i][j] )
            {
                DFS( i, j, 0 );
                cnt++;
            }
        }
    }
    int B_cnt = 0;
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= n; j++ )
        {
            if ( !DFS_B_Visited[i][j] )
            {
                DFS_Blind( i, j, 0 );
                B_cnt++;
            }
        }
    }

    printf( "%d %d", cnt, B_cnt );

    return 0;
}

int DFS( int row, int column, int size )
{
    DFS_Visited[row][column] = 1;
    size++;
    char c = Map[row][column];

    if ( Map[row-1][column] == c && !DFS_Visited[row-1][column] )
        size = DFS( row-1, column, size );
    if ( Map[row][column-1] == c && !DFS_Visited[row][column-1] )
        size = DFS( row, column-1, size );
    if ( Map[row+1][column] == c && !DFS_Visited[row+1][column] )
        size = DFS( row+1, column, size );
    if ( Map[row][column+1] == c && !DFS_Visited[row][column+1] )
        size = DFS( row, column+1, size );

    return size;
}
int DFS_Blind( int row, int column, int size )
{
    DFS_B_Visited[row][column] = 1;
    size++;
    char c = Map[row][column];

    if ( c == 'R' || c == 'G' )
    {
        if ( ( Map[row-1][column] == 'R' || Map[row-1][column] == 'G' ) && !DFS_B_Visited[row-1][column] )
            size = DFS_Blind( row-1, column, size );
        if ( ( Map[row][column-1] == 'R' || Map[row][column-1] == 'G' ) && !DFS_B_Visited[row][column-1] )
            size = DFS_Blind( row, column-1, size );
        if ( ( Map[row+1][column] == 'R' || Map[row+1][column] == 'G' ) && !DFS_B_Visited[row+1][column] )
            size = DFS_Blind( row+1, column, size );
        if ( ( Map[row][column+1] == 'R' || Map[row][column+1] == 'G' ) && !DFS_B_Visited[row][column+1] )
            size = DFS_Blind( row, column+1, size );
    }
    else
    {
        if ( Map[row-1][column] == c && !DFS_B_Visited[row-1][column] )
            size = DFS_Blind( row-1, column, size );
        if ( Map[row][column-1] == c && !DFS_B_Visited[row][column-1] )
            size = DFS_Blind( row, column-1, size );
        if ( Map[row+1][column] == c && !DFS_B_Visited[row+1][column] )
            size = DFS_Blind( row+1, column, size );
        if ( Map[row][column+1] == c && !DFS_B_Visited[row][column+1] )
            size = DFS_Blind( row, column+1, size );
    }

    return size;
}