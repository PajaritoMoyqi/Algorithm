#include "BTree.h"

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
    if ( N == NULL ) return;

    printf( " %c", N->Data );
    PreorderPrintBT( N->Left );
    PreorderPrintBT( N->Right );
}

void InorderPrintBT( BTNode* N )
{
    if ( N == NULL ) return;

    InorderPrintBT( N->Left );
    printf( " %c", N->Data );
    InorderPrintBT( N->Right );
}

void PostorderPrintBT( BTNode* N )
{
    if ( N == NULL ) return;

    PostorderPrintBT( N->Left );
    PostorderPrintBT( N->Right );
    printf( " %c", N->Data );
}