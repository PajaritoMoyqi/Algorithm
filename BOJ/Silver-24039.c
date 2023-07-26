#include <stdio.h>
#include <math.h>

int main( void )
{
    int givenNumber;
    scanf( "%d", &givenNumber );
    const int MAX = 100000;

    int primes[MAX+1];
    int specialNumber[MAX+1];
    primes[0] = primes[1] = 0;

    int i;
    for ( i = 2; i <= MAX; i++ )
        primes[i] = 1;
    for ( i = 0; i <= MAX; i++ )
        specialNumber[i] = 0;

    for ( i = 2; i <= sqrt(MAX); i++ )
    {
        if ( primes[i] == 0 ) continue;

        int mult;
        for ( mult = 2; i*mult <= MAX; mult++ )
            primes[i*mult] = 0;
    }

    int prevSpecial, nowSpecial;
    prevSpecial = nowSpecial = 0;
    for ( i = 2; i <= MAX; i++ )
    {
        if ( primes[i] == 1 )
        {
            if ( prevSpecial == 0 )
                prevSpecial = i;
            else
            {
                nowSpecial = i;

                if ( prevSpecial*nowSpecial > MAX ) break;

                specialNumber[prevSpecial*nowSpecial] = 1;

                prevSpecial = nowSpecial;
            }
        }
    }


    for ( i = givenNumber + 1; i <= MAX; i++ )
    {
        if ( specialNumber[i] == 1 )
        {
            printf( "%d", i );
            break;
        }
    }

    return 0;
}