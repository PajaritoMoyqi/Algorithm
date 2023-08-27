#include <stdio.h>

#define len 3

char str[len+1];

int main( void )
{
    scanf( "%s", str );

    int length = len;
    while ( length-- )
        printf( "%c", str[length] );

    return 0;
}