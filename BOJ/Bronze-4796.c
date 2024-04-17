#include <stdio.h>

int main( void )
{
    int avail, interval, total;

    int idx = 1;
    while ( 1 )
    {
        scanf( "%d%d%d", &avail, &interval, &total );
        if ( !avail && !interval && !total )
            break;

        int ans = 0;
        while ( total )
        {
            if ( total > interval )
            {
                ans += avail;
                total -= interval;
            }
            else
            {
                if ( total >= avail )
                    ans += avail;
                else
                    ans += total;

                total = 0;
            }
        }

        printf( "Case %d: %d\n", idx++, ans );
    }

    return 0;
}