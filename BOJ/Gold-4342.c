#include <stdio.h>

int getGCD( int a, int b, int cnt );

int main( void )
{
    while ( 1 )
    {
        int a, b;
        scanf( "%d%d", &a, &b );
        if ( a == 0 && b == 0 ) break;

        if ( getGCD( a, b, 0 ) & 1 ) printf( "A wins\n" );
        else printf( "B wins\n" );
    }

    return 0;
}

int getGCD( int a, int b, int cnt )
{
    int big = (a >= b) ? a : b;
    int small = (a >= b) ? b : a; 
    int mod = big % small;

    if ( mod == 0 )
    {
        return ++cnt;
    }
    else
    {
        if ( big - small < small ) return getGCD( small, mod, ++cnt );
        else return ++cnt;
    }
}