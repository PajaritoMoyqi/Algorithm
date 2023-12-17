#include "KMP.h"

void Preprocess( char* Pattern, int patternLength, int* Border )
{
    int i = 0, j = -1;
    Border[0] = -1;

    while ( i < patternLength )
    {
        while ( j > -1 && Pattern[i] != Pattern[j] )
            j = Border[j];

        i++;j++;

        Border[i] = j;
    }
}

int KnuthMorrisPratt( char* Text, int textLength, int startIdx, char* Pattern, int patternLength )
{
    int i = startIdx;
    int j = 0, position = -1;

    int* Border = (int*)calloc( patternLength + 1, sizeof( int ) );
    Preprocess( Pattern, patternLength, Border );

    while ( i < textLength )
    {
        while ( j >= 0 && Text[i] != Pattern[j] )
            j = Border[j];

        i++;j++;

        if ( j == patternLength )
        {
            position = i - j;
            break;
        }
    }

    free( Border );
    
    return position;
}