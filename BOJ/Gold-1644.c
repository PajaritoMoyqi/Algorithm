#include <stdio.h>
#include <math.h>

#define MAX 4000000
int primes[MAX+1];

int main( void )
{
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

    int t, cnt = 0, start = 2, end = 2, sum = 0;
    scanf( "%d", &t );

    for ( i = 2; i <= t; i++ )
    {
        if ( primes[start] )
        {
            while ( sum < t && end <= t )
            {
                if ( primes[end] ) sum += end;
                end++;
            }

            if ( sum == t )
                cnt++;

            sum -= start;
        }
        start++;
    }

    printf( "%d", cnt );

    return 0;
}