#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 25

int BFS_Visited[MAX_LEN*MAX_LEN+1];
int Map[MAX_LEN+1][MAX_LEN+1];
int Queue[MAX_LEN*MAX_LEN+1];
int Ans[MAX_LEN*MAX_LEN];

int cmp( const void* _elem1, const void* _elem2 );
int BFS( int idx, int n, int m );

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
            if ( Map[i][j] == 1 && !BFS_Visited[(i-1)*n+j] )
            {
                Ans[idx++] = BFS( (i-1)*n+j, n, n );
                cnt++;
            }
        }
    }

    qsort( Ans, cnt, sizeof( int ), cmp );
    printf( "%d\n", cnt );
    for ( i = 0; i < cnt; i++ )
        printf( "%d\n", Ans[i] );

    return 0;
}

int BFS( int idx, int n, int m )
{
    int front, rear;
    front = rear = 0;

    BFS_Visited[idx] = 1;
    Queue[rear++] = idx;

    int pop;
    while ( front < rear )
    {
        pop = Queue[front++];

        int row = 1 + (pop-1)/m;
        int col = pop % m == 0 ? m : pop % m;
        // printf( "pop: %d, row: %d, col: %d, front: %d\n", pop, row, col, front );
        if ( Map[row+1][col] == 1 && !BFS_Visited[row*m+col] )
        {
            if ( row*m+col > n*m || row+1 < 1 || col < 1 || row+1 > n || col > m )
                continue;

            Queue[rear++] = row*m+col;
            BFS_Visited[row*m+col] = 1;
        }
        if ( Map[row][col+1] == 1 && !BFS_Visited[(row-1)*m+col+1] )
        {
            if ( (row-1)*m+col+1 > n*m || row < 1 || col+1 < 1 || row > n || col+1 > m )
                continue;

            Queue[rear++] = (row-1)*m+col+1;
            BFS_Visited[(row-1)*m+col+1] = 1;
        }
        if ( Map[row-1][col] == 1 && !BFS_Visited[(row-2)*m+col] )
        {
            if ( (row-2)*m+col < 1 || row-1 < 1 || col < 1 || row-1 > n || col > m )
                continue;

            Queue[rear++] = (row-2)*m+col;
            BFS_Visited[(row-2)*m+col] = 1;
        }
        if ( Map[row][col-1] == 1 && !BFS_Visited[(row-1)*m+col-1] )
        {
            if ( (row-1)*m+col-1 < 1 || row < 1 || col-1 < 1 || row > n || col-1 > m  )
                continue;

            Queue[rear++] = (row-1)*m+col-1;
            BFS_Visited[(row-1)*m+col-1] = 1;
        }
    }

    return rear;
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