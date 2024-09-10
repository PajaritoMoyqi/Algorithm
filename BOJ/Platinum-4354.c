#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000000

void Preprocess( char* Pattern, int patternLength, int* Border );
int KnuthMorrisPratt( char* Text, int textLength, int startIdx, char* Pattern, int patternLength );

int Ans[MAX_LEN+1];

int main( void )
{
    char str[MAX_LEN+1];
    while ( 1 )
    {
        scanf( "%s", str ); 
        if ( !strcmp( str, "." ) )
            break;

        int len = strlen( str );

        int* Border = calloc( len + 2, sizeof( int ) );
        Preprocess( str, len, Border );

        int idx = 1;
        int i;
        for ( i = 1; i <= len; i++ )
        {
            if ( !Border[i] )
            {
                idx = i;
                continue;
            }
            if ( Border[i] != Border[i-1] + 1 )
                idx++;
        }

        // printf( "idx: %d\n", idx );
        if ( Border[len] % idx != 0 )
            printf( "1\n" );
        else
            printf( "%d\n", (Border[len] / idx) + 1 );

        // for ( i = 0; i <= len; i++ )
        //     printf( "%d ", Border[i] );
        // puts( "" );
    }

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