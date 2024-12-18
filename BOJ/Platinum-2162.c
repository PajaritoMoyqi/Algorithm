#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_NODE 3000

typedef struct _Node
{
    int data;
    long long x1, y1, x2, y2;
    int parent;
} Node;

Node N[MAX_NODE+1];
int Visited[MAX_NODE+1];

int FindParent( int idx );
void Union( int x, int y );

int checkCCW( long long xA, long long yA, long long xB, long long yB, long long xC, long long yC );

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 1; i <= n; i++ )
    {
        scanf( "%lld%lld%lld%lld", &N[i].x1, &N[i].y1, &N[i].x2, &N[i].y2 );
        N[i].data = i;
        N[i].parent = i;
    }

    int j;
    for ( i = 1; i < n; i++ )
    {
        for ( j = i+1; j <= n; j++ )
        {
            if ( FindParent( i ) == FindParent( j ) )
                continue;

            int res1 = checkCCW( N[i].x1, N[i].y1, N[i].x2, N[i].y2, N[j].x1, N[j].y1 );
            int res2 = checkCCW( N[i].x1, N[i].y1, N[i].x2, N[i].y2, N[j].x2, N[j].y2 );

            int res3 = checkCCW( N[j].x1, N[j].y1, N[j].x2, N[j].y2, N[i].x1, N[i].y1 );
            int res4 = checkCCW( N[j].x1, N[j].y1, N[j].x2, N[j].y2, N[i].x2, N[i].y2 );

            if ( res1*res2 <= 0 && res3*res4 <= 0 )
            {
                if ( res1*res2 == 0 && res3*res4 == 0 )
                {
                    if ( (N[i].x1 > N[j].x1 && N[i].x1 > N[j].x2 && N[i].x2 > N[j].x1 && N[i].x2 > N[j].x2)
                        || (N[j].x1 > N[i].x1 && N[j].x1 > N[i].x2 && N[j].x2 > N[i].x1 && N[j].x2 > N[i].x2) )
                        continue;
                    else if ( (N[i].y1 > N[j].y1 && N[i].y1 > N[j].y2 && N[i].y2 > N[j].y1 && N[i].y2 > N[j].y2)
                        || (N[j].y1 > N[i].y1 && N[j].y1 > N[i].y2 && N[j].y2 > N[i].y1 && N[j].y2 > N[i].y2) )
                        continue;
                }
                
                Union( i, j );
            }
        }
    }

    int cnt = 0, par, max = 0;
    for ( i = 1; i <= n; i++ )
    {
        par = FindParent( i );

        if ( !Visited[par] )
            cnt++;

        Visited[par]++;

        max = max > Visited[par] ? max : Visited[par];
    }

    printf( "%d\n%d", cnt, max );

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

int checkCCW( long long xA, long long yA, long long xB, long long yB, long long xC, long long yC )
{
    long long xAB = (xB - xA);
    long long yAB = (yB - yA);
    long long xAC = (xC - xA); 
    long long yAC = (yC - yA);
    long long zAB = 0, zAC = 0;
    if ( xAB*yAC - xAC*yAB > 0 ) return 1;
    else if ( xAB*yAC - xAC*yAB < 0 ) return -1;
    else return 0;
}