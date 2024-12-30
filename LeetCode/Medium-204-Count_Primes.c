#include <math.h>

int countPrimes( int n )
{
    if ( n <= 2 )
        return 0;

    const int MAX = n-1;

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
    {
        if ( primes[i] )
            cnt++;
    }

    return cnt;
}