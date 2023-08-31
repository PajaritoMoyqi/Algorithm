#include <stdio.h>

long long power2( long long number );

int main( void )
{
    int trials;
    scanf( "%d", &trials );

    int i = 0;
    for ( i = 0; i < trials; i++ )
    {   
        long long int sum, xor;
        scanf( "%lld %lld", &sum, &xor );

        long long int common = sum - xor;

        if ( common < 0 )
        {
            printf( "%d\n", 0 );
            continue;
        }

        if ( common & 1 )
        {
            printf( "%d\n", 0 );
        }
        else
        {
            long long int and = common / 2;
            if ( xor & and )
                printf( "%d\n", 0 );
            else
            {
                long long int cnt = 0;
                while ( xor )
                {
                    if ( xor & 1 ) cnt++;
                    xor >>= 1;
                }

                printf( "%lld\n", power2( cnt ) );
            }
        }
    }

    return 0;
}

long long power2( long long number )
{
    if ( number == 0 ) return 1;
    else
        return 2 * power2( number - 1 );
}