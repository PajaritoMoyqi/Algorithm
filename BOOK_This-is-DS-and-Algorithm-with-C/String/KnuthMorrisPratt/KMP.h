#ifndef KMP_H
#define KMP_H

# include <stdio.h>

void Preprocess( char* Pattern, int PatternSize, int* Border );
int KMP( char* Text, int TextSize, int Start, char* Pattern, int PatternSize );

#endif