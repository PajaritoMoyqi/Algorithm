#ifndef HEAP_H
#define HEAP_H

# include <stdio.h>
# include <memory.h>
# include <stdlib.h>

typedef int ElemType;

typedef struct PQNode
{
    ElemType Data;
} PQNode;

typedef struct PQueue
{
    PQNode* Nodes;
    int Capacity;
    int UsedSize;
} PQueue;

// declarations
PQueue* Create( int size );
void DestroyPQueue( PQueue* H );

int GetParentIdx( int idx );
int SwapNodes( PQueue* H, int idx1, int idx2 );
void Enqueue( PQueue* H, ElemType data );
int GetLeftChildIdx( int idx );
void Dequeue( PQueue* H, PQNode* RemovedRoot );

#endif