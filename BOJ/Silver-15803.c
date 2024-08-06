#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    int x1, y1, x2, y2, x3, y3;
    scanf( "%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3 );

    int diffX1 = abs(x2 - x1);
    int diffY1 = abs(y2 - y1);
    int diffX2 = abs(x3 - x2);
    int diffY2 = abs(y3 - y2);
    int diffX3 = abs(x1 - x3);
    int diffY3 = abs(y1 - y3);

    if ( diffX1 * diffY2 == diffX2 * diffY1 &&
        diffX2 * diffY3 == diffX3 * diffY2 &&
        diffX1 * diffY3 == diffX3 * diffY1 )
        printf( "WHERE IS MY CHICKEN?" );
    else
        printf( "WINNER WINNER CHICKEN DINNER!" );

    return 0;
}