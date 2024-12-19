#include <stdio.h>
#include <math.h>

#define MAX 10000000

int Primes[MAX+1];

int main( void )
{
    int i;
    for ( i = 2; i <= MAX; i++ )
        Primes[i] = 1;

    for ( i = 2; i <= sqrt(MAX); i++ )
    {
        if ( Primes[i] == 0 ) continue;

        int mult;
        for ( mult = 2; i*mult <= MAX; mult++ )
            Primes[i*mult] = 0;
    }

    int n;
    scanf( "%d", &n );

    int idx = 1;
    for ( i = 1; i <= n; i++ )
    {
        while ( 1 )
        {
            idx++;

            if ( Primes[idx] == 1 )
            {
                printf( "%d ", idx );
                break;
            }
        }
    }

    return 0;
}