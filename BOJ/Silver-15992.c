#include <stdio.h>
#define MAX 1000

long long ans[MAX+1][MAX+1];

int main( void )
{
    ans[1][1] = 1LL;
    ans[2][1] = 1LL;
    ans[2][2] = 1LL;
    ans[3][1] = 1LL;
    ans[3][2] = 2LL;
    ans[3][3] = 1LL;

    int i, j;
    for ( i = 4; i <= MAX; i++ )
        for ( j = (i-1)/3 + 1; j <= i; j++ )
            ans[i][j] = (ans[i-1][j-1] + ans[i-2][j-1] + ans[i-3][j-1]) % 1000000009;

    int t;
    scanf( "%d", &t );

    int n, m;
    while ( t-- )
    {
        scanf( "%d%d", &n, &m );
        printf( "%d\n", ans[n][m] );
    }

    return 0;
}