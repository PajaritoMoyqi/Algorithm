#include <stdio.h>
#define MAX 100000

long long ans[MAX+1][4];

int main( void )
{
    ans[1][1] = 1LL;
    ans[2][2] = 1LL;
    ans[3][1] = 1LL;
    ans[3][2] = 1LL;
    ans[3][3] = 1LL;

    int i, j;
    for ( i = 4; i <= MAX; i++ )
    {
        for ( j = 1; j <= 3; j++ )
        {
            if ( j == 1 ) ans[i][j] = (ans[i-j][2] + ans[i-j][3]) % 1000000009;
            else if ( j == 2 ) ans[i][j] = (ans[i-j][1] + ans[i-j][3]) % 1000000009;
            else ans[i][j] = (ans[i-j][1] + ans[i-j][2]) % 1000000009;
        }
    }

    int t;
    scanf( "%d", &t );

    int n;
    while ( t-- )
    {
        scanf( "%d", &n );
        printf( "%d\n", (ans[n][1] + ans[n][2] + ans[n][3]) % 1000000009 );
    }

    return 0;
}