#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100000

int Map[MAX_LEN+1];
int BFS_Visited[MAX_LEN+1];
int Queue[MAX_LEN+1];

void BFS( int start, int target );
int powInt( int num, int times );

int main( void )
{
    int start, target;
    scanf( "%d%d", &start, &target );

    int i;
    for ( i = 0; i <= MAX_LEN; i++ )
    {
        Map[i] = -1;
        BFS_Visited[i] = -1;
    }

    BFS( start, target );
    
    // for ( i = 0; i <= target; i++ )
    // {
    //     printf( "%d, %d\n", Map[i], BFS_Visited[i] );
    // }
    printf( "%d", BFS_Visited[target] );

    return 0;
}

void BFS( int start, int target )
{
    int front, rear, time;
    front = rear = 0;
    time = 0;

    Map[start] = 1;
    BFS_Visited[start] = time;
    Queue[rear++] = start;

    int pop;
    while ( front < rear )
    {
        pop = Queue[front++];
        time = BFS_Visited[pop];

        int i;
        if ( pop == 0 )
        {
            if ( !~Map[1] )
                Map[1] = 1;
            if ( !~BFS_Visited[1] )
            {
                BFS_Visited[1] = time + 1;
                Queue[rear++] = 1;
            }

            if ( 1 == target )
                goto end;

            continue;
        }

        if ( pop*2 <= MAX_LEN )
        {
            if ( !~Map[pop*2] )
                Map[pop*2] = 1;
            if ( !~BFS_Visited[pop*2] )
            {
                BFS_Visited[pop*2] = time + 1;
                Queue[rear++] = pop*2;
            }

            if ( pop*2 == target )
                goto end;
        }

        if ( pop - 1 >= 0 )
        {
            if ( !~Map[pop - 1] )
                Map[pop - 1] = 1;
            if ( !~BFS_Visited[pop - 1] )
            {
                BFS_Visited[pop - 1] = time + 1;
                Queue[rear++] = pop - 1;
            }

            if ( pop - 1 == target )
                goto end;
        }

        if ( pop + 1 <= MAX_LEN )
        {
            if ( !~Map[pop + 1] )
                Map[pop + 1] = 1;
            if ( !~BFS_Visited[pop + 1] )
            {
                BFS_Visited[pop + 1] = time + 1;
                Queue[rear++] = pop + 1;
            }

            if ( pop + 1 == target )
                goto end;
        }
    }

    end:

}