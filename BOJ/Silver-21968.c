#include <stdio.h>

int main( void )
{
    int t;
    scanf( "%d", &t );

    while ( t-- )
    {
        long long a;
        scanf( "%lld", &a );

        long long cnt = 1, ans = 0, pow3 = 1;
        while ( a )
        {
            if ( a & 1 )
                ans += pow3;

            pow3 *= 3;
            cnt++;
            a /= 2;
        }

        printf( "%lld\n", ans );
    }

    return 0;
}