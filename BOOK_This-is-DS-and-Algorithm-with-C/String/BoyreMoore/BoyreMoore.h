#ifndef BOYREMOORE_H
#define BOYREMOORE_H

#include <stdio.h>

int BoyreMoore( char* Text, int TextSize, int Start, char* Pattern, int PatternSize );
void BuildBST( char* Pattern, int PatternSize, int* BadCharTable );
void BuildGST( char* Pattern, int PatternSize, int* PostOfBorder, int* GoodSuffTable );
int Max( int A, int B );

#endif