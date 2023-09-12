#include <stdio.h>

int G[1000000+1];

int main( void )
{
    long long n;
    scanf( "%d", &n );

    G[1] = 1;
    G[2] = 3;
    G[3] = 5;
    int i, j, cnt = 0;
    long long sum = 5;
    for ( i = 3, j = 4; sum <= 2000000000; )
    {
        if ( cnt == G[i] - G[i-1] )
        {
            cnt = 0;
            i++;
            continue;
        }
        sum += i;
        G[j] = sum;
        cnt++;
        j++;
    }

    for ( i = 1; i <= 1000000; i++ )
    {
        if ( G[i] >= n )
        {
            printf( "%d", i );
            break;
        }
        // printf( "G[%d]: %d\n", i, G[i] );
    }

    return 0;
}