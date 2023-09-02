#include <stdio.h>

#ifndef max
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#endif

int acc[10000+1];

int main( void )
{
    int t, n;
    scanf( "%d", &t );

    while ( t-- )
    {
        scanf( "%d", &n );
        acc[n]++;
    }

    int i;
    for ( i = 1; i <= 10000; i++ )
    {
        while ( acc[i] )
        {
            printf( "%d\n", i );
            acc[i]--;
        }
    }
}