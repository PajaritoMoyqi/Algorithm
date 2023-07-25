#include <stdio.h>

int fib( int num );

int main( void )
{
    int cycle;
    scanf( "%d", &cycle );
    int i;

    int number;

    for ( i = 0; i < cycle; i++ )
    {
        scanf( "%d", &number );
        
        if ( number == 0 )
            printf( "1 0\n" );
        else
            printf( "%d %d\n", fib( number - 1 ), fib( number ) );
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
        Latest = Current;
        Current = Result;
        Result = Latest + Current;
    }

    return Result;
}