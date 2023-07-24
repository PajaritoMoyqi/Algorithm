#include <stdio.h>
#include <stdlib.h>

void FindSolution( int Column[], int Row, int NumberOfQueens, int* SolutionCount );

int main( void )
{
    int SolutionCnt = 0;
    int NumberOfQueens;
    scanf( "%d", &NumberOfQueens );

    int* Columns;
    Columns = (int*)calloc( NumberOfQueens, sizeof( int ) );
    int i;

    for ( i = 0; i < NumberOfQueens; i++ )
    {
        Columns[0] = i;
        FindSolution( Columns, 0, NumberOfQueens, &SolutionCnt );
    }

    printf( "%d", SolutionCnt );
    free( Columns );

    return 0;
}

int IsThreatened( int Columns[], int NewRow )
{
    int CurrentRow = 0;
    int Threatened = 0;

    while ( CurrentRow < NewRow )
    {
        if ( Columns[NewRow] == Columns[CurrentRow] 
        || abs( Columns[NewRow] - Columns[CurrentRow] ) == abs( NewRow - CurrentRow ) )
        {
            Threatened = 1;
            break;
        }

        CurrentRow++;
    }

    return Threatened;
}
void FindSolution( int Columns[], int Row, int NumberOfQueens, int* SolutionCount )
{
    if ( IsThreatened( Columns, Row ) )
        return;

    if ( Row == NumberOfQueens - 1 )
        ++(*SolutionCount);
    else
    {
        int i;

        for ( i = 0; i < NumberOfQueens; i++ )
        {
            Columns[Row+1] = i;
            FindSolution( Columns, Row+1, NumberOfQueens, SolutionCount );
        }
    }
}