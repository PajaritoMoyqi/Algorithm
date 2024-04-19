#include <stdio.h>
#include <string.h>
#define MAX_LEN 1000

char s[100];
char cmpS[1000];

int main( void )
{
    int len, num;
    scanf( "%d%d", &len, &num );

    scanf( "%s", s );

    int i, idx;
    while ( num-- )
    {
        scanf( "%s", cmpS );
        i = idx = 0;
        
        while ( s[i] && cmpS[idx] )
        {
            if ( s[i] == cmpS[idx++] )
                i++;
        }

        if ( i == len )
            printf( "true\n" );
        else
            printf( "false\n" );
    }

    return 0;
}