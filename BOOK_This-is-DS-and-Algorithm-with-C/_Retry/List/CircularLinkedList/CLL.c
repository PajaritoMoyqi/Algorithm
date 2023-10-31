#include "CLL.h"

CLLNode* CreateCLLNode( Element data )
{
    CLLNode* Head = (CLLNode*)malloc( sizeof( CLLNode ) );

    Head->Data = data;
    Head->PrevCLLNode = NULL;
    Head->NextCLLNode = NULL;

    return Head;
}

void AppendCLLNode( CLLNode** Head, CLLNode* New )
{
    if ( (*Head) == NULL )
    {
        *Head = New;
        (*Head)->PrevCLLNode = *Head;
        (*Head)->NextCLLNode = *Head;
    }
    else
    {
        CLLNode* Tail = (*Head)->PrevCLLNode;

        Tail->NextCLLNode->PrevCLLNode = New;
        Tail->NextCLLNode = New;

        New->NextCLLNode = (*Head);
        New->PrevCLLNode = Tail;
    }
}

void InsertCLLNode( CLLNode* Target, CLLNode* New )
{
    New->NextCLLNode = Target->NextCLLNode;
    New->PrevCLLNode = Target;

    if ( Target->NextCLLNode != NULL )
    {
        Target->NextCLLNode->PrevCLLNode = New;
        Target->NextCLLNode = New;
    }
}

void RemoveCLLNode( CLLNode** Head, CLLNode* Target )
{
    if ( (*Head) == Target )
    {
        (*Head)->PrevCLLNode->NextCLLNode = Target->NextCLLNode;
        (*Head)->NextCLLNode->PrevCLLNode = Target->PrevCLLNode;

        *Head = Target->NextCLLNode;
    }
    else
    {
        Target->PrevCLLNode->NextCLLNode = Target->NextCLLNode;
        Target->NextCLLNode->PrevCLLNode = Target->PrevCLLNode;
    }

    Target->PrevCLLNode = NULL;
    Target->NextCLLNode = NULL;
}

CLLNode* SearchCLL( CLLNode* Head, int idx )
{
    CLLNode* Candidate = Head;
    while( Candidate != NULL && (--idx) >= 0 )
        Candidate = Candidate->NextCLLNode;

    return Candidate;
}
int LengthCLL( CLLNode* Head )
{
    int cnt = 0;

    CLLNode* Current = Head;
    while ( Current != NULL )
    {
        Current = Current->NextCLLNode;
        cnt++;
    }

    return cnt;
}

void DestroyCLLNode( CLLNode* Node )
{
    free( Node );
}