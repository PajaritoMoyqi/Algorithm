#include <stdio.h>

int main( void )
{
    int freq;
    scanf( "%d", &freq );

    if ( freq >= 620 ) printf( "Red" );
    else if ( freq >= 590 ) printf( "Orange" );
    else if ( freq >= 570 ) printf( "Yellow" );
    else if ( freq >= 495 ) printf( "Green" );
    else if ( freq >= 450 ) printf( "Blue" );
    else if ( freq >= 425 ) printf( "Indigo" );
    else printf( "Violet" );

    return 0;
}