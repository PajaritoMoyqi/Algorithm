#include <stdio.h>

int main( void )
{
    int asdf;
    scanf( "%d", &asdf );
    asdf /= 4;

    while ( asdf-- )
    {
        printf( "long " );
    }

    printf( "int" );

    return 0;
}