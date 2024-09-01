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
void DestroyTree( BTNode* N );
void PreorderPrintBT( BTNode* N );
void InorderPrintBT( BTNode* N );
void PostorderPrintBT( BTNode* N );

#define MAX_NUM 100000

int InInput[MAX_NUM];
int PostInput[MAX_NUM];
int idx;

BTNode* makeTree( BTNode* Tree, int start, int end );

int main( void )
{
    BTNode* Tree = NULL;

    int n;
    scanf( "%d", &n );

    idx = n-1;

    int i;
    for ( i = 0; i < n; i++ )
        scanf( "%d", &InInput[i] );
    for ( i = 0; i < n; i++ )
        scanf( "%d", &PostInput[i] );

    Tree = makeTree( Tree, 0, n-1 );

    PreorderPrintBT( Tree );
    puts( "" );

    return 0;
}

BTNode* makeTree( BTNode* Tree, int start, int end )
{
    // printf( "start: %d, end: %d\n", start, end );
    int mid = PostInput[idx--];
    Tree = CreateNode( mid );

    int pos = 0;
    while ( mid != InInput[pos] )
        pos++;

    // printf( "pos: %d\n", pos );

    if ( pos+1 <= end )
        Tree->Right = makeTree( Tree->Right, pos+1, end );
    if ( start <= pos-1 )
        Tree->Left = makeTree( Tree->Left, start, pos-1 );

    return Tree;
}
BTNode* CreateNode( ElemType data )
{
    BTNode* NewNode = (BTNode*)malloc( sizeof( BTNode ) );

    NewNode->Data = data;
    NewNode->Left = NULL;
    NewNode->Right = NULL;

    return NewNode;
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