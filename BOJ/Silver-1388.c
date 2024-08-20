#include <stdio.h>

#define MAX_LEN 50

typedef struct _Point
{
    char data;
    int visited;
} Point;

Point Map[MAX_LEN+1][MAX_LEN+1];

DFS( int row, int col, int height, int width, char data );

int main( void )
{
    int n, m;
    scanf( "%d%d", &n, &m );

    int i, j;
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= m; j++ )
        {
            scanf( " %c", &Map[i][j].data );
            Map[i][j].visited = 0;
        }

    int cnt = 0;
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= m; j++ )
        {
            if ( !Map[i][j].visited )
            {
                // printf( "(%d, %d)\n", i, j );
                DFS( i, j, n, m, Map[i][j].data );
                cnt++;
            }
        }

    printf( "%d", cnt );

    return 0;
}

DFS( int row, int col, int height, int width, char data )
{
    Map[row][col].visited = 1;
    if ( data == '-' && Map[row][col+1].data == '-' && col + 1 <= width && !Map[row][col+1].visited )
        DFS( row, col+1, height, width, Map[row][col+1].data );
    else if ( data == '|' && Map[row+1][col].data == '|' && row + 1 <= height && !Map[row+1][col].visited )
        DFS( row+1, col, height, width, Map[row+1][col].data );
}