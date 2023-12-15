#ifndef HEAP_H
#define HEAP_H

# include <stdio.h>
# include <memory.h>
# include <stdlib.h>

typedef int ElemType;

typedef struct HNode
{
    ElemType Data;
} HNode;

typedef struct Heap
{
    HNode* Nodes;
    int Capacity;
    int UsedSize;
} Heap;

// declarations
Heap* Create( int size );
void DestroyHeap( Heap* H );

int GetParentIdx( int idx );
int SwapNodes( Heap* H, int idx1, int idx2 );
void Insert( Heap* H, ElemType data );
int GetLeftChildIdx( int idx );
void Dequeue( Heap* H, HNode* RemovedRoot );

#endif