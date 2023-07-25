#include <stdio.h>
#include <math.h>

int main( void )
{
    int min, max = 1000000;
    scanf( "%d", &min );

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
    if ( min == 1 )
        min++;
    for ( idx = min; idx <= max; idx++ )
    {
        if ( isPrime[idx] == 1 )
        {
            int reversed = 0;
            int originalNumber = idx;

            while ( originalNumber != 0 )
            {
                reversed *= 10;
                reversed += originalNumber % 10;
                originalNumber /= 10;
            }

            if ( reversed == idx )
            {
                printf( "%d", idx );
                goto last;
            }
        }
    }

    printf( "%d", 1003001 );

    last:

    return 0;
}