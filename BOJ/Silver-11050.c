#include <stdio.h>

long long factorial( long long num );
long long combination( long long n, long long k );

int main( void )
{
    long long n, k;
    scanf( "%lld%lld", &n, &k );

    printf( "%lld", combination( n, k ) );

    return 0;
}

long long factorial( long long num )
{
    long long result = 1;
    if ( num == 1 ) return result;
    else
    {
        long long i;
        for ( i = num; i > 0; i-- )
            result = (result * i);
    }

    return result;
}

long long combination( long long n, long long k )
{
    return factorial( n ) / (factorial( k ) * factorial( n-k )); 
}