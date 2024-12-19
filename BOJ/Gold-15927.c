#include <stdio.h>
#include <string.h>

#define MAX 500000

char STR[MAX+1];

int main( void )
{
    scanf( "%s", STR );
    int len = strlen( STR );

    int palFlag = 1;
    int impFlag = 1;
    char firstSTR = STR[0];
    int i;
    for ( i = 0; i < len/2 + (len&1); i++ )
    {
        if ( STR[i] != STR[len-1-i] )
            palFlag = 0;

        if ( firstSTR != STR[i] || firstSTR != STR[len-1-i] )
            impFlag = 0;

        if ( !impFlag && !palFlag )
            break;
    }

    if ( len == 1 || impFlag )
        printf( "-1" );
    else
    {
        if ( palFlag )
            printf( "%d", len - 1 );
        else
            printf( "%d", len );
    }

    return 0;
}