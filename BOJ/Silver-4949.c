#include <stdio.h>
#include <stdlib.h>

typedef char Element;

typedef struct _ASNode
{
    Element Data;
} ASNode;

typedef struct _ArrayStack
{
    int Capacity;
    int Top;
    ASNode* Nodes;
} ArrayStack;

void CreateAS( ArrayStack** Stack, int capacity );
void ASPush( ArrayStack* Stack, Element data );
Element ASPop( ArrayStack* Stack );
void DestroyAS( ArrayStack* Stack );

#define MAX_LEN 102

int main( void )
{
    while ( 1 )
    {
        char c;
        scanf( "%c", &c );
        // printf( "start char: %c\n", c );

        if ( c == '.' )
            break;

        ArrayStack* S;
        CreateAS( &S, MAX_LEN );
        int cnt = 0;
        while ( 1 )
        {
            if ( cnt )
                scanf( "%c", &c );
            cnt++;

            // printf( "in: %c\n", c );

            if ( c == '(' || c == ')' || c == '[' || c == ']' )
            {
                if ( !~(S->Top) )
                {
                    ASPush( S, c );
                    continue;
                }

                char popC = ASPop( S );

                if ( c == ')' && popC == '(' )
                    continue;
                if ( c == ']' && popC == '[' )
                    continue;

                ASPush( S, popC );
                ASPush( S, c );
            }

            if ( c == '.' )
            {
                if ( !~(S->Top) )
                    printf( "yes\n" );
                else
                    printf( "no\n" );

                break;
            }

        }
        getchar();
    }

    return 0;
}

void CreateAS( ArrayStack** Stack, int capacity )
{
    (*Stack) = (ArrayStack*)malloc( sizeof( ArrayStack ) );

    (*Stack)->Nodes = (ASNode*)malloc( sizeof( ASNode ) * capacity );

    (*Stack)->Capacity = capacity;
    (*Stack)->Top = -1;
}

void ASPush( ArrayStack* Stack, Element data )
{
    Stack->Top++;
    Stack->Nodes[Stack->Top].Data = data;
}
Element ASPop( ArrayStack* Stack )
{
    int idx = Stack->Top--;
    return Stack->Nodes[idx].Data;
}

void DestroyAS( ArrayStack* Stack )
{
    free( Stack->Nodes );
    free( Stack );
}