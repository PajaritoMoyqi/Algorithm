#include <stdio.h>

int main( void )
{
    int h, i, a, r, c;
    scanf( "%d%d%d%d%d", &h, &i, &a, &r, &c );

    printf( "%d", h*i - a*r*c );

    return 0;
}