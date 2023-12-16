void BFS( Vertex* V, LinkedQueue* Q )
{
    Edge* E = NULL;

    printf( "%d ", V->Data );
    
    V->Visited = Visited;

    Enqueue( Q, CreateNode( V ) );

    while( !IsEmpty( Q ) )
    {
        QNode* PoppedNode = Dequeue( Q );
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