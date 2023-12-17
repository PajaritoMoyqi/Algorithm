#include <stdio.h>
#include <stdlib.h>


typedef int Element;

typedef struct LLNode
{
   Element Data;
   struct LLNode* NextLLNode;
} LLNode;

LLNode* CreateLLNode( Element data );
void AppendLLNode( LLNode** Head, LLNode* New );
void InsertLLNode( LLNode* Target, LLNode* New );
void InsertLLHead( LLNode** Head, LLNode* New );
void RemoveLLNode( LLNode** Head, LLNode* Target );
LLNode* SearchLLNode( LLNode* Head, int idx );
int LengthLL( LLNode* Head );
void DestroyLLNode( LLNode* Node );


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
void TSort_DFS( Vertex* V, LLNode** L );
void TSort( Vertex* V, LLNode** L );