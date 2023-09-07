#include <stdio.h>

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

int main( void )
{
    int N, i;
    scanf( "%d", &N );

    int nums[N];
    for ( i = 0; i < N; i++ )
        scanf( "%d", &nums[i] );

    int len[N];
    len[0] = 1;
    for ( i = 1; i < N; i++ )
    {
        len[i] = 1;

        int j;
        for ( j = 0; j < i; j++ )
            if ( nums[i] < nums[j] )
                len[i] = max( len[i], len[j] + 1 );
    }
 
    int cnt = 0;
    for( i = 0; i < N; i++ )
        if ( len[i] > cnt )
            cnt = len[i];

    printf( "%d\n", cnt );

    return 0;
}