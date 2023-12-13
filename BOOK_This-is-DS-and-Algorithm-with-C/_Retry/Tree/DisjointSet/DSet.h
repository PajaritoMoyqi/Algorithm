#ifndef DSET_H
#define DSET_H

# include <stdio.h>
# include <stdlib.h>

typedef struct DSet
{
    struct DSet* Parent;

    void* Data;
} DSet;

// declarations
DSet* MakeDSetNode( void* data );
void DestroyDSet( DSet* Set );
DSet* FindDSet( DSet* Set );
void UnionSet( DSet* Set1, DSet* Set2 );

#endif