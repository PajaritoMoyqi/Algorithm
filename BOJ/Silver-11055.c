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

    int sum[N];
    sum[0] = nums[0];
    for ( i = 1; i < N; i++ )
    {
        sum[i] = nums[i];

        int j;
        for ( j = 0; j < i; j++ )
            if ( nums[i] > nums[j] )
                sum[i] = max( sum[i], sum[j] + nums[i] );
    }
 
    int res = 0;
    for( i = 0; i < N; i++ )
        if ( sum[i] > res )
            res = sum[i];

    printf( "%d\n", res );

    return 0;
}