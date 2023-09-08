#include <stdio.h>

#ifndef max
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#endif

int given[10000+1];
int ans[10000+1];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 1; i <= n; i++ )
        scanf( "%d", &given[i] );

    ans[1] = given[1];
    ans[2] = given[1] + given[2];
    ans[3] = max( max( given[2] + given[3], given[1] + given[3] ), ans[2] );

    for ( i = 4; i <= n; i++ )
        ans[i] = max( max( given[i] + given[i-1] + ans[i-3], given[i] + ans[i-2] ), ans[i-1] );

    printf( "%d", ans[n] );

    return 0;
}