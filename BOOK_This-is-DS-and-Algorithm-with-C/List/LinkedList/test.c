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

    for ( i = 0; i < 5; i++ )
    {
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }

    return 0;
}