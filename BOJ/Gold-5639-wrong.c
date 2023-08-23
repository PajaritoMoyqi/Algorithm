#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
    struct tagNode* Left;
    struct tagNode* Right;
    struct tagNode* Parent;

    int Data;
} Node;

Node* createNode( int Data );
void postorderPrint( Node* N );

int main( void )
{
    int x;
    scanf( "%d", &x );
    Node* Tree = createNode( x );
    Node* Curr = Tree;

    int input;
    while ( (input = scanf( "%d", &x ) != EOF) && input == 1 )
    {
        // printf( "%d: while\n", x );
        // printf( "after\n" );
        // printf( "%d\n", input );

        Node* N = createNode( x );
        if ( Curr->Data > x )
        {
            // printf( "Left\n" );
            Curr->Left = N;
            Curr->Left->Parent = Curr;
            Curr = N;
        }
        else
        {
            // printf( "Right\n" );
            while ( Curr->Parent )
            {
                // printf( "Right While\n" );
                // printf( "%d %d\n", Curr->Data, Curr->Parent->Data );
                if ( (Curr->Data < x) && (Curr->Parent->Data > x) ) break;
                Curr = Curr->Parent;
            }

            // printf( "hey\n" );
            Curr->Right = N;
            Curr->Right->Parent = Curr;
            Curr = N;
        }

        // printf( "done\n" );
    }
    // printf( "hey\n" );

    postorderPrint( Tree );

    free( Tree );

    return 0;
}

Node* createNode( int Data )
{
    Node* NewNode = (Node*)malloc( sizeof( Node ) );

    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Parent = NULL;
    NewNode->Data = Data;

    return NewNode;
}

void postorderPrint( Node* N )
{
    if ( !N ) return;

    postorderPrint( N->Left );
    postorderPrint( N->Right );
    printf( "%d\n", N->Data );
}