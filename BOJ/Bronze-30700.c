#include <stdio.h>
#include <string.h>

char K[1000];

int main( void )
{
    scanf( "%s", K );

    int len = strlen( K );
    char* Name = "KOREA";

    int i, idx = 0, cnt = 0;
    for ( i = 0; i < len; i++ )
    {
        if ( Name[idx] == K[i] )
        {
            if ( idx == 4 )
                idx = 0;
            else
                idx++;

            cnt++;
        }
    }

    printf( "%d", cnt );

    return 0;
}