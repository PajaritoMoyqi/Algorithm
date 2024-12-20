#include <stdio.h>
#include <string.h>

#define MAX 100000

void swapChar( char* a, char* b );

int main( void )
{
    int t;
    scanf( "%d", &t );

    while ( t-- )
    {
        char STR1[MAX+1] = { 0, };
        char STR2[MAX+1] = { 0, };

        scanf( "%s %s", STR1, STR2 );

        int len1 = strlen( STR1 );
        int len2 = strlen( STR2 );

        if ( len1 != len2 )
        {
            printf( "-1\n" );
            continue;
        }

        int cnt = 0;
        int i, j;
        for ( i = 0; i < len1; i++ )
        {
            if ( STR1[i] == STR2[i] )
                continue;

            for ( j = i+1; j < len1; j++ )
            {
                if ( STR2[i] == STR1[j] )
                {
                    cnt += (j - i);
                    swapChar( &STR1[i], &STR1[j] );
                    break;
                }
            }
        }

        printf( "%d\n", cnt );
    }

    return 0;
}

void swapChar( char* a, char* b )
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}