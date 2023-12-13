#ifndef BTREE_H
#define BTREE_H

# include <stdio.h>
# include <stdlib.h>

typedef char ElemType;

typedef struct BTNode
{
    struct BTNode* Left;
    struct BTNode* Right;

    ElemType Data;
} BTNode;

// declarations
BTNode* CreateNode( ElemType data );
void DestroyTree( BTNode* N );
void PreorderPrintBT( BTNode* N );
void InorderPrintBT( BTNode* N );
void PostorderPrintBT( BTNode* N );

#endif