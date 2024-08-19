#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000

int BFS_Visited[MAX_LEN+1][MAX_LEN+1];
int Map[MAX_LEN+1][MAX_LEN+1];
int Queue[MAX_LEN*MAX_LEN+1];
int Ans[MAX_LEN*MAX_LEN];

int BFS( int row, int column, int n, int m );

int main( void )
{
    int m, n;
    scanf( "%d%d", &m, &n );

    int i, j;
    for ( i = 0; i <= n+1; i++ )
    {
        for ( j = 0; j <= m+1; j++ )
        {
            Map[i][j] = -1;
        }
    }
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= m; j++ )
        {
            scanf( "%d", &Map[i][j] );
        }
    }

    int cnt = 0, idx = 0;
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= m; j++ )
        {
            if ( Map[i][j] == 1 && !BFS_Visited[i][j] )
            {
                // printf( "start: %d, %d\n", i, j );
                Ans[idx++] = BFS( i, j, n, m );
                cnt++;
            }
        }
    }

    // puts( "" );
    // for ( i = 1; i <= n; i++ )
    // {
    //     puts( "" );
    //     for ( j = 1; j <= m; j++ )
    //     {
    //         printf( "%d ", Map[i][j] );
    //     }
    // }
    // puts( "" );
    // for ( i = 1; i <= n; i++ )
    // {
    //     puts( "" );
    //     for ( j = 1; j <= m; j++ )
    //     {
    //         printf( "%d ", BFS_Visited[i][j] );
    //     }
    // }
    // puts( "" );

    int flag = 0;
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= m; j++ )
        {
            if ( !Map[i][j] && !BFS_Visited[i][j] )
            {
                flag = 1;
                goto end;
            }
        }
    }

    end:
    int ans = 0;
    if ( !flag )
    {
        for ( i = 1; i <= n; i++ )
        {
            for ( j = 1; j <= m; j++ )
            {
                ans = ans < BFS_Visited[i][j] ? BFS_Visited[i][j] : ans;
            }
        }
    }
    printf( "%d", ans-1 );

    return 0;
}

int BFS( int row, int column, int n, int m )
{
    int front, rear;
    front = rear = 0;

    BFS_Visited[row][column] = 1;
    Queue[rear++] = (row-1)*m + column;

    int pop, depth = 1;
    while ( front < rear )
    {
        pop = Queue[front++];

        int pRow = (pop-1)/m + 1;
        int pCol = pop % m == 0 ? m : pop % m;
        int dist = abs( row - pRow ) + abs( column - pCol );
        depth = BFS_Visited[pRow][pCol];

        if ( Map[pRow+1][pCol] == 0 && ( !BFS_Visited[pRow+1][pCol] || BFS_Visited[pRow+1][pCol] > depth + 1 ) )
        {
            Queue[rear++] = (pRow)*m+pCol;
            BFS_Visited[pRow+1][pCol] = depth + 1;
            // printf( "bottom add: %d\n", (pRow)*m+pCol );
        }
        if ( Map[pRow][pCol+1] == 0 && ( !BFS_Visited[pRow][pCol+1] || BFS_Visited[pRow][pCol+1] > depth + 1 ) )
        {
            Queue[rear++] = (pRow-1)*m+pCol+1;
            BFS_Visited[pRow][pCol+1] = depth + 1;
            // printf( "right add: %d\n", (pRow-1)*m+pCol+1 );
        }
        if ( Map[pRow-1][pCol] == 0 && ( !BFS_Visited[pRow-1][pCol] || BFS_Visited[pRow-1][pCol] > depth + 1 ) )
        {
            Queue[rear++] = (pRow-2)*m+pCol;
            BFS_Visited[pRow-1][pCol] = depth + 1;
            // printf( "top add: %d\n", (pRow-2)*m+pCol );
        }
        if ( Map[pRow][pCol-1] == 0 && ( !BFS_Visited[pRow][pCol-1] || BFS_Visited[pRow][pCol-1] > depth + 1 ) )
        {
            Queue[rear++] = (pRow-1)*m+pCol-1;
            BFS_Visited[pRow][pCol-1] = depth + 1;
            // printf( "left add: %d\n", (pRow-1)*m+pCol-1 );
        }
    }

    return depth;
}