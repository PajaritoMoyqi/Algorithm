#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN 1000000

long long Hash( char* Str, int startIdx, int length, long long mod );
long long ReHash( char* Str, int startIdx, int length, long long prevHash, long long coefficient, long long mod );
int KarpRabin( char* Text, int textLength, int startIdx, char* Pattern, int patternLength, long long MOD );
long long Mod( long long num, long long mod );

long long fpow( long long C, long long n, long long mod );
long long fpow2( long long C, long long n, long long mod );

int main( void )
{
    long long MOD = 1000000007;

    char str[MAX_LEN+1];
    char cmp[MAX_LEN+1];

    scanf( "%s", str );
    scanf( "%s", cmp ); 

    int strLen = strlen( str );
    int cmpLen = strlen( cmp );

    int ans = KarpRabin( str, strLen, 0, cmp, cmpLen, MOD );

    if ( ans == -1 )
        printf( "0" );
    else
        printf( "1" );

    return 0;
}

long long Mod( long long num, long long mod )
{
    if ( num >= 0 )
        return num % mod;
    return ((-num / mod + 1) * mod + num) % mod;
}
long long Hash( char* Str, int startIdx, int length, long long mod )
{
    int i;
    long long hashValue = 0;
    for ( i = startIdx; i < length; i++ )
    {
        hashValue = Mod( ((long long)Str[i] + ( hashValue * 2 )), mod );
        // printf( "hashValue: %lld\n", hashValue );
    }

    return hashValue;
}
long long ReHash( char* Str, int startIdx, int length, long long prevHash, long long coefficient, long long mod )
{
    if ( startIdx == 0 )
        return prevHash;

    // printf( "%d - prevHash: %lld\n", startIdx, prevHash );
    return Mod( ((long long)Str[startIdx + length - 1] + 2 * (prevHash - coefficient * (long long)Str[startIdx-1])), mod );
}
int KarpRabin( char* Text, int textLength, int startIdx, char* Pattern, int patternLength, long long mod )
{
    long long coefficient = fpow2( 2, patternLength-1, mod );
    long long textHash = Hash( Text, startIdx, patternLength, mod );
    long long patternHash = Hash( Pattern, startIdx, patternLength, mod );

    // printf( "coefficient: %lld\n", coefficient );
    // printf( "pH: %lld\n", patternHash );
    int i, j, idx = 0;
    for ( i = startIdx; i <= textLength - patternLength; i++ )
    {
        textHash = ReHash( Text, i, patternLength, textHash, coefficient, mod );
        // printf( "tHs: %lld\n", textHash );

        if ( patternHash == textHash )
        {
            // printf( "Hash collision: %d\n", i );
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

long long fpow( long long C, long long n, long long mod )
{
    if ( n == 1 )
        return C % mod;
    else
    {
        long long x = fpow( C, n/2, mod );
        if ( n & 1 )
            return x*x*C % mod;
        else
            return x*x % mod;
    }
}
long long fpow2( long long C, long long n, long long mod )
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