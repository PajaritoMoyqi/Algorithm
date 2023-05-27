#include "LinkedList.h"

// SLL means "Singly Linked List"

Node* SLL_CreateNode_WrongWay(ElementType NewData)
{
    Node NewNode; // Make new node in Stack
    // initialization
    NewNode.Data = NewData;
    NewNode.NextNode = NULL;

    return &NewNode; // Returns memory address
    
    // code ends -> created memory removed automatically
}

Node* SLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node)); // Make new node in Heap
    // Actually NewNode, which is pointer, stays in Stack, and real node, which is struct, exists in Heap.

    NewNode->Data = NewData;
    NewNode->NextNode = NULL;

    // print variables if needed
    // printf("New Node Address in Heap: %p\n", NewNode);

    return NewNode;
}

void SLL_DestroyNode(Node* Node)
{
    free(Node); // Remove space for Node from Heap
}

void SLL_AppendNode(Node** Head, Node* NewNode) // Double Asterisk means double pointer
// If we don't use double aserisk, then it'll cause a possible problem when Head node is NULL.
// If Head is just a pointer of original node, not pointer of original node pointer,
// then it only transmit the address value that head nointer contains.
// It doesn't give us the address of pointer variable, which is 'Head' in this function.
// So, at first, 'Head' parameter has only the address that also actual argument has.
// in the context in 'if' statement, 'Head' parameter now has the address of NewNode,
// however the actual argument, which is gonna exist more than 'Head' parameter, can't have that address,
// because there is no relation between 'Head' paramter and actual argument.
// That's the reason why we should use double pointer which points its actual argument's address.
{
    // The address of List in Heap comes through 'Head'
    // The address of NewNode in Heap comes through 'NewNode'

    // If head node is null, new node becomes head.
    if ( (*Head) == NULL )
    {
        *Head = NewNode; // original node = New node address

        // print variables if needed
        // printf("==FIRST==\n");
        // printf("*_NewNode: %p\n_NewNode: %p\n", *NewNode, NewNode);
        // printf("**_Head: %p\n*_Head: %p\n_Head: %p\n", **Head, *Head, Head);
    }
    else
    {
        // Tail is head node pointer
        Node* Tail = (*Head);

        // print variables if needed
        // printf("==NOT FIRST==\n");
        // printf("*_NewNode: %p\n_NewNode: %p\n", *NewNode, NewNode);
        // printf("**_Head: %p\n*_Head: %p\n_Head: %p\n", **Head, *Head, Head);

        // If Tail has NextNode(not NULL), then let's start journey to find 'real' tail
        while ( Tail->NextNode != NULL )
        {
            // print variables if needed
            // printf("Next Node: %p\n", Tail->NextNode);
            
            Tail = Tail->NextNode;
        }
        
        Tail->NextNode = NewNode; // Now Tail points real tail node and its NextNode is NewNode
        
        // print variables if needed
        // printf("Last Node: %p\n", Tail->NextNode);
    }
}

Node* SLL_GetNodeAt(Node* Head, int Location) // Location should be given as index, not n-th number
{
    Node* Current = Head;

    while ( Current != NULL && (--Location) >= 0 )
        Current = Current->NextNode;
    
    return Current;
}

void SLL_RemoveNode(Node** Head, Node* Remove)
{
    if ( *Head == Remove )
        *Head = Remove->NextNode;
    else
    {
        Node* Current = *Head;
        
        while ( Current != NULL && Current->NextNode != Remove )
            Current = Current->NextNode;

        if ( Current != NULL )
            Current->NextNode = Remove->NextNode;
    }
}

void SLL_InsertAfter(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

void SLL_InsertBefore(Node** Head, Node* Current, Node* NewNode)
{
    Node* PreviousNode = (*Head);

    while ( PreviousNode != NULL )
        if ( PreviousNode->NextNode == Current )
            PreviousNode->NextNode = NewNode;
        else
            PreviousNode = PreviousNode->NextNode;

    NewNode->NextNode = Current;
}

void SLL_InsertNewHead(Node** Head, Node* NewHead)
{
    if ( Head == NULL )
        (*Head) = NewHead;
    else
    {
        NewHead->NextNode = (*Head);
        (*Head) = NewHead;
    }
}

int SLL_GetNodeCount(Node* Head)
{
    int Count = 0;
    Node* Current = Head;

    while ( Current != NULL )
    {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}

void SLL_DestroyAllNodes(Node** Head)
{
    Node* Current = *Head;
    Node* Previous = NULL;

    while ( Current != NULL )
    {
        Previous = Current;
        Current = Current->NextNode;

        free(Previous);
    }
    
    free(Current);
}