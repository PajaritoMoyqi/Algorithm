#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100000

int Map[MAX_LEN+1];
int BFS_Dist[MAX_LEN+1];
int BFS_Cnt[MAX_LEN+1];
int Queue[MAX_LEN+1];

int BFS( int start, int target );
int powInt( int num, int times );

int main( void )
{
    int start, target;
    scanf( "%d%d", &start, &target );

    int i;
    for ( i = 0; i <= MAX_LEN; i++ )
    {
        Map[i] = -1;
        BFS_Dist[i] = -1;
    }

    int cnt = BFS( start, target );
    
    // for ( i = 0; i <= target; i++ )
    // {
    //     printf( "%d, %d\n", Map[i], BFS_Dist[i] );
    // }
    printf( "%d\n", BFS_Dist[target] );
    printf( "%d", cnt );

    return 0;
}

int BFS( int start, int target )
{
    int front, rear, time;
    front = rear = 0;
    time = 0;

    Map[start] = 1;
    BFS_Dist[start] = time;
    BFS_Cnt[start] = 1;
    Queue[rear++] = start;

    int pop;
    int flag = 0;
    int limit = -1;
    while ( front < rear )
    {
        pop = Queue[front++];
        time = BFS_Dist[pop];
        if ( flag && time > limit )
            break;

        int i;
        if ( pop == 0 )
        {
            if ( !~Map[1] )
                Map[1] = 1;
            if ( !~BFS_Dist[1] )
            {
                BFS_Dist[1] = time + 1;
                BFS_Cnt[1] = BFS_Cnt[pop];
                Queue[rear++] = 1;
            }
            else if ( BFS_Dist[1] == time + 1 )
            {
                BFS_Cnt[1] += BFS_Cnt[pop];
            }

            if ( 1 == target )
            {
                flag = 1;
                limit = BFS_Dist[1];
                continue;
            }

            continue;
        }

        if ( pop*2 <= MAX_LEN )
        {
            if ( !~Map[pop*2] )
                Map[pop*2] = 1;
            if ( !~BFS_Dist[pop*2] )
            {
                BFS_Dist[pop*2] = time + 1;
                BFS_Cnt[pop*2] = BFS_Cnt[pop];
                Queue[rear++] = pop*2;
            }
            else if ( BFS_Dist[pop*2] == time + 1 )
            {
                BFS_Cnt[pop*2] += BFS_Cnt[pop];
            }

            if ( pop*2 == target )
            {
                flag = 1;
                limit = BFS_Dist[pop*2];
            }
        }

        if ( pop - 1 >= 0 )
        {
            if ( !~Map[pop - 1] )
                Map[pop - 1] = 1;
            if ( !~BFS_Dist[pop - 1] )
            {
                BFS_Dist[pop - 1] = time + 1;
                BFS_Cnt[pop - 1] = BFS_Cnt[pop];
                Queue[rear++] = pop - 1;
            }
            else if ( BFS_Dist[pop - 1] == time + 1 )
            {
                BFS_Cnt[pop - 1] += BFS_Cnt[pop];
            }

            if ( pop - 1 == target )
            {
                flag = 1;
                limit = BFS_Dist[pop - 1];
            }
        }

        if ( pop + 1 <= MAX_LEN )
        {
            if ( !~Map[pop + 1] )
                Map[pop + 1] = 1;
            if ( !~BFS_Dist[pop + 1] )
            {
                BFS_Dist[pop + 1] = time + 1;
                BFS_Cnt[pop + 1] = BFS_Cnt[pop];
                Queue[rear++] = pop + 1;
            }
            else if ( BFS_Dist[pop + 1] == time + 1 )
            {
                BFS_Cnt[pop + 1] += BFS_Cnt[pop];
            }

            if ( pop + 1 == target )
            {
                flag = 1;
                limit = BFS_Dist[pop + 1];
            }
        }
    }

    return BFS_Cnt[target];
}