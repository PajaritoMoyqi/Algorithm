#include "PriorityQueue.h"

void PrintNode( PQNode* Node )
{
    printf( "name: %s(priority: %d)\n", Node->Data, Node->Priority );
}

int main( void )
{
    PriorityQueue* PQ = PQ_Create( 3 );

    PQNode Popped;

    PQNode Nodes[7] =
    {
        { 34, (void*)"C Coding" },
        { 12, (void*)"Debugging" },
        { 87, (void*)"Making Computing System" },
        { 45, (void*)"Taking a Rest" },
        { 35, (void*)"Cooking" },
        { 65, (void*)"Calling" }
    };

    PQ_Enqueue( PQ, Nodes[0] );
    PQ_Enqueue( PQ, Nodes[1] );
    PQ_Enqueue( PQ, Nodes[2] );
    PQ_Enqueue( PQ, Nodes[3] );
    PQ_Enqueue( PQ, Nodes[4] );
    PQ_Enqueue( PQ, Nodes[5] );

    printf( "left works in queue: %d\n", PQ->UsedSize );

    while( !PQ_IsEmpty( PQ ) )
    {
        PQ_Dequeue( PQ, &Popped );
        PrintNode( &Popped );
    }

    return 0;
}