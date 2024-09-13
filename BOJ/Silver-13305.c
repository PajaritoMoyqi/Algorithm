#include <stdio.h>

#define MAX_N 100000

long long Dist[MAX_N+1];
long long Cost[MAX_N+1];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 1; i < n; i++  )
        scanf( "%lld", &Dist[i] );
    for ( i = 1; i <= n; i++  )
        scanf( "%lld", &Cost[i] );

    long long min;
    long long totalCost = 0;
    for ( i = 1; i <= n-1; i++ )
    {
        if ( i == 1 )
            min = Cost[i];
        else
            min = min < Cost[i] ? min : Cost[i];

        totalCost += min*Dist[i];
    }

    printf( "%lld", totalCost );

    return 0;
}