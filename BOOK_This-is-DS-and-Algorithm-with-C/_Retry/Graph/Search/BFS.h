#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct LQNode
{
    char* Data;
    struct LQNode* Next;
} LQNode;

typedef struct LQ
{
    LQNode* Front;
    LQNode* Rear;
    int Cnt;
} LQ;

void CreateLQ( LQ** Queue );
LQNode* CreateLQNode( char* data );
void LQEnqueue( LQ* Queue, LQNode* N );
LQNode* LQDequeue( LQ* Queue );
void DestroyLQNode( LQNode* N );
void DestroyLQ( LQ* Queue );


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

Graph* CreateGraph(  );
Vertex* CreateVertex( ElemType data );
Edge* CreateEdge( Vertex* From, Vertex* To, int weight );
void DestroyEdge( Edge* E );
void DestroyVertex( Vertex* V );
void DestroyGraph( Graph* G );

void AddVertex( Graph* G, Vertex* V );
void AddEdge( Vertex* V, Edge* E );

void PrintGraph( Graph* G );


// declarations
void BFS( Vertex* V, LQ* Q );