#include <stdio.h>

int main( void )
{
    int x, y;
    scanf( "%d%d", &x, &y );

    int max = x > y ? x : y;
    int min = x < y ? x : y;

    printf( "%d", max + min + (min/10) );

    return 0;
}