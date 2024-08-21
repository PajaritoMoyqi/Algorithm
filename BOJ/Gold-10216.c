#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CIRCLE 3000
#define MAX_PAYMENT 10000000

typedef struct _Circle
{
    int x;
    int y;
    int radius;
    int parent;
} Circle;

Circle C[MAX_CIRCLE+1];
int Visited[MAX_CIRCLE+1];

int FindParent( int idx );
void Union( int x, int y );

int main( void )
{
    int t;
    scanf( "%d", &t );

    while ( t-- )
    {
        int circleNum;
        scanf( "%d", &circleNum );

        int i;
        for ( i = 1; i <= circleNum; i++ )

        for ( i = 1; i <= circleNum; i++ )
        {
            scanf( "%d%d%d", &C[i].x, &C[i].y, &C[i].radius );
            C[i].parent = i;
            Visited[i] = 0;
        }

        int j;
        for ( i = 1; i <= circleNum; i++ )
            for ( j = i+1; j <= circleNum; j++ )
            {
                double dist = sqrt( ( C[i].x - C[j].x )*( C[i].x - C[j].x ) + ( C[i].y - C[j].y )*( C[i].y - C[j].y ) );
                
                if ( dist <= (double)C[i].radius + C[j].radius )
                {
                    Union( i, j );
                }
            }

        int par = -1;
        int cnt = 0;
        for ( i = 1; i <= circleNum; i++ )
        {
            par = FindParent( i );
            // printf( "par: %d, Visited: %d\n", par, Visited[par] );
            if ( !Visited[par] )
            {
                cnt++;
                Visited[par] = 1;
                // printf( "cnt: %d, par: %d\n", cnt, par );
            }
        }

        // for ( i = 1; i <= circleNum; i++ )
        //     printf( "%d ", FindParent( i ) );
        // puts( "" );
        // for ( i = 1; i <= circleNum; i++ )
        //     printf( "%d ", Visited[i] );
        // puts( "" );

        printf( "%d\n", cnt );
    }

    return 0;
}

int FindParent( int idx )
{
    if ( C[idx].parent == idx ) return idx;
    else return C[idx].parent = FindParent( C[idx].parent );
}
void Union( int x, int y )
{
    int xParent = FindParent( x );
    int yParent = FindParent( y );

    if ( xParent != yParent )
    {
        if ( xParent < yParent )
            C[yParent].parent = xParent;
        else
            C[xParent].parent = yParent;
    }
}