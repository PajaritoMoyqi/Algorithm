#include <stdio.h>

int size, i, N, j, sum;

int main( void )
{
    scanf( "%d", &size );

    for ( j = 0; j < size; j++ )
    {
        sum = 0;
        for ( i = 0; i < size; i++ )
        {
            scanf( "%d", &N );
            if ( j == i ) continue;
            sum |= N;
        }

        printf( "%d ", sum );
    }

    return 0;
}