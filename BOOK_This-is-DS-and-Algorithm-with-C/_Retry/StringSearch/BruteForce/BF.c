#include "BF.h"

int BruteForce( char* Text, int textLength, int startIdx, char* Pattern, int patternLength )
{
    int i, j;
    for ( i = startIdx; i <= textLength - patternLength; i++ )
    {
        for ( j = 0; j < patternLength; j++ )
        {
            if ( Text[i+j] != Pattern[j] )
                break;
        }

        if ( j >= patternLength )
            return i;
    }

    return -1;
}