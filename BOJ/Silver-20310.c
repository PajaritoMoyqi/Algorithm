#include <stdio.h>
#include <string.h>

char S[500];

int main( void )
{
    scanf( "%s", S );
    int length = strlen( S );

    int i, cnt0 = 0, cnt1 = 0;
    for ( i = 0; i < length; i++ )
    {
        if ( S[i] == '0' ) cnt0++;
        else cnt1++;
    }

    cnt0 /= 2;
    cnt1 /= 2;

    for ( i = 0; i < length; i++ )
    {
        if ( S[i] == '0' && cnt0-- > 0 ) printf( "%c", S[i] );
        else if ( S[i] == '1' && cnt1-- <= 0 ) printf( "%c", S[i] );
    }

    return 0;
}