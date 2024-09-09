#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

enum VisitMode
{
    NotVisited,
    Visited
};

typedef int ElemType;
typedef int PriorityType;

typedef struct _DSet
{
    struct _DSet* Parent;

    void* Data;
} DSet;

typedef struct _PQNode
{
    PriorityType Priority;
    void* Data;
} PQNode;

typedef struct _PQueue
{
    PQNode* Nodes;
    int Capacity;
    int UsedSize;
} PQueue;

typedef struct _Vertex
{
    int Visited;
    int Index;
    ElemType Data;

    struct _Vertex* Next;
    struct _Edge* AdjacencyList;
    struct _Edge* LastAdjacency;
} Vertex;
typedef struct _Edge
{
    int Weight;
    struct _Edge* Next;
    struct _Vertex* From;
    struct _Vertex* To;
} Edge;
typedef struct _Graph
{
    Vertex* Vertices;
    Vertex* LastVertex;
    int VertexCount;
} Graph;

DSet* MakeDSetNode( void* data );
void DestroyDSet( DSet* Set );
DSet* FindDSet( DSet* Set );
void UnionSet( DSet* Set1, DSet* Set2 );

PQueue* Create( int size );
void DestroyPQueue( PQueue* PQ );
int GetParentIdx( int idx );
void SwapNodes( PQueue* PQ, int idx1, int idx2 );
void Enqueue( PQueue* PQ, PQNode N );
void EnqueueMax( PQueue* PQ, PQNode N );
int GetLeftChildIdx( int idx );
PQNode* Dequeue( PQueue* PQ );
PQNode* DequeueMax( PQueue* PQ );

Graph* CreateGraph( void );
Vertex* CreateVertex( ElemType data );
Edge* CreateEdge( Vertex* From, Vertex* To, int weight );
void DestroyEdge( Edge* E );
void DestroyVertex( Vertex* V );
void DestroyGraph( Graph* G );
void AddVertex( Graph* G, Vertex* V );
void AddEdge( Vertex* V, Edge* E );
void PrintGraph( Graph* G );
void DFS( Vertex* V );

void PrimMST( Graph* G, Vertex* StartVertex, Graph* MST );
void KruskalMST( Graph* G, Graph* MST );
Vertex** Dijkstra( Graph* G, Vertex* StartVertex, Graph* DijkstraGraph );

#define MAX_WEIGHT 3000000
#define MAX_EDGE 300000

int main( void )
{
    int v, e, target = 1;
    scanf( "%d%d", &v, &e );

    Graph* G = CreateGraph();
    Vertex* VertexSet[v+1];

    int i;
    for ( i = 1; i <= v; i++ )
    {
        VertexSet[i] = CreateVertex( i );
        AddVertex( G, VertexSet[i] );
    }

    int a, b, weight;
    Edge* E;
    for ( i = 0; i < e; i++ )
    {
        scanf( "%d%d%d", &a, &b, &weight );
        E = CreateEdge( VertexSet[a], VertexSet[b], weight );
        AddEdge( VertexSet[a], E );
        E = CreateEdge( VertexSet[b], VertexSet[a], weight );
        AddEdge( VertexSet[b], E );
    }

    Graph* MSTGraph = CreateGraph();
    Vertex** P = Dijkstra( G, VertexSet[target], MSTGraph );

    printf( "%d\n", MSTGraph->VertexCount - 1 );
    for ( i = 1; i < MSTGraph->VertexCount; i++ )
        printf( "%d %d\n", P[i]->Data, i+1 );

    return 0;
}

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
void Enqueue( PQueue* PQ, PQNode N )
{
    int currentIdx = PQ->UsedSize;
    int parentIdx = GetParentIdx( currentIdx );

    if ( PQ->UsedSize == PQ->Capacity )
    {
        PQ->Capacity *= 2;
        PQ->Nodes = (PQNode*)realloc( PQ->Nodes, sizeof( PQNode ) * PQ->Capacity );
    }

    PQ->Nodes[currentIdx].Priority = N.Priority;
    PQ->Nodes[currentIdx].Data = N.Data;

    while ( currentIdx > 0 && PQ->Nodes[currentIdx].Priority < PQ->Nodes[parentIdx].Priority )
    {
        SwapNodes( PQ, currentIdx, parentIdx );

        currentIdx = parentIdx;
        parentIdx = GetParentIdx( currentIdx );
    }

    PQ->UsedSize++;
}
void EnqueueMax( PQueue* PQ, PQNode N )
{
    int currentIdx = PQ->UsedSize;
    int parentIdx = GetParentIdx( currentIdx );

    if ( PQ->UsedSize == PQ->Capacity )
    {
        PQ->Capacity *= 2;
        PQ->Nodes = (PQNode*)realloc( PQ->Nodes, sizeof( PQNode ) * PQ->Capacity );
    }

    PQ->Nodes[currentIdx].Priority = N.Priority;
    PQ->Nodes[currentIdx].Data = N.Data;

    // printf( "currIdx: %d, parIdx: %d\n", currentIdx, parentIdx );
    // printf( "curr: %d, par: %d\n", PQ->Nodes[currentIdx].Priority, PQ->Nodes[parentIdx].Priority );
    // printf( "a > b: %d\n", PQ->Nodes[currentIdx].Priority > PQ->Nodes[parentIdx].Priority );

    while ( currentIdx > 0 && PQ->Nodes[currentIdx].Priority > PQ->Nodes[parentIdx].Priority )
    {
        SwapNodes( PQ, currentIdx, parentIdx );
        // printf( "(%d <-> %d)\n", currentIdx, parentIdx );

        currentIdx = parentIdx;
        parentIdx = GetParentIdx( currentIdx );
    }
    // printf( "0st: %d\n", PQ->Nodes[0].Priority );

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
            if ( PQ->Nodes[leftChildIdx].Priority > PQ->Nodes[rightChildIdx].Priority )
                selectedIdx = rightChildIdx;
            else
                selectedIdx = leftChildIdx;
        }

        if ( PQ->Nodes[selectedIdx].Priority < PQ->Nodes[parentIdx].Priority )
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
            if ( PQ->Nodes[leftChildIdx].Priority < PQ->Nodes[rightChildIdx].Priority )
                selectedIdx = rightChildIdx;
            else
                selectedIdx = leftChildIdx;
        }

        // printf( "sIdx: %d, parIdx: %d\n", selectedIdx, parentIdx );
        if ( PQ->Nodes[selectedIdx].Priority > PQ->Nodes[parentIdx].Priority )
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

Graph* CreateGraph( void )
{
    Graph* G = (Graph*)malloc( sizeof( Graph ) );
    
    G->Vertices = NULL;
    G->LastVertex = NULL; // added
    G->VertexCount = 0;

    return G;
}
Vertex* CreateVertex( ElemType data )
{
    Vertex* V = (Vertex*)malloc( sizeof( Vertex ) );

    V->Data = data;
    V->Next = NULL;
    V->AdjacencyList = NULL;
    V->LastAdjacency = NULL; // added
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
    {
        G->Vertices = V;
        G->LastVertex = V;
    }
    else
    {
        G->LastVertex->Next = V;
        G->LastVertex = V;
    }

    V->Index = G->VertexCount++;
}
void AddEdge( Vertex* V, Edge* E )
{
    if ( V->AdjacencyList == NULL )
    {
        V->AdjacencyList = E;
        V->LastAdjacency = E;
    }
    else
    {
        V->LastAdjacency->Next = E;
        V->LastAdjacency = E;
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
        printf( "%d - ", V->Data );

        if ( ( E = V->AdjacencyList ) == NULL )
        {
            V = V->Next;
            printf( "\n" );
            continue;
        }

        while ( E != NULL )
        {
            printf( "%d[%d] ", E->To->Data, E->Weight );
            E = E->Next;
        }

        V = V->Next;
        printf( "\n" );
    }

    printf( "\n" );
}

void DFS( Vertex* V )
{
    Edge* E = NULL;

    // printf( "%d ", V->Data );

    V->Visited = Visited;

    E = V->AdjacencyList;
    while( E != NULL )
    {
        if ( E->To != NULL && E->To->Visited == NotVisited )
            DFS( E->To );

        E = E->Next;
    }
}

void PrimMST( Graph* G, Vertex* StartVertex, Graph* MST )
{
    PQNode StartNode = { 0, StartVertex };
    PQueue* PQ = Create( MAX_EDGE );

    Vertex* CurrVertex = NULL;
    Edge* CurrEdge = NULL;

    int* Weights = (int*)malloc( sizeof( int ) * G->VertexCount );
    Vertex** MSTVertices = (Vertex**)malloc( sizeof( Vertex* ) * G->VertexCount );
    Vertex** Fringes = (Vertex**)malloc( sizeof( Vertex* ) * G->VertexCount );
    Vertex** Precedences = (Vertex**)malloc( sizeof( Vertex* ) * G->VertexCount );

    CurrVertex = G->Vertices;
    int i = 0;
    // Traverse all nodes in given graph
    while ( CurrVertex != NULL )
    {
        Vertex* NewVertex = CreateVertex( CurrVertex->Data );
        AddVertex( MST, NewVertex ); // There are only Vertices in MST

        Fringes[i] = NULL;
        Precedences[i] = NULL;
        MSTVertices[i] = NewVertex;
        Weights[i] = MAX_WEIGHT+1;

        i++;
        CurrVertex = CurrVertex->Next;
    }

    Enqueue( PQ, StartNode );

    while ( PQ->UsedSize != 0 )
    {
        PQNode* Popped;
        // Select target vertex
        Popped = Dequeue( PQ );

        CurrVertex = (Vertex*)Popped->Data;
        Fringes[CurrVertex->Index] = CurrVertex;
        CurrEdge = CurrVertex->AdjacencyList;

        // Check selected target vertex's "Edges"
        while ( CurrEdge != NULL )
        {
            Vertex* TargetVertex = CurrEdge->To; // connected vertex to selected target vertex

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

void KruskalMST( Graph* G, Graph* MST )
{
    Vertex* CurrVertex = NULL;
    Vertex** MSTVertices = (Vertex**)malloc( sizeof( Vertex* ) * G->VertexCount );
    DSet** VertexSet = (DSet**)malloc( sizeof( DSet* ) * G->VertexCount );
    PQueue* PQ = Create( MAX_EDGE );

    CurrVertex = G->Vertices;
    int i = 0;
    while ( CurrVertex != NULL )
    {
        Edge* CurrEdge = NULL;

        VertexSet[i] = MakeDSetNode( CurrVertex );
        MSTVertices[i] = CreateVertex( CurrVertex->Data );
        AddVertex( MST, MSTVertices[i] ); // There are only Vertices in MST

        // Put every edges of every vertices in priority queue
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
        PQNode* Popped;

        Popped = Dequeue( PQ ); // Pop the most efficient edge
        CurrEdge = (Edge*)Popped->Data;

        fromIdx = CurrEdge->From->Index;
        toIdx = CurrEdge->To->Index;

        // Check cycle
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

Vertex** Dijkstra( Graph* G, Vertex* StartVertex, Graph* DijkstraGraph )
{
    PQNode StartNode = { 0, StartVertex };
    PQueue* PQ = Create( MAX_EDGE );

    Vertex* CurrVertex = NULL;
    Edge* CurrEdge = NULL;

    int* Weights = (int*)malloc( sizeof( int ) * G->VertexCount );
    Vertex** DijkstraVertices = (Vertex**)malloc( sizeof( Vertex* ) * G->VertexCount );
    Vertex** Fringes = (Vertex**)malloc( sizeof( Vertex* ) * G->VertexCount );
    Vertex** Precedences = (Vertex**)malloc( sizeof( Vertex* ) * G->VertexCount );

    CurrVertex = G->Vertices;
    int i = 0;
    // Traverse all nodes in given graph
    while ( CurrVertex != NULL )
    {
        Vertex* NewVertex = CurrVertex;
        AddVertex( DijkstraGraph, NewVertex ); // There is only Vertices in MST(DijkstraGraph)

        Fringes[i] = NULL;
        Precedences[i] = NULL;
        DijkstraVertices[i] = NewVertex;
        Weights[i] = MAX_WEIGHT+1;

        CurrVertex = CurrVertex->Next;
        i++;
    }

    Enqueue( PQ, StartNode );
    Weights[StartVertex->Index] = 0;

    while ( PQ->UsedSize != 0 )
    {
        PQNode* Popped;
        // Select target vertex
        Popped = Dequeue( PQ );

        CurrVertex = (Vertex*)Popped->Data;
        Fringes[CurrVertex->Index] = CurrVertex;
        CurrEdge = CurrVertex->AdjacencyList;

        // Check selected target vertex's "Edges"
        while ( CurrEdge != NULL )
        {
            Vertex* TargetVertex = CurrEdge->To; // connected vertex to selected target vertex

            if ( Fringes[TargetVertex->Index] == NULL // not visited
                && Weights[CurrVertex->Index] + CurrEdge->Weight < Weights[TargetVertex->Index] ) // Select most fast parent path
            {
                PQNode NewNode = { Weights[CurrVertex->Index] + CurrEdge->Weight, TargetVertex };
                Enqueue( PQ, NewNode );

                // Update datas(which of the connected vertex)
                Precedences[TargetVertex->Index] = CurrEdge->From;
                Weights[TargetVertex->Index] = Weights[CurrVertex->Index] + CurrEdge->Weight;
            }

            CurrEdge = CurrEdge->Next;
        }
    }

    for ( i = 0; i < G->VertexCount; i++ )
    {
        int fromIdx, toIdx;

        if ( Precedences[i] == NULL )
            continue;

        fromIdx = Precedences[i]->Index;
        toIdx = i;

        // Now we have Vertices and Edges in MST
        AddEdge( DijkstraVertices[fromIdx], CreateEdge( DijkstraVertices[fromIdx], DijkstraVertices[toIdx], Weights[i] ) );
    }

    free( Fringes );
    free( Weights );
    free( DijkstraVertices );

    DestroyPQueue( PQ );

    return Precedences;
}