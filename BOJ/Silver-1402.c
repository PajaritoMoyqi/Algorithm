#include <stdio.h>

int main( void )
{
    int a, b, c;

    scanf( "%d", &a );

    while ( a-- )
    {
        scanf( "%d", &b );
        scanf( "%d", &c );

        printf( "yes\n" );
    }
}