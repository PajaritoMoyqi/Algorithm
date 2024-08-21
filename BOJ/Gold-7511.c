#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NEURON 1000000

typedef struct _Neuron
{
    int data;
    int parent;
} Neuron;

Neuron N[MAX_NEURON+1];

int FindParent( int idx );
void Union( int x, int y );

int main( void )
{
    int t;
    scanf( "%d", &t );

    int k;
    for ( k = 1; k <= t; k++ )
    {
        printf( "Scenario %d:\n", k );
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
        for ( i = 1; i <= m; i++ )
        {
            scanf( "%d%d", &x, &y );
            xPar = FindParent( x );
            yPar = FindParent( y );

            if ( xPar != yPar )
                Union( x, y );
        }

        int tt;
        scanf( "%d", &tt );
        for ( i = 1; i <= tt; i++ )
        {
            int flag = 0;
            scanf( "%d%d", &x, &y );
            xPar = FindParent( x );
            yPar = FindParent( y );

            if ( xPar == yPar )
                flag = 1;
            
            printf( "%d\n", flag );
        }

        puts( "" );
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