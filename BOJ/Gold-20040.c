#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODE 500000

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
    int n, r;
    scanf( "%d%d", &n, &r );

    int i;
    for ( i = 1; i <= n; i++ )
    {
        N[i].data = i;
        N[i].parent = i;
    }

    int d1, d2, p1, p2;
    int cnt = 0, flag = 0;
    for ( i = 1; i <= r; i++ )
    {
        cnt++;
        scanf( "%d%d", &d1, &d2 );
        p1 = FindParent( d1 );
        p2 = FindParent( d2 );

        // printf( "%d, %d\n", p1, p2 );

        if ( p1 == p2 )
        {
            flag = 1;
            break;
        }
        else
            Union( d1, d2 );
    }

    if ( !flag )
        printf( "%d", 0 );
    else
        printf( "%d", cnt );

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