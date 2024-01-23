#include <stdio.h>

int DFS_Visited[100+1];
int BFS_Visited[100+1];
int Graph[100+1][100+1];
int Queue[100+1];

void DFS( int startIdx, int vertices );
void BFS( int startIdx, int vertices );

int main( void )
{
    int vertices, edges, idx = 1;
    scanf( "%d%d", &vertices, &edges );

    int i, j;
    while ( edges-- )
    {
        scanf( "%d%d", &i, &j );
        Graph[i][j] = 1;
        Graph[j][i] = 1;
    }

    BFS( idx, vertices );

    int sum = -1;
    for ( i = 1; i <= vertices; i++ )
        if ( BFS_Visited[i] )
            sum++;

    printf( "%d", sum );

    return 0;
}

void DFS( int startIdx, int vertices )
{
    DFS_Visited[startIdx] = 1;
    printf( "%d ", startIdx );

    int i;
    for ( i = 1; i <= vertices; i++ )
    {
        if ( Graph[startIdx][i] == 1 && !DFS_Visited[i] )
            DFS( i, vertices );
    }
}
void BFS( int startIdx, int vertices )
{
    int front, rear;
    front = rear = 0;

    BFS_Visited[startIdx] = 1;
    Queue[rear++] = startIdx;

    int i, pop;
    while ( front < rear )
    {
        pop = Queue[front++];
        for ( i = 1; i <= vertices; i++ )
        {
            if ( Graph[pop][i] == 1 && !BFS_Visited[i] )
            {
                Queue[rear++] = i;
                BFS_Visited[i] = 1;
            }
        }
    }
}