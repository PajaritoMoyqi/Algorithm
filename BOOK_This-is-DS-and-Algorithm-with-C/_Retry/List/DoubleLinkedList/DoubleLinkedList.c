#include "DoubleLinkedList.h"

DLLNode* CreateDLLNode( Element data )
{
    DLLNode* Head = (DLLNode*)malloc( sizeof( DLLNode ) );

    Head->Data = data;
    Head->PrevDLLNode = NULL;
    Head->NextDLLNode = NULL;

    return Head;
}

void AppendDLLNode( DLLNode** Head, DLLNode* New )
{
    if ( (*Head) == NULL )
        *Head = New;
    else
    {
        DLLNode* Tail = (*Head);
        while ( Tail->NextDLLNode == NULL )
            Tail = Tail->NextDLLNode;

        Tail->NextDLLNode = New;
    }
}

void InsertDLLNode( DLLNode* Target, DLLNode* New )
{
    New->NextDLLNode = Target->NextDLLNode;
    New->PrevDLLNode = Target;

    if ( Target->NextDLLNode != NULL )
    {
        Target->NextDLLNode->PrevDLLNode = New;
        Target->NextDLLNode = New;
    }
}
void InsertDLLHead( DLLNode** Head, DLLNode* New )
{
    if ( (*Head) == NULL )
        *Head = New;
    else
    {
        New->NextDLLNode = (*Head);
        *Head = New;
    }
}

void RemoveDLLNode( DLLNode** Head, DLLNode* Target )
{
    if ( (*Head) == Target )
    {
        *Head = Target->NextDLLNode;
        if ( (*Head) != NULL )
            (*Head)->PrevDLLNode = NULL;
    }
    else
    {
        DLLNode* Tmp = Target;
        if ( Target->PrevDLLNode != NULL )
            Target->PrevDLLNode->NextDLLNode = Target->NextDLLNode;

        if ( Target->NextDLLNode != NULL )
            Target->NextDLLNode->PrevDLLNode = Target->PrevDLLNode;
    }

    Target->PrevDLLNode = NULL;
    Target->NextDLLNode = NULL;
}

DLLNode* SearchDLL( DLLNode* Head, int idx )
{
    DLLNode* Candidate = Head;
    while( Candidate != NULL && (--idx) >= 0 )
        Candidate = Candidate->NextDLLNode;

    return Candidate;
}
int LengthDLL( DLLNode* Head )
{
    int cnt = 0;

    DLLNode* Current = Head;
    while ( Current != NULL )
    {
        Current = Current->NextDLLNode;
        cnt++;
    }

    return cnt;
}

void DestroyDLLNode( DLLNode* Node )
{
    free( Node );
}