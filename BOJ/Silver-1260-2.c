#include <stdio.h>

int DFS_Visited[1000+1];
int BFS_Visited[1000+1];
int Graph[1000+1][1000+1];
int Queue[1000+1];

void DFS( int idx, int vertices );
void BFS( int idx, int vertices );

int main( void )
{
    int vertices, edges, idx;
    scanf( "%d%d%d", &vertices, &edges, &idx );

    int i, j;
    while ( edges-- )
    {
        scanf( "%d%d", &i, &j );
        Graph[i][j] = 1;
        Graph[j][i] = 1;
    }

    DFS( idx, vertices );
    puts( "" );
    BFS( idx, vertices );

    return 0;
}

void DFS( int idx, int vertices )
{
    DFS_Visited[idx] = 1;
    printf( "%d ", idx );

    int i;
    for ( i = 1; i <= vertices; i++ )
    {
        if ( Graph[idx][i] == 1 && !DFS_Visited[i] )
            DFS( i, vertices );
    }
}
void BFS( int idx, int vertices )
{
    int front, rear;
    front = rear = 0;

    printf( "%d ", idx );
    BFS_Visited[idx] = 1;
    Queue[rear++] = idx;

    int i, pop;
    while ( front < rear )
    {
        pop = Queue[front++];
        for ( i = 1; i <= vertices; i++ )
        {
            if ( Graph[pop][i] == 1 && !BFS_Visited[i] )
            {
                printf( "%d ", i );
                Queue[rear++] = i;
                BFS_Visited[i] = 1;
            }
        }
    }
}