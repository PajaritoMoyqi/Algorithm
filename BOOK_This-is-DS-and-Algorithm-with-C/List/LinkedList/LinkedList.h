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

#endif