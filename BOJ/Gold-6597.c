#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ElemType;

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

#define MAX_LEN 26

char PreInput[MAX_LEN+1];
char InInput[MAX_LEN+1];
int idx = 0;

BTNode* makeTree( BTNode* Tree, int start, int end );

int main( void )
{
    while ( scanf( "%s %s", PreInput, InInput ) != EOF )
    {
        idx = 0;

        BTNode* Tree = NULL;

        int len = strlen( PreInput );

        Tree = makeTree( Tree, 0, len-1 );

        PostorderPrintBT( Tree );
        puts( "" );
    }

    return 0;
}

BTNode* makeTree( BTNode* Tree, int start, int end )
{
    // printf( "start: %d, end: %d\n", start, end );
    int mid = PreInput[idx++];
    Tree = CreateNode( mid );

    int pos = 0;
    while ( mid != InInput[pos] )
        pos++;

    // printf( "pos: %d\n", pos );

    if ( start <= pos-1 )
        Tree->Left = makeTree( Tree->Left, start, pos-1 );
    if ( pos+1 <= end )
        Tree->Right = makeTree( Tree->Right, pos+1, end );

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

    printf( "%c", N->Data );
    PreorderPrintBT( N->Left );
    PreorderPrintBT( N->Right );
}
void InorderPrintBT( BTNode* N )
{
    if ( N == NULL )
        return;

    InorderPrintBT( N->Left );
    printf( "%c", N->Data );
    InorderPrintBT( N->Right );
}
void PostorderPrintBT( BTNode* N )
{
    if ( N == NULL )
        return;

    PostorderPrintBT( N->Left );
    PostorderPrintBT( N->Right );
    printf( "%c", N->Data );
}