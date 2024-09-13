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
        List[i] = i+1;

    DFS( 0, n );

    return 0;
}

void DFS( int depth, int maxDepth )
{
    int i;
    if ( depth == maxDepth )
    {
        int sum = 0;
        for( i = 0; i < maxDepth; i++ )
        {
            printf( "%d ", Nums[i] );
        }
        puts( "" );
    }
    
    for( i = 0; i < maxDepth; i++ )
    {
        if ( !Visited[i] )
        {
            Visited[i] = 1;
            Nums[depth] = List[i];

            DFS( depth + 1, maxDepth );

            Visited[i] = 0;
        }
    }
}