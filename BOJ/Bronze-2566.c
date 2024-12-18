#include <stdio.h>

#define MAX 90

int main( void )
{
    int i, max = -1, num, ans;
    for ( i = 0; i < MAX; i++ )
    {
        scanf( "%d", &num );

        if ( max < num )
        {
            max = num;
            ans = i;
        }
    }

    printf( "%d\n", max );
    printf( "%d %d", (ans / 9) + 1, (ans % 9) + 1 );

    return 0;
}