#include <stdio.h>

int main( void )
{
    long long len;
    scanf( "%d", &len );

    char c;
    long long n, ans = 0, mod = 1234567891;
    long long i;
    for ( i = 0; i < len; i++ )
    {
        scanf( " %c", &c );
        n = c - 96;

        long long cnt = 0;
        while ( cnt++ < i )
            n = ((n << 5) - n) % mod;

        ans += n;
        ans %= mod;
    }

    printf( "%lld", ans );

    return 0;
}