#include <stdio.h>

int main( void )
{
    int a, b;
    scanf( "%d%d", &a, &b );

    int i, j;
    char c;
    float ans = 0;
    for ( i = 0; i < a; i++ )
    {
        int flag = 0;
        for ( j = 0; j < b; j++ )
        {
            scanf( " %c", &c ); // remove whitespace and initialize c
            // printf( "num: %d, char: %c\n", i*4+j+1, c );

            if ( c == '/' || c == 92 )
            {
                if ( !flag )
                    flag = 1;
                else
                    flag = 0;

                ans += 0.5;
            }
            else if ( c == '.' )
            {
                if ( flag )
                    ans += 1;
            }
        }
    }

    printf( "%d", (int)ans );

    return 0;
}