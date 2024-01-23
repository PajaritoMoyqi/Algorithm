#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

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

    printf( "%d ", V->Data );

    V->Visited = Visited;

    E = V->AdjacencyList;
    while( E != NULL )
    {
        if ( E->To != NULL && E->To->Visited == NotVisited )
            DFS( E->To );

        E = E->Next;
    }
}

typedef int PriorityType;

typedef struct tagPQNode
{
    int Data;
    PriorityType Priority;
} PQNode;

typedef struct tagPriorityQueue
{
    PQNode* Nodes;
    int Capacity;
    int UsedSize;
} PriorityQueue;

PriorityQueue* PQ_Create( int InitialSize )
{
    PriorityQueue* NewPQ = (PriorityQueue*)malloc( sizeof( PriorityQueue ) );
    NewPQ->Capacity = InitialSize;
    NewPQ->UsedSize = 0;
    NewPQ->Nodes = (PQNode*)malloc( sizeof( PQNode ) * NewPQ->Capacity );

    return NewPQ;
}

void PQ_Destory( PriorityQueue* PQ )
{
    free( PQ->Nodes );
    free( PQ );
}

int PQ_GetParent( int Index )
{
    return (int)((Index - 1) / 2);
}

int PQ_GetLeftChild( int Index )
{
    return (2 * Index) + 1;
}

void PQ_PrintNodes( PriorityQueue* PQ )
{
    int i = 0;
    for( i = 0; i < PQ->UsedSize; i++ )
        printf( "%d ", PQ->Nodes[i].Data );

    printf( "\n" );
}

int PQ_IsEmpty( PriorityQueue* PQ )
{
    return (PQ->UsedSize == 0);
}

void PQ_SwapNodes( PriorityQueue* PQ, int Index1, int Index2 )
{
    int CopySize = sizeof( PQNode );
    PQNode* Temp = (PQNode*)malloc( CopySize );

    memcpy( Temp, &PQ->Nodes[Index1], CopySize );
    memcpy( &PQ->Nodes[Index1], &PQ->Nodes[Index2], CopySize );
    memcpy( &PQ->Nodes[Index2], Temp, CopySize );

    free( Temp );
}

void PQ_Enqueue( PriorityQueue* PQ, PQNode NewNode )
{
    int CurrentPosition = PQ->UsedSize;
    int ParentPosition = PQ_GetParent( CurrentPosition );

    if( PQ->UsedSize == PQ->Capacity )
    {
        if( PQ->Capacity == 0 )
            PQ->Capacity = 1;

        PQ->Capacity *= 2;
        PQ->Nodes = (PQNode*)realloc( PQ->Nodes, sizeof( PQNode ) * PQ->Capacity );
    }

    PQ->Nodes[CurrentPosition] = NewNode;

    while (
        CurrentPosition > 0 &&
        (
            (PQ->Nodes[CurrentPosition].Priority < PQ->Nodes[ParentPosition].Priority) ||
            ((PQ->Nodes[CurrentPosition].Priority == PQ->Nodes[ParentPosition].Priority) && (PQ->Nodes[CurrentPosition].Data < PQ->Nodes[ParentPosition].Data))
        )
    ) // changeable point
    {
        PQ_SwapNodes( PQ, CurrentPosition, ParentPosition );

        CurrentPosition = ParentPosition;
        ParentPosition = PQ_GetParent( CurrentPosition );
    }

    PQ->UsedSize++;
}
void PQ_EnqueueMAX( PriorityQueue* PQ, PQNode NewNode )
{
    int CurrentPosition = PQ->UsedSize;
    int ParentPosition = PQ_GetParent( CurrentPosition );

    if( PQ->UsedSize == PQ->Capacity )
    {
        if( PQ->Capacity == 0 )
            PQ->Capacity = 1;

        PQ->Capacity *= 2;
        PQ->Nodes = (PQNode*)realloc( PQ->Nodes, sizeof( PQNode ) * PQ->Capacity );
    }

    PQ->Nodes[CurrentPosition] = NewNode;

    while (
        CurrentPosition > 0 &&
        (
            (PQ->Nodes[CurrentPosition].Priority > PQ->Nodes[ParentPosition].Priority) ||
            ((PQ->Nodes[CurrentPosition].Priority == PQ->Nodes[ParentPosition].Priority) && (PQ->Nodes[CurrentPosition].Data > PQ->Nodes[ParentPosition].Data))
        )
    ) // changeable point
    {
        PQ_SwapNodes( PQ, CurrentPosition, ParentPosition );

        CurrentPosition = ParentPosition;
        ParentPosition = PQ_GetParent( CurrentPosition );
    }

    PQ->UsedSize++;
}


void PQ_Dequeue( PriorityQueue* PQ, PQNode* Root )
{
    int ParentPosition = 0;
    int LeftPosition = 0;
    int RightPosition = 0;

    memcpy( Root, &PQ->Nodes[0], sizeof( PQNode ) );
    memset( &PQ->Nodes[0], 0, sizeof( PQNode ) );

    PQ->UsedSize--;
    PQ_SwapNodes( PQ, 0, PQ->UsedSize );

    LeftPosition = PQ_GetLeftChild( 0 );
    RightPosition = LeftPosition + 1;

    while( 1 )
    {
        int SelectedChild = 0;

        if( LeftPosition >= PQ->UsedSize )
            break;

        if( RightPosition >= PQ->UsedSize )
            SelectedChild = LeftPosition;
        else
        {
            if (
                (PQ->Nodes[LeftPosition].Priority > PQ->Nodes[RightPosition].Priority) ||
                ((PQ->Nodes[LeftPosition].Priority == PQ->Nodes[RightPosition].Priority) && (PQ->Nodes[LeftPosition].Data > PQ->Nodes[RightPosition].Data))
            ) // changeable point
                SelectedChild = RightPosition;
            else
                SelectedChild = LeftPosition;
        }

        if (
            (PQ->Nodes[SelectedChild].Priority < PQ->Nodes[ParentPosition].Priority) ||
            ((PQ->Nodes[SelectedChild].Priority == PQ->Nodes[ParentPosition].Priority) && (PQ->Nodes[SelectedChild].Data < PQ->Nodes[ParentPosition].Data))
        ) // changeable point
        {
            PQ_SwapNodes( PQ, ParentPosition, SelectedChild );
            ParentPosition = SelectedChild;
        }
        else
            break;

        LeftPosition = PQ_GetLeftChild( ParentPosition );
        RightPosition = LeftPosition + 1;
    }

    if( PQ->UsedSize < (PQ->Capacity / 2) )
    {
        PQ->Capacity /= 2;
        PQ->Nodes = (PQNode*)realloc( PQ->Nodes, sizeof( PQNode ) * PQ->Capacity );
    }
}
void PQ_DequeueMAX( PriorityQueue* PQ, PQNode* Root )
{
    int ParentPosition = 0;
    int LeftPosition = 0;
    int RightPosition = 0;

    memcpy( Root, &PQ->Nodes[0], sizeof( PQNode ) );
    memset( &PQ->Nodes[0], 0, sizeof( PQNode ) );

    PQ->UsedSize--;
    PQ_SwapNodes( PQ, 0, PQ->UsedSize );

    LeftPosition = PQ_GetLeftChild( 0 );
    RightPosition = LeftPosition + 1;

    while( 1 )
    {
        int SelectedChild = 0;

        if ( LeftPosition >= PQ->UsedSize )
            break;

        if ( RightPosition >= PQ->UsedSize )
            SelectedChild = LeftPosition;
        else
        {
            if (
                PQ->Nodes[LeftPosition].Priority < PQ->Nodes[RightPosition].Priority ||
                ((PQ->Nodes[LeftPosition].Priority == PQ->Nodes[RightPosition].Priority) && (PQ->Nodes[LeftPosition].Data < PQ->Nodes[RightPosition].Data))
            ) // changeable point
                SelectedChild = RightPosition;
            else
                SelectedChild = LeftPosition;
        }

        if (
            PQ->Nodes[SelectedChild].Priority > PQ->Nodes[ParentPosition].Priority ||
            ((PQ->Nodes[SelectedChild].Priority == PQ->Nodes[ParentPosition].Priority) && (PQ->Nodes[SelectedChild].Data > PQ->Nodes[ParentPosition].Data))
        ) // changeable point
        {
            PQ_SwapNodes( PQ, ParentPosition, SelectedChild );
            ParentPosition = SelectedChild;
        }
        else
            break;

        LeftPosition = PQ_GetLeftChild( ParentPosition );
        RightPosition = LeftPosition + 1;
    }

    if ( PQ->UsedSize < (PQ->Capacity / 2) )
    {
        PQ->Capacity /= 2;
        PQ->Nodes = (PQNode*)realloc( PQ->Nodes, sizeof( PQNode ) * PQ->Capacity );
    }
}


int cmp2( const void* _elem1, const void* _elem2 )
{
    PQNode* elem1 = (PQNode*)_elem1;
    PQNode* elem2 = (PQNode*)_elem2;

    if ( elem1->Data == elem2->Data )
    {
        if ( elem1->Priority > elem2->Priority )
            return 1;
        else if ( elem1->Priority < elem2->Priority )
            return -1;
        else
            return 0;
    }
    else
    {
        if ( elem1->Data > elem2->Data )
            return 1;
        else if ( elem1->Data < elem2->Data )
            return -1;
        else
            return 0;
    }
}
typedef struct LQNode
{
    int Data;
    struct LQNode* Next;
} LQNode;

typedef struct LQ
{
    LQNode* Front;
    LQNode* Rear;
    int Cnt;
} LQ;

void CreateLQ( LQ** Queue )
{
    (*Queue) = ( LQ* )malloc( sizeof( LQ ) );

    (*Queue)->Front = NULL;
    (*Queue)->Rear = NULL;
    (*Queue)->Cnt = 0;
}
LQNode* CreateLQNode( int data )
{
    LQNode* N = (LQNode*)malloc( sizeof( LQNode ) );
    
    N->Data = data;
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

void BFS_LQ( Vertex* V, LQ* LQ, Vertex** VertexSet )
{
    Edge* E = NULL;

    printf( "%d ", V->Data );
    
    V->Visited = Visited;

    LQEnqueue( LQ, CreateLQNode( V->Data ) );

    while( LQ->Cnt != 0 )
    {
        LQNode* PoppedNode = LQDequeue( LQ );
        V = VertexSet[PoppedNode->Data];
        E = V->AdjacencyList;

        while ( E != NULL )
        {
            V = E->To;

            if ( V != NULL && V->Visited == NotVisited )
            {
                printf( "%d ", V->Data );
                V->Visited = Visited;
                LQEnqueue( LQ, CreateLQNode( V->Data ) );
            }

            E = E->Next;
        }
    }
}
void BFS_PQ( Vertex* V, PriorityQueue* PQ, Vertex** VertexSet )
{
    Edge* E = NULL;

    V->Visited = Visited;

    PQNode N = { V->Data, 0 };
    PQ_Enqueue( PQ, N );

    while( PQ->UsedSize != 0 )
    {
        // printf( "before pop\n" );
        // PQ_PrintNodes( PQ );
        PQNode PoppedNode;
        PQ_Dequeue( PQ, &PoppedNode );
        V = VertexSet[PoppedNode.Data];
        E = V->AdjacencyList;

        // printf( "after pop\n" );
        // PQ_PrintNodes( PQ );
        // printf( "---Data---\n" );
        // printf( "%d %d\n", V->Data, PoppedNode.Priority );
        printf( "%d ", V->Data );
        while ( E != NULL )
        {
            V = E->To;

            // printf( "Candidate: %d\n", V->Data );
            if ( V != NULL && V->Visited == NotVisited )
            {
                // printf( "Enqueue: %d\n", V->Data );
                V->Visited = Visited;
                PQNode N = { V->Data, PoppedNode.Priority + 1 };
                PQ_Enqueue( PQ, N );
            }

            E = E->Next;
        }
    }
}

typedef struct Relation
{
    int x;
    int y;
} Relation;
int cmp ( const void* x, const void* y )
{
    Relation* p1 = (Relation*)x;
    Relation* p2 = (Relation*)y;

    if ( p1->x == p2->x )
    {
        return p1->y - p2->y;
    }
    else
        return p1->x - p2->x;
}

int main( void )
{
    int n, m, v;
    scanf( "%d%d%d", &n, &m, &v );

    Graph* G = CreateGraph(  );

    Vertex* VertexSet[n+1];
    int i;
    for ( i = 1; i <= n; i++ )
        VertexSet[i] = CreateVertex( i );

    for ( i = 1; i <= n; i++ )
        AddVertex( G, VertexSet[i] );

    Relation EdgeSet[m];
    int tmpX, tmpY;
    for ( i = 0; i < m; i++ )
    {
        scanf( "%d%d", &tmpX, &tmpY );
        EdgeSet[i].x = tmpX < tmpY ? tmpX : tmpY;
        EdgeSet[i].y = tmpX > tmpY ? tmpX : tmpY;
    }
    qsort( EdgeSet, m, sizeof( Relation ), cmp );

    // for ( i = 0; i < m; i++ )
    //     printf( "%d, %d\n", EdgeSet[i].x, EdgeSet[i].y );

    int a, b, prevA = -1, prevB = -1;
    for ( i = 0; i < m; i++ )
    {
        a = EdgeSet[i].x;
        b = EdgeSet[i].y;
        if ( prevA == a && prevB == b ) continue;

        // printf( "Edge: From %d to %d\n", a, b );
        AddEdge( VertexSet[a], CreateEdge( VertexSet[a], VertexSet[b], 0 ) );
        AddEdge( VertexSet[b], CreateEdge( VertexSet[b], VertexSet[a], 0 ) );

        prevA = a;
        prevB = b;
    }

    // printf( "DFS\n" );
    DFS( VertexSet[v] );
    puts( "" );

    // printf( "BFS\n" );
    for ( i = 1; i <= n; i++ )
        VertexSet[i]->Visited = NotVisited;

    // PriorityQueue* PQ = PQ_Create( n );
    // BFS_PQ( VertexSet[v], PQ, VertexSet );
    LQ* Queue = NULL;
    CreateLQ( &Queue );
    BFS_LQ( VertexSet[v], Queue, VertexSet );

    return 0;
}