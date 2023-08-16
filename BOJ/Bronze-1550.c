#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    char s[6+1];
    scanf( "%s", s );
    int d = strtol( s, NULL, 16 );

    printf( "%d", d );

    return 0;
}