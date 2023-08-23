#include <stdio.h>

int ans[10+1];

int main( void )
{
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 4;

    int i;
    for ( i = 4; i <= 10; i++ )
        ans[i] = ans[i-1] + ans[i-2] + ans[i-3];

    scanf( "%d", &i );

    int n;
    while ( i-- )
    {
        scanf( "%d", &n );
        printf( "%d\n", ans[n] );
    }

    return 0;
}