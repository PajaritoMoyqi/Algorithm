#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int PriorityType;

typedef struct _PQNode
{
    PriorityType Data;
} PQNode;

typedef struct _PQueue
{
    PQNode* Nodes;
    int Capacity;
    int UsedSize;
} PQueue;

PQueue* Create( int size );
void DestroyPQueue( PQueue* PQ );
int GetParentIdx( int idx );
void SwapNodes( PQueue* PQ, int idx1, int idx2 );
void Enqueue( PQueue* PQ, PriorityType data );
void EnqueueMax( PQueue* PQ, PriorityType data );
int GetLeftChildIdx( int idx );
PQNode* Dequeue( PQueue* PQ );
PQNode* DequeueMax( PQueue* PQ );

#define MAX_LEN 5000

int main( void )
{
    int n;
    scanf( "%d", &n );

    PQueue* PQ = Create( n );

    int cmd, num;
    int i;
    PQNode* N;
    for ( i = 0; i < n; i++ )
    {
        scanf( "%d", &cmd );
        if ( !cmd )
        {
            if ( !PQ->UsedSize )
                printf( "%d\n", -1 );
            else
            {
                N = DequeueMax( PQ );
                printf( "%d\n", N->Data );
            }
        }
        else
        {
            while ( cmd-- )
            {
                scanf( "%d", &num );
                EnqueueMax( PQ, num );
            }
        }
    }

    return 0;
}

PQueue* Create( int size )
{
    PQueue* NewPQueue = (PQueue*)malloc( sizeof( PQueue ) );

    NewPQueue->Capacity = size;
    NewPQueue->UsedSize = 0;
    NewPQueue->Nodes = (PQNode*)malloc( sizeof( PQNode ) * NewPQueue->Capacity );

    return NewPQueue;
}
void DestroyPQueue( PQueue* PQ )
{
    free( PQ->Nodes );
    free( PQ );
}

int GetParentIdx( int idx )
{
    return (int) ((idx - 1) / 2);
}
void SwapNodes( PQueue* PQ, int idx1, int idx2 )
{
    PQNode* Tmp = (PQNode*)malloc( sizeof( PQNode ) );

    memcpy( Tmp, &PQ->Nodes[idx1], sizeof( PQNode ) );
    memcpy( &PQ->Nodes[idx1], &PQ->Nodes[idx2], sizeof( PQNode ) );
    memcpy( &PQ->Nodes[idx2], Tmp, sizeof( PQNode ) );

    free( Tmp );
}
void Enqueue( PQueue* PQ, PriorityType data )
{
    int currentIdx = PQ->UsedSize;
    int parentIdx = GetParentIdx( currentIdx );

    if ( PQ->UsedSize == PQ->Capacity )
    {
        PQ->Capacity *= 2;
        PQ->Nodes = (PQNode*)realloc( PQ->Nodes, sizeof( PQNode ) * PQ->Capacity );
    }

    PQ->Nodes[currentIdx].Data = data;

    while ( currentIdx > 0 && PQ->Nodes[currentIdx].Data < PQ->Nodes[parentIdx].Data )
    {
        SwapNodes( PQ, currentIdx, parentIdx );

        currentIdx = parentIdx;
        parentIdx = GetParentIdx( currentIdx );
    }

    PQ->UsedSize++;
}
void EnqueueMax( PQueue* PQ, PriorityType data )
{
    int currentIdx = PQ->UsedSize;
    int parentIdx = GetParentIdx( currentIdx );

    if ( PQ->UsedSize == PQ->Capacity )
    {
        PQ->Capacity *= 2;
        PQ->Nodes = (PQNode*)realloc( PQ->Nodes, sizeof( PQNode ) * PQ->Capacity );
    }

    PQ->Nodes[currentIdx].Data = data;

    // printf( "currIdx: %d, parIdx: %d\n", currentIdx, parentIdx );
    // printf( "curr: %d, par: %d\n", PQ->Nodes[currentIdx].Data, PQ->Nodes[parentIdx].Data );
    // printf( "a > b: %d\n", PQ->Nodes[currentIdx].Data > PQ->Nodes[parentIdx].Data );

    while ( currentIdx > 0 && PQ->Nodes[currentIdx].Data > PQ->Nodes[parentIdx].Data )
    {
        SwapNodes( PQ, currentIdx, parentIdx );
        // printf( "(%d <-> %d)\n", currentIdx, parentIdx );

        currentIdx = parentIdx;
        parentIdx = GetParentIdx( currentIdx );
    }
    // printf( "0st: %d\n", PQ->Nodes[0].Data );

    PQ->UsedSize++;
}

int GetLeftChildIdx( int idx )
{
    return (2 * idx) + 1;
}
PQNode* Dequeue( PQueue* PQ )
{
    int parentIdx, leftChildIdx, rightChildIdx;
    PQNode* RemovedRoot = (PQNode*)malloc( sizeof( PQNode ) );

    memcpy( RemovedRoot, &PQ->Nodes[0], sizeof( PQNode ) );
    memset( &PQ->Nodes[0], 0, sizeof( PQNode ) );

    PQ->UsedSize--;
    SwapNodes( PQ, 0, PQ->UsedSize );

    parentIdx = 0;
    leftChildIdx = GetLeftChildIdx( parentIdx );
    rightChildIdx = leftChildIdx + 1;
    while ( 1 )
    {
        int selectedIdx = 0;

        if ( leftChildIdx >= PQ->UsedSize ) break;

        // pick smaller data
        if ( rightChildIdx >= PQ->UsedSize )
            selectedIdx = leftChildIdx;
        else
        {
            if ( PQ->Nodes[leftChildIdx].Data > PQ->Nodes[rightChildIdx].Data )
                selectedIdx = rightChildIdx;
            else
                selectedIdx = leftChildIdx;
        }

        if ( PQ->Nodes[selectedIdx].Data < PQ->Nodes[parentIdx].Data )
        {
            SwapNodes( PQ, parentIdx, selectedIdx );
            parentIdx = selectedIdx;
        }
        else
            break;

        leftChildIdx = GetLeftChildIdx( parentIdx );
        rightChildIdx = leftChildIdx + 1;
    }

    if ( PQ->UsedSize < (PQ->Capacity / 2) )
    {
        PQ->Capacity /= 2;
        PQ->Nodes = (PQNode*)realloc( PQ->Nodes, sizeof( PQNode ) * PQ->Capacity );
    }

    return RemovedRoot;
}
PQNode* DequeueMax( PQueue* PQ )
{
    int parentIdx, leftChildIdx, rightChildIdx;
    PQNode* RemovedRoot = (PQNode*)malloc( sizeof( PQNode ) );

    memcpy( RemovedRoot, &PQ->Nodes[0], sizeof( PQNode ) );
    memset( &PQ->Nodes[0], 0, sizeof( PQNode ) );

    PQ->UsedSize--;
    SwapNodes( PQ, 0, PQ->UsedSize );

    parentIdx = 0;
    leftChildIdx = GetLeftChildIdx( parentIdx );
    rightChildIdx = leftChildIdx + 1;
    while ( 1 )
    {
        int selectedIdx = 0;

        if ( leftChildIdx >= PQ->UsedSize ) break;

        // pick smaller data
        if ( rightChildIdx >= PQ->UsedSize )
            selectedIdx = leftChildIdx;
        else
        {
            if ( PQ->Nodes[leftChildIdx].Data < PQ->Nodes[rightChildIdx].Data )
                selectedIdx = rightChildIdx;
            else
                selectedIdx = leftChildIdx;
        }

        // printf( "sIdx: %d, parIdx: %d\n", selectedIdx, parentIdx );
        if ( PQ->Nodes[selectedIdx].Data > PQ->Nodes[parentIdx].Data )
        {
            SwapNodes( PQ, parentIdx, selectedIdx );
            parentIdx = selectedIdx;
        }
        else
            break;

        leftChildIdx = GetLeftChildIdx( parentIdx );
        rightChildIdx = leftChildIdx + 1;
    }

    if ( PQ->UsedSize < (PQ->Capacity / 2) )
    {
        PQ->Capacity /= 2;
        PQ->Nodes = (PQNode*)realloc( PQ->Nodes, sizeof( PQNode ) * PQ->Capacity );
    }

    return RemovedRoot;
}