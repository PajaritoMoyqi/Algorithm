#include <stdio.h>

int fib( int num );

int main( void )
{
    int cycle;
    scanf( "%d", &cycle );
    
    printf( "%d", fib( cycle ) );

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