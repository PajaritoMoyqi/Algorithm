#ifndef NQUEENS_H
#define NQUEENS_H

void FindSolutionForQueen( int Columns[], int Row, int NumberOfQueens, int* SolutionCount );
int IsThreatened( int Columns[], int NewRow );
void PrintSolution( int Columns[], int NumberOrQueens );

#endif