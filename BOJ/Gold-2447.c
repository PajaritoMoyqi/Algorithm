#include <stdio.h>

char paper[2187][2187];
int n;

void mark( int row, int col, int N );

int main( void )
{
    scanf( "%d", &n );
    memset( paper, ' ', sizeof( paper ) );
    mark( 0, 0, n );

    int i, j;
    for ( i = 0; i < n; i++ )
    {
        for ( j = 0; j < n; j++ )
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
        paper[row][col+1] = '*';
        paper[row][col+2] = '*';
        paper[row+1][col] = '*';
        paper[row+1][col+2] = '*';
        paper[row+2][col] = '*';
        paper[row+2][col+1] = '*';
        paper[row+2][col+2] = '*';
    }
    else
    {
        mark( row, col, N/3 );
        mark( row + N/3, col, N/3 );
        mark( row + N/3 + N/3, col, N/3 );
        mark( row, col + N/3, N/3 );
        mark( row + N/3 + N/3, col + N/3, N/3 );
        mark( row, col + N/3 + N/3, N/3 );
        mark( row + N/3, col + N/3 + N/3, N/3 );
        mark( row + N/3 + N/3, col + N/3 + N/3, N/3 );        
    }
}