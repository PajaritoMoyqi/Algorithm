#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int PriorityType;

typedef struct tagPQNode
{
    int Data;
    PriorityType Priority;
} PQNode;

typedef struct tagPriorityQueue
{
    PQNode* Nodes;
    int Capacity;
    int UsedSize;
} PriorityQueue;

PriorityQueue* PQ_Create( int InitialSize )
{
    PriorityQueue* NewPQ = (PriorityQueue*)malloc( sizeof( PriorityQueue ) );
    NewPQ->Capacity = InitialSize;
    NewPQ->UsedSize = 0;
    NewPQ->Nodes = (PQNode*)malloc( sizeof( PQNode ) * NewPQ->Capacity );

    return NewPQ;
}

void PQ_Destory( PriorityQueue* PQ )
{
    free( PQ->Nodes );
    free( PQ );
}

void PQ_Enqueue( PriorityQueue* PQ, PQNode NewNode )
{
    int CurrentPosition = PQ->UsedSize;
    int ParentPosition = PQ_GetParent( CurrentPosition );

    if( PQ->UsedSize == PQ->Capacity )
    {
        if( PQ->Capacity == 0 )
            PQ->Capacity = 1;

        PQ->Capacity *= 2;
        PQ->Nodes = (PQNode*)realloc( PQ->Nodes, sizeof( PQNode ) * PQ->Capacity );
    }

    PQ->Nodes[CurrentPosition] = NewNode;

    while( CurrentPosition > 0 &&
        PQ->Nodes[CurrentPosition].Priority < PQ->Nodes[ParentPosition].Priority ) // changeable point
    {
        PQ_SwapNodes( PQ, CurrentPosition, ParentPosition );

        CurrentPosition = ParentPosition;
        ParentPosition = PQ_GetParent( CurrentPosition );
    }

    PQ->UsedSize++;
}
void PQ_EnqueueMAX( PriorityQueue* PQ, PQNode NewNode )
{
    int CurrentPosition = PQ->UsedSize;
    int ParentPosition = PQ_GetParent( CurrentPosition );

    if( PQ->UsedSize == PQ->Capacity )
    {
        if( PQ->Capacity == 0 )
            PQ->Capacity = 1;

        PQ->Capacity *= 2;
        PQ->Nodes = (PQNode*)realloc( PQ->Nodes, sizeof( PQNode ) * PQ->Capacity );
    }

    PQ->Nodes[CurrentPosition] = NewNode;

    while( CurrentPosition > 0 &&
        PQ->Nodes[CurrentPosition].Priority > PQ->Nodes[ParentPosition].Priority ) // changeable point
    {
        PQ_SwapNodes( PQ, CurrentPosition, ParentPosition );

        CurrentPosition = ParentPosition;
        ParentPosition = PQ_GetParent( CurrentPosition );
    }

    PQ->UsedSize++;
}

void PQ_SwapNodes( PriorityQueue* PQ, int Index1, int Index2 )
{
    int CopySize = sizeof( PQNode );
    PQNode* Temp = (PQNode*)malloc( CopySize );

    memcpy( Temp, &PQ->Nodes[Index1], CopySize );
    memcpy( &PQ->Nodes[Index1], &PQ->Nodes[Index2], CopySize );
    memcpy( &PQ->Nodes[Index2], Temp, CopySize );

    free( Temp );
}

void PQ_Dequeue( PriorityQueue* PQ, PQNode* Root )
{
    int ParentPosition = 0;
    int LeftPosition = 0;
    int RightPosition = 0;

    memcpy( Root, &PQ->Nodes[0], sizeof( PQNode ) );
    memset( &PQ->Nodes[0], 0, sizeof( PQNode ) );

    PQ->UsedSize--;
    PQ_SwapNodes( PQ, 0, PQ->UsedSize );

    LeftPosition = PQ_GetLeftChild( 0 );
    RightPosition = LeftPosition + 1;

    while( 1 )
    {
        int SelectedChild = 0;

        if( LeftPosition >= PQ->UsedSize )
            break;

        if( RightPosition >= PQ->UsedSize )
            SelectedChild = LeftPosition;
        else
        {
            if( PQ->Nodes[LeftPosition].Priority > PQ->Nodes[RightPosition].Priority ) // changeable point
                SelectedChild = RightPosition;
            else
                SelectedChild = LeftPosition;
        }

        if( PQ->Nodes[SelectedChild].Priority < PQ->Nodes[ParentPosition].Priority ) // changeable point
        {
            PQ_SwapNodes( PQ, ParentPosition, SelectedChild );
            ParentPosition = SelectedChild;
        }
        else
            break;

        LeftPosition = PQ_GetLeftChild( ParentPosition );
        RightPosition = LeftPosition + 1;
    }

    if( PQ->UsedSize < (PQ->Capacity / 2) )
    {
        PQ->Capacity /= 2;
        PQ->Nodes = (PQNode*)realloc( PQ->Nodes, sizeof( PQNode ) * PQ->Capacity );
    }
}
void PQ_DequeueMAX( PriorityQueue* PQ, PQNode* Root )
{
    int ParentPosition = 0;
    int LeftPosition = 0;
    int RightPosition = 0;

    memcpy( Root, &PQ->Nodes[0], sizeof( PQNode ) );
    memset( &PQ->Nodes[0], 0, sizeof( PQNode ) );

    PQ->UsedSize--;
    PQ_SwapNodes( PQ, 0, PQ->UsedSize );

    LeftPosition = PQ_GetLeftChild( 0 );
    RightPosition = LeftPosition + 1;

    while( 1 )
    {
        int SelectedChild = 0;

        if( LeftPosition >= PQ->UsedSize )
            break;

        if( RightPosition >= PQ->UsedSize )
            SelectedChild = LeftPosition;
        else
        {
            if( PQ->Nodes[LeftPosition].Priority < PQ->Nodes[RightPosition].Priority ) // changeable point
                SelectedChild = RightPosition;
            else
                SelectedChild = LeftPosition;
        }

        if( PQ->Nodes[SelectedChild].Priority > PQ->Nodes[ParentPosition].Priority ) // changeable point
        {
            PQ_SwapNodes( PQ, ParentPosition, SelectedChild );
            ParentPosition = SelectedChild;
        }
        else
            break;

        LeftPosition = PQ_GetLeftChild( ParentPosition );
        RightPosition = LeftPosition + 1;
    }

    if( PQ->UsedSize < (PQ->Capacity / 2) )
    {
        PQ->Capacity /= 2;
        PQ->Nodes = (PQNode*)realloc( PQ->Nodes, sizeof( PQNode ) * PQ->Capacity );
    }
}

int PQ_GetParent( int Index )
{
    return (int)((Index - 1) / 2);
}

int PQ_GetLeftChild( int Index )
{
    return (2 * Index) + 1;
}

void PQ_PrintNodes( PriorityQueue* PQ )
{
    int i = 0;
    for( i = 0; i < PQ->UsedSize; i++ )
        printf( "%d ", PQ->Nodes[i].Data );

    printf( "\n" );
}

int PQ_IsEmpty( PriorityQueue* PQ )
{
    return (PQ->UsedSize == 0);
}

int cmp( const void* _elem1, const void* _elem2 )
{
    PQNode* elem1 = (PQNode*)_elem1;
    PQNode* elem2 = (PQNode*)_elem2;

    if ( elem1->Data == elem2->Data )
    {
        if ( elem1->Priority > elem2->Priority )
            return 1;
        else if ( elem1->Priority < elem2->Priority )
            return -1;
        else
            return 0;
    }
    else
    {
        if ( elem1->Data > elem2->Data )
            return 1;
        else if ( elem1->Data < elem2->Data )
            return -1;
        else
            return 0;
    }
}

int main( void )
{
    int n, year;
    scanf( "%d%d", &n, &year );

    PriorityQueue* PQ1 = PQ_Create( n );
    PriorityQueue* PQ2 = PQ_Create( n );
    PriorityQueue* PQ3 = PQ_Create( n );
    PriorityQueue* PQ4 = PQ_Create( n );
    PriorityQueue* PQ5 = PQ_Create( n );
    PriorityQueue* PQ6 = PQ_Create( n );
    PriorityQueue* PQ7 = PQ_Create( n );
    PriorityQueue* PQ8 = PQ_Create( n );
    PriorityQueue* PQ9 = PQ_Create( n );
    PriorityQueue* PQ10 = PQ_Create( n );
    PriorityQueue* PQ11 = PQ_Create( n );

    int i, position, strength;
    for ( i = 0; i < n; i++ )
    {
        scanf( "%d%d", &position, &strength );
        PQNode N = { position, strength };

        if ( position == 1 ) PQ_EnqueueMAX( PQ1, N );
        else if ( position == 2 ) PQ_EnqueueMAX( PQ2, N );
        else if ( position == 3 ) PQ_EnqueueMAX( PQ3, N );
        else if ( position == 4 ) PQ_EnqueueMAX( PQ4, N );
        else if ( position == 5 ) PQ_EnqueueMAX( PQ5, N );
        else if ( position == 6 ) PQ_EnqueueMAX( PQ6, N );
        else if ( position == 7 ) PQ_EnqueueMAX( PQ7, N );
        else if ( position == 8 ) PQ_EnqueueMAX( PQ8, N );
        else if ( position == 9 ) PQ_EnqueueMAX( PQ9, N );
        else if ( position == 10 ) PQ_EnqueueMAX( PQ10, N );
        else if ( position == 11 ) PQ_EnqueueMAX( PQ11, N );
    }

    if ( PQ1->UsedSize == 0 ) PQ_EnqueueMAX( PQ1, (PQNode){ 1, 0 } );
    if ( PQ2->UsedSize == 0 ) PQ_EnqueueMAX( PQ2, (PQNode){ 2, 0 } );
    if ( PQ3->UsedSize == 0 ) PQ_EnqueueMAX( PQ3, (PQNode){ 3, 0 } );
    if ( PQ4->UsedSize == 0 ) PQ_EnqueueMAX( PQ4, (PQNode){ 4, 0 } );
    if ( PQ5->UsedSize == 0 ) PQ_EnqueueMAX( PQ5, (PQNode){ 5, 0 } );
    if ( PQ6->UsedSize == 0 ) PQ_EnqueueMAX( PQ6, (PQNode){ 6, 0 } );
    if ( PQ7->UsedSize == 0 ) PQ_EnqueueMAX( PQ7, (PQNode){ 7, 0 } );
    if ( PQ8->UsedSize == 0 ) PQ_EnqueueMAX( PQ8, (PQNode){ 8, 0 } );
    if ( PQ9->UsedSize == 0 ) PQ_EnqueueMAX( PQ9, (PQNode){ 9, 0 } );
    if ( PQ10->UsedSize == 0 ) PQ_EnqueueMAX( PQ10, (PQNode){ 10, 0 } );
    if ( PQ11->UsedSize == 0 ) PQ_EnqueueMAX( PQ11, (PQNode){ 11, 0 } );

    int BestEleven[12] = { 0 };
    PQNode Popped1, Popped2, Popped3, Popped4, Popped5, Popped6, Popped7, Popped8, Popped9, Popped10, Popped11;

    while ( year-- )
    {
        PQ_DequeueMAX( PQ1, &Popped1 );
        PQ_DequeueMAX( PQ2, &Popped2 );
        PQ_DequeueMAX( PQ3, &Popped3 );
        PQ_DequeueMAX( PQ4, &Popped4 );
        PQ_DequeueMAX( PQ5, &Popped5 );
        PQ_DequeueMAX( PQ6, &Popped6 );
        PQ_DequeueMAX( PQ7, &Popped7 );
        PQ_DequeueMAX( PQ8, &Popped8 );
        PQ_DequeueMAX( PQ9, &Popped9 );
        PQ_DequeueMAX( PQ10, &Popped10 );
        PQ_DequeueMAX( PQ11, &Popped11 );

        if ( Popped1.Priority != 0 ) Popped1.Priority--;
        if ( Popped2.Priority != 0 ) Popped2.Priority--;
        if ( Popped3.Priority != 0 ) Popped3.Priority--;
        if ( Popped4.Priority != 0 ) Popped4.Priority--;
        if ( Popped5.Priority != 0 ) Popped5.Priority--;
        if ( Popped6.Priority != 0 ) Popped6.Priority--;
        if ( Popped7.Priority != 0 ) Popped7.Priority--;
        if ( Popped8.Priority != 0 ) Popped8.Priority--;
        if ( Popped9.Priority != 0 ) Popped9.Priority--;
        if ( Popped10.Priority != 0 ) Popped10.Priority--;
        if ( Popped11.Priority != 0 ) Popped11.Priority--;

        PQ_EnqueueMAX( PQ1, Popped1 );
        PQ_EnqueueMAX( PQ2, Popped2 );
        PQ_EnqueueMAX( PQ3, Popped3 );
        PQ_EnqueueMAX( PQ4, Popped4 );
        PQ_EnqueueMAX( PQ5, Popped5 );
        PQ_EnqueueMAX( PQ6, Popped6 );
        PQ_EnqueueMAX( PQ7, Popped7 );
        PQ_EnqueueMAX( PQ8, Popped8 );
        PQ_EnqueueMAX( PQ9, Popped9 );
        PQ_EnqueueMAX( PQ10, Popped10 );
        PQ_EnqueueMAX( PQ11, Popped11 );
    }

    PQ_DequeueMAX( PQ1, &Popped1 );
    PQ_DequeueMAX( PQ2, &Popped2 );
    PQ_DequeueMAX( PQ3, &Popped3 );
    PQ_DequeueMAX( PQ4, &Popped4 );
    PQ_DequeueMAX( PQ5, &Popped5 );
    PQ_DequeueMAX( PQ6, &Popped6 );
    PQ_DequeueMAX( PQ7, &Popped7 );
    PQ_DequeueMAX( PQ8, &Popped8 );
    PQ_DequeueMAX( PQ9, &Popped9 );
    PQ_DequeueMAX( PQ10, &Popped10 );
    PQ_DequeueMAX( PQ11, &Popped11 );

    int ans = Popped1.Priority;
    ans += Popped2.Priority;
    ans += Popped3.Priority;
    ans += Popped4.Priority;
    ans += Popped5.Priority;
    ans += Popped6.Priority;
    ans += Popped7.Priority;
    ans += Popped8.Priority;
    ans += Popped9.Priority;
    ans += Popped10.Priority;
    ans += Popped11.Priority;

    printf( "%d", ans );

    return 0;
}