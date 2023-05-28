#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
} Node;

// declaration of functions
Node* CDLL_CreateNode( ElementType NewData );
void CDLL_DestoryNode( Node* Node );
void CDLL_AppendNode( Node** Head, Node* NewNode );
void CDLL_InsertAfter( Node* Current, Node* NewNode );
void CDLL_RemoveNode( Node** Head, Node* Remove );
Node* CDLL_GetNodeAt( Node* Head, int Location );
int CDLL_GetNodeCount( Node* Head );
void PrintNode( Node* _Node );

#endif