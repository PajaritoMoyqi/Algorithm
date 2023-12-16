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