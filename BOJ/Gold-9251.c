#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct structTable
{
    int** Data;
} Table;

char x[1000+1];
char y[1000+1];

int LCS( char* X, char* Y, int i, int j, Table* Table );

int main( void )
{
    scanf( "%s%s", &x, &y );
    int xLen = strlen( x );
    int yLen = strlen( y );

    Table Table;
    Table.Data = (int**)malloc( sizeof( int* ) * (xLen + 1) );
    int i;
    for ( i = 0; i < xLen + 1; i++ )
    {
        Table.Data[i] = (int*)malloc( sizeof( int ) * (yLen + 1) );
        memset( Table.Data[i], 0, sizeof( int ) * (yLen + 1) );
    }

    printf( "%d", LCS( x, y, xLen, yLen, &Table ) );

    return 0;
}

int LCS( char* X, char* Y, int i, int j, Table* Table )
{
    int m, n;

    for ( m = 0; m <= i; m++ )
        Table->Data[m][0] = 0;
    for ( n = 0; n <= j; n++ )
        Table->Data[0][n] = 0;

    for ( m = 1; m <= i; m++ )
    {
        for ( n = 1; n <= j; n++ )
        {
            if ( X[m-1] == Y[n-1] )
                Table->Data[m][n] = Table->Data[m-1][n-1] + 1;
            else
            {
                if ( Table->Data[m][n-1] >= Table->Data[m-1][n] )
                    Table->Data[m][n] = Table->Data[m][n-1];
                else
                    Table->Data[m][n] = Table->Data[m-1][n];
            }
        }
    }

    return Table->Data[i][j];
}