#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagTable
{
    int** Data;
} Table;

int LCS( char* X, char* Y, int i, int j, Table* Table );
void traceLCS( char* X, char* Y, int xEnd, int yEnd, Table* Table );

char x[1000+1];
char y[1000+1];
char ans[1000+1];
int idx = 0;

int main( void )
{
    scanf( "%s%s", x, y );
    int xLen = strlen( x );
    int yLen = strlen( y );

    Table Table;
    Table.Data = (int**)malloc( sizeof( int* ) * (xLen + 1) );
    int i;
    for ( i = 0; i <= xLen; i++ )
    {
        Table.Data[i] = (int*)malloc( sizeof( int ) * (yLen + 1) );
        memset( Table.Data[i], 0, sizeof( int ) * (yLen + 1) );
    }

    printf( "%d\n", LCS( x, y, xLen, yLen, &Table ) );
    traceLCS( x, y, xLen, yLen, &Table );
    
    printf( "%s", ans );
    for ( i = 0; i < strlen( ans )/2; i++ )
    {
        char tmp;
        tmp = ans[i];
        ans[i] = ans[strlen( ans )-i-1];
        ans[strlen( ans )-i-1] = tmp;
    }
    printf( "%s", ans );

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
            {
                Table->Data[m][n] = Table->Data[m-1][n-1] + 1;
            }
            else
            {
                if ( Table->Data[m-1][n] >= Table->Data[m][n-1] )
                    Table->Data[m][n] = Table->Data[m-1][n];
                else
                    Table->Data[m][n] = Table->Data[m][n-1];
            }
        }
    }

    return Table->Data[i][j];
}

void traceLCS( char* X, char* Y, int xEnd, int yEnd, Table* Table )
{
    if ( xEnd == 0 || yEnd == 0 ) return;

    if ( Table->Data[xEnd][yEnd] > Table->Data[xEnd-1][yEnd-1]
        && Table->Data[xEnd][yEnd] > Table->Data[xEnd-1][yEnd]
        && Table->Data[xEnd][yEnd] > Table->Data[xEnd][yEnd-1] )
    {
        ans[idx++] = X[xEnd-1];
        traceLCS( x, y, xEnd-1, yEnd-1, Table );
    }
    else if ( Table->Data[xEnd][yEnd] > Table->Data[xEnd-1][yEnd]
        && Table->Data[xEnd][yEnd] == Table->Data[xEnd][yEnd-1] )
    {
        traceLCS( x, y, xEnd, yEnd-1, Table );
    }
    else
        traceLCS( x, y, xEnd-1, yEnd, Table );
}