#include <stdio.h>
#include <string.h>

int main( void )
{
    char s[4+1];
    scanf( "%s", s );

    if ( !strcmp( s, "NLCS" ) ) printf( "North London Collegiate School" );
    else if ( !strcmp( s, "BHA" ) ) printf( "Branksome Hall Asia" );
    else if ( !strcmp( s, "KIS" ) ) printf( "Korea International School" );
    else if ( !strcmp( s, "SJA" ) ) printf( "St. Johnsbury Academy" );

    return 0;
}