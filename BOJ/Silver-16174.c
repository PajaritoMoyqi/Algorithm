#include <stdio.h>
#include <stdlib.h>

enum VisitMode
{
    NotVisited,
    Visited
};

typedef int ElemType;

typedef struct _Vertex
{
    int Visited;
    int Index;
    ElemType Data;

    struct _Vertex* Next;
    struct _Edge* AdjacencyList;
} Vertex;
typedef struct _Edge
{
    int Weight;
    struct _Edge* Next;
    struct _Vertex* From;
    struct _Vertex* To;
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
void DFS( Vertex* V );

int main( void )
{
    int n;
    scanf( "%d", &n );
    int len = n*n;

    Graph* G = CreateGraph();
    Vertex* VertexSet[len+1];
    int i;
    for ( i = 1; i <= len; i++ )
        VertexSet[i] = CreateVertex( i );

    int num;
    Edge* E;
    for ( i = 1; i <= len; i++ )
    {
        scanf( "%d", &num );

        if ( i == len )
            break;

        if ( !num )
            continue;
        
        // printf( "(%d), %d\n", i, num );
        if ( i % n != 0 && i + num <= ((i-1)/n + 1)*n )
        {
            // printf( "(%d) -> %d\n", i, i+num );
            E = CreateEdge( VertexSet[i], VertexSet[i + num], 0 );
            AddEdge( VertexSet[i], E );
        }
        if ( i % n != 1 && i - num > ((i-1)/n)*n )
        {
            // printf( "(%d) -> %d\n", i, i-num );
            E = CreateEdge( VertexSet[i], VertexSet[i - num], 0 );
            AddEdge( VertexSet[i], E );
        }
        if ( i + n*num <= len )
        {
            // printf( "(%d) -> %d\n", i, i + n*num );
            E = CreateEdge( VertexSet[i], VertexSet[i + n*num], 0 );
            AddEdge( VertexSet[i], E );
        }
        if ( i - n*num > 0 )
        {
            // printf( "(%d) -> %d\n", i, i - n*num );
            E = CreateEdge( VertexSet[i], VertexSet[i - n*num], 0 );
            AddEdge( VertexSet[i], E );
        }
    }
    for ( i = 1; i <= n; i++ )
        AddVertex( G, VertexSet[i] );

    DFS( VertexSet[1] );

    if ( VertexSet[len]->Visited )
        printf( "HaruHaru" );
    else
        printf( "Hing" );

    return 0;
}

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