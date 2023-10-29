#include "AStack.h"

void CreateAS( ArrayStack** Stack, int capacity )
{
    (*Stack) = (ArrayStack*)malloc( sizeof( ArrayStack ) );

    (*Stack)->Nodes = (ASNode*)malloc( sizeof( ASNode ) * capacity );

    (*Stack)->Capacity = capacity;
    (*Stack)->Top = -1;
}

void ASPush( ArrayStack* Stack, Element data )
{
    Stack->Top++;
    Stack->Nodes[Stack->Top].Data = data;
}
Element ASPop( ArrayStack* Stack )
{
    int idx = Stack->Top--;
    return Stack->Nodes[idx].Data;
}

void DestroyAS( ArrayStack* Stack )
{
    free( Stack->Nodes );
    free( Stack );
}