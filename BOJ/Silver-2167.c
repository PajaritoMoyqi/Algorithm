#include <stdio.h>

int main( void )
{
    int row, col;
    scanf( "%d%d", &row, &col );

    int Nums[row][col];
    int i, j;
    for ( i = 0; i < row; i++ )
        for ( j = 0; j < col; j++ )
            scanf( "%d", &Nums[i][j] );

    int n, x1, y1, x2, y2;
    scanf( "%d", &n );
    while ( n-- )
    {
        int sum = 0;
        scanf( "%d%d%d%d", &x1, &y1, &x2, &y2 );

        x1--; y1--; x2--; y2--;

        for ( i = x1; i <= x2; i++ )
        {
            for ( j = y1; j <= y2; j++ )
                sum += Nums[i][j];
        }

        printf( "%d\n", sum );
    }

    return 0;
}