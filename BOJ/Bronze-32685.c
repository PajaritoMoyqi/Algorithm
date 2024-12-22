#include <stdio.h>

int main( void )
{
    int a, b, c;
    scanf( "%d%d%d", &a, &b, &c );

    int pA = 0, pB = 0, pC = 0;
    int pow2 = 1;
    int i;
    for ( i = 0; i < 4; i++ )
    {
        if ( a & 1 )
            pA += pow2;
        if ( b & 1 )
            pB += pow2;
        if ( c & 1 )
            pC += pow2;

        a /= 2;
        b /= 2;
        c /= 2;
        pow2 *= 2;
    }

    int ans = (pA << 8) + (pB << 4) + pC;
    int Ans[4];

    for ( i = 0; i < 4; i++ )
    {
        Ans[i] = ans % 10;
        ans /= 10;
    }

    for ( i = 3; i >= 0; i-- )
        printf( "%d", Ans[i] );

    return 0;
}