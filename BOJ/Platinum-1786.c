#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000000

long long Hash( char* Str, int startIdx, int length, int base, long long mod );
long long ReHash( char* Str, int startIdx, int length, long long prevHash, long long coefficient, int base, long long mod );
int KarpRabin( char* Text, int textLength, int startIdx, char* Pattern, int patternLength, int base, long long mod );
long long Mod( long long num, long long mod );

long long fpow( long long C, long long n, long long mod );

int Ans[MAX_LEN+1];

int main( void )
{
    long long MOD = 2147483647LL;

    char str[MAX_LEN+1];
    char cmp[MAX_LEN+1];

    fgets( str, MAX_LEN+2, stdin );
    fgets( cmp, MAX_LEN+2, stdin );

    // printf( "Q: %s, C: %s\n", str, cmp );

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

    // printf( "QLen: %d, CLen: %d\n", strLen, cmpLen );

    int cnt = KarpRabin( str, strLen, 0, cmp, cmpLen, 7, MOD );

    printf( "%d\n", cnt );
    int i;
    for ( i = 0; i < cnt; i++ )
        printf( "%d ", Ans[i]+1 );

    return 0;
}

long long Mod( long long num, long long mod )
{
    if ( num >= 0 )
        return num % mod;
    return ((-num / mod + 1) * mod + num) % mod;
}
long long Hash( char* Str, int startIdx, int length, int base, long long mod )
{
    int i;
    long long hashValue = 0;
    for ( i = startIdx; i < length; i++ )
    {
        hashValue = Mod( ((long long)Str[i] + ( hashValue * base )), mod );
        // printf( "hashValue: %lld\n", hashValue );
    }

    return hashValue;
}
long long ReHash( char* Str, int startIdx, int length, long long prevHash, long long coefficient, int base, long long mod )
{
    if ( startIdx == 0 )
        return prevHash;

    // printf( "%d - prevHash: %lld\n", startIdx, prevHash );
    return Mod( ((long long)Str[startIdx + length - 1] + base * (prevHash - coefficient * (long long)Str[startIdx-1])), mod );
}
int KarpRabin( char* Text, int textLength, int startIdx, char* Pattern, int patternLength, int base, long long mod )
{
    long long coefficient = fpow( base, patternLength-1, mod );
    long long textHash = Hash( Text, startIdx, patternLength, base, mod );
    long long patternHash = Hash( Pattern, startIdx, patternLength, base, mod );

    // printf( "coefficient: %lld\n", coefficient );
    // printf( "pH: %lld\n", patternHash );
    int i, j, idx = 0;
    for ( i = startIdx; i <= textLength - patternLength; i++ )
    {
        textHash = ReHash( Text, i, patternLength, textHash, coefficient, base, mod );
        // printf( "tHs: %lld\n", textHash );

        if ( patternHash == textHash )
        {
            // printf( "Hash collision: %d\n", i );
            // for ( j = 0; j < patternLength; j++ )
            // {
            //     if ( Text[i+j] != Pattern[j] )
            //         break;
            // }

            // if ( j >= patternLength )
                Ans[idx++] = i;
        }
    }

    return idx;
}

long long fpow( long long C, long long n, long long mod )
{
    long long res = 1;
    while ( n > 0 )
    {
        if ( n & 1 )
            res = (C * res) % mod;

        C = (C * C) % mod;
        n = n >> 1;
    }
    return res;
}