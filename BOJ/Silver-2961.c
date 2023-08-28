#include <stdio.h>
#include <math.h>

enum taste { SOUR, BITTER };

int ingredient[10][2];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i, j;
    for ( i = 0; i < n; i++ )
        scanf( "%d%d", &ingredient[i][SOUR], &ingredient[i][BITTER] );

    long long bit, sour, dif = -1, changed;

    for ( i = 1; i < (1 << n); i++ )
    {
        // printf( "for i: %d, (1 << n): %d\n", i, (1 << n) );
        int idx = 0;
        j = i;
        bit = 0, sour = 1, changed = 0;
        while ( j )
        {
            if ( j & 1 )
            {
                sour *= ingredient[idx][SOUR];
                bit += ingredient[idx][BITTER];
                // printf( "j: %d\n", j );
                if ( !changed ) changed = 1;
            }
            
            j >>= 1;
            idx++;
        }

        // printf( "current dif: %lld, sour: %lld, bit: %lld\n", dif, sour, bit );

        if ( !~dif
            || ( changed && dif > abs( bit - sour ) ) )
        {
            dif = abs( bit - sour );
        }
    }

    printf( "%lld", dif );

    return 0;
}