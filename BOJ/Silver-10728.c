#include <stdio.h>

int power2( int number );

int main( void )
{
    int n;
    scanf( "%d", &n );

    while ( n-- )
    {
        int d;
        scanf( "%d", &d );

        if ( d == 1 )
        {
            printf( "1\n1\n" );
            continue;
        }
        if ( d == 2 )
        {
            printf( "2\n1 2\n" );
            continue;
        }

        int i, limit;
        for ( i = 0; i <= 7; i++ )
        {
            if ( d < power2( i ) )
            {
                limit = power2( i-2 );
                break;
            }
        }

        // printf( "num: %d\n", d );
        int biggestNum = d > 3*limit - 1 ? 3*limit -1 : d;

        printf( "%d\n", biggestNum - limit + 1 );
        for ( i = limit; i <= biggestNum; i++ )
            printf( "%d ", i );
        puts( "" );
    }

    // int i, j, k;
    // for ( i = 1; i <= 100; i++ )
    //     for ( j = 1; j < i; j++ )
    //         for ( k = 1; k < j; k++ )
    //         {
    //             if ( (i^j^k) == 0 )
    //                 printf( "(%d, %d, %d)\n", k, j, i );
    //         }

    return 0;
}

int power2( int number )
{
    if ( number == 0 ) return 1;
    else
        return 2 * power2( number - 1 );
}