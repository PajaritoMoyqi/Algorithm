#include <stdio.h>
#include <math.h>

int main( void )
{
    int testCase;
    scanf( "%d", &testCase );
    const int MAX = 1299709;

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

    int givenNumber, upNumber, downNumber, cnt;
    for ( i = 0; i < testCase; i++ )
    {
        scanf( "%d", &givenNumber );
        cnt = 0;
        
        upNumber = downNumber = givenNumber;
        while ( primes[upNumber] != 1 )
        {
            cnt++;
            upNumber++;
        }
        while ( primes[downNumber] != 1 )
        {
            cnt++;
            downNumber--;
        }

        if ( !cnt )
            printf( "%d\n", 0 );
        else
            printf( "%d\n", cnt );
    }

    return 0;
}