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

    int givenNumber, bigNumber, smallNumber, cnt = 0;
    scanf( "%d", &givenNumber );

    while ( givenNumber > 3 )
    {
        if ( givenNumber == 4 )
        {
            cnt++;
            break;
        }
        smallNumber = 3;
        bigNumber = givenNumber - 3;

        while ( smallNumber <= bigNumber )
        {
            // printf( "cnt: %d, g: %d, s: %d, b: %d\n", cnt, givenNumber, smallNumber, bigNumber );
            if ( primes[smallNumber] == 1
                && primes[bigNumber] == 1 )
            {
                givenNumber = bigNumber - smallNumber;
                cnt++;
                break;
            }
            else
            {   
                smallNumber += 2;
                bigNumber -= 2;
            }
        }
    }

    printf( "%d", cnt );

    return 0;
}