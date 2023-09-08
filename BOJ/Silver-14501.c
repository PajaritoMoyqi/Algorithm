#include <stdio.h>

#ifndef max
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#endif

int day[15+1];
int pay[15+1];
int visited[15+1+5];

// int DP( int sum, int d, int limit );

int main( void )
{
    int d;
    scanf( "%d", &d );

    int i;
    for ( i = 1; i <= d; i++ )
        scanf( "%d%d", &day[i], &pay[i] );

    int sum = 0;
    for ( i = d; i >= 1; i-- )
    {
        if ( day[i] + i <= d + 1 )
        {
            visited[i] = pay[i] + visited[i + day[i]];
            // printf( "added %d - ", visited[i + day[i]] );
        }
        else
        {
            visited[i] = sum;
            // printf( "copied - " );
        }

        sum = max( sum, visited[i] );
        visited[i] = sum;
        // printf( "visted[%d]: %d, idx: %d, sum: %d\n", i, visited[i], i, sum );
    }

    printf( "%d", sum );

    return 0;
}

int DP( int sum, int d, int limit )
{
    if ( d > limit ) return sum;
    if ( day[d] + d > limit + 1 ) return DP( sum, d + 1, limit );

    sum += pay[d];
    return DP( sum, day[d] + d, limit );
}