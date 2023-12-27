#include <stdio.h>
#include <stdlib.h>

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

char Res[100001];

int main( void )
{
    char c;
    int sum = 0, flag = 0, len = 0, first = 0;
    while ( scanf( "%c", &c ) != EOF )
    {
        int tmp = c - '0';
        if ( !first && !tmp ) break;
        else if ( !first && tmp ) first++;

        // printf( "tmp: %d\n", tmp );
        if ( !flag && !tmp ) flag = 1;
        sum += tmp;
        Res[len++] = c;
    }

    // printf( "sum: %d, flag: %d\n", sum, flag );

    if ( sum % 3 == 0 && flag )
    { 
        qsort( Res, len, sizeof( char ), cmp );

        int i;
        printf( "%s", Res );
        // for ( i = 0; i < len; i++ )
        //     printf( "%c", Res[i] );
    }
    else printf( "-1" );

    return 0;
}