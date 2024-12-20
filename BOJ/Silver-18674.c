#include <stdio.h>
#include <stdlib.h>

#define MAX 20001

long long Seq[MAX];

int main( void )
{
    int t;
    scanf( "%d", &t );

    int andN, orN, total;
    int i;
    while ( t-- )
    {
        scanf( "%d%d", &andN, &orN );
        total = andN + orN;
        
        for ( i = 0; i <= total; i++ )
            scanf( "%lld", &Seq[i] );

        long long ans = Seq[0];
        for ( i = 1; i <= total; i++ )
        {
            if ( andN )
            {
                ans &= Seq[i];
                andN--;
                continue;
            }

            if ( orN )
            {
                ans |= Seq[i];
                orN--;
                continue;
            }
        }

        printf( "%lld\n", ans );
    }

    return 0;
}