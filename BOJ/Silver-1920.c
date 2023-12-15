#include <stdio.h>
#include <stdlib.h> // qsort

int cmp( const void* _elem1, const void* _elem2 );

int main( void )
{
    int n, m, num, i;
    scanf( "%d", &n );
    
    int NumberSet[n];
    for ( i = 0; i < n; i++ )
        scanf( "%d", &NumberSet[i] );

    qsort( NumberSet, n, sizeof( int ), cmp );

    int* find;
    scanf( "%d", &m );
    while ( m-- )
    {
        scanf( "%d", &num );
        if ( (find = bsearch( &num, NumberSet, n, sizeof( int ), cmp )) != NULL )
            printf( "1\n" );
        else
            printf( "0\n" );
    }

    return 0;
}

int cmp( const void* _elem1, const void* _elem2 )
{
    int* elem1 = (int*)_elem1;
    int* elem2 = (int*)_elem2;

    if ( *elem1 > *elem2 )
        return 1;
    else if ( *elem1 < *elem2 )
        return -1;
    else
        return 0;
}