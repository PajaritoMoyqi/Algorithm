#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <math.h>

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
int SwapNodes( PQueue* PQ, int idx1, int idx2 )
{
    int nodeSize = sizeof( PQNode );
    PQNode* Tmp = (PQNode*)malloc( nodeSize );

    memcpy( Tmp, &PQ->Nodes[idx1], nodeSize );
    memcpy( &PQ->Nodes[idx1], &PQ->Nodes[idx2], nodeSize );
    memcpy( &PQ->Nodes[idx2], Tmp, nodeSize );

    free( Tmp );
}
void Enqueue( PQueue* PQ, ElemType data )
{
    int currentIdx = PQ->UsedSize;
    int parentIdx = GetParentIdx( currentIdx );

    if ( PQ->UsedSize == PQ->Capacity )
    {
        PQ->Capacity *= 2;
        PQ->Nodes = (PQNode*)realloc( PQ->Nodes, sizeof( PQNode ) * PQ->Capacity );
    }

    PQ->Nodes[currentIdx].Data = data;

    while ( currentIdx > 0
        && ( abs( PQ->Nodes[currentIdx].Data ) < abs( PQ->Nodes[parentIdx].Data )
            || ( abs( PQ->Nodes[currentIdx].Data ) == abs( PQ->Nodes[parentIdx].Data ) && PQ->Nodes[currentIdx].Data < PQ->Nodes[parentIdx].Data ) ) )
    {
        SwapNodes( PQ, currentIdx, parentIdx );

        currentIdx = parentIdx;
        parentIdx = GetParentIdx( currentIdx );
    }

    PQ->UsedSize++;
}

int GetLeftChildIdx( int idx )
{
    return (2 * idx) + 1;
}
void Dequeue( PQueue* PQ, PQNode* RemovedRoot )
{
    int parentIdx, leftChildIdx, rightChildIdx;

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
            if ( ( abs( PQ->Nodes[rightChildIdx].Data ) < abs( PQ->Nodes[leftChildIdx].Data )
                || ( abs( PQ->Nodes[rightChildIdx].Data ) == abs( PQ->Nodes[leftChildIdx].Data ) && PQ->Nodes[rightChildIdx].Data < PQ->Nodes[leftChildIdx].Data ) ) )
                selectedIdx = rightChildIdx;
            else
                selectedIdx = leftChildIdx;
        }

        if ( ( abs( PQ->Nodes[selectedIdx].Data ) < abs( PQ->Nodes[parentIdx].Data )
            || ( abs( PQ->Nodes[selectedIdx].Data ) == abs( PQ->Nodes[parentIdx].Data ) && PQ->Nodes[selectedIdx].Data < PQ->Nodes[parentIdx].Data ) ) )
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
}

int main( void )
{
    int n, givenNum;
    scanf( "%d", &n );

    PQueue* PQ = Create( n );
    
    while ( n-- )
    {
        PQNode Popped;
        scanf( "%d", &givenNum );

        if ( !givenNum )
        {
            if ( !(PQ->UsedSize) )
            {
                printf( "0\n" );
            }
            else
            {
                Dequeue( PQ, &Popped );
                printf( "%d\n", Popped.Data );
            }
        }
        else
        {
            Enqueue( PQ, givenNum );
        }
    }

    return 0;
}