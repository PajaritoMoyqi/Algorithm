#include <stdio.h>
#include <string.h>

char S[3000];
char Max[3000];
char Min[3000];

int main( void )
{
    scanf( "%s", S );

    int length = strlen( S );
    int i, j, cnt = 0;
    for ( i = 0; i < length; i++ )
    {
        if ( S[i] == 'M' )
        {
            cnt++;
        }
        else
        {
            strcat( Max, "5" );
            for ( j = 0; j < cnt; j++ )
                strcat( Max, "0" );

            cnt = 0;
        }
    }
    for ( i = 0; i < cnt; i++ )
        strcat( Max, "1" );

    cnt = 0;
    for ( i = 0; i < length; i++ )
    {
        if ( S[i] == 'M' )
        {
            cnt++;
        }
        else
        {
            for ( j = 0; j < cnt; j++ )
            {
                if ( !j )
                    strcat( Min, "1" );
                else
                    strcat( Min, "0" );
            }
            strcat( Min, "5" );

            cnt = 0;
        }
    }
    for ( i = 0; i < cnt; i++ )
    {
        if ( !i )
            strcat( Min, "1" );
        else
            strcat( Min, "0" );
    }

    printf( "%s\n%s", Max, Min );

    return 0;
}