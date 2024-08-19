#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000

typedef struct _Queue {
    int x;
    int y;
} Queue;

int BFS_Visited[MAX_LEN+1][MAX_LEN+1];
int Map[MAX_LEN+1][MAX_LEN+1];
void BFS( int row, int col, int n, int m, Queue* Q );

int main( void )
{
    int n, m;
    scanf( "%d%d", &n, &m );
    
    Queue* Q = (Queue*)calloc( n*m+1, sizeof( Queue ) );

    int i, j;
    int startI, startJ;
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= m; j++ )
        {
            scanf( "%d", &Map[i][j] );
            if ( Map[i][j] == 2 )
            {
                startI = i;
                startJ = j;
            }
        }
    }

    BFS( startI, startJ, n, m, Q );

    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= m; j++ )
        {
            if ( Map[i][j] == 1 && !BFS_Visited[i][j] )
                printf( "%d ", -1 );
            else
                printf( "%d ", BFS_Visited[i][j] );
        }
        puts( "" );
    }

    return 0;
}
void BFS( int row, int col, int n, int m, Queue* Q )
{
    int front, rear;
    front = rear = 0;

    int depth = 0;
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
}