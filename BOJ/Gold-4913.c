#include <stdio.h>
#include <math.h>

#define MAX 1000000

int isPrime[MAX+1];
int primeSum[MAX+1];
int FermatSum[MAX+1];

int main( void )
{
    int i;
    for ( i = 2; i <= MAX; i++ )
        isPrime[i] = 1;

    for ( i = 2; i <= sqrt(MAX); i++ )
    {
        if ( isPrime[i] == 0 )
            continue;
        
        int mult;
        for ( mult = 2; i*mult <= MAX; mult++ )
            isPrime[i*mult] = 0;
    }
    for ( i = 2; i <= MAX ; i++ )
    {
        if ( isPrime[i] ) primeSum[i] = primeSum[i-1] + 1;
        else primeSum[i] = primeSum[i-1];

        if ( isPrime[i] && ( i % 4 == 1 || i == 2 ) ) FermatSum[i] = FermatSum[i-1] + 1;
        else FermatSum[i] = FermatSum[i-1];
    }

    int min, max;
    while ( 1 )
    {
        scanf( "%d%d", &min, &max );
        if ( min == -1 && max == -1 ) break;

        if ( min >= 1 ) printf( "%d %d %d %d\n", min, max, primeSum[max] - primeSum[min-1], FermatSum[max] - FermatSum[min-1] );
        else
        {
            if ( max >= 0 ) printf( "%d %d %d %d\n", min, max, primeSum[max], FermatSum[max] );
            else printf( "%d %d %d %d\n", min, max, 0, 0 );
        }
    }

    return 0;
}