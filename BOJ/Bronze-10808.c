#include <stdio.h>

int main( void )
{
    char str[101];
    scanf( "%s", str );
    char cnt[26] = { 0 };
    char* ptr = str;

    while ( *ptr )
        cnt[*ptr++ - 'a']++;


    int i;
    for ( i = 0; i < 26; i++ )
        printf( "%d ", cnt[i] );

    return 0;
}