#include <stdio.h>

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

int main( void )
{
    int N;
    scanf( "%d", &N );

    int nums[N];
    int i;
    for ( i = 0; i < N; i++ )
        scanf("%d", &nums[i]);

    int prev[N];
    for ( i = 0; i < N; i++ )
        prev[i] = i;

    int len[N];
    len[0] = 1;
    for ( i = 1; i < N; i++ )
    {
        len[i] = 1;

        int j;
        for ( j = 0; j < i; j++ )
            if ( nums[i] > nums[j] )
            {
                if ( len[j] + 1 > len[i] )
                    prev[i] = j;
                len[i] = max( len[i], len[j] + 1 );
            }
    }
 
    int cnt = 0, last = -1;
    for( i = 0; i < N; i++ )
        if ( len[i] > cnt )
        {
            cnt = len[i];
            last = i;
        }

    printf( "%d\n", cnt );
    
    int ans[cnt];
    int idx = cnt;
    while ( prev[last] != last )
    {
        ans[--idx] = nums[last];
        last = prev[last];
    }
    ans[--idx] = nums[last];
    
    for( i = 0; i < cnt; i++ )
        printf( "%d ", ans[i] );

    return 0;
}