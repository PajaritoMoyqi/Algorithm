#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000

typedef struct _Queue {
    int x;
    int y;
} Queue;

int BFS_Visited[MAX_LEN+1][MAX_LEN+1];
int Map[MAX_LEN+1][MAX_LEN+1];
int BFS( int row, int col, Queue* Q );

int main( void )
{
    int n, m, k;
    scanf( "%d%d%d", &n, &m, &k );

    int i;
    int px, py;
    for ( i = 1; i <= k; i++ )
    {
        scanf( "%d%d", &px, &py );
        Map[px][py] = 1;
    }

    int max = 0, cnt;
    int j;
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= m; j++ )
        {
            if ( Map[i][j] && !BFS_Visited[i][j] )
            {
                Queue* Q = (Queue*)calloc( n*m+1, sizeof( Queue ) );
                cnt = BFS( i, j, Q );
                max = max > cnt ? max : cnt;
            }
        }
    }

    printf( "%d", max );

    return 0;
}
int BFS( int row, int col, Queue* Q )
{
    int front, rear;
    front = rear = 0;

    int depth = 1;
    BFS_Visited[row][col] = depth;
    Q[rear].x = row;
    Q[rear].y = col;
    rear++;

    Queue Pop;
    while ( front < rear )
    {
        Pop = Q[front++];
        int pRow = Pop.x;
        int pCol = Pop.y;
        depth = BFS_Visited[pRow][pCol] + 1;
        
        if ( Map[pRow+1][pCol] == 1 && !BFS_Visited[pRow+1][pCol] )
        {
            Q[rear].x = pRow+1;
            Q[rear].y = pCol;
            BFS_Visited[pRow+1][pCol] = depth;
            rear++;
        }
        if ( Map[pRow][pCol+1] == 1 && !BFS_Visited[pRow][pCol+1] )
        {
            Q[rear].x = pRow;
            Q[rear].y = pCol+1;
            BFS_Visited[pRow][pCol+1] = depth;
            rear++;
        }
        if ( Map[pRow-1][pCol] == 1 && !BFS_Visited[pRow-1][pCol] )
        {
            Q[rear].x = pRow-1;
            Q[rear].y = pCol;
            BFS_Visited[pRow-1][pCol] = depth;
            rear++;
        }
        if ( Map[pRow][pCol-1] == 1 && !BFS_Visited[pRow][pCol-1] )
        {
            Q[rear].x = pRow;
            Q[rear].y = pCol-1;
            BFS_Visited[pRow][pCol-1] = depth;
            rear++;
        }
    }

    return rear;
}