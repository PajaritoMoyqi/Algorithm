#include <stdio.h>
#include <string.h>

char str[1000000];

int main( void )
{
    scanf( "%s", str );

    int i, length = strlen( str ), prev = -1, cnt = 0;
    for ( i = 0; i < length; i++ )
    {
        if ( i )
        {
            if ( prev != str[i] )
                cnt++;
        }

        prev = str[i];
    }

    if ( cnt & 1 )
        printf( "%d", (cnt / 2) + 1 );
    else
        printf( "%d", cnt / 2 );

    return 0;
}