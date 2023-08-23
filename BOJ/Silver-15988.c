#include <stdio.h>
#define MAX 1000000

long long ans[MAX+1];

int main( void )
{
    ans[1] = 1LL;
    ans[2] = 2LL;
    ans[3] = 4LL;

    int i;
    for ( i = 4; i <= MAX; i++ )
        ans[i] = (ans[i-1] + ans[i-2] + ans[i-3]) % 1000000009 ;

    int t;
    scanf( "%d", &t );

    int n;
    while ( t-- )
    {
        scanf( "%d", &n );
        printf( "%d\n", ans[n] );
    }

    return 0;
}