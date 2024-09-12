#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#define MAX_N 531441

int main( void )
{
    int n;

    while ( scanf( "%d", &n ) != EOF )
    {
        int max = 1;
        int i;
        for ( i = 0; i < n; i++ )
            max *= 3;

        char* str = (char*)calloc( MAX_N+1, sizeof( char ) );
        memset( str, '-', max );
        int len = strlen( str );

        exchangeStr( str, len );

        printf( "%s\n", str );
    }

    return 0;
}

void exchangeStr( char* string, int len )
{
    if ( len == 1 )
        return;

    int partition = len/3;

    memset( string + partition, ' ', partition );

    exchangeStr( string, partition );
    exchangeStr( string + 2*partition, partition );
};