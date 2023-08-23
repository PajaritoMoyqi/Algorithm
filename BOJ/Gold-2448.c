#include <stdio.h>

char paper[3072][6144];
int n;

void mark( int row, int col, int N );

int main( void )
{
    scanf( "%d", &n );
    memset( paper, ' ', sizeof( paper ) );
    mark( 0, n - 1, n );

    int i, j;
    for ( i = 0; i < n; i++ )
    {
        for ( j = 0; j < 2*n; j++ )
            putchar( paper[i][j] );

        putchar( 10 );
    }

    return 0;   
}

void mark( int row, int col, int N )
{
    if ( N == 3 )
    {
        paper[row][col] = '*';
        paper[row+1][col-1] = '*';
        paper[row+1][col+1] = '*';
        paper[row+2][col-2] = '*';
        paper[row+2][col-1] = '*';
        paper[row+2][col] = '*';
        paper[row+2][col+1] = '*';
        paper[row+2][col+2] = '*';
    }
    else
    {
        mark( row, col, N/2 );
        mark( row + N/2, col - N/2, N/2 );
        mark( row + N/2, col + N/2, N/2 );
    }
}