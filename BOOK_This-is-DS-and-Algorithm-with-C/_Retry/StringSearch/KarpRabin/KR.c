#include "KR.h"

int Hash( char* Str, int length )
{
    int i, hashValue = 0;
    for ( i = 0; i < length; i++ )
        hashValue = Str[i] + ( hashValue * 2 );

    return hashValue;
}
int ReHash( char* Str, int startIdx, int length, int prevHash, int coefficient )
{
    if ( startIdx == 0 )
        return prevHash;

    return Str[startIdx + length - 1] + 2 * (prevHash - coefficient * Str[startIdx-1]);
}

int KarpRabin( char* Text, int textLength, int startIdx, char* Pattern, int patternLength )
{
    int coefficient = pow( 2, patternLength );
    int textHash = Hash( Text, patternLength );
    int patternHash = Hash( Pattern, patternLength );

    int i, j;
    for ( i = 0; i <= textLength - patternLength; i++ )
    {
        textHash = ReHash( Text, i, patternLength, textHash, coefficient );

        if ( patternHash == textHash )
        {
            for ( j = 0; j < patternLength; j++ )
            {
                if ( Text[i+j] != Pattern[j] )
                    break;
            }

            if ( j >= patternLength )
                return i;
        }
    }

    return -1;
}