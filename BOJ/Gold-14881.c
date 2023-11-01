#include <stdio.h>

int getGCD( int a, int b );

int main( void )
{
    int i, t;
    scanf( "%d", &t );

    int a, b, c;
    for ( i = 0; i < t; i++ )
    {
        scanf( "%d%d%d", &a, &b, &c );

        if ( a >= c || b >= c )
        {
            int GCD = getGCD( a, b );
            if ( c % GCD ) printf( "NO\n" );
            else printf( "YES\n" );
        }
        else
        {
            printf( "NO\n" );
        }
    }
}

int getGCD( int a, int b )
{
    int big = (a >= b) ? a : b;
    int small = (a >= b) ? b : a; 
    int mod = big % small;

    if ( mod == 0 )
        return small;
    else
        return getGCD( small, mod );
}