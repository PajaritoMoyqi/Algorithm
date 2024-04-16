#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    unsigned n;
    scanf( "%d", &n );

    unsigned i = 1;
    while ( n >= i )
    {
        n -= i;
        i++;
    }

    printf( "%u", i - 1 );

    return 0;
}