#include <stdio.h>

int main( void )
{
    int chess[6] = { 1, 1, 2, 2, 2, 8 };

    int idx, n;
    for ( idx = 0; idx <= 5; idx++ )
    {
        scanf( "%d", &n );
        printf( "%d ", chess[idx] - n );
    }

    return 0;
}