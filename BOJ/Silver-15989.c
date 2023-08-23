#include <stdio.h>
#define MAX 100000

long long ans[MAX+1];

int main( void )
{
    ans[1] = 1LL;
    ans[2] = 2LL;
    ans[3] = 3LL;
    ans[4] = 4LL;
    ans[5] = 5LL;

    int i;
    for ( i = 6; i <= MAX; i++ )
    {
        if ( i % 6 == 1 ) ans[i] += (ans[i-1] + i/6);
        else ans[i] += (ans[i-1] + i/6 + 1);
    }

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