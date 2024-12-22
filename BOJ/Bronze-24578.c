#include <stdio.h>

char LED[4][4];

int main( void )
{
    int time;
    scanf( "%d", &time );

    int hour, minute;
    hour = time / 100;
    minute = time % 100;

    int h1, h2, m1, m2;
    h1 = hour / 10;
    h2 = hour % 10;
    m1 = minute / 10;
    m2 = minute % 10;

    int i;
    for ( i = 3; i >= 0; i-- )
    {
        LED[i][0] = h1 & 1 ? '*' : '.';
        LED[i][1] = h2 & 1 ? '*' : '.';
        LED[i][2] = m1 & 1 ? '*' : '.';
        LED[i][3] = m2 & 1 ? '*' : '.';

        h1 /= 2;
        h2 /= 2;
        m1 /= 2;
        m2 /= 2;
    }

    for ( i = 0; i < 4; i++ )
    {
        printf( "%c", LED[i][0] );
        printf( " " );
        printf( "%c", LED[i][1] );
        printf( "   " );
        printf( "%c", LED[i][2] );
        printf( " " );
        printf( "%c", LED[i][3] );
        puts( "" );
    }

    return 0;
}