#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* mySubstr( char str[], int idx, int len );

int main( void )
{
    int pLen, len;
    scanf( "%d%d", &pLen, &len );
    char str[len+1];
    pLen = pLen * 2 + 1;
    char pattern[pLen+1];
    int i;
    for( i = 0; i <= pLen; i++ )
    {
        if ( i == pLen )
        {
            pattern[i] = 0;
            break;
        }
        if ( i & 1 ) pattern[i] = 'O';
        else pattern[i] = 'I';
    }
    scanf( "%s", str );
    // printf( "pattern: %s\n", pattern );

    int cnt = 0;
    i = 0;
    while ( i != len )
    {
        // printf( "%d-th while statement\n", i );
        if ( i + pLen > len )
        {
            // printf( "pattern's last index: %d > len: %d\n", i + pLen, len );
            break;
        }
        if ( str[i] == 'I' )
        {
            // printf( "I found\n" );


            char* test = mySubstr( str, i, pLen );
            // printf( "pattern: %s, test: %s\n", pattern, test );
            if ( !strcmp( pattern, test ) )
            {
                // printf( "pattern found\n" );
                cnt++;
                i += 2;
                free( test );
                continue;
            }
        }
        
        i++;
    }

    printf( "%d", cnt );

    return 0;
}

char* mySubstr( char str[], int idx, int len )
{
    char* ss = (char*)malloc( sizeof( char ) * ( len + 1 ) );
    strncpy( ss, str + idx, len );
    ss[len] = '\0';
    return ss;
}