#include "CircularDoublyLinkedList.h"

int main()
{
    int i = 0;
    int Count = 0;
    Node* List = NULL;
    Node* NewNode = NULL;
    Node* Current = NULL;

    // create
    for ( i = 0; i < 5; i++ )
    {
        NewNode = CDLL_CreateNode( i );
        CDLL_AppendNode( &List, NewNode );
    }

    // print list
    Count = CDLL_GetNodeCount( List );
    for ( i = 0; i < Count; i++ )
    {
        Current = CDLL_GetNodeAt( List, i );
        printf("List[%d]: %d\n", i, Current->Data);
    }

    // insert
    Current = CDLL_GetNodeAt( List, 2 );
    NewNode = CDLL_CreateNode( 3000 );
    CDLL_InsertAfter( Current, NewNode );

    // remove and destroy
    CDLL_RemoveNode( &List, Current );
    CDLL_DestoryNode( Current );

    // print list
    Count = CDLL_GetNodeCount( List );
    for ( i = 0; i < Count*2; i++ )
    {
        Current = CDLL_GetNodeAt( List, i );
        printf("List[%d]: %d\n", i, Current->Data);
    }

    // remove and destory all nodes
    Count = CDLL_GetNodeCount( List );
    for ( i = 0; i < Count; i++ )
    {
        Current = CDLL_GetNodeAt( List, 0 );

        if ( Current != NULL )
        {
            CDLL_RemoveNode( &List, Current );
            CDLL_DestoryNode( Current );
        }
    }

    return 0;
}