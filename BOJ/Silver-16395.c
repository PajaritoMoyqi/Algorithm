#include <stdio.h>

long long acc[30+1][30+1];

int main( void )
{
    acc[0][0] = 1;
    acc[1][0] = 1;
    acc[1][1] = 1;

    int i, j;
    for ( i = 2; i <= 30; i++ )
    {
        for ( j = 0; j <= i; j++ )
        {
            if ( !j || j == i )
                acc[i][j] = 1;
            else
                acc[i][j] = acc[i-1][j] + acc[i-1][j-1];
        }
    }

    int n, k;
    scanf( "%d%d", &n, &k );

    printf( "%lld", acc[n-1][k-1] );

    return 0;
}