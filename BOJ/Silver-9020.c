#include <stdio.h>
#include <math.h>

int main( void )
{
    int testCase;
    scanf( "%d", &testCase );
    const int MAX = 10000;

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

    int givenNumber, bigNumber, smallNumber;
    for ( i = 0; i < testCase; i++ )
    {
        scanf( "%d", &givenNumber );
        bigNumber = smallNumber = givenNumber / 2;

        while ( smallNumber > 0 )
        {
            if ( primes[bigNumber]
                && primes[smallNumber] )
            {
                printf( "%d %d\n", smallNumber, bigNumber );
                break;
            }
            else
            {
                if ( bigNumber % 2 )
                {
                    bigNumber += 2;
                    smallNumber -= 2;
                }
                else
                {
                    bigNumber += 1;
                    smallNumber -= 1;
                }
            }
        }
    }

    return 0;
}