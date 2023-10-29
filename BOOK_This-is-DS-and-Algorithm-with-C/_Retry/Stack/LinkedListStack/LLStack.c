#include <LLStack.h>

void CreateLLS( LLStack** Stack )
{
    (*Stack) = (LLStack*)malloc( sizeof( LLStack ) );

    (*Stack)->List = NULL;
    (*Stack)->Top = NULL;
}
LLSNode* CreateLLSNode( char* data )
{
    LLSNode* New = (LLSNode*)malloc( sizeof( LLSNode ) );
    
    New->Data = (char*)malloc( sizeof( data ) + 1 );
    strcpy( New->Data, data );

    New->NextLLSNode = NULL;

    return New;
}

void LLSPush( LLStack* Stack, LLSNode* New )
{
    if ( Stack->List == NULL )
        Stack->List = New;
    else
        Stack->Top->NextLLSNode = New;

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
        LLSNode* Candidate = Stack->List;
        while ( Candidate != NULL && Candidate->NextLLSNode != Stack->Top )
            Candidate = Candidate->NextLLSNode;

        Stack->Top = Candidate;
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
    free( Target->Data );
    free( Target );
}
void DestroyLLS( LLStack* Stack )
{
    while( LLSIsEmpty( Stack ) )
    {
        LLSNode* Popped = PopLLS( Stack );
        DestroyLLSNode( Popped );
    }

    free( Stack );
}