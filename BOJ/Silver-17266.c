#include <stdio.h>

int main( void )
{
    int len, n, prev, pos, max = 0;
    scanf( "%d%d", &len, &n );

    prev = 0;
    for ( int i = 0; i < n; i++ )
    {
        scanf( "%d", &pos );

        if ( i == 0 )
        {
            if ( pos - prev > max )
                max = pos - prev;
        }
        else
        {
            if ( (pos - prev) > max * 2 )
            {
                if ( (pos - prev) % 2 == 0 )
                    max = (pos - prev) / 2;
                else
                    max = ((pos - prev) / 2) + 1;
            }
        }
        
        prev = pos;

        printf( "i: %d, max: %d\n", i, max );
    }

    if ( len - pos > max )
        max = len - pos;

    printf( "%d", max );

    return 0;
}