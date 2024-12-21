#include <stdio.h>

#define MAX 500000

long long BigCnt[MAX+1];
long long SmallCnt[MAX+1];
long long Ans[MAX+1];

int popCount( unsigned int n );

int main( void )
{
    int t;
    scanf( "%d", &t );

    int num = 2;
    int i;
    for ( i = 1; i <= MAX; i++ )
    {
        while ( 1 )
        {
            if ( i - num + 1 < 0 )
            {
                num /= 2;
                break;
            }
            num *= 2;
        }
        BigCnt[i] = BigCnt[i-1] + popCount( num - 1 );
        SmallCnt[i] = SmallCnt[i-1] + popCount( i - num + 1 );
    }

    // for ( i = 0; i <= 12; i++ )
    //     printf( "%d, %d\n", BigCnt[i], SmallCnt[i] );

    while ( t-- )
    {
        int n;
        scanf( "%d", &n );

        int p, q;
        scanf( "%d%d", &p, &q );

        int max = p > q ? p : q;
        int min = p > q ? q : p;

        printf( "%lld\n", BigCnt[n]*max + SmallCnt[n]*min );
    }

    return 0;
}

int popCount( unsigned int n )
{
    n = (n >> 1 & 0x55555555) + (n & 0x55555555);
    n = (n >> 2 & 0x33333333) + (n & 0x33333333);
    n = (n >> 4 & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
    n = (n >> 8 & 0x00FF00FF) + (n & 0x00FF00FF);
    n = (n >> 16 & 0x0000FFFF) + (n & 0x0000FFFF);
    return n;
}