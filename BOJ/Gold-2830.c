#include <stdio.h>

int main( void )
{
    long long t, i, num, idx;
    scanf( "%d", &t );

    long long cnt[20] = { 0, };
    long long sum = 0LL;
    for ( i = 0; i < t; i++ )
    {
        idx = 0LL;
        scanf( "%d", &num );
        
        while ( num )
        {
            if ( num & 1LL ) cnt[idx]++;
            num >>= 1;
            idx++;
        }
    }
    // for ( i = 0; i < 20; i++ )
    //     printf( "cnt[%d]: %d\n", i, cnt[i] );

    for ( i = 0; i < 20; i++ )
    {
        sum += (1LL << i) * (t - cnt[i]) * cnt[i];
    }

    printf( "%lld", sum );

    return 0;
}