#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODE 100000

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
    int gateN, planeN;
    scanf( "%d %d", &gateN, &planeN );

    int m, cnt = 0;
    int i, j;
    for ( i = 0; i < planeN; i++ )
    {
        scanf( "%d", &m );

        int tmp, j = m;
        while ( j > 0 && Visited[j] > 0 )
        {
            tmp = Visited[j];
            Visited[j]++;
            j = j - tmp;
        }

        if ( j <= 0 )
            break;
        else
        {
            Visited[j] = 1;
            cnt++;
        }
    }

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