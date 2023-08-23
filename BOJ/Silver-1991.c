#include <stdio.h>
#include <stdlib.h>

int t;

typedef struct tagNode
{
    struct tagNode* Left;
    struct tagNode* Right;

    char Data;
} Node;

Node* createNode( char Data );
Node* exists( Node* N, char Data );
void preorderPrint( Node* N );
void inorderPrint( Node* N );
void postorderPrint( Node* N );

int main( void )
{
    scanf( "%d", &t );

    Node* Tree = createNode( NULL );
    Node* Tmp;
    int i;
    for ( i = 0; i < t; i++ )
    {
        char a, b, c;
        scanf( " %c %c %c", &a, &b, &c ); // space is important

        // printf( "now: %c %c %c\n", a, b, c );
        Tmp = exists( Tree, a );
        if ( Tmp )
        {
            // printf( "data: %c\n", Tmp->Data );
            insertNode( Tmp, a, b, c );
        }
        else insertNode( Tree, a, b, c );
    }

    preorderPrint( Tree );
    puts( "" );
    inorderPrint( Tree );
    puts( "" );
    postorderPrint( Tree );

    free( Tree );

    return 0;
}

Node* createNode( char Data )
{
    Node* NewNode = (Node*)malloc( sizeof( Node ) );

    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = Data;

    return NewNode;
}

Node* exists( Node* N, char Data )
{
    if ( N )
    {
        if ( N->Data == Data )
            return N;
        else
        {
            Node* Tmp = exists( N->Left, Data );
            if ( Tmp )
            {
                // printf( "exists: %c\n", Tmp->Data );
                return Tmp;
            }
            else
                return exists( N->Right, Data );
        }
    }
    else
        return NULL;
}

void insertNode( Node* N, char a, char b, char c )
{
    N->Data = a;
    if ( b != '.' ) N->Left = createNode( b );
    if ( c != '.' ) N->Right = createNode( c );
}

void preorderPrint( Node* N )
{
    if ( !N ) return;

    printf( "%c", N->Data );
    preorderPrint( N->Left );
    preorderPrint( N->Right );
}
void inorderPrint( Node* N )
{
    if ( !N ) return;

    inorderPrint( N->Left );
    printf( "%c", N->Data );
    inorderPrint( N->Right );
}
void postorderPrint( Node* N )
{
    if ( !N ) return;

    postorderPrint( N->Left );
    postorderPrint( N->Right );
    printf( "%c", N->Data );
}