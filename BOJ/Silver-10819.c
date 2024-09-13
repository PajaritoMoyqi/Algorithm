#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp( const void* _elem1, const void* _elem2 );

#define MAX_NODE 8

int List[MAX_NODE+1];
int Visited[MAX_NODE+1];
int Nums[MAX_NODE+1];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 0; i < n; i++ )
        scanf( "%d", &List[i] );

    int ans = 0;
    DFS( 0, n, &ans );

    printf( "%d", ans );

    return 0;
}

void DFS( int depth, int maxDepth, int* ans )
{
    int i;
    if ( depth == maxDepth )
    {
        int sum = 0;
        for( i = 0; i < maxDepth-1; i++ )
        {
            sum += abs( Nums[i] - Nums[i+1] );
        }

        // for( i = 0; i < maxDepth; i++ )
        //     printf( "%d ", Nums[i] );
        // puts( "" );
        // printf( "sum: %d\n", sum );

        (*ans) = (*ans) > sum ? (*ans) : sum;
    }
    
    for( i = 0; i < maxDepth; i++ )
    {
        if ( !Visited[i] )
        {
            Visited[i] = 1;
            Nums[depth] = List[i];

            DFS( depth + 1, maxDepth, ans );

            Visited[i] = 0;
        }
    }
}