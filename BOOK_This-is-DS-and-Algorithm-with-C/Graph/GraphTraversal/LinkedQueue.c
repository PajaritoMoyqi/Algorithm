#include "LinkedQueue.h"

void LQ_CreateQueue( LinkedQueue** Queue )
{
    (*Queue) = (LinkedQueue*)malloc( sizeof( LinkedQueue ) );

    (*Queue)->Count = 0;
    (*Queue)->Front = NULL;
    (*Queue)->Rear = NULL;
}

void LQ_DestroyQueue( LinkedQueue* Queue )
{
    while ( ! LQ_IsEmpty( Queue ) )
    {
        Node* Popped = LQ_Dequeue( Queue );
        LQ_DestroyNode( Popped );
    }

    free( Queue );
}

Node* LQ_CreateNode( Vertex* V )
{
    Node* NewNode = (Node*)malloc( sizeof( Node ) );
    NewNode->Data = V;

    NewNode->NextNode = NULL;

    return NewNode;
}

void LQ_DestroyNode( Node* _Node )
{
    free( _Node->Data );
    free( _Node );
}

void LQ_Enqueue( LinkedQueue* Queue, Node* NewNode )
{
    if ( Queue->Front == NULL )
    {
        Queue->Front = NewNode;
        Queue->Rear = NewNode;
    }
    else
    {
        Queue->Rear->NextNode = NewNode;
        Queue->Rear = NewNode;
    }
    
    Queue->Count++;
}

Node* LQ_Dequeue( LinkedQueue* Queue )
{
    Node* Front = Queue->Front;

    if ( Queue->Front->NextNode == NULL )
    {
        Queue->Front = NULL;
        Queue->Rear = NULL;
    }
    else
        Queue->Front = Queue->Front->NextNode;

    Queue->Count--;

    return Front;
}

int LQ_IsEmpty( LinkedQueue* Queue )
{
    return ( Queue->Front == NULL );
}