#include <stdio.h>

int main( void )
{
    int day, quotient, remain;
    scanf( "%d", &day );

    quotient = day / 5;
    remain = day % 5;

    while ( quotient-- )
        printf( "V" );
    while ( remain-- )
        printf( "I" ) ;

    return 0;
}