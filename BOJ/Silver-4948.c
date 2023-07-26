#include <stdio.h>
#include <math.h>

int main( void )
{
    const int MAX = 123456*2;

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

    int givenNumber, cnt;
    scanf( "%d", &givenNumber );

    while ( givenNumber )
    {
        cnt = 0;

        for ( i = givenNumber+1; i <= givenNumber*2; i++ )
            if ( primes[i] == 1 )
                cnt++;

        printf( "%d\n", cnt );

        scanf( "%d", &givenNumber );
    }

    return 0;
}