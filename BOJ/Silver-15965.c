#include <stdio.h>
#include <math.h>

int main( void )
{
    const int MAX = 8000000;

    char primes[MAX+1];
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

    // int temp_cnt = 0;
    // for ( i = 2; i <= MAX; i++ )
    //     if ( primes[i] == 1 ) temp_cnt++;

    // printf( "temp_cnt: %d\n", temp_cnt );

    int givenNumber, cnt = 0;
    scanf( "%d", &givenNumber );

    for ( i = 2; i <= MAX; i++ )
    {
        if ( primes[i] == 1 ) cnt++;
        if ( cnt == givenNumber )
        {
            printf( "%d", i );
            break;
        }
    }

    return 0;
}