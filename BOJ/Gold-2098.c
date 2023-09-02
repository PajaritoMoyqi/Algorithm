#include <stdio.h> 
#include <string.h>

#ifndef min
#define min(a,b)  (((a) < (b)) ? (a) : (b))
#endif

#define MAX 16
#define INF 987654321

int N;
int W[MAX][MAX];
int cache[MAX][1<<MAX];

int TSP( int place, int visited );

int main( void )
{
    scanf( "%d", &N );

    if ( N < 2 || N > MAX )
        return -1;

    int i, j;
    for ( i = 0; i < N; i++ )
        for ( j = 0; j < N; j++ )
            scanf( "%d", &W[i][j] );

    memset( cache, -1, sizeof( cache ) );

    printf( "%d", TSP(0, 1) );

    return 0;
}

int TSP( int place, int visited )
{
    // if visit all
    if ( visited == (1 << N) - 1 )
    {
        if ( W[place][0] != 0 )
            return W[place][0];

        return INF;
    }

    // if already visited with same past route
    if ( cache[place][visited] != -1 )
        return cache[place][visited];

    cache[place][visited] = INF;

    // next cities
    int idx;
    for ( idx = 0; idx < N; idx++ )
    {
        // already visited or same city
        if ( visited & (1 << idx) || W[place][idx] == 0 )
            continue;

        int candidate = W[place][idx] + TSP( idx, visited + (1 << idx) );
        cache[place][visited] = min( cache[place][visited], candidate );
    }

    return cache[place][visited];
}