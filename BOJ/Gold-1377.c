#include <stdlib.h>
#include <stdio.h>
#define max(a, b) a > b ? a : b

typedef struct tagNode
{
    int Data;
    int Index;
} Node;

int cmp( const Node* _elem1, const Node* _elem2 );

int main( void )
{
    int N = 0, i = 0, changed = 0;

    scanf( "%d", &N );

    Node A[N];

    // printf( "Before sort\n" );
    for ( i = 0; i < N ; i++ ) {
        scanf( "%d", &A[i].Data );
        A[i].Index = i;

        // printf( "A[%d] - value: %d, index: %d\n", i, A[i].Data, A[i].Index );
    }

    qsort( A, N, sizeof( Node ), cmp );

    // printf( "After sort\n" );
    // for ( i = 0; i < N ; i++ ) {
    //     printf( "A[%d] - value: %d, index: %d\n", i, A[i].Data, A[i].Index );
    // }

    for ( i = 0; i < N; i++ )
    {
        int displacement = A[i].Index - i;

        if ( displacement > 0 )
            changed = max( changed, displacement );
    }

    printf( "%d", changed + 1 );

    return 0;
}

int cmp( const Node* _elem1, const Node* _elem2 )
{
    int elem1 = _elem1->Data;
    int elem2 = _elem2->Data;

    if ( elem1 > elem2 )
        return 1;
    else if ( elem1 < elem2 )
        return -1;
    else
        return 0;
}