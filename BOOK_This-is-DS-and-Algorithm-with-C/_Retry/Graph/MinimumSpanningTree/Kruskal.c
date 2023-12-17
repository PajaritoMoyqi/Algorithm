#include "Kruskal.h"

// Disjoint Set
DSet* MakeDSetNode( void* data )
{
    DSet* NewNode = (DSet*)malloc( sizeof( DSet ) );

    NewNode->Data = data;
    NewNode->Parent = NULL;

    return NewNode;
}

void DestroyDSet( DSet* Set )
{
    free( Set );
}

DSet* FindDSet( DSet* Set )
{
    while ( Set->Parent != NULL )
        Set = Set->Parent;

    return Set;
}

void UnionSet( DSet* Set1, DSet* Set2 )
{
    Set2 = FindDSet( Set2 );
    Set2->Parent = Set1;
}


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


// Kruskal
void KruskalMST( Graph* G, Graph* MST )
{
    Vertex* CurrVertex = NULL;
    Vertex** MSTVertices = (Vertex**)malloc( sizeof( Vertex* ) * G->VertexCount );
    DSet** VertexSet = (DSet**)malloc( sizeof( DSet* ) * G->VertexCount );
    PQueue* PQ = Create( 10 );

    CurrVertex = G->Vertices;
    int i = 0;
    while ( CurrVertex != NULL )
    {
        Edge* CurrEdge = NULL;

        VertexSet[i] = MakeDSetNode( CurrVertex );
        MSTVertices[i] = CreateVertex( CurrVertex->Data );
        AddVertex( MST, MSTVertices[i] );

        CurrEdge = CurrVertex->AdjacencyList;
        while ( CurrEdge != NULL )
        {
            PQNode NewNode = { CurrEdge->Weight, CurrEdge };
            Enqueue( PQ, NewNode );

            CurrEdge = CurrEdge->Next;
        }

        CurrVertex = CurrVertex->Next;
        i++;
    }

    while ( PQ->UsedSize != 0 )
    {
        Edge* CurrEdge;
        int fromIdx;
        int toIdx;
        PQNode Popped;

        Dequeue( PQ, &Popped );
        CurrEdge = (Edge*)Popped.Data;

        fromIdx = CurrEdge->From->Index;
        toIdx = CurrEdge->To->Index;

        if ( FindDSet( VertexSet[fromIdx] ) != FindDSet( VertexSet[toIdx] ) )
        {
            AddEdge( MSTVertices[fromIdx], CreateEdge( MSTVertices[fromIdx], MSTVertices[toIdx], CurrEdge->Weight ) );
            AddEdge( MSTVertices[toIdx], CreateEdge( MSTVertices[toIdx], MSTVertices[fromIdx], CurrEdge->Weight ) );

            UnionSet( VertexSet[fromIdx], VertexSet[toIdx] );
        }
    }

    for ( i = 0; i < G->VertexCount; i++ )
        DestroyDSet( VertexSet[i] );

    free( VertexSet );
    free( MSTVertices );
}