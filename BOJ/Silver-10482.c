#include <stdio.h>
#include <math.h>

int main( void )
{
    int testCase;
    scanf( "%d", &testCase );
    const int MAX = 32000;

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

    int cnt = 0;
    for ( i = 2; i <= MAX; i++ )
        if ( primes[i] == 1 ) cnt++;

    int givenNumber, bigNumber, smallNumber;
    int answer[cnt], idx;

    for ( i = 0; i < testCase; i++ )
    {
        scanf( "%d", &givenNumber );
        bigNumber = smallNumber = givenNumber / 2;
        idx = 0;

        while ( smallNumber > 0 )
        {
            if ( primes[bigNumber]
                && primes[smallNumber] )
            {
                answer[idx] = smallNumber;
                idx++;
            }

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

        printf( "%d has %d representation(s)\n", givenNumber, idx );
        
        int j;
        for ( j = 0; j < idx; j++ )
            printf( "%d+%d\n", answer[idx-j-1], givenNumber - answer[idx-j-1] );

        if ( i == testCase - 1 ) goto end;
        printf( "\n" );
    }

    end:
        return 0;
}