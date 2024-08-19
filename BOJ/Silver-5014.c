#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000000

int BFS_Dist[MAX_LEN+1];
int Queue[MAX_LEN+1];

int BFS( int limit, int start, int target, int up, int down );

int main( void )
{
    int height, start, target, up, down;
    scanf( "%d%d%d%d%d", &height, &start, &target, &up, &down );

    int i;
    for ( i = 0; i <= MAX_LEN; i++ )
    {
        BFS_Dist[i] = -1;
    }

    // for ( i = 0; i <= target; i++ )
    // {
    //     printf( "%d, %d\n", Map[i], BFS_Dist[i] );
    // }

    int ans = BFS( height, start, target, up, down );
    if ( !~ans )
        printf( "use the stairs" );
    else
        printf( "%d", ans );


    return 0;
}

int BFS( int limit, int start, int target, int up, int down )
{
    int front, rear, time;
    front = rear = 0;
    time = 0;

    BFS_Dist[start] = time;
    Queue[rear++] = start;

    int pop;
    while ( front < rear )
    {
        pop = Queue[front++];
        time = BFS_Dist[pop];

        if ( pop - down > 0 )
        {
            if ( !~BFS_Dist[pop - down] )
            {
                BFS_Dist[pop - down] = time + 1;
                Queue[rear++] = pop - down;
            }

            if ( pop - down == target )
                goto end;
        }

        if ( pop + up <= limit )
        {
            if ( !~BFS_Dist[pop + up] )
            {
                BFS_Dist[pop + up] = time + 1;
                Queue[rear++] = pop + up;
            }

            if ( pop + up == target )
                goto end;
        }
    }

    end:
    return BFS_Dist[target];
}