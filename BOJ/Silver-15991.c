#include <stdio.h>
#define MAX 100000

long long ans[MAX+1];

int main( void )
{
    ans[1] = 1LL;
    ans[2] = 2LL;
    ans[3] = 2LL;
    ans[4] = 3LL;
    ans[5] = 3LL;
    ans[6] = 6LL;

    int i;
    for ( i = 7; i <= MAX; i++ )
        ans[i] = (ans[i-2] + ans[i-4] + ans[i-6]) % 1000000009;

    int t;
    scanf( "%d", &t );

    int n;
    while ( t-- )
    {
        scanf( "%d", &n );
        printf( "%lld\n", ans[n] );
    }

    return 0;
}