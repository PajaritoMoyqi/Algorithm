#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100000

int Map[MAX_LEN+1];
int BFS_Visited[MAX_LEN+1];
int BFS_Route[MAX_LEN+1];
int BFS_Ans[MAX_LEN+1];
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
        BFS_Route[i] = -1;
    }

    BFS( start, target );
    
    // for ( i = 0; i <= target*2; i++ )
    // {
    //     printf( "%d - vis: %d, dist: %d, prev: %d\n", i, Map[i], BFS_Visited[i], BFS_Route[i] );
    // }

    printf( "%d\n", BFS_Visited[target] );

    int curr, prev;
    curr = prev = -1;
    int cnt = BFS_Visited[target];
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

    for ( i = 0; i <= BFS_Visited[target]; i++ )
        printf( "%d ", BFS_Ans[i] );

    return 0;
}

void BFS( int start, int target )
{
    int front, rear, time;
    front = rear = 0;
    time = 0;

    Map[start] = 1;
    BFS_Visited[start] = time;
    BFS_Route[start] = start;
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
                BFS_Route[1] = pop;
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
                BFS_Route[pop*2] = pop;
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
                BFS_Route[pop - 1] = pop;
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
                BFS_Route[pop + 1] = pop;
                Queue[rear++] = pop + 1;
            }

            if ( pop + 1 == target )
                goto end;
        }
    }

    end:

}