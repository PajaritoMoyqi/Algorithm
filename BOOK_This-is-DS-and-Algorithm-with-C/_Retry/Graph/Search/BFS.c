#include "BFS.h"

// LinkedQueue
void CreateLQ( LQ** Queue )
{
    (*Queue) = ( LQ* )malloc( sizeof( LQ ) );

    (*Queue)->Front = NULL;
    (*Queue)->Rear = NULL;
    (*Queue)->Cnt = 0;
}
LQNode* CreateLQNode( char* data )
{
    LQNode* N = (LQNode*)malloc( sizeof( LQNode ) );
    
    N->Data = (char*)malloc( strlen( data ) + 1 );
    strcpy( N->Data, data );
    N->Next = NULL;

    return N;
}

void LQEnqueue( LQ* Queue, LQNode* N )
{
    if ( Queue->Front == NULL )
    {
        Queue->Front = N;
        Queue->Rear = N;
        Queue->Cnt++;
    }
    else
    {
        Queue->Rear->Next = N;
        Queue->Rear = N;
        Queue->Cnt++;
    }
}
LQNode* LQDequeue( LQ* Queue )
{
    LQNode* Front = Queue->Front;

    if ( Queue->Front->Next == NULL )
    {
        Queue->Front = NULL;
        Queue->Rear = NULL;
    }
    else
        Queue->Front = Queue->Front->Next;

    Queue->Cnt--;

    return Front;
}

void DestroyLQNode( LQNode* N )
{
    free( N->Data );
    free( N );
}
void DestroyLQ( LQ* Queue )
{
    while ( Queue->Front != NULL )
    {
        LQNode* Popped = LQDequeue( Queue );
        DestroyLQNode( Popped );
    }

    free( Queue );
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

// BFS

void BFS( Vertex* V, LQ* Q )
{
    Edge* E = NULL;

    printf( "%d ", V->Data );
    
    V->Visited = Visited;

    Enqueue( Q, CreateNode( V ) );

    while( !IsEmpty( Q ) )
    {
        LQNode* PoppedNode = Dequeue( Q );
        V = PoppedNode->Data;
        E = V->AdjacencyList;

        while ( E != NULL )
        {
            V = E->To;

            if ( V != NULL && V->Visited == NotVisited )
            {
                printf( "%d ", V->Data );
                V->Visited = Visited;
                Enqueue( Q, CreateNode( V ) );
            }

            E = E->Next;
        }
    }
}