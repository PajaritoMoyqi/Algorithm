#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* mySubstr( char str[], int idx, int len );

int main( void )
{
    int pLen, len;
    scanf( "%d%d", &pLen, &len );
    char str[len+1];
    scanf( "%s", str );

    int pCnt, cnt = 0;
    int i;
    for ( i = 0; i < len; i++ )
    {
        pCnt = 0;

        if ( str[i] == 'O' )
            continue;

        while ( str[i+1] == 'O' && str[i+2] == 'I' )
        {
            pCnt++;
            if ( pCnt == pLen )
            {
                pCnt--;
                cnt++;
            }
            i += 2;
        }
    }

    printf( "%d", cnt );

    return 0;
}