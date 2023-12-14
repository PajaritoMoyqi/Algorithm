#ifndef BSEARCH_TREE_H
#define BSEARCH_TREE_H

# include <stdio.h>
# include <stdlib.h>

typedef int ElemType;

typedef struct BSTNode
{
    struct BSTNode* Left;
    struct BSTNode* Right;

    ElemType Data;
} BSTNode;

// declarations
BSTNode* CreateNode( ElemType data );
void DestroyNode( BSTNode* N );
void DestroyTree( BSTNode* Tree );
BSTNode* SearchNode( BSTNode* Tree, ElemType target );
void InsertNode( BSTNode* Tree, BSTNode* NewNode );
BSTNode* SearchMinNode( BSTNode* Tree );
BSTNode* RemoveNode( BSTNode* Tree, BSTNode* Parent, ElemType target );

#endif