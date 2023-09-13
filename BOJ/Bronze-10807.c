#include <stdio.h>

int acc[200+1];

int main( void )
{
    int t;
    scanf( "%d", &t );

    int o;
    while ( t-- )
    {
        scanf( "%d", &o );
        o += 100;

        acc[o]++;
    }

    scanf( "%d", &o );
    printf( "%d", acc[o+100] );

    return 0;
}