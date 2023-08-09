#include <stdio.h>
#include <math.h>

int main( void )
{
    int cnt, max = 1000000;
    scanf( "%d", &cnt );

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

    int idx = 0;
    for ( i = 2; i <= max; i++ )
    {
        if ( isPrime[i] == 1 )
        {
            idx++;

            if ( idx == cnt )
            {
                printf( "%d", i );
                break;
            }
        }
    }

    return 0;
}