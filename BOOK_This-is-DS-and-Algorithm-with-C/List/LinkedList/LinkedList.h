#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// spacing between # and include for readability
# include <stdio.h>
# include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
    struct tagNode* NextNode;
} Node;

// delclaration of functions
Node* SLL_CreateNode_WrongWay(ElementType NewData);
Node* SLL_CreateNode(ElementType NewData);
void SLL_DestroyNode(Node* Node);
void SLL_AppendNode(Node** Head, Node* NewNode);
Node* SLL_GetNodeAt(Node* Head, int Location);
void SLL_RemoveNode(Node** Head, Node* Remove);
void SLL_InsertAfter(Node* Current, Node* NewNode);
void SLL_InsertBefore(Node** Head, Node* Current, Node* NewNode);
void SLL_InsertNewHead(Node** Head, Node* NewHead);
int SLL_GetNodeCount(Node* Head);
void SLL_DestroyAllNodes(Node** Head);

#endif