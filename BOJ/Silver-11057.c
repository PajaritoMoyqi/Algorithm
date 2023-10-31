#include <stdio.h>

int arr[1000+1][9+1];

int main( void )
{
    int i, j, n;
    for ( j = 0; j <= 9; j++ )
        arr[1][j] = 1;
    for ( i = 2; i <= 1000; i++ )
    {
        arr[i][0] = 1;
        arr[i][1] = i;
        for ( j = 2; j <= 9; j++ )
            arr[i][j] = (arr[i-1][j] + arr[i][j-1]) % 10007;
    }

    scanf( "%d", &n );
    int sum = 0;
    for ( j = 0; j <= 9; j++ )
    {
        sum = (sum + arr[n-1][j] * (10 - j)) % 10007;
        // printf( "%d ", arr[n-1][j] );
    }

    if ( n == 1 ) printf( "%d", 10 );
    else printf( "%d", sum );

    return 0;
}