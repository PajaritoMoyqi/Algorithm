#ifndef GRAPH_H
#define GRAPH_H

# include <stdio.h>
# include <stdlib.h>

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

#endif