#include <stdio.h>
#define MAX 1000*1000

int cost[1000+1][3+1];
int ans[1000+1][3+1];

int min( int x, int y );

int main( void )
{
    int N;
    scanf( "%d", &N );

    int i, j;
    for ( i = 1; i <= N; i++ )
        for ( j = 1; j <= 3; j++ )
            scanf( "%d", &cost[i][j] );

    ans[1][1] = cost[1][1];
    ans[1][2] = cost[1][2];
    ans[1][3] = cost[1][3];

    for ( i = 2; i <= N; i++ )
    {
        ans[i][1] = min( ans[i-1][2], ans[i-1][3] ) + cost[i][1];
        ans[i][2] = min( ans[i-1][1], ans[i-1][3] ) + cost[i][2];
        ans[i][3] = min( ans[i-1][1], ans[i-1][2] ) + cost[i][3];
    }

    int res = MAX + 1;
    for ( i = 1; i <= 3; i++ )
        if ( ans[N][i] < res )
            res = ans[N][i];

    printf( "%d", res );

    return 0;
}

int min( int x, int y )
{
	  return x < y ? x : y;
}