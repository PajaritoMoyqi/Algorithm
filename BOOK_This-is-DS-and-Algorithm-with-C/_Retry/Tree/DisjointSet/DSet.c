#include "DSet.h"

DSet* MakeDSetNode( void* data )
{
    DSet* NewNode = (DSet*)malloc( sizeof( DSet ) );

    NewNode->Data = data;
    NewNode->Parent = NULL;

    return NewNode;
}

void DestroyDSet( DSet* Set )
{
    free( Set );
}

DSet* FindDSet( DSet* Set )
{
    while ( Set->Parent != NULL )
        Set = Set->Parent;

    return Set;
}

void UnionSet( DSet* Set1, DSet* Set2 )
{
    Set2 = FindDSet( Set2 );
    Set2->Parent = Set1;
}