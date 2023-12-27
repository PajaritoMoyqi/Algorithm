#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char Str[100001];

int cmp( const void* _elem1, const void* _elem2 )
{
    char* elem1 = (char*)_elem1;
    char* elem2 = (char*)_elem2;

    if ( *elem1 < *elem2 )
        return 1;
    else if ( *elem1 > *elem2 )
        return -1;
    else
        return 0;
}

int main( void )
{
    int sum = 0;
    scanf( "%s", Str );
    if ( strchr( Str, '0' ) == NULL || Str[0] == '0' )
    {
        printf( "-1" );
        return 0;
    }

    int len = 0;
    while ( Str[len] != NULL )
        sum += (Str[len++] - 48);

    if ( sum % 3 != 0 || !sum )
    {
        printf( "-1" );
        return 0;
    }
    else
        qsort( Str, sizeof( Str ) - 1, sizeof( char ), cmp );

    printf( "%s", Str );

    return 0;
}