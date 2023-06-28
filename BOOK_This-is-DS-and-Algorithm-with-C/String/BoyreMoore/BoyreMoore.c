#include "BoyreMoore.h"
#include <stdlib.h>

int BoyreMoore( char* Text, int TextSize, int Start, char* Pattern, int PatternSize )
{
    int BadCharTable[128];
    int* GoodSuffTable = (int*)calloc( PatternSize + 1, sizeof( int ) );
    int* PostOfBorder = (int*)calloc( PatternSize + 1, sizeof( int ) );
    int i = Start;
    int j = 0;

    int Position = -1;

    BuildBST( Pattern, PatternSize, BadCharTable );
    BuildGST( Pattern, PatternSize, PostOfBorder, GoodSuffTable );

    while ( i <= TextSize - PatternSize )
    {
        j = PatternSize - 1;

        while ( j >= 0
            && Pattern[j] == Text[i+j] )
        {
            j--;
        }

        if ( j < 0 )
        {
            Position = i;
            break;
        }
        else
            i += Max( GoodSuffTable[j + 1], j - BadCharTable[Text[i + j]] );
    }

    free( PostOfBorder );
    free( GoodSuffTable );

    return Position;
}

void BuildBST( char* Pattern, int PatternSize, int* BadCharTable )
{
    int i;
    int j;

    for ( i = 0; i < 128; i++ )
        BadCharTable[i] = -1;

    for ( j = 0; j < PatternSize; j++ )
        BadCharTable[Pattern[j]] = j;
}

void BuildGST( char* Pattern, int PatternSize, int* PostOfBorder, int* GoodSuffTable )
{
    int i = PatternSize;
    int j = PatternSize + 1;

    PostOfBorder[i] = j;

    while ( i > 0 )
    {
        while ( j <= PatternSize
            && Pattern[i - 1] != Pattern[j - 1] )
        {
            if ( GoodSuffTable[j] == 0 )
                GoodSuffTable[j] = j - 1;

            j = PostOfBorder[j];
        }

        i--;
        j--;

        PostOfBorder[i] = j;
    }

    j = PostOfBorder[0];

    for ( i = 0; i <= PatternSize; i++ )
    {
        if ( GoodSuffTable[i] == 0 )
            GoodSuffTable[i] = j;

        if ( i == j )
            j = PostOfBorder[j];
    }
}

int Max( int A, int B )
{
    if ( A > B )
        return A;
    else
        return B;
}