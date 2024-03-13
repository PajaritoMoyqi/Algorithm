#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 3000

char str[MAX_LENGTH];

int main( void )
{
    scanf( "%s", str );
    int length = strlen( str );

    int i = 1, pos = 0, lastIdx = length - 1;
    while ( 1 )
    {
        char cmpStr[MAX_LENGTH];
        sprintf( cmpStr, "%d", i );

        int cmpLength = strlen( cmpStr );
        int j;
        for ( j = 0; j < cmpLength; j++ )
        {
            if ( cmpStr[j] == str[pos] )
                pos++;

            if ( pos == length )
                goto end;
        }

        i++;
    }

    end:
        printf( "%d", i );

    return 0;
}