#include <stdio.h>
#include <string.h>

char str[100];

int main( void )
{
    scanf( "%s", str );

    if ( strcmp( "SONGDO", str ) == 0 ) printf( "HIGHSCHOOL" );
    else if ( strcmp( "CODE", str ) == 0 ) printf( "MASTER" );
    else if ( strcmp( "2023", str ) == 0 ) printf( "0611" );
    else if ( strcmp( "ALGORITHM", str ) == 0 ) printf( "CONTEST" );

    return 0;
}