#include <stdio.h>

#define MAX 500

char MAP[MAX+1][MAX+1];

int main( void )
{
    int height, width;
    scanf( "%d%d", &height, &width );

    int i, j;
    for ( i = 0; i < height; i++ )
        scanf( "%s", MAP[i] );

    for ( i = 0; i < height; i++ )
    {
        for ( j = 0; j < width; j++ )
        {
            if ( MAP[i][j] == 'W' )
            {
                if ( i != 0 )
                {
                    if ( MAP[i-1][j] == 'S' )
                    {
                        printf( "0" );
                        return 0;
                    }
                }
                if ( i != height-1 )
                {
                    if ( MAP[i+1][j] == 'S' )
                    {
                        printf( "0" );
                        return 0;
                    }
                }
                if ( j != 0 )
                {
                    if ( MAP[i][j-1] == 'S' )
                    {
                        printf( "0" );
                        return 0;
                    }
                }
                if ( j != width-1 )
                {
                    if ( MAP[i][j+1] == 'S' )
                    {
                        printf( "0" );
                        return 0;
                    }
                }
            }
        }
    }

    printf( "1\n" );
    for ( i = 0; i < height; i++ )
    {
        for ( j = 0; j < width; j++ )
        {
            if ( MAP[i][j] == '.' )
                printf( "D" );
            else
                printf( "%c", MAP[i][j] );
        }
        printf( "\n" );
    }

    return 0;
}