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

    int givenNumber, bigNumber, smallNumber, flag;
    scanf( "%d", &givenNumber );

    while ( givenNumber != 0 )
    {
        flag = 0;
        bigNumber = givenNumber - 3;
        smallNumber = 3;

        while ( smallNumber <= bigNumber )
        {
            if ( primes[smallNumber] == 1
                && primes[bigNumber] == 1 )
            {
                printf( "%d = %d + %d\n", givenNumber, smallNumber, bigNumber );
                flag = 1;
                break;
            }
            else
            {   
                smallNumber += 2;
                bigNumber -= 2;
            }
        }

        if ( !flag )
            printf( "Goldbach's conjecture is wrong.\n" );
        
        scanf( "%d", &givenNumber );
    }

    return 0;
}