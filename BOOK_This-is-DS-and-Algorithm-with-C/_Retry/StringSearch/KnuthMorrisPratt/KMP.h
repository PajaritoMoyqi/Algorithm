#ifndef KMP_H
#define KMP_H

# include <stdio.h>
# include <stdlib.h>

void Preprocess( char* Pattern, int patternLength, int* Border );
int KnuthMorrisPratt( char* Text, int textLength, int startIdx, char* Pattern, int patternLength );

#endif