#include "BinarySearchTree.h"

BSTNode* BST_CreateNode( ElementType NewData )
{
    BSTNode* NewNode = (BSTNode*)malloc( sizeof( BSTNode ) );

    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

void BST_DestroyNode( BSTNode* Node )
{
    free( Node );
}

void BST_DestroyTree( BSTNode* Tree )
{
    if ( Tree->Right != NULL )
        BST_DestroyTree( Tree->Right );
    else if ( Tree->Left != NULL )
        BST_DestroyTree( Tree->Left );

    Tree->Left = NULL;
    Tree->Right = NULL;

    BST_DestroyTree( Tree );
}

BSTNode* BST_SearchNode( BSTNode* Tree, ElementType Target )
{
    if ( Tree == NULL )
        return NULL;

    if ( Tree->Data == Target )
        return Tree;
    else if( Tree->Data > Target )
        return BST_SearchNode( Tree->Left, Target );
    else
        return BST_SearchNode( Tree->Right, Target );
}

BSTNode* BST_SearchMinNode( BSTNode* Tree )
{
    if ( Tree == NULL )
        return NULL;

    if ( Tree->Left == NULL )
        return Tree;
    else
        return BST_SearchMinNode( Tree->Left );
}

void BST_InsertNode( BSTNode* Tree, BSTNode* NewNode )
{
    if ( Tree->Data < NewNode->Data )
    {
        if ( Tree->Right == NULL )
            Tree->Right = NewNode;
        else
            BST_InsertNode( Tree->Right, NewNode );
    }
    else if ( Tree->Data > NewNode->Data )
    {
        if ( Tree->Left == NULL )
            Tree->Left = NewNode;
        else
            BST_InsertNode( Tree->Left, NewNode );
    }
}

BSTNode* BST_RemoveNode( BSTNode* Tree, BSTNode* Parent, ElementType Target )
{
    BSTNode* Removed = NULL;

    if ( Tree == NULL )
        return NULL;

    if ( Tree->Data > Target )
        Removed = BST_RemoveNode( Tree->Left, Tree, Target );
    else if ( Tree->Data < Target )
        Removed = BST_RemoveNode( Tree->Right, Tree, Target );
    else // when we get target
    {
        Removed = Tree;

        if ( Tree->Left == NULL && Tree->Right == NULL )
        {
            if ( Parent->Left == Tree )
                Parent->Left = NULL;
            else
                Parent->Right = NULL;
        }
        else // both or one side has one's child(ren)
        {
            if ( Tree->Left != NULL && Tree->Right != NULL ) // both side has one's child(ren)
            {
                BSTNode* MinNode = BST_SearchMinNode( Tree->Right ); // At right side of target tree,
                MinNode = BST_RemoveNode( Tree, NULL, MinNode->Data ); // remove the smallest node,
                Tree->Data = MinNode->Data; // and move it to the place where target tree was.
            }
            else // only one side has one's child(ren)
            {
                BSTNode* Temp = NULL;

                if ( Tree->Left != NULL ) // search which side the child of tree is
                    Temp = Tree->Left;
                else
                    Temp = Tree->Right;

                if ( Parent->Left == Tree ) // put the child to the place where target tree was
                    Parent->Left = Temp;
                else
                    Parent->Right = Temp;
            }
        }
    }

    return Removed;
}