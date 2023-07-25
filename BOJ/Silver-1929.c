#include <stdio.h>
#include <math.h>

int main( void )
{
    int min, max;
    scanf( "%d", &min );
    scanf( "%d", &max );

    int isPrime[max+1];

    isPrime[0] = 0;
    isPrime[1] = 0;

    for (int k = 2; k <= max; k++)
        isPrime[k] = 1;

    int i;
    for ( i = 2; i <= sqrt(max); i++ )
    {
        if ( isPrime[i] == 0 )
            continue;
        
        int mult;
        for ( mult = 2; i*mult <= max; mult++ )
            isPrime[i*mult] = 0;
    }

    int idx;
    for ( idx = min; idx <= max; idx++ )
        if ( isPrime[idx] == 1 )
            printf( "%d\n", idx );

    return 0;
}