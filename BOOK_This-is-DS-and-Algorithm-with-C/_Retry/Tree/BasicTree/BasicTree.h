#ifndef B_TREE_H
#define B_TREE_H

# include <stdio.h>
# include <stdlib.h>

typedef char ElemType;

typedef struct TreeNode
{
    struct TreeNode* LeftChild;
    struct TreeNode* RightSibling;

    ElemType Data;
} TreeNode;

// declarations
TreeNode* CreateNode( ElemType data );
void DestroyNode( TreeNode* N );
void DestroyTree( TreeNode* Root );
void AddChildNode( TreeNode* Parent, TreeNode* NewNode );

#endif