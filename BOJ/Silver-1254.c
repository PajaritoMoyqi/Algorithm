#include <stdio.h>
#include <string.h>

int palindrome( char* str, int idx, int idx2 );

int main( void )
{
    char str[50+1];
    scanf( "%s", str );
    int len = strlen( str );

    int i, idx, returnVal;
    for ( i = 0; i < len; i++ )
    {
        idx = i;
        // printf( "idx: %d, len: %d\n", idx, len );
        returnVal = palindrome( str, idx, len - 1 );
        // printf( "return: %d\n", returnVal );

        if ( returnVal )
            break;
    }

    printf( "%d", len + idx );

    return 0;
}

int palindrome( char* str, int idx, int idx2 )
{
    // printf( "idx: %d, idx2: %d, str[idx]: %c, str[idx2]: %c\n", idx, idx2, str[idx], str[idx2] );
    if ( (idx == idx2) || (idx2 + 1 == idx) ) return 1;
    // printf( "not matched\n" );

    if ( str[idx++] == str[idx2--] ) return palindrome( str, idx, idx2 );

    return 0;
}