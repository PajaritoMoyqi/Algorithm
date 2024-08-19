#include <stdio.h>

int DFS_Visited[1000+1];
int Graph[1000+1][1000+1];
int Queue[1000+1];

void DFS( int idx, int vertices );

int main( void )
{
    int vertices, edges;
    scanf( "%d%d", &vertices, &edges );

    int i, j;
    while ( edges-- )
    {
        scanf( "%d%d", &i, &j );
        Graph[i][j] = 1;
        Graph[j][i] = 1;
    }

    int cnt = 0;
    for ( i = 1; i <= vertices; i++ )
    {
        if ( !DFS_Visited[i] )
        {
            DFS( i, vertices );
            cnt++;
        }
    }

    printf( "%d", cnt );

    return 0;
}

void DFS( int startIdx, int vertices )
{
    DFS_Visited[startIdx] = 1;
    // printf( "%d ", startIdx );

    int i;
    for ( i = 1; i <= vertices; i++ )
    {
        if ( Graph[startIdx][i] == 1 && !DFS_Visited[i] )
            DFS( i, vertices );
    }
}