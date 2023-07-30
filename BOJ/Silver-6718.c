#include <stdio.h>
#include <math.h>

#define MAX 1000000

int main( void )
{
    int primes[MAX+1];
    primes[0] = primes[1] = 0;

    int i;
    for ( i = 2; i <= MAX; i++ )
        primes[i] = 1;

    for ( i = 2; i <= sqrt(MAX); i++ )
    {
        if ( primes[i] == 0 ) continue;

        int mult;
        for ( mult = 2; i*mult <= MAX; mult++ )
            primes[i*mult] = 0;
    }

    int givenNumber, bigNumber, smallNumber, cnt;
    scanf( "%d", &givenNumber );

    while ( givenNumber )
    {
        cnt = 0;
        bigNumber = givenNumber - 2;
        smallNumber = 2;

        while ( smallNumber <= bigNumber )
        {
            if ( primes[smallNumber] == 1
                && primes[bigNumber] == 1 )
            {
                cnt++;
            }

            if ( smallNumber == 2 )
            {
                smallNumber += 1;
                bigNumber -= 1;
            }
            else
            {
                smallNumber += 2;
                bigNumber -= 2;
            }
        }

        printf ( "%d\n", cnt );
        scanf( "%d", &givenNumber );
    }

    return 0;
}