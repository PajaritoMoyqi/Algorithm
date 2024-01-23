#include <stdio.h>

int main( void )
{
    int a = 4;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    while ( a-- )
    {
        scanf( "%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4 );

        if ( x2 < x3 || x4 < x1 || y2 < y3 || y4 < y1 )
            printf( "d\n" );
        else if ( x1 == x4 || x2 == x3 )
        {
            if ( y4 == y1 || y2 == y3 )
                printf( "c\n" );
            else
                printf( "b\n" );
        }
        else if ( y4 == y1 || y2 == y3 )
            printf( "b\n" );
        else
            printf( "a\n" );
    }

    return 0;
}