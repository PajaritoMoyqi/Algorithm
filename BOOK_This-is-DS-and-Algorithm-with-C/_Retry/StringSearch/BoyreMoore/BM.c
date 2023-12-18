#include "BM.h"

int Max( int a, int b )
{
    if ( a > b )
        return a;
    else
        return b;
}
void BuildBST( char* Pattern, int patternLength, int* BadCharTable )
{
    int i;
    for ( i = 0; i < 128; i++ )
        BadCharTable[i] = -1;

    for ( i = 0; i < patternLength; i++ )
        BadCharTable[Pattern[i]] = i;
}
void BuildGST( char* Pattern, int patternLength, int* PostOfBorder, int* GoodSuffixTable )
{
    int i = patternLength, j = patternLength + 1;
    // start of loop
    PostOfBorder[i] = j; // empty character right after last character of pattern

    while ( i > 0 ) // loop length = pattern length
    {
        while ( j <= patternLength && Pattern[i-1] != Pattern[j-1] ) // if there is border in pattern
        {
            if ( GoodSuffixTable[j] == 0 )
                GoodSuffixTable[j] = j - i;

            j = PostOfBorder[j];
        }

        // start of loop
        i--; j--;
        PostOfBorder[i] = j; // save the found start point of border
    }

    j = PostOfBorder[0];
    for ( i = 0; i <= patternLength; i++ ) // gives pattern match information to index where its value is 0 in good suffix table
    {
        if ( GoodSuffixTable[i] == 0 )
            GoodSuffixTable[i] = j;

        if ( i == j )
            j = PostOfBorder[j];
    }
}
int BoyreMoore( char* Text, int textLength, int startIdx, char* Pattern, int patternLength )
{
    int BadCharTable[128];
    int* GoodSuffixTable = (int*)calloc( patternLength + 1, sizeof( int ) ); // len + 1
    int* PostOfBorder = (int*)calloc( patternLength + 1, sizeof( int ) );
    
    int i = startIdx, j = 0;
    int position = -1;

    // build two tables
    BuildBST( Pattern, patternLength, BadCharTable );
    BuildGST( Pattern, patternLength, PostOfBorder, GoodSuffixTable );

    while ( i <= textLength - patternLength )
    {
        j = patternLength - 1;

        while ( j >= 0 && Pattern[j] == Text[i+j] )
            j--;

        if ( j < 0 ) // find same string
        {
            position = i;
            break;
        }
        else // move pattern with max distance of good suffix table and bad character table
            i += Max( GoodSuffixTable[j+1], j - BadCharTable[Text[i+j]] );
    }

    free( PostOfBorder );
    free( GoodSuffixTable );

    return position;
}