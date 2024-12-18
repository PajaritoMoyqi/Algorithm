#include <stdio.h>

int main( void )
{
    int a, b;
    scanf( "%d%d", &a, &b );

    int i, j;
    for ( i = 0; i < a; i++ )
    {
        for ( j = 0; j < b; j++ )
            printf( "*" );

        printf( "\n" );
    }

    return 0;
}