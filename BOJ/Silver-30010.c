#include <stdio.h>

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 0; i < n; i++ )
    {
        if ( !i )
            printf( "%d ", n );
        else
            printf( "%d ", i );
    }

    return 0;
}