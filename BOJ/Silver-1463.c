#include <stdio.h>

#define MAX 1000000

int main( void )
{
    int n;
    int dp[MAX+1] = { 0 };
    scanf( "%d", &n );
    dp[1] = 0;

    int i;
    for ( i = 2; i <= n; i++ )
    {
        dp[i] = dp[i-1] + 1;
        if ( !(i % 2) && (dp[i] > dp[i/2] + 1) )
            dp[i] = dp[i/2] + 1;
        if ( !(i % 3) && (dp[i] > dp[i/3] + 1) )
            dp[i] = dp[i/3] + 1;
    }

    printf( "%d", dp[n] );

    return 0;
}