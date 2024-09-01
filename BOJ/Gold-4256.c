#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct _BTNode
{
    struct _BTNode* Left;
    struct _BTNode* Right;

    ElemType Data;
} BTNode;

BTNode* CreateNode( ElemType data );
BTNode* CreateTree( BTNode* N, ElemType d );
void DestroyTree( BTNode* N );
void PreorderPrintBT( BTNode* N );
void InorderPrintBT( BTNode* N );
void PostorderPrintBT( BTNode* N );

#define MAX_NUM 1000

int PreInput[MAX_NUM];
int InInput[MAX_NUM];
int idx = 0;

void makeTree( int start, int end );

int main( void )
{
    int t;
    scanf( "%d", &t );

    while ( t-- )
    {
        idx = 0;

        BTNode* Tree = NULL;

        int n;
        scanf( "%d", &n );

        int i;
        for ( i = 0; i < n; i++ )
            scanf( "%d", &PreInput[i] );
        for ( i = 0; i < n; i++ )
            scanf( "%d", &InInput[i] );

        makeTree( 0, n-1 );

        // PostorderPrintBT( Tree );
        puts( "" );
    }

    return 0;
}

void makeTree( int start, int end )
{
    // printf( "start: %d, end: %d\n", start, end );
    int mid = PreInput[idx++];
    // Tree = CreateTree( Tree, mid );

    int pos = 0;
    while ( mid != InInput[pos] )
        pos++;

    // printf( "pos: %d\n", pos );

    if ( start <= pos-1 )
        makeTree( start, pos-1 );
    if ( pos+1 <= end )
        makeTree( pos+1, end );

    printf( "%d ", mid );
}

BTNode* CreateNode( ElemType data )
{
    BTNode* NewNode = (BTNode*)malloc( sizeof( BTNode ) );

    NewNode->Data = data;
    NewNode->Left = NULL;
    NewNode->Right = NULL;

    return NewNode;
}
BTNode* CreateTree( BTNode* N, ElemType d )
{
    N = (BTNode*)malloc( sizeof( BTNode ) );

    N->Data = d;
    N->Left = NULL;
    N->Right = NULL;
}

void DestroyTree( BTNode* N )
{
    if ( N == NULL ) return;

    DestroyTree( N->Left );
    DestroyTree( N->Right );

    free( N );
}

void PreorderPrintBT( BTNode* N )
{
    if ( N == NULL )
        return;

    printf( "%d ", N->Data );
    PreorderPrintBT( N->Left );
    PreorderPrintBT( N->Right );
}
void InorderPrintBT( BTNode* N )
{
    if ( N == NULL )
        return;

    InorderPrintBT( N->Left );
    printf( "%d ", N->Data );
    InorderPrintBT( N->Right );
}
void PostorderPrintBT( BTNode* N )
{
    if ( N == NULL )
        return;

    PostorderPrintBT( N->Left );
    PostorderPrintBT( N->Right );
    printf( "%d ", N->Data );
}