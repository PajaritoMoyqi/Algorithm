#include <stdio.h>
#include <string.h>

int main( void ){
    char str[101];
    unsigned int length = 0;

    scanf( "%s", &str );
    length = strlen( str );

    for ( int i = 0; i < length ; i++ )
    {
        // printf( "str: %c, ", str[i] );
        // printf( "address: %d\n", &str[i] );

        if ( str[i] >= 'A' && str[i] <= 'Z' )
            str[i] += 32;
        else if ( str[i] >= 'a' && str[i] <= 'z' )
            str[i] -= 32;
    }

    printf( "%s", str );

    return 0;
}