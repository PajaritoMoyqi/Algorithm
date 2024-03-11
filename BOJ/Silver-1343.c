#include <stdio.h>
#include <string.h>

int main( void )
{
    char str[50+1] = { 0, };
    char ans[50+1] = { 0, };

    scanf( "%s", str );

    int size = strlen(str);
    int i, num = 0;
    for ( i = 0; i < size; i++ )
    {
        if ( str[i] == '.' )
        {
            if ( num == 1 || num == 3 )
            {
                printf( "-1" );
                return 0;
            }
            else if ( num == 2 )
            {
                strcat( ans, "BB." );
                num = 0;
            }
            else if ( num == 0 )
            {
                strcat( ans, "." );
            }
            else if ( num == 4 )
            {
                strcat( ans, "AAAA." );
                num = 0;
            }
        }
        else
        {
            if ( num == 4 )
            {
                num = 1;
                strcat( ans, "AAAA" );
            }
            else
                num++;
        }
    }

    if ( num == 1 || num == 3 )
    {
        printf( "-1" );
        return 0;
    }
    else if ( num == 2 )
        strcat( ans, "BB" );
    else if ( num == 4 )
        strcat( ans, "AAAA" );

    printf( "%s", ans );

    return 0;
}