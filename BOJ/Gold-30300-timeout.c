#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

long long Seq[MAX];
long long Tmp[MAX];

int main( void )
{
    int t;
    scanf( "%d", &t );

    int N;
    int i;
    while ( t-- )
    {
        scanf( "%d", &N );

        for ( i = 0; i < N; i++ )
            scanf( "%lld", &Seq[i] );

        int mex = -1;
        long long ans = 0, mask;
        int k;
        for ( i = 0; i <= 20; i++ )
        {
            mask = (1 << i) - 1;
            // printf( "K: %d, ", k );
            int* Cnt = (int*)calloc( mask+2, sizeof( int ) );

            for ( k = 0; k < N; k++ )
            {
                Tmp[k] = Seq[k] & mask;
                // printf( "Tmp[%d]: %lld, ", i, Tmp[k] );
                Cnt[Tmp[k]]++;
            }

            for ( k = 0; k <= mask+1; k++ )
            {
                if ( !Cnt[k] )
                {
                    // printf( "%d!!", i );
                    if ( mex < k )
                    {
                        mex = k;
                        ans = mask;
                    }
                    break;
                }
            }

            free( Cnt );
        }

        printf( "%lld", ans );
    }

    return 0;
}