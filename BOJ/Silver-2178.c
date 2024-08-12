#include <stdio.h>
#include <stdlib.h>

#define MAX_VER 10000
#define MAX_LEN 100

// int DFS_Visited[MAX_VER+1];
int BFS_Visited[MAX_VER+1];
int Map[MAX_LEN+1][MAX_LEN+1];
// int Graph[MAX_VER+1][MAX_VER+1];
int Queue[MAX_VER+1];

// void DFS( int idx, int vertices );
void BFS( int idx, int n, int m );

int main( void )
{
    int n, m;
    scanf( "%d%d", &n, &m );

    int i, j;
    char c;
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= m; j++ )
        {
            scanf( " %c", &c );
            Map[i][j] = c - 48;
        }
    }
    
    // for ( i = 1; i <= n; i++ )
    // {
    //     for ( j = 1; j <= m; j++ )
    //     {
    //         if ( Map[i][j] == 1 && Map[i+1][j] == 1 )
    //         {
    //             Graph[(i-1)*m+j][i*m+j] = 1;
    //             Graph[i*m+j][(i-1)*m+j] = 1;
    //         }
    //         if ( Map[i][j] == 1 && Map[i][j+1] == 1 )
    //         {
    //             Graph[(i-1)*m+j][(i-1)*m+j+1] = 1;
    //             Graph[(i-1)*m+j+1][(i-1)*m+j] = 1;
    //         }
    //     }
    // }

    // for ( i = 1; i <= n; i++ )
    // {
    //     printf( "\n" );
    //     for ( j = 1; j <= m; j++ )
    //     {
    //         printf( "%d ", Map[i][j] );
    //     }
    // }
    // puts( "" );

    // int vertices = n*m;
    BFS( 1, n, m );

    // puts( "" );
    // for ( i = 1; i <= n; i++ )
    // {
    //     printf( "\n" );
    //     for ( j = 1; j <= m; j++ )
    //     {
    //         printf( "%d ", BFS_Visited[(i-1)*m+j] );
    //     }
    // }
    // puts( "" );

    return 0;
}

// void DFS( int idx, int vertices )
// {
//     DFS_Visited[idx] = 1;
//     printf( "%d ", idx );

//     int i;
//     for ( i = 1; i <= vertices; i++ )
//     {
//         if ( Graph[idx][i] == 1 && !DFS_Visited[i] )
//             DFS( i, vertices );
//     }
// }
void BFS( int idx, int n, int m )
{
    int front, rear;
    front = rear = 0;

    // printf( "%d ", idx );
    int depth = 1;
    BFS_Visited[idx] = depth;
    Queue[rear++] = idx;

    int i, j, pop;
    while ( front < rear )
    {
        pop = Queue[front++];
        depth = BFS_Visited[pop] + 1;

        int row = 1 + (pop-1)/m;
        int col = pop % m == 0 ? m : pop % m;
        // printf( "%d::: row: %d, col: %d\n", pop, row, col );
        if ( Map[row+1][col] == 1 && !BFS_Visited[row*m+col] )
        {
            // printf( "%d ", row*m+col );
            Queue[rear++] = row*m+col;
            BFS_Visited[row*m+col] = depth;
        }
        if ( Map[row][col+1] == 1 && !BFS_Visited[(row-1)*m+col+1] )
        {
            // printf( "%d ", (row-1)*m+col+1 );
            Queue[rear++] = (row-1)*m+col+1;
            BFS_Visited[(row-1)*m+col+1] = depth;
        }
        if ( Map[row-1][col] == 1 && !BFS_Visited[(row-2)*m+col] )
        {
            // printf( "%d ", (row-2)*m+col );
            Queue[rear++] = (row-2)*m+col;
            BFS_Visited[(row-2)*m+col] = depth;
        }
        if ( Map[row][col-1] == 1 && !BFS_Visited[(row-1)*m+col-1] )
        {
            // printf( "%d ", (row-1)*m+col-1 );
            Queue[rear++] = (row-1)*m+col-1;
            BFS_Visited[(row-1)*m+col-1] = depth;
        }
    }

    printf( "%d", BFS_Visited[n*m] );
}