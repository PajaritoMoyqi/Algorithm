#include <stdio.h>

int main( void )
{
    int a = 1;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    while ( a-- )
    {
        scanf( "%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4 );

        if ( x2 < x3 || x4 < x1 || y2 < y3 || y4 < y1 )
            printf( "NULL\n" );
        else if ( x1 == x4 || x2 == x3 )
        {
            if ( y4 == y1 || y2 == y3 )
                printf( "POINT\n" );
            else
                printf( "LINE\n" );
        }
        else if ( y4 == y1 || y2 == y3 )
            printf( "LINE\n" );
        else
            printf( "FACE\n" );
    }

    return 0;
}