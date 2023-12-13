#include "BasicTree.h"

TreeNode* CreateNode( ElemType data )
{
    TreeNode* NewNode = (TreeNode*)malloc( sizeof( TreeNode ) );

    NewNode->Data = data;
    NewNode->LeftChild = NULL;
    NewNode->RightSibling = NULL;

    return NewNode;
}

void DestroyNode( TreeNode* N )
{
    free( N );
}

void DestroyTree( TreeNode* Root )
{
    if ( Root->RightSibling != NULL )
        DestroyNode( Root->RightSibling );

    if ( Root->LeftChild != NULL )
        DestroyNode( Root->LeftChild );

    Root->LeftChild = NULL;
    Root->RightSibling = NULL;

    DestroyNode( Root );
}

void AddChildNode( TreeNode* Parent, TreeNode* NewNode )
{
    if ( Parent->LeftChild == NULL )
        Parent->LeftChild = NewNode;
    else
    {
        TreeNode* TmpNode = Parent->LeftChild;
        while( TmpNode->RightSibling != NULL )
            TmpNode = TmpNode->RightSibling;

        TmpNode->RightSibling = NewNode;
    }
}