#include <stdio.h>
#include <string.h>
#include <math.h>

char paper[1024][1024];
void mark( int row, int col, int N );

int main( void )
{
    memset( paper, ' ', sizeof( paper ) );
    
    int n;
    scanf( "%d", &n );
    int limit = (int)pow( 2, n );

    mark( 0, 0, n );

    int i, j;
    for ( i = 0; i < limit; i++ )
    {
        for ( j = 0; j < limit - i; j++ )
            printf( "%c", paper[i][j] );
        puts( "" );
    }

    return 0;
}

void mark( int row, int col, int N )
{
    if ( N == 0 )
    {
        paper[0][0] = '*';
        return;
    }
    else if ( N == 1 )
    {
        paper[0][0] = '*';
        paper[1][0] = '*';
        paper[0][1] = '*';
        return;
    }
    else if ( N == 2 )
    {
        paper[row][col] = '*';
        paper[row][col+1] = '*';
        paper[row][col+2] = '*';
        paper[row][col+3] = '*';
        paper[row+1][col] = '*';
        paper[row+1][col+2] = '*';
        paper[row+2][col] = '*';
        paper[row+2][col+1] = '*';
        paper[row+3][col] = '*';
    }
    else
    {
        int dif = (int)pow( 2, N - 1 );
        mark( row, col, N - 1 );
        mark( row, col + dif, N - 1 );
        mark( row + dif, col, N - 1 );
    }
}