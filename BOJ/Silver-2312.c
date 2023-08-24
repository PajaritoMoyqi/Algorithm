#include <stdio.h>
#include <math.h>

#define MAX 100000

char isPrime[MAX+1];
int ans[MAX+1];

int main( void )
{
    isPrime[0] = 0;
    isPrime[1] = 0;

    int k;
    for ( k = 2; k <= MAX; k++ )
        isPrime[k] = 1;

    int i;
    for ( i = 2; i <= sqrt(MAX); i++ )
    {
        if ( isPrime[i] == 0 )
            continue;
        
        int mult;
        for ( mult = 2; i*mult <= MAX; mult++ )
            isPrime[i*mult] = 0;
    }

    scanf( "%d", &k );

    while ( k-- )
    {
        int d;
        scanf( "%d", &d );

        for ( i = 0; i <= MAX; i++ )
            ans[i] = 0;

        for ( i = 2; i <= MAX; i++ )
        {
            if ( d == 1 ) break;

            if ( isPrime[i] && (d % i == 0) )
            {
                while ( d % i == 0 )
                {
                    ans[i]++;
                    d /= i;
                }
            }
        }

        for ( i = 2; i <= MAX; i++ )
            if ( ans[i] ) printf( "%d %d\n", i, ans[i] );
    }

    return 0;
}