#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _LLSNode
{
    char Data;
    struct _LLSNode* NextLLSNode;
    struct _LLSNode* PrevLLSNode;
} LLSNode;

typedef struct _LLStack
{
    LLSNode* List;
    LLSNode* Top;
} LLStack;

void CreateLLS( LLStack** Stack );
LLSNode* CreateLLSNode( char data );
void LLSPush( LLStack* Stack, LLSNode* New );
LLSNode* LLSPop( LLStack* Stack );
int LLSIsEmpty( LLStack* Stack );
void DestroyLLSNode( LLSNode* Target );
void DestroyLLS( LLStack* Stack );

#define MAX_STR_LEN 1000000
#define MAX_BOOM_LEN 36

char str[MAX_STR_LEN+1];
char boom[MAX_BOOM_LEN+1];

int main( void )
{
    scanf( "%s", str );
    int len = strlen( str );
    scanf( "%s", boom );
    int boomLen = strlen( boom );

    LLStack* S;
    CreateLLS( &S );

    int i;
    int cnt = 0;
    for ( i = 0; i < len; i++ )
    {
        char c = str[i];
        int flag = 0;
        int idx = boomLen-1;

        if ( c == boom[idx--] )
        {
            if ( i - cnt > idx )
            {
                char diffChar;
                while ( idx >= 0 )
                {
                    char cmpC = LLSPop( S )->Data;
                    if ( cmpC == boom[idx--] ) // idx = -1
                        continue;
                    else
                    {
                        flag = 1;
                        diffChar = cmpC;
                        break;
                    }
                }

                if ( flag )
                {
                    // printf( "diff: %c\n", diffChar );
                    LLSNode* NewNode = CreateLLSNode( diffChar );
                    LLSPush( S, NewNode );
                    idx++;

                    idx++;
                    while ( idx != boomLen )
                    {
                        LLSNode* NewNode = CreateLLSNode( boom[idx++] );
                        LLSPush( S, NewNode );
                    }
                }
                else
                {
                    cnt += boomLen;
                }
            }
            else
            {
                LLSNode* NewNode = CreateLLSNode( c );
                LLSPush( S, NewNode );
            }
        }
        else
        {
            LLSNode* NewNode = CreateLLSNode( c );
            LLSPush( S, NewNode );
        }
    }

    LLSNode* Node = S->List;
    if ( Node == NULL )
        printf( "FRULA" );
    while ( Node != NULL )
    {
        printf( "%c", Node->Data );
        Node = Node->NextLLSNode;
    }

    return 0;
}

void CreateLLS( LLStack** Stack )
{
    (*Stack) = (LLStack*)malloc( sizeof( LLStack ) );

    (*Stack)->List = NULL;
    (*Stack)->Top = NULL;
}
LLSNode* CreateLLSNode( char data )
{
    LLSNode* New = (LLSNode*)malloc( sizeof( LLSNode ) );
    
    New->Data = data;
    New->NextLLSNode = NULL;
    New->PrevLLSNode = NULL;

    return New;
}

void LLSPush( LLStack* Stack, LLSNode* New )
{
    if ( Stack->List == NULL )
        Stack->List = New;
    else
    {
        New->PrevLLSNode = Stack->Top;
        Stack->Top->NextLLSNode = New;
    }

    Stack->Top = New;
}
LLSNode* LLSPop( LLStack* Stack )
{
    LLSNode* TopLLSNode = Stack->Top;

    if ( Stack->List == Stack->Top )
    {
        Stack->List = NULL;
        Stack->Top = NULL;
    }
    else
    {
        LLSNode* Candidate = Stack->Top->PrevLLSNode;

        Stack->Top = Candidate;
        if ( Stack->Top != NULL )
            Stack->Top->NextLLSNode = NULL;
    }

    return TopLLSNode;
}

int LLSIsEmpty( LLStack* Stack )
{
    return (Stack->List == NULL);
}

void DestroyLLSNode( LLSNode* Target )
{
    free( Target );
}
void DestroyLLS( LLStack* Stack )
{
    while( LLSIsEmpty( Stack ) )
    {
        LLSNode* Popped = LLSPop( Stack );
        DestroyLLSNode( Popped );
    }

    free( Stack );
}