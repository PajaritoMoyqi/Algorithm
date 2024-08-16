#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 25

int DFS_Visited[MAX_LEN+1][MAX_LEN+1];
int Map[MAX_LEN+1][MAX_LEN+1];
int Ans[MAX_LEN*MAX_LEN];

int cmp( const void* _elem1, const void* _elem2 );
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
            scanf( "%1d", &Map[i][j] );
        }
    }

    int cnt = 0, idx = 0;
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= n; j++ )
        {
            if ( Map[i][j] == 1 && !DFS_Visited[i][j] )
                Ans[cnt++] = DFS( i, j, 0 );
        }
    }

    qsort( Ans, cnt, sizeof( int ), cmp );
    printf( "%d\n", cnt );
    for ( i = 0; i < cnt; i++ )
        printf( "%d\n", Ans[i] );

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
int cmp( const void* _elem1, const void* _elem2 )
{
    int* elem1 = (int*)_elem1;
    int* elem2 = (int*)_elem2;

    if ( *elem1 > *elem2 )
        return 1;
    else if ( *elem1 < *elem2 )
        return -1;
    else
        return 0;
}