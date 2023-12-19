#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct LCSTable
{
    int** Data;
} LCSTable;

int LCS( char* X, char* Y, int lenX, int lenY, LCSTable* T )
{
    int i, j;
    for ( i = 0; i <= lenX; i++ )
        T->Data[i][0] = 0;
    for ( j = 0; j <= lenY; j++ )
        T->Data[0][j] = 0;

    for ( i = 1; i <= lenX; i++ )
    {
        for ( j = 1; j <= lenY; j++ )
        {
            if ( X[i-1] == Y[i-1] )
                T->Data[i][j] = T->Data[i-1][j-1] + 1;
            else
            {
                if ( T->Data[i][j-1] >= T->Data[i-1][j] )
                    T->Data[i][j] = T->Data[i][j-1];
                else
                    T->Data[i][j] = T->Data[i-1][j];
            }
        }
    }

    return T->Data[i][j];
}

void FindLCS( char* X, char* Y, int lenX, int lenY, LCSTable* T, char* LCS )
{
    if ( lenX == 0 || lenY == 0 )
        return;

    if ( T->Data[lenX][lenY] > T->Data[lenX-1][lenY-1]
        && T->Data[lenX][lenY] > T->Data[lenX-1][lenY]
        && T->Data[lenX][lenY] > T->Data[lenX][lenY-1] )
    {
        char TmpLCS[100];
        strcpy( TmpLCS, LCS );
        sprintf( LCS, "%c%s", X[lenX-1], TmpLCS );

        FindLCS( X, Y, lenX-1, lenY-1, T, LCS );
    }
    else if ( T->Data[lenX][lenY] > T->Data[lenX-1][lenY]
        && T->Data[lenX][lenY] == T->Data[lenX][lenY-1] )
    {
        FindLCS( X, Y, lenX, lenY-1, T, LCS );
    }
    else
    {
        FindLCS( X, Y, lenX-1, lenY, T, LCS );
    }
}