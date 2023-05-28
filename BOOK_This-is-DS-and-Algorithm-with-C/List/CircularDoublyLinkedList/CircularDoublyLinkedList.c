#include "CircularDoublyLinkedList.h"

Node* CDLL_CreateNode( ElementType NewData )
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->NextNode = NULL;
    NewNode->PrevNode = NULL;

    return NewNode;
}

void CDLL_DestoryNode( Node* Node )
{
    free(Node);
}

void CDLL_AppendNode( Node** Head, Node* NewNode )
{
    if ( (*Head) == NULL )
    {
        (*Head) = NewNode;
        (*Head)->NextNode = NewNode;
        (*Head)->PrevNode = NewNode;
    }
    else
    {
        Node* Tail = (*Head)->PrevNode;

        (*Head)->PrevNode->NextNode = NewNode;
        (*Head)->PrevNode = NewNode;

        NewNode->NextNode = (*Head);
        NewNode->PrevNode = Tail;
    }
}

void CDLL_InsertAfter( Node* Current, Node* NewNode )
{
    NewNode->PrevNode = Current;
    NewNode->NextNode = Current->NextNode;

    Current->NextNode->PrevNode = NewNode;
    Current->NextNode = NewNode;
}

void CDLL_RemoveNode( Node** Head, Node* Remove )
{
    if ( (*Head) == Remove )
    {
        (*Head)->PrevNode->NextNode = Remove->NextNode;
        (*Head)->NextNode->PrevNode = Remove->PrevNode;

        (*Head) = Remove->NextNode;

        Remove->NextNode = NULL;
        Remove->PrevNode = NULL;
    }
    else
    {
        Remove->NextNode->PrevNode = Remove->PrevNode;
        Remove->PrevNode->NextNode = Remove->NextNode;

        Remove->NextNode = NULL;
        Remove->PrevNode = NULL;
    }
}

Node* CDLL_GetNodeAt( Node* Head, int Location )
{
    Node* Current = Head;

    while ( Current != NULL && (--Location) >= 0 )
        Current = Current->NextNode;
    
    return Current;
}

int CDLL_GetNodeCount( Node* Head )
{
    unsigned int Count = 0;
    Node* Current = Head;

    while ( Current != NULL )
    {
        Current = Current->NextNode;
        Count++;

        if ( Current == Head )
            break;
    }

    return Count;
}

void PrintNode( Node* _Node )
{
    if ( _Node->PrevNode == NULL )
        printf("Prev: NULL\n");
    else
    {
        printf("Prev: %d\n", _Node->PrevNode->Data);

        printf("Current: %d\n", _Node->Data);
    }

    if ( _Node->NextNode == NULL )
        printf("Next: NULL\n");
    else
        printf("Next: %d\n", _Node->NextNode->Data);    
}