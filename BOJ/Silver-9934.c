#include <stdio.h>

#define MAX_FLOOR 10
#define MAX_NUM 1024

int Input[MAX_NUM];
int Tree[MAX_FLOOR][MAX_NUM];
int idx = 0;

void findRoot( int start, int end, int depth, int maxDepth );

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    int num = 1;
    for ( i = 0; i < n; i++ )
        num *= 2;

    for ( i = 0; i < num; i++ )
        scanf( "%d", &Input[i] );

    findRoot( 0, num-1, 0, n );

    int j;
    for ( i = 0; i < n; i++ )
    {
        for ( j = 0; j < num; j++ )
        {
            if ( Tree[i][j] )
                printf( "%d ", Tree[i][j] );
        }
        
        puts( "" );
    }

    return 0;
}

void findRoot( int start, int end, int depth, int maxDepth )
{
    if ( depth == maxDepth )
        return;

    int mid = (start+end) / 2;
    Tree[depth++][idx++] = Input[mid];

    findRoot( start, mid - 1, depth, maxDepth );
    findRoot( mid + 1, end, depth, maxDepth );
}