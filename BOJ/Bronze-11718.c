#include <stdio.h>

int main()
{
    char str[101];

    while ( fgets( str, 101, stdin ) )
        printf( "%s", str );

    return 0;
}