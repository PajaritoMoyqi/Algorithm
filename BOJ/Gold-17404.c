#include <stdio.h>

#define MAX_N 1000
#define MAX_COLOR 3

int cost[MAX_N+1][MAX_COLOR+1];
int ans[MAX_N+1][MAX_COLOR+1];

int min( int x, int y );

int main( void )
{
    int N;
    scanf( "%d", &N );

    int i, j;
    for ( i = 1; i <= N; i++ )
        for ( j = 1; j <= MAX_COLOR; j++ )
            scanf( "%d", &cost[i][j] );

    int s;
    int res = MAX_N*MAX_N + 1;
    for ( s = 1; s <= MAX_COLOR; s++ )
    {
        for ( j = 1; j <= MAX_COLOR; j++ )
        {
            if ( s == j )
                ans[1][j] = cost[1][j];
            else
                ans[1][j] = MAX_N*MAX_N+1;
        }

        for ( i = 2; i <= N; i++ )
        {
            ans[i][1] = min( ans[i-1][2], ans[i-1][3] ) + cost[i][1];
            ans[i][2] = min( ans[i-1][1], ans[i-1][3] ) + cost[i][2];
            ans[i][3] = min( ans[i-1][1], ans[i-1][2] ) + cost[i][3];
        }

        for ( i = 1; i <= MAX_COLOR; i++ )
        {
            if ( s == i )
                continue;

            if ( ans[N][i] < res )
                res = ans[N][i];
        }
    }

    printf( "%d", res );

    return 0;
}

int min( int x, int y )
{
	  return x < y ? x : y;
}