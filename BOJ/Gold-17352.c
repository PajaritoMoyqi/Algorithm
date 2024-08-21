#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ISLAND 300000

typedef struct _Island
{
    int data;
    int parent;
} Island;

Island I[MAX_ISLAND+1];
int Visited[MAX_ISLAND+1];

int FindParent( int idx );
void Union( int x, int y );

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 1; i <= n; i++ )
        I[i].parent = i;

    int x, y, xPar, yPar;
    for ( i = 1; i <= n-2; i++ )
    {
        scanf( "%d%d", &x, &y );
        xPar = FindParent( x );
        yPar = FindParent( y );

        if ( xPar != yPar )
            Union( x, y );
    }

    int par = -1;
    int island1 = 0, island2 = 0;
    for ( i = 1; i <= n; i++ )
    {
        par = FindParent( i );
        if ( !Visited[par] )
        {
            Visited[par] = 1;
            if ( !island1 )
                island1 = i;
            else
                island2 = i;
        }
    }

    printf( "%d %d", island1, island2 );

    return 0;
}

int FindParent( int idx )
{
    if ( I[idx].parent == idx ) return idx;
    else return I[idx].parent = FindParent( I[idx].parent );
}
void Union( int x, int y )
{
    int xParent = FindParent( x );
    int yParent = FindParent( y );

    if ( xParent != yParent )
    {
        if ( xParent < yParent )
            I[yParent].parent = xParent;
        else
            I[xParent].parent = yParent;
    }
}