#include <stdio.h>

#ifndef max
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#endif

int stair[301];
int acc[301];

int main( void )
{
    int T, i;
    scanf( "%d", &T );
    for ( i = 1; i <= T; i++ )
        scanf( "%d", &stair[i] );

    acc[0] = 0;
    acc[1] = stair[1];
    acc[2] = stair[1] + stair[2];
    for ( i = 3; i <= T; i++ )
        acc[i] = stair[i] + max( acc[i-2], stair[i-1] + acc[i-3] );

    printf( "%d", acc[T] );

    return 0;
}