#include <stdio.h>

int main( void )
{
    char onePick;
    scanf( "%c", &onePick );

    if ( onePick == 'M' ) printf( "MatKor" );
    else if ( onePick == 'W' ) printf( "WiCys" );
    else if ( onePick == 'C' ) printf( "CyKor" );
    else if ( onePick == 'A' ) printf( "AlKor" );
    else if ( onePick == '$' ) printf( "$clear" );

    return 0;
}