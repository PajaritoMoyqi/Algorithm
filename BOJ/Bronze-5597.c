#include <stdio.h>

char check[30+1];

int main( void )
{
    int num = 28, i;
    while ( num-- )
    {
        scanf( "%d", &i );
        check[i] = 1;
    }

    for ( i = 1; i <= 30; i++ )
        if ( !check[i] ) printf( "%d\n", i );

    return 0;
}