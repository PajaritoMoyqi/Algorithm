#include <stdio.h>

#ifndef max
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#endif

int cand[100000+1];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    int res = -1000;
    for ( i = 1; i <= n; i++ )
    {
        scanf( "%d", &cand[i] );

        if ( cand[i-1] > 0 )
            cand[i] += cand[i-1];

        res = max( res, cand[i] );
    }

    printf( "%d", res );
}