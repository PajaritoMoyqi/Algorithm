#include <stdio.h>

int n;
int stair[100+1][9+1];

int main( void )
{
    int i, j;
    
    stair[1][0] = 0;
    for ( j = 1; j <= 9; j++ )
        stair[1][j] = 1;

    for ( i = 2; i <= 100; i++ )
        for ( j = 0; j <= 9; j++ )
            {
                if ( j == 0 ) stair[i][j] = stair[i-1][j+1] % 1000000000;
                else if ( j == 9 ) stair[i][j] = stair[i-1][j-1] % 1000000000;
                else stair[i][j] = (stair[i-1][j+1] + stair[i-1][j-1]) % 1000000000;
            }

    scanf( "%d", &n );

    int res = 0;
    for ( j = 0; j <= 9; j++ )
        res = (res + stair[n][j]) % 1000000000;

    printf( "%d", res );

    return 0;
}