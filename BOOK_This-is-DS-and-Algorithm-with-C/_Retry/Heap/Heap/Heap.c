#include "Heap.h"

Heap* Create( int size )
{
    Heap* NewHeap = (Heap*)malloc( sizeof( Heap ) );
    NewHeap->Capacity = size;
    NewHeap->UsedSize = 0;
    NewHeap->Nodes = (HNode*)malloc( sizeof( HNode ) * NewHeap->Capacity );

    return NewHeap;
}
void DestroyHeap( Heap* H )
{
    free( H->Nodes );
    free( H );
}

int GetParentIdx( int idx )
{
    return (int) ((idx - 1) / 2);
}
int SwapNodes( Heap* H, int idx1, int idx2 )
{
    int nodeSize = sizeof( HNode );
    HNode* Tmp = (HNode*)malloc( nodeSize );

    memcpy( Tmp, &H->Nodes[idx1], nodeSize );
    memcpy( &H->Nodes[idx1], &H->Nodes[idx2], nodeSize );
    memcpy( &H->Nodes[idx2], Tmp, nodeSize );

    free( Tmp );
}
void Insert( Heap* H, ElemType data )
{
    int currentIdx = H->UsedSize;
    int parentIdx = GetParentIdx( currentIdx );

    if ( H->UsedSize == H->Capacity )
    {
        H->Capacity *= 2;
        H->Nodes = (HNode*)realloc( H->Nodes, sizeof( HNode ) * H->Capacity );
    }

    H->Nodes[currentIdx].Data = data;

    while ( currentIdx > 0 && H->Nodes[currentIdx].Data < H->Nodes[parentIdx].Data )
    {
        SwapNodes( H, currentIdx, parentIdx );

        currentIdx = parentIdx;
        parentIdx = GetParentIdx( currentIdx );
    }

    H->UsedSize++;
}

int GetLeftChildIdx( int idx )
{
    return (2 * idx) + 1;
}
void Dequeue( Heap* H, HNode* RemovedRoot )
{
    int parentIdx, leftChildIdx, rightChildIdx;

    memcpy( RemovedRoot, &H->Nodes[0], sizeof( HNode ) );
    memset( &H->Nodes[0], 0, sizeof( HNode ) );

    H->UsedSize--;
    SwapNodes( H, 0, H->UsedSize );

    parentIdx = 0;
    leftChildIdx = GetLeftChildIdx( parentIdx );
    rightChildIdx = leftChildIdx + 1;
    while ( 1 )
    {
        int selectedIdx = 0;

        if ( leftChildIdx >= H->UsedSize ) break;

        // pick smaller data
        if ( rightChildIdx >= H->UsedSize )
            selectedIdx = leftChildIdx;
        else
        {
            if ( H->Nodes[leftChildIdx].Data > H->Nodes[rightChildIdx].Data )
                selectedIdx = rightChildIdx;
            else
                selectedIdx = leftChildIdx;
        }

        if ( H->Nodes[selectedIdx].Data > H->Nodes[parentIdx].Data )
        {
            SwapNodes( H, parentIdx, selectedIdx );
            parentIdx = selectedIdx;
        }
        else
            break;

        leftChildIdx = GetLeftChildIdx( parentIdx );
        rightChildIdx = leftChildIdx + 1;
    }

    if ( H->UsedSize < (H->Capacity / 2) )
    {
        H->Capacity /= 2;
        H->Nodes = (HNode*)realloc( H->Nodes, sizeof( HNode ) * H->Capacity );
    }
}