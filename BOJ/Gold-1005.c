#include <stdio.h>
#include <memory.h>

#define max(a, b) a > b ? a : b
#define MAX_LEN 1000

int DP[MAX_LEN+1];
int Visited[MAX_LEN+1];
int Relation[MAX_LEN+1][MAX_LEN+1];

int DFS( int idx, int num );

int main( void )
{
    int t;
    scanf( "%d", &t );

    while ( t-- )
    {
        memset( DP, 0, sizeof( DP ) );
        memset( Visited, -1, sizeof( Visited ) );
        memset( Relation, 0, sizeof( Relation ) );

        int n, cmpN;
        scanf( "%d%d", &n, &cmpN );

        int i;
        for ( i = 1; i <= n; i++ )
            scanf( "%d", &DP[i] );

        int v1, v2;
        for ( i = 0; i < cmpN; i++ )
        {
            scanf( "%d%d", &v1, &v2 );
            Relation[v1][v2] = 1;
        }

        int target;
        scanf( "%d", &target );
        printf( "%d\n", DFS( target, n ) );
    }
}
int DFS( int idx, int num )
{
    if ( ~Visited[idx] )
        return Visited[idx];

    int time = 0;
    int i;
    for ( i = 1; i <= num; i++ )
        if ( Relation[i][idx] )
            time = max( time, DFS( i, num ) );

    return Visited[idx] = time + DP[idx];
} 