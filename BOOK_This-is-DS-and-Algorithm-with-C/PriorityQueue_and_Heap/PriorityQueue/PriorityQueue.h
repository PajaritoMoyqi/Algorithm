#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

# include <stdio.h>
# include <memory.h>
# include <stdlib.h>

typedef int PriorityType;

typedef struct tagPQNode
{
    PriorityType Priority;
    void* Data;
} PQNode;

typedef struct tagPriorityQueue
{
    PQNode* Nodes;
    int Capacity;
    int UsedSize;
} PriorityQueue;

PriorityQueue* PQ_Create( int InitialSize );
void PQ_Destory( PriorityQueue* PQ );

void PQ_Enqueue( PriorityQueue* PQ, PQNode NewNode );

void PQ_SwapNodes( PriorityQueue* PQ, int Index1, int Index2 );

void PQ_Dequeue( PriorityQueue* PQ, PQNode* Root );

int PQ_GetParent( int Index );
int PQ_GetLeftChild( int Index );
void PQ_PrintNodes( PriorityQueue* PQ );

int PQ_IsEmpty( PriorityQueue* PQ );

#endif