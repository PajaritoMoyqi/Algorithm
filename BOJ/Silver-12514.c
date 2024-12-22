#include <stdio.h>

#define MAX 1000

int Seq[MAX];

int main( void )
{
    int t;
    scanf( "%d", &t );

    int i;
    for ( i = 1; i <= t; i++ )
    {
        int n;
        scanf( "%d", &n );

        int min = 1000000, sum = 0, xorSum = 0;
        int j;
        for ( j = 0; j < n; j++ )
        {
            scanf( "%d", &Seq[j] );
            if ( Seq[j] < min )
                min = Seq[j];
            sum += Seq[j];
            xorSum ^= Seq[j];
        }

        if ( !xorSum )
            printf( "Case #%d: %d\n", i, sum - min );
        else
            printf( "Case #%d: NO\n", i );
    }

    return 0;
}