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

int main( void )
{
    int n, selectedPoint, myPoint;
    scanf( "%d", &n );
    if ( n == 1 )
    {
        printf( "0" );
        return 0;
    }

    PriorityQueue* PQ = PQ_Create( n-1 );

    scanf( "%d", &myPoint );
    int i;
    for ( i = 1; i < n; i++ )
    {
        scanf( "%d", &selectedPoint );
        PQNode N = { selectedPoint, i };

        PQ_Enqueue( PQ, N );
    }

    PQNode Popped;
    int cnt = 0;
    while ( 1 )
    {
        PQ_Dequeue( PQ, &Popped );
        // printf( "myPoint: %d, candidatePoint: %d\n", myPoint, Popped.Priority );
        if ( myPoint > Popped.Priority )
            break;
        else
        {
            myPoint++;
            Popped.Priority--;
            cnt++;
            PQ_Enqueue( PQ, Popped );
        }
    }

    printf( "%d", cnt );

    return 0;
}