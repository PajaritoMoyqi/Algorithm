#include "LinkedList.h"

LLNode* CreateLLNode( Element data )
{
    LLNode* Head = (LLNode*)malloc( sizeof( LLNode ) );

    Head->Data = data;
    Head->NextLLNode = NULL;

    return Head;
}

void AppendLLNode( LLNode** Head, LLNode* New )
{
    if ( (*Head) == NULL )
        *Head = New;
    else
    {
        LLNode* Tail = (*Head);
        while ( Tail->NextLLNode == NULL )
            Tail = Tail->NextLLNode;

        Tail->NextLLNode = New;
    }
}

void InsertLLNode( LLNode* Target, LLNode* New )
{
    New->NextLLNode = Target->NextLLNode;
    Target->NextLLNode = New;
}
void InsertLLHead( LLNode** Head, LLNode* New )
{
    if ( (*Head) == NULL )
        *Head = New;
    else
    {
        New->NextLLNode = (*Head);
        *Head = New;
    }
}

void RemoveLLNode( LLNode** Head, LLNode* Target )
{
    if ( (*Head) == Target )
        *Head = Target->NextLLNode;
    else
    {
        LLNode* Candidate = (*Head);
        while( Candidate != NULL && Candidate->NextLLNode != Target )
            Candidate = Candidate->NextLLNode;

        if( Candidate != NULL )
            Candidate->NextLLNode = Target->NextLLNode;
    }
}

LLNode* SearchLL( LLNode* Head, int idx )
{
    LLNode* Candidate = Head;
    while( Candidate != NULL && (--idx) >= 0 )
        Candidate = Candidate->NextLLNode;

    return Candidate;
}
int LengthLL( LLNode* Head )
{
    int cnt = 0;

    LLNode* Current = Head;
    while ( Current != NULL )
    {
        Current = Current->NextLLNode;
        cnt++;
    }

    return cnt;
}

void DestroyLLNode( LLNode* Node )
{
    free( Node );
}