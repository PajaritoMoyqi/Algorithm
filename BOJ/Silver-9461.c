#include <stdio.h>

long long ans[100+1];

int main( void )
{
    ans[1] = 1;
    ans[2] = 1;
    ans[3] = 1;
    ans[4] = 2;
    ans[5] = 2;

    int n, num, i;
    scanf( "%d", &n );

    for ( i = 6; i <= 100; i++ )
        ans[i] = ans[i-1] + ans[i-5];
    
    while ( n-- )
    {
        scanf( "%d", &num );
        printf( "%lld\n", ans[num] );
    }

    return 0;
}