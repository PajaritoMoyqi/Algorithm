#include <stdio.h>

char str[500000];

int main( void )
{
    int length;
    scanf( "%d", &length );
    scanf( "%s", str );

    char prev = 'A';
    int i, cnt = 0;
    for ( i = 0; i < length; i++ )
    {
        if ( prev != str[i] )
            cnt++;

        prev = str[i];
    }

    printf( "%d", cnt/2 + 1 );

    return 0;
}