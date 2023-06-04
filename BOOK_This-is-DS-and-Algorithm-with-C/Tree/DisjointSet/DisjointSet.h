#ifndef DISJOINTSET_H
#define DISJOINTSET_H

# include <stdio.h>
# include <stdlib.h>

typedef struct tagDisjointSet
{
    struct tagDisjoitSet* Parent;
    void* Data; // to set data in any type
} DisjointSet;

DisjointSet* DS_FindSet( DisjointSet* Set );
void DS_UnoinSet( DisjointSet* Parent, DisjointSet* Child );
DisjointSet* DS_MakeSet( void* NewData );
void DS_DestroySet( DisjointSet* Set );

#endif