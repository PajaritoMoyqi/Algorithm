#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
    int Data;
    struct tagNode* Left;
    struct tagNode* Right;
} Node;

void postorderPrint( Node* R );
Node* createTree( Node* R, int d );

int main( void )
{
    Node* tree = NULL;

    int d;
    while ( scanf( "%d", &d ) != EOF )
        tree = createTree( tree, d );

    postorderPrint( tree );
}

void postorderPrint( Node* R )
{
    if ( R == NULL ) return;

    postorderPrint( R->Left );
    postorderPrint( R->Right );

    printf( "%d\n", R->Data );
}
Node* createTree( Node* N, int d )
{
    if ( N == NULL )
    {
        N = (Node*)malloc( sizeof( Node ) );
        N->Data = d;
        N->Left = NULL;
        N->Right = NULL;

        return N;
    }
    else if ( d < N->Data )
        N->Left = createTree( N->Left, d );
    else if ( d > N->Data )
        N->Right = createTree( N->Right, d );

    return N;
}