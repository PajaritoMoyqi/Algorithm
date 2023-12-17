#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define MAX_WEIGHT 99999 // Dijkstra

// Priority Queue
typedef int PriorityType;

typedef struct PQNode
{
    PriorityType Priority;
    void* Data;
} PQNode;

typedef struct PQueue
{
    PQNode* Nodes;
    int Capacity;
    int UsedSize;
} PQueue;

// declarations
PQueue* Create( int size );
void DestroyPQueue( PQueue* H );

int GetParentIdx( int idx );
int SwapNodes( PQueue* H, int idx1, int idx2 );
void Enqueue( PQueue* H, ElemType data );
int GetLeftChildIdx( int idx );
void Dequeue( PQueue* H, PQNode* RemovedRoot );

// Graph
enum VisitMode
{
    Visited,
    NotVisited
};

typedef int ElemType;

typedef struct Vertex
{
    int Visited;
    int Index;
    ElemType Data;

    struct Vertex* Next;
    struct Edge* AdjacencyList;
} Vertex;
typedef struct Edge
{
    int Weight;
    struct Edge* Next;
    struct Vertex* From;
    struct Vertex* To;
} Edge;
typedef struct Graph
{
    Vertex* Vertices;
    int VertexCount;
} Graph;

// declarations
Graph* CreateGraph(  );
Vertex* CreateVertex( ElemType data );
Edge* CreateEdge( Vertex* From, Vertex* To, int weight );
void DestroyEdge( Edge* E );
void DestroyVertex( Vertex* V );
void DestroyGraph( Graph* G );

void AddVertex( Graph* G, Vertex* V );
void AddEdge( Vertex* V, Edge* E );

void PrintGraph( Graph* G );


// Dijkstra
void Dijkstra( Graph* G, Vertex* StartVertex, Graph* DijkstraGraph );