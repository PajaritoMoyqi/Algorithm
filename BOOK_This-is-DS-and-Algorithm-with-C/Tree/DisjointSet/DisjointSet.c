#include "DisjointSet.h"

DisjointSet* DS_FindSet( DisjointSet* Set )
{
    while ( Set->Parent != NULL )
        Set = Set->Parent;

    return Set;
}

void DS_UnoinSet( DisjointSet* Parent, DisjointSet* Child )
{
    Child = DS_FindeSet(Child);
    Child->Parent = Parent;
}

DisjointSet* DS_MakeSet( void* NewData )
{
    DisjointSet* NewNode = (DisjointSet*)malloc( sizeof( DisjointSet ) );

    NewNode->Data = NewData;
    NewNode->Parent = NULL;

    return NewNode;
}

void DS_DestroySet( DisjointSet* Set )
{
    free( Set );
}