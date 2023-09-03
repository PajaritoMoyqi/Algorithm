#include <stdio.h>
#include <string.h>

char str[20];

int main( void )
{
    int t;
    scanf( "%d", &t );

    while ( t-- )
    {
        scanf( "%s", str );
        if ( strlen( str ) >= 6 && strlen( str ) <= 9 )
            printf( "yes\n" );
        else
            printf( "no\n" );
    }

    return 0;
}