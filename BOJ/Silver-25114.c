#include <stdio.h>
#include <string.h>

#define MAX 1000000

long long SeqA[MAX];
long long SeqB[MAX];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 0; i < n; i++ )
        scanf( "%lld", &SeqA[i] );
    for ( i = 0; i < n; i++ )
        scanf( "%lld", &SeqB[i] );

    long long xNum;
    int cnt = 0;
    for ( i = 0; i < n; i++ )
    {
        if ( i == n-1 )
        {
            if ( SeqA[i] == SeqB[i] )
                printf( "%d", cnt );
            else
                printf( "-1" );
        }

        if ( SeqA[i] == SeqB[i] )
            continue;

        xNum = SeqA[i] ^ SeqB[i];
        SeqA[i+1] ^= xNum;
        cnt++;
    }

    return 0;
}