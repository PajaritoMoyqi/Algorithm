#include <stdio.h>
#include <stdlib.h> // qsort

int cmp( const void* _elem1, const void* _elem2 );

int main( void )
{
    int n, m, num, i;
    scanf( "%d%d", &n, &m );
    
    int NumberSet[n];
    for ( i = 0; i < n; i++ )
        scanf( "%d", &NumberSet[i] );

    qsort( NumberSet, n, sizeof( int ), cmp );

    int* find;
    while ( m-- )
    {
        scanf( "%d", &num );
        if ( (find = bsearch( &num, NumberSet, n, sizeof( int ), cmp )) != NULL )
        {
            printf( "%d\n", BSearch( NumberSet, n, num ) );
        }
        else
            printf( "-1\n" );
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
int BSearch( int Set[], int len, int target )
{
    int leftIdx = 0, rightIdx = len, middle;

    leftIdx = 0, rightIdx = len;
    while ( rightIdx > leftIdx )
    {
        middle = (leftIdx + rightIdx) / 2;
        Set[middle] >= target ? rightIdx = middle : (leftIdx = middle + 1);
    }
    return rightIdx;
}