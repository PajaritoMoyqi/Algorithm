#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000000

int KnuthMorrisPratt( char* Text, int textLength, int startIdx, char* Pattern, int patternLength );

int Ans[MAX_LEN+1];

int main( void )
{
    char str[MAX_LEN+1];
    char cmp[MAX_LEN+1];

    fgets( str, MAX_LEN+2, stdin );
    fgets( cmp, MAX_LEN+2, stdin );


    int strLen = strlen( str );
    int cmpLen = strlen( cmp );
    if ( str[strLen-1] == '\n' )
    {
        str[strLen-1] = 0;
        strLen--;
    }
    if ( cmp[cmpLen-1] == '\n' )
    {
        cmp[cmpLen-1] = 0;
        cmpLen--;
    }

    // printf( "Q: %s, C: %s\n", str, cmp );
    // printf( "QLen: %d, CLen: %d\n", strLen, cmpLen );

    int cnt = KnuthMorrisPratt( str, strLen, 0, cmp, cmpLen );

    printf( "%d\n", cnt );
    int i;
    for ( i = 0; i < cnt; i++ )
        printf( "%d ", Ans[i]+1 );

    return 0;
}

void Preprocess( char* Pattern, int patternLength, int* Border )
{
    int i = 0, j = -1;
    Border[0] = -1;

    while ( i <= patternLength )
    {
        while ( j >= 0 && Pattern[i] != Pattern[j] )
            j = Border[j];

        Border[++i] = ++j;
    }

    // printf( "Border: " );
    // for ( i = 0; i <= patternLength; i++ )
    //     printf( "%d ", Border[i] );
    // puts( "" );
}

int KnuthMorrisPratt( char* Text, int textLength, int startIdx, char* Pattern, int patternLength )
{
    int i = startIdx;
    int j = 0;
    int idx = 0;

    int* Border = (int*)calloc( patternLength + 2, sizeof( int ) );
    Preprocess( Pattern, patternLength, Border );

    while ( i < textLength )
    {
        while ( j >= 0 && Text[i] != Pattern[j] )
            j = Border[j];

        i++; j++;

        if ( j == patternLength )
            Ans[idx++] = i - j;
    }

    free( Border );
    
    return idx;
}