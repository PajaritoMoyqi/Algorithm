#include <stdio.h>
#include <string.h>

int main( void )
{
    int n;
    char s[22+1];

    scanf( "%d", &n );

    while( n-- )
    {
        scanf( "%s", s );

        if ( !strcmp( s, "Algorithm" ) ) printf( "204\n" );
        else if ( !strcmp( s, "DataAnalysis" ) ) printf( "207\n" );
        else if ( !strcmp( s, "ArtificialIntelligence" ) ) printf( "302\n" );
        else if ( !strcmp( s, "CyberSecurity" ) ) printf( "B101\n" );
        else if ( !strcmp( s, "Network" ) ) printf( "303\n" );
        else if ( !strcmp( s, "Startup" ) ) printf( "501\n" );
        else if ( !strcmp( s, "TestStrategy" ) ) printf( "105\n" );
    }

    return 0;
}