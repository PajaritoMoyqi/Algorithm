#ifndef BM_H
#define BM_H

# include <stdio.h>
# include <stdlib.h>

int Max( int a, int b );
void BuildBST( char* Pattern, int patternLength, int* BadCharTable );
void BuildGST( char* Pattern, int patternLength, int* PostOfBorder, int* GoodSuffixTable );

int BoyreMoore( char* Text, int textLength, int startIdx, char* Pattern, int patternLength );

#endif