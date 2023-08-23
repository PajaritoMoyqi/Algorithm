#include <stdio.h>

int N, r, c;

int divNconq( int r, int c, int N, int sum );
int power2( int number );

int main( void )
{
    scanf( "%d%d%d", &N, &r, &c );

    printf( "%d", divNconq( r, c, N, 0 ) );

    return 0;
}

int divNconq( int r, int c, int N, int sum )
{
    if ( N == 0 ) return sum;

    int res = sum;
    int mid = power2( N-1 );
    int part = power2( 2*N ) / 4;

    if ( c / mid )
    {
        sum += part;
        c -= mid;
    }
    if ( r / mid )
    {
        sum += part * 2;
        r -= mid;
    }

    return divNconq( r, c, N - 1, sum );
}

int power2( int number )
{
    int result;
    if ( number == 0 ) return 1;
    else
        return 2 * power2( number - 1 );
}