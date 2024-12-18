#include <stdio.h>

int main( void )
{
    int num, i, j;

    while ( 1 )
    {
        scanf( "%d", &num );

        if ( !num )
            break;

        for ( i = 1; i <= num; i++ )
        {
            for ( j = 0; j < i; j++ )
                printf( "*" );

            printf( "\n" );
        }
    }

    return 0;
}