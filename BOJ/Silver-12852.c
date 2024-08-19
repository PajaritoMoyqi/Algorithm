#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000000

int BFS_Dist[MAX_LEN+1];
int BFS_Route[MAX_LEN+1];
int BFS_Ans[MAX_LEN+1];
int Queue[MAX_LEN+1];

int BFS( int start, int target );
int powInt( int num, int times );

int main( void )
{
    int start;
    scanf( "%d", &start );
    int target = 1;

    int i;
    for ( i = 0; i <= MAX_LEN; i++ )
    {
        BFS_Dist[i] = -1;
    }

    // for ( i = 0; i <= target; i++ )
    // {
    //     printf( "%d, %d\n", Map[i], BFS_Dist[i] );
    // }

    int cnt = BFS( start, target );
    printf( "%d\n", cnt );
    
    if ( cnt )
    {
        int curr, prev;
        curr = prev = -1;
        while ( 1 )
        {
            if ( curr == -1 && prev == -1 )
            {
                BFS_Ans[cnt--] = target;
                curr = target;
            }
            
            BFS_Ans[cnt--] = BFS_Route[curr];

            prev = curr;
            curr = BFS_Route[curr];

            if ( curr == start )
            {
                BFS_Ans[cnt--] = start;
                break;
            }
        }

        for ( i = 0; i <= BFS_Dist[target]; i++ )
            printf( "%d ", BFS_Ans[i] );
    }
    else
    {
        printf( "1" );
    }


    return 0;
}

int BFS( int start, int target )
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

        if ( pop == 1 )
            goto end;

        if ( pop % 2 == 0 )
        {
            if ( !~BFS_Dist[pop/2] )
            {
                BFS_Dist[pop/2] = time + 1;
                BFS_Route[pop/2] = pop;
                Queue[rear++] = pop/2;
            }

            if ( pop/2 == target )
                goto end;
        }

        if ( pop % 3 == 0 )
        {
            if ( !~BFS_Dist[pop/3] )
            {
                BFS_Dist[pop/3] = time + 1;
                BFS_Route[pop/3] = pop;
                Queue[rear++] = pop/3;
            }

            if ( pop/3 == target )
                goto end;
        }


        if ( !~BFS_Dist[pop-1] )
        {
            BFS_Dist[pop-1] = time + 1;
            BFS_Route[pop-1] = pop;
            Queue[rear++] = pop-1;
        }

        if ( pop-1 == target )
            goto end;
    }

    end:
    return BFS_Dist[target];
}