#include <stdio.h>

char s[100001];
char t[100001];

int main( void )
{
    while ( scanf( "%s %s", s, t ) != EOF )
    {
        int i = 0, max = -1, flag = 1;
        while ( s[i] && flag )
        {
            int j;
            for ( j = max+1; ; j++ )
            {
                if ( t[j] == '\0' )
                {
                    flag = 0;
                    break;
                }

                if ( s[i] == t[j] )
                {
                    max = j;
                    break;
                }
            }

            i++;
        }

        if ( flag )
            printf( "Yes\n" );
        else
            printf( "No\n" );
    }

    return 0;
}