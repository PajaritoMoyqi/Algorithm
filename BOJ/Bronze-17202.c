#include <stdio.h>

int res[16];

void DP( int depth );

int main( void )
{
    int a, b;
    scanf( "%d%d", &a, &b );

    int i;
    for ( i = 0; i < 8; i++ )
    {
        res[15-2*i-1] = a % 10;
        a /= 10;
    }
    for ( i = 0; i < 8; i++ )
    {
        res[15-2*i] = b % 10;
        b /= 10;
    }

    int depth = 16;

    while ( depth != 2 )
        DP( depth-- );

    printf( "%d%d", res[0], res[1] );

    return 0;
}

void DP( int depth )
{
    int i;
    for ( i = 0; i < depth - 1; i++ )
        res[i] = (res[i] + res[i+1]) % 10;
}