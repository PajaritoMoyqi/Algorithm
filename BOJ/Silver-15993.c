#include <stdio.h>
#define MAX 100000

long long ans[MAX+1][2];

int main( void )
{
    ans[1][0] = 0LL;
    ans[1][1] = 1LL;
    ans[2][0] = 1LL;
    ans[2][1] = 1LL;
    ans[3][0] = 2LL;
    ans[3][1] = 2LL;

    int i, j;
    for ( i = 4; i <= MAX; i++ )
        for ( j = 0; j <= 1; j++ )
            ans[i][j] = (ans[i-1][j ? 0 : 1] + ans[i-2][j ? 0 : 1] + ans[i-3][j ? 0 : 1]) % 1000000009 ;

    int t;
    scanf( "%d", &t );

    int n;
    while ( t-- )
    {
        scanf( "%d", &n );
        printf( "%d %d\n", ans[n][1], ans[n][0] );
    }

    return 0;
}