#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct _LLNode
{
   Element Data;
   struct _LLNode* NextLLNode;
} LLNode;

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
    struct _Edge* LastAdjacency;
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
    Vertex* LastVertex;
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

void TSort_DFS( Vertex* V, LLNode** L );
void TSort( Vertex* V, LLNode** L );

LLNode* CreateLLNode( Element data );
void AppendLLNode( LLNode** Head, LLNode* New );
void InsertLLNode( LLNode* Target, LLNode* New );
void InsertLLHead( LLNode** Head, LLNode* New );
void RemoveLLNode( LLNode** Head, LLNode* Target );
LLNode* SearchLL( LLNode* Head, int idx );
int LengthLL( LLNode* Head );
void DestroyLLNode( LLNode* Node );

#define MAX_N 32000

int Visit[MAX_N+1];
int Ans[MAX_N+1];
int cnt = 0;

int main( void )
{
    int n, cmpN;
    scanf( "%d%d", &n, &cmpN );

    if ( n == 1 )
    {
        printf( "1" );
        return 0;
    }

    LLNode* SortedList = NULL;

    Graph* G = CreateGraph();
    Vertex* VertexSet[n+1];

    int i;
    Edge* E;
    int a, b;
    for ( i = 0; i < cmpN; i++ )
    {
        scanf( "%d%d", &a, &b );
        // printf( "(%d, %d)\n", a, b );
        if ( !Visit[a] )
        {
            // printf( "add (%d)\n", a );
            Visit[a] = Visited;
            VertexSet[a] = CreateVertex( a );
            AddVertex( G, VertexSet[a] );
        }
        if ( !Visit[b] )
        {
            // printf( "add (%d)\n", b );
            Visit[b] = Visited;
            VertexSet[b] = CreateVertex( b );
            AddVertex( G, VertexSet[b] );
        }

        E = CreateEdge( VertexSet[a], VertexSet[b], 0 );
        AddEdge( VertexSet[a], E );
    }

    // Vertex* V1 = G->Vertices;
    // while ( V1 != NULL )
    // {
    //     printf( "%d ", V1->Data );
    //     V1 = V1->Next;
    // }
    // puts( "" );

    TSort( G->Vertices, &SortedList );

    LLNode* CurrNode = SortedList;
    while ( CurrNode != NULL )
    {
        printf( "%d ", CurrNode->Data );
        CurrNode = CurrNode->NextLLNode;
    }

    for ( i = 1; i <= n; i++ )
        if ( !Visit[i] )
            printf( "%d ", i );

    // Vertex* CurrVertex = G->Vertices;
    // while ( CurrVertex != NULL )
    // {
    //     if ( CurrVertex->Visited )
    //     {
    //         CurrVertex = CurrVertex->Next;
    //         continue;
    //     }

    //     DFS( CurrVertex );
    //     CurrVertex = CurrVertex->Next;
    // }

    // cnt--;
    // for ( i = cnt; i >= 0; i-- )
    //     printf( "%d ", Ans[i] );

    return 0;
}

Graph* CreateGraph(  )
{
    Graph* G = (Graph*)malloc( sizeof( Graph ) );
    
    G->Vertices = NULL;
    G->LastVertex = NULL;
    G->VertexCount = 0;

    return G;
}
Vertex* CreateVertex( ElemType data )
{
    Vertex* V = (Vertex*)malloc( sizeof( Vertex ) );

    V->Data = data;
    V->Next = NULL;
    V->AdjacencyList = NULL;
    V->LastAdjacency = NULL;
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
    // printf( "latest vertex cnt: %d\n", G->VertexCount );
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

    Ans[cnt++] = V->Data;
}

void TSort_DFS( Vertex* V, LLNode** L )
{
    LLNode* NewHead = NULL;
    Edge* E = NULL;

    V->Visited = Visited;

    E = V->AdjacencyList;
    while ( E != NULL )
    {
        if ( E->To != NULL && E->To->Visited == NotVisited )
        {
            // printf( "Go further from %d to %d\n", E->From->Data, E->To->Data );
            TSort_DFS( E->To, L );
        }

        E = E->Next;
    }

    NewHead = CreateLLNode( V->Data );
    InsertLLHead( L, NewHead );
    // printf( "insert head: %d\n", V->Data );
}

void TSort( Vertex* V, LLNode** L )
{
    while ( V != NULL )
    {
        // printf( "before check - V: %d\n", V->Data );
        if ( V->Visited == Visited )
        {
            V = V->Next;
            continue;
        }
  
        TSort_DFS( V, L );

        // if ( V->Next != NULL )
        //     printf( "next check - V: %d\n", V->Next->Data );
        V = V->Next;
    }
}

// functions

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
        while ( Tail->NextLLNode != NULL )
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
        while ( Candidate != NULL && Candidate->NextLLNode != Target )
            Candidate = Candidate->NextLLNode;

        if( Candidate != NULL )
            Candidate->NextLLNode = Target->NextLLNode;
    }
}

LLNode* SearchLL( LLNode* Head, int idx )
{
    LLNode* Candidate = Head;
    while ( Candidate != NULL && (--idx) >= 0 )
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