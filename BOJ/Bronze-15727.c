#include <stdio.h>

int main( void )
{
    int L;
    scanf( "%d", &L );

    if ( L % 5 ) printf( "%d", (L / 5) + 1 );
    else printf( "%d", L / 5 );

    return 0;
}