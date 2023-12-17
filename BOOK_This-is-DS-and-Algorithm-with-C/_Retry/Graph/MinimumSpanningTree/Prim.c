#include "Prim.h"

// Priority Queue
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

    while ( currentIdx > 0 && PQ->Nodes[currentIdx].Data < PQ->Nodes[parentIdx].Data )
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
            if ( PQ->Nodes[leftChildIdx].Data > PQ->Nodes[rightChildIdx].Data )
                selectedIdx = rightChildIdx;
            else
                selectedIdx = leftChildIdx;
        }

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
}

// Graph
Graph* CreateGraph(  )
{
    Graph* G = (Graph*)malloc( sizeof( Graph ) );
    G->Vertices = NULL;
    G->VertexCount = 0;

    return G;
}
Vertex* CreateVertex( ElemType data )
{
    Vertex* V = (Vertex*)malloc( sizeof( Vertex ) );

    V->Data = data;
    V->Next = NULL;
    V->AdjacencyList = NULL;
    V->Index = -1;
    V->Visited = NotVisited;

    return V;
}
Edge* CreateEdge( Vertex* From, Vertex* To, int weight )
{
    Edge* E = (Edge*)malloc( sizeof( Edge ) );

    E->From = From;
    E->To = To;
    E->Weight = weight;
    E->Next = NULL;

    return E;
}
void DestroyEdge( Edge* E )
{
    free( E );
}
void DestroyVertex( Vertex* V )
{
    while ( V->AdjacencyList != NULL )
    {
        Edge* E = V->AdjacencyList->Next;
        DestroyEdge( E );

        V->AdjacencyList = E;
    }

    free( V );
}
void DestroyGraph( Graph* G )
{
    while ( G->Vertices != NULL )
    {
        Vertex* V = G->Vertices->Next;
        DestroyVertex( G->Vertices );
        G->Vertices = V;
    }
}

void AddVertex( Graph* G, Vertex* V )
{
    Vertex* VertexList = G->Vertices;

    if ( VertexList == NULL )
        G->Vertices = V;
    else
    {
        while ( VertexList->Next != NULL )
            VertexList = VertexList->Next;

        VertexList->Next = V;
    }

    V->Index = G->VertexCount++;
}
void AddEdge( Vertex* V, Edge* E )
{
    if ( V->AdjacencyList == NULL )
        V->AdjacencyList = E;
    else
    {
        Edge* AdjacencyList = V->AdjacencyList;

        while ( AdjacencyList->Next != NULL )
            AdjacencyList = AdjacencyList->Next;

        AdjacencyList->Next = E;
    }
}

void PrintGraph( Graph* G )
{
    Vertex* V = NULL;
    Edge* E = NULL;
    
    if ( ( V = G->Vertices ) == NULL )
        return;

    while ( V != NULL )
    {
        printf( "%c - ", V->Data );

        if ( ( E = V->AdjacencyList ) == NULL )
        {
            V = V->Next;
            printf( "\n" );
            continue;
        }

        while ( E != NULL )
        {
            printf( "%c[%d] ", E->To->Data, E->Weight );
            E = E->Next;
        }

        V = V->Next;
        printf( "\n" );
    }

    printf( "\n" );
}

// Prim
void PrimMST( Graph* G, Vertex* StartVertex, Graph* MST )
{
    PQNode* StartNode = { 0, StartVertex };
    PQueue* PQ = Create( 10 );

    Vertex* CurrVertex = NULL;
    Edge* CurrEdge = NULL;

    int* Weights = (int*)malloc( sizeof( int ) * G->VertexCount );
    Vertex** MSTVertices = (Vertex**)malloc( sizeof( Vertex ) * G->VertexCount );
    Vertex** Fringes = (Vertex**)malloc( sizeof( Vertex ) * G->VertexCount );
    Vertex** Precedences = (Vertex**)malloc( sizeof( Vertex ) * G->VertexCount );

    CurrVertex = G->Vertices;
    int i = 0;
    // Traverse all nodes in given graph
    while ( CurrVertex != NULL )
    {
        Vertex* NewVertex = CreateVertex( CurrVertex->Data );
        AddVertex( MST, NewVertex ); // There is only Vertices in MST

        Fringes[i] = NULL;
        Precedences[i] = NULL;
        MSTVertices[i] = NewVertex;
        Weights[i] = MAX_WEIGHT;

        i++;
        CurrVertex = CurrVertex->Next;
    }

    Enqueue( PQ, StartNode );

    while ( PQ->UsedSize != 0 )
    {
        PQNode Popped;
        // Select target vertex
        Dequeue( PQ, &Popped );

        CurrVertex = (Vertex*)Popped.Data;
        Fringes[CurrVertex->Index] = CurrVertex;
        CurrEdge = CurrVertex->AdjacencyList;

        // Check selected target vertex's "Edges"
        while ( CurrEdge != NULL )
        {
            Vertex* TargetVertex = CurrEdge->Next; // connected vertex to selected target vertex

            if ( Fringes[TargetVertex->Index] == NULL // not visited
                && CurrEdge->Weight < Weights[TargetVertex->Index] ) // Select most efficient parent path
            {
                PQNode NewNode = { CurrEdge->Weight, TargetVertex };
                Enqueue( PQ, NewNode );

                // Update datas
                Precedences[TargetVertex->Index] = CurrEdge->From;
                Weights[TargetVertex->Index] = CurrEdge->Weight;
            }

            CurrEdge = CurrEdge->Next;
        }
    }

    for ( i = 0; i < G->VertexCount; i++ )
    {
        int fromIndex, toIndex;

        if ( Precedences[i] == NULL )
            continue;

        fromIndex = Precedences[i]->Index;
        toIndex = i;

        // Now we have Vertices and Edges in MST
        AddEdge( MSTVertices[fromIndex], CreateEdge( MSTVertices[fromIndex], MSTVertices[toIndex], Weights[i] ) );
        AddEdge( MSTVertices[toIndex], CreateEdge( MSTVertices[toIndex], MSTVertices[fromIndex], Weights[i] ) );
    }

    free( Fringes );
    free( Precedences );
    free( MSTVertices );
    free( Weights );

    DestroyPQueue( PQ );
}