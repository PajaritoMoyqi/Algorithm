#include <stdio.h>

#define MAX_N 64

int Video[MAX_N+1][MAX_N+1];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i, j;
    for ( i = 1; i <= n; i++ )
        for ( j = 1; j <= n; j++ )
            scanf( "%1d", &Video[i][j] );
    // for ( i = 1; i <= n; i++ )
    // {
    //     for ( j = 1; j <= n; j++ )
    //         printf( "%d", Video[i][j] );
    //     puts( "" );
    // }

    Compression( Video, 1, 1, n );

    return 0;
}

void Compression( int(* Video)[MAX_N+1], int x, int y, int len )
{
    int num, flag = 0;
    int i, j;
    for ( i = y; i < y + len; i++ )
        for ( j = x; j < x + len; j++ )
        {
            if ( i == y && j == x )
            {
                num = Video[i][j];
                continue;
            }

            if ( num != Video[i][j] )
            {
                int L = len/2;
                flag = 1;
                printf( "(" );
                Compression( Video, x, y, L );
                Compression( Video, x+L, y, L );
                Compression( Video, x, y+L, L );
                Compression( Video, x+L, y+L, L );
                printf( ")" );
                
                return;
            }
        }

    if ( !flag )
        printf( "%d", num );
}