#include "LinkedList.h"

// SLL means Singly 

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

    return NewNode;
}

void SLL_DestroyNode(Node* Node)
{
    free(Node); // Remove space for Node from Heap
}