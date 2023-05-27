#include "LinkedList.h"

int main( void )
{
    int i = 0;
    int Count = 0;
    Node* List = NULL;
    Node* Current = NULL;
    Node* NewNode = NULL;
    
    // print variables if needed
    // printf("&List: %p\nList: %p\n", &List, List);

    // Initialization
    for ( i = 0; i < 5; i++ )
    {
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }

    // New head
    NewNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&List, NewNode);
    NewNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&List, NewNode);

    // Print list
    Count = SLL_GetNodeCount(List);

    for ( i = 0; i < Count; i++ )
    {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d]: %d\n", i, Current->Data);
    }

    // Insert node
    Current = SLL_GetNodeAt(List, 2);
    NewNode = SLL_CreateNode(3000);
    SLL_InsertAfter(Current, NewNode);
    NewNode = SLL_CreateNode(4000);
    SLL_InsertBefore(&List, Current, NewNode);

    // Print list again
    Count = SLL_GetNodeCount(List);

    for ( i = 0; i < Count; i++ )
    {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d]: %d\n", i, Current->Data);
    }

    // Remove and destroy all nodes from Heap
    for ( i = 0; i < Count; i++ )
    {
        Current = SLL_GetNodeAt(List, 0);

        if ( Current != NULL )
        {
            SLL_RemoveNode(&List, Current);
            SLL_DestroyNode(Current);
        }
    }

    // Or destory it at once
    // SLL_DestroyAllNodes(&List);

    return 0;
}