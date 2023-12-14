#include "BSearchTree.h"

BSTNode* CreateNode( ElemType data )
{
    BSTNode* NewNode = (BSTNode*)malloc( sizeof( BSTNode ) );

    NewNode->Data = data;
    NewNode->Left = NULL;
    NewNode->Right = NULL;

    return NewNode;
}
void DestroyNode( BSTNode* N )
{
    free( N );
}
void DestroyTree( BSTNode* Tree )
{
    if ( Tree->Right != NULL )
        DestroyTree( Tree->Right );
    if ( Tree->Left != NULL )
        DestroyTree( Tree->Left );
    
    Tree->Left = NULL;
    Tree->Right = NULL;

    DestroyNode( Tree );
}

BSTNode* SearchNode( BSTNode* Tree, ElemType target )
{
    if ( Tree == NULL ) return NULL;

    if ( Tree->Data == target )
        return Tree;
    else if ( Tree->Data > target )
        return SearchNode( Tree->Left, target );
    else
        return SearchNode( Tree->Right, target );
}

void InsertNode( BSTNode* Tree, BSTNode* NewNode )
{
    if ( Tree->Data < NewNode->Data )
    {
        if ( Tree->Right == NULL )
            Tree->Right = NewNode;
        else
            InsertNode( Tree->Right, NewNode );
    }
    if ( Tree->Data > NewNode->Data )
    {
        if ( Tree->Left == NULL )
            Tree->Left = NewNode;
        else
            InsertNode( Tree->Left, NewNode );
    }
}
BSTNode* SearchMinNode( BSTNode* Tree )
{
    if ( Tree == NULL )
        return NULL;
    
    if ( Tree->Left == NULL )
        return Tree;
    else
        return SearchMinNode( Tree->Left );
}
BSTNode* RemoveNode( BSTNode* Tree, BSTNode* Parent, ElemType target )
{
    BSTNode* Removed = NULL;

    if ( Tree == NULL ) return Removed;

    if ( Tree->Data > target )
        Removed = RemoveNode( Tree->Left, Tree, target );
    else if ( Tree->Data < target )
        Removed = RemoveNode( Tree->Right, Tree, target );
    else
    {
        Removed = Tree;

        if ( Tree->Left == NULL && Tree->Right == NULL )
        {
            if ( Parent->Left == Tree )
                Parent->Left = NULL;
            else
                Parent->Right = NULL;
        }
        else
        {
            if ( Tree->Left != NULL && Tree->Right != NULL )
            {
                BSTNode* MinNode = SearchMinNode( Tree->Right );
                MinNode = RemoveNode( Tree, NULL, MinNode->Data );
                Tree->Data = MinNode->Data;
            }
            else
            {
                BSTNode* Tmp = NULL;

                if ( Tree->Left != NULL )
                    Tmp = Tree->Left;
                else
                    Tmp = Tree->Right;
                
                if ( Parent->Left == Tree )
                    Parent->Left = Tmp;
                else
                    Parent->Right = Tmp;
            }
        }
    }

    return Removed;
}