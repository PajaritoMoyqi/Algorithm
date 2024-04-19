#include <stdio.h>
#include <string.h>
#define MAX_LEN 100000

char str[MAX_LEN];

int main( void )
{
    scanf( "%s", str );
    int length = strlen( str );

    int i = 0, cnt = 1;
    while ( str[i] )
    {
        if ( str[i+1] )
        {
            if ( str[i] >= str[i+1] )
                cnt++;

            i++;
        }
        else
            break;
    }

    printf( "%d", cnt );

    return 0;
}