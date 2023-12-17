#include "TSort.h"

LLNode* CreateLLNode( Element data )
{
    LLNode* Head = (LLNode*)malloc( sizeof( LLNode ) );

    Head->Data = data;
    Head->NextLLNode = NULL;

    return Head;
}

void AppendLLNode( LLNode** Head, LLNode* New )
{
    if ( (*Head) == NULL )
        *Head = New;
    else
    {
        LLNode* Tail = (*Head);
        while ( Tail->NextLLNode == NULL )
            Tail = Tail->NextLLNode;

        Tail->NextLLNode = New;
    }
}

void InsertLLNode( LLNode* Target, LLNode* New )
{
    New->NextLLNode = Target->NextLLNode;
    Target->NextLLNode = New;
}
void InsertLLHead( LLNode** Head, LLNode* New )
{
    if ( (*Head) == NULL )
        *Head = New;
    else
    {
        New->NextLLNode = (*Head);
        *Head = New;
    }
}

void RemoveLLNode( LLNode** Head, LLNode* Target )
{
    if ( (*Head) == Target )
        *Head = Target->NextLLNode;
    else
    {
        LLNode* Candidate = (*Head);
        while( Candidate != NULL && Candidate->NextLLNode != Target )
            Candidate = Candidate->NextLLNode;

        if( Candidate != NULL )
            Candidate->NextLLNode = Target->NextLLNode;
    }
}

LLNode* SearchLL( LLNode* Head, int idx )
{
    LLNode* Candidate = Head;
    while( Candidate != NULL && (--idx) >= 0 )
        Candidate = Candidate->NextLLNode;

    return Candidate;
}
int LengthLL( LLNode* Head )
{
    int cnt = 0;

    LLNode* Current = Head;
    while ( Current != NULL )
    {
        Current = Current->NextLLNode;
        cnt++;
    }

    return cnt;
}

void DestroyLLNode( LLNode* Node )
{
    free( Node );
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

// Topological Sort

void TSort_DFS( Vertex* V, LLNode** L )
{
    LLNode* NewHead = NULL;
    Edge* E = NULL;

    V->Visited = Visited;

    E = V->AdjacencyList;
    while ( E != NULL )
    {
        if ( E->To != NULL && E->To->Visited == NotVisited )
            TSort_DFS( E->To, L );

        E = E->Next;
    }

    NewHead = CreateLLNode( V );
    InsertLLHead( L, NewHead );
}

void TSort( Vertex* V, LLNode** L )
{
    while ( V != NULL && V->Visited == NotVisited )
    {
        TSortDFS( V, L );
        
        V = V->Next;
    }
}