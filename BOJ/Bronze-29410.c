#include <stdio.h>

int main( void )
{
    int n, cost0, cost1;
    scanf( "%d%d%d", &n, &cost0, &cost1 );

    int cost = 0;
    while ( n-- )
    {
        int m;
        scanf( "%d", &m );
        while ( m-- )
        {
            int h;
            scanf( "%d", &h );

            while ( h )
            {
                if ( h & 1 )
                    cost += cost1;
                else
                    cost += cost0;

                h /= 2;
            }
        }
    }

    printf( "%d", cost );
    
    return 0;
}