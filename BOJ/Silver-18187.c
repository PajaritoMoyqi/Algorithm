#include <stdio.h>

int ans[1+100];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    ans[0] = 1;
    for ( i = 1; i <= 100; i++ )
        ans[i] = ans[i-1] + (i - ((i-1)/3));

    printf( "%d", ans[n] );

    return 0;
}