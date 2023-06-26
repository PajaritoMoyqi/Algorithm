#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

# include <stdio.h>
# include <stdlib.h>

typedef int ElementType;

typedef struct tagRBTNode
{
    struct tagRBTNode* Parent;
    struct tagRBTNode* Left;
    struct tagRBTNode* Right;

    enum { RED, BLACK } Color;

    ElementType Data;
} RBTNode;

RBTNode* RBT_CreateNode( ElementType NewData );

void RBT_DestroyNode( RBTNode* Node );
void RBT_DestroyTree( RBTNode* Tree );

RBTNode* RBT_SearchNode( RBTNode* Tree, ElementType Target );
RBTNode* RBT_SearchMinNode( RBTNode* Tree );

void RBT_InsertNode( RBTNode** Tree, RBTNode* NewNode );
void RBT_InsertNodeHelper( RBTNode** Tree, RBTNode* NewNode );

void RBT_RotateRight( RBTNode** Root, RBTNode* Parent );
void RBT_RotateLeft( RBTNode** Root, RBTNode* Parent );

void RBT_RebuildAfterInsert( RBTNode** Root, RBTNode* X );

#endif