#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODE 1000

typedef struct _Node
{
    int data;
    int parent;
} Node;

Node N[MAX_NODE+1];
int Visited[MAX_NODE+1];

int FindParent( int idx );
void Union( int x, int y );

int main( void )
{
    int t;
    scanf( "%d", &t );

    while ( t-- )
    {
        int n, m;
        scanf( "%d", &n );
        scanf( "%d", &m );

        int i;
        for ( i = 1; i <= n; i++ )
        {
            N[i].data = i;
            N[i].parent = i;
        }

        int x, y, xPar, yPar;
        int cnt = 0;
        for ( i = 1; i <= m; i++ )
        {
            scanf( "%d%d", &x, &y );
            xPar = FindParent( x );
            yPar = FindParent( y );

            if ( xPar != yPar )
                Union( x, y );
            else
                cnt++;
        }

        int par = -1;
        for ( i = 1; i <= n; i++ )
        {
            par = FindParent( i );
            if ( par == i )
                cnt++;
        }

        if ( cnt - 1 == 0 )
            printf( "tree\n" );
        else
            printf( "graph\n" );
    }

    return 0;
}

int FindParent( int idx )
{
    if ( N[idx].parent == idx ) return idx;
    else return N[idx].parent = FindParent( N[idx].parent );
}
void Union( int x, int y )
{
    int xParent = FindParent( x );
    int yParent = FindParent( y );

    if ( xParent != yParent )
    {
        if ( xParent < yParent )
            N[yParent].parent = xParent;
        else
            N[xParent].parent = yParent;
    }
}