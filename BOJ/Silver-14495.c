#include <stdio.h>

#define MAX 116

int main( void )
{
    int n;
    long long int dp[MAX+1] = { 0 };
    scanf( "%d", &n );
    dp[1] = 1LL;
    dp[2] = 1LL;
    dp[3] = 1LL;

    int i;
    for ( i = 4; i <= n; i++ )
    {
        dp[i] = dp[i-1] + dp[i-3];
    }

    printf( "%lld", dp[n] );

    return 0;
}