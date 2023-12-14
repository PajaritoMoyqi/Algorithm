#include <stdio.h>
#include <stdlib.h> // qsort

int cmp( const void* _elem1, const void* _elem2 );

int main( void )
{
    int n, i;
    scanf( "%d", &n );

    int TimeSet[n];

    for ( i = 0; i < n; i++ )
        scanf( "%d", &TimeSet[i] );

    qsort( TimeSet, n, sizeof( int ), cmp );

    int sum = 0;
    for ( i = 0; i < n; i++ )
        sum += ((n - i) * TimeSet[i]);

    printf( "%d", sum );

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