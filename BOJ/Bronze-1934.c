#include <stdio.h>

long long getGCD( long long a, long long b );

int main( void )
{
    long long a, b, t, n;
    scanf( "%lld", &t );

    while( t-- )
    {
        scanf( "%lld%lld", &a, &b );
        n = getGCD( a, b );
        a = a / n;
        b = b / n;

        printf( "%lld\n", a * b * n );
    }

    return 0;
}

long long getGCD( long long a, long long b )
{
    long long big = (a >= b) ? a : b;
    long long small = (a >= b) ? b : a; 
    long long mod = big % small;

    if ( mod == 0 )
        return small;
    else
        return getGCD( small, mod );
}