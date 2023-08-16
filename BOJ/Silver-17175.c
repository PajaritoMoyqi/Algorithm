#include <stdio.h>

#define MAX 50

int main( void )
{
    int n;
    int dp[MAX+1] = { 0 };
    scanf( "%d", &n );
    dp[0] = 1;
    dp[1] = 1;

    int i;
    for ( i = 2; i <= n; i++ )
    {
        dp[i] = (dp[i-1] + dp[i-2] + 1) % 1000000007;
    }

    printf( "%d", dp[n] );

    return 0;
}