#include <stdio.h>
#include <string.h>

int JavaStrHashcode( char* str );

int main( void )
{
    int n;
    scanf( "%d", &n );

    n -= 2;

    printf( "Aa" );

    int i;
    for ( i = 0; i < n; i++ )
        printf( "a" );
    puts( "" );

    printf( "BB" );

    for ( i = 0; i < n; i++ )
        printf( "a" );
    puts( "" );

    // char* str1 = "Aa";
    // char* str2 = "BB";
    // printf( "%d\n", JavaStrHashcode( str1 ) );
    // printf( "%d\n", JavaStrHashcode( str2 ) );

    return 0;
}

int JavaStrHashcode( char* str )
{
    int len = strlen( str );
    int i;
    int num = 0;
    for ( i = 0; i < len; i++ )
    {
        int c = str[i];
        num *= 31;
        num += c;
    }

    return num;
}