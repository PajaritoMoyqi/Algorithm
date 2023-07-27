#include <stdio.h>
#include <math.h>

int main( void )
{
    const int MAX = 100000;

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

    int smallNumber, bigNumber;
    scanf( "%d", &smallNumber );
    scanf( "%d", &bigNumber );

    int number, cnt, underPrimeCnt = 0;
    for ( i = smallNumber; i <= bigNumber; i++ )
    {
        number = i;
        cnt = 0;
        
        int j;
        for ( j = 2; j <= number; j++ )
        {
            if ( primes[j] == 1 )
            {
                while ( number % j == 0 )
                {
                    cnt++;
                    number /= j;
                }
            }
        }

        if ( primes[cnt] == 1 )
            underPrimeCnt++;
    }
    
    printf( "%d", underPrimeCnt );

    return 0;
}