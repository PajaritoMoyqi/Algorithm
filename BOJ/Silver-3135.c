#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    int curr, goal;
    scanf( "%d%d", &curr, &goal );

    int interval = abs( curr - goal ), flag = 0;

    int n, teleport;
    scanf( "%d", &n );
    while ( n-- )
    {
        scanf( "%d", &teleport );
        int tmp = abs( goal - teleport );

        if ( tmp < interval )
        {
            interval = tmp;
            flag = 1;
        }
    }

    printf( "%d", interval + flag );

    return 0;
}