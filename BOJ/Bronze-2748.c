#include <stdio.h>

long long int fib( long long int num );

long long int main( void )
{
    long long int cycle;
    scanf( "%lld", &cycle );
    
    printf( "%lld", fib( cycle ) );

    return 0;
}

long long int fib( long long int num )
{
    long long int Latest, Current, Result;
    Current = 1, Latest = Result = 0;
    
    long long int i;
    for ( i = 0; i < num; i++ )
    {
        Latest = Current;
        Current = Result;
        Result = Latest + Current;
    }

    return Result;
}