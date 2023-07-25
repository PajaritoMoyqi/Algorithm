#include <stdio.h>
#include <math.h>

int fib( int num );

int main( void )
{
    int number;
    scanf( "%d", &number );

    if ( number >= 0 )
    {
        if ( number == 0 )
            printf( "0\n0\n" );
        else
            printf( "1\n%d\n", fib( number ) % 1000000000 );
    }
    else
    {
        if ( abs( number ) % 2 == 0 )
            printf( "-1\n%d\n", fib( abs( number ) ) % 1000000000 );
        else
            printf( "1\n%d\n", fib( abs( number ) ) % 1000000000 );
    }

    return 0;
}

int fib( int num )
{
    int Latest, Current, Result;
    Current = 1, Latest = Result = 0;
    
    int i;

    for ( i = 0; i < num; i++ )
    {
        Latest = Current % 1000000000;
        Current = Result % 1000000000;
        Result = (Latest + Current) % 1000000000;
    }

    return Result;
}