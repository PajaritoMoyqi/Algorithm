#include<stdio.h>
#include<stdlib.h>
 
typedef struct _Queue {
    int x;
    int y;
    int order;
} Queue;
 
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
 
int n, m;
int front, rear;
void BFS( int** box, Queue* q, int y, int x );
 
int main( void )
{
    scanf( "%d %d", &m, &n );

    int** Map = (int**)calloc( n, sizeof( int* ) );
    int i;
    for ( i = 0; i < n; i++ )
        Map[i] = (int*)calloc( m, sizeof( int ) );
  
    int total = n*m;
    Queue* Q = (Queue*)calloc( n*m+1, sizeof( Queue ) );
    front = 0, rear = 0;
  
    int j;
    for ( i = 0; i < n; i++ )
    {
        for ( j = 0; j < m; j++ )
        {
            scanf( "%d", &Map[i][j] );
            if ( Map[i][j] == -1 )
                total--;
            else if ( Map[i][j] )
            {
                rear++;
                Q[rear].y = i;
                Q[rear].x = j;
                Q[rear].order = 0;
            }
        }
    }
    
    BFS( Map, Q, Q[0].y, Q[0].x );
  
    if ( total != rear )
        printf( "-1" );
    else
        printf( "%d", Q[rear].order );
  
    for ( i = 0; i < n; i++ )
        free( Map[i] );
    free( Map );

    return 0;
}
 
void BFS( int** Map, Queue* Q, int y, int x )
{
    while ( front < rear )
    {
        front++;

        int i;
        for ( i = 0; i < 4; i++ )
        {
            int ny = Q[front].y + dy[i];
            int nx = Q[front].x + dx[i];

            if ( ny < 0 || nx < 0 || ny >= n || nx >= m )
                continue;
            else
            {
                if ( !Map[ny][nx] )
                {
                    rear++;
                    Q[rear].y = ny;
                    Q[rear].x = nx;
                    Q[rear].order = Q[front].order + 1;
                    Map[ny][nx] = 1;
                }
            }
        }
    }
}