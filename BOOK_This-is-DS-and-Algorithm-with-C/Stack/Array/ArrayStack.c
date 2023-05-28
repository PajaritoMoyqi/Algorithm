#include "ArrayStack.h"

void AS_CreateStack( ArrayStack** Stack, int Capacity )
{
    (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

    (*Stack)->Nodes = (Node*)malloc(sizeof(Node)*Capacity);

    (*Stack)->Capacity = Capacity;
    (*Stack)->Top = -1;
}

void AS_DestroyStack( ArrayStack* Stack )
{
    free(Stack->Nodes);
    free(Stack);
}

void AS_Push( ArrayStack* Stack, ElementType Data )
{
    Stack->Top++;
    // Why should we need to use "."? Why -> is not working?
    Stack->Nodes[Stack->Top].Data = Data;
}

ElementType AS_Pop( ArrayStack* Stack )
{
    int Position = Stack->Top--; // -- is at back, so variable 'Position' gets Stack->pop as a value
    return Stack->Nodes[Position].Data;
}

ElementType AS_Top( ArrayStack* Stack )
{
    return Stack->Nodes[Stack->Top].Data;
}

int AS_GetSize( ArrayStack* Stack )
{
    return Stack->Top + 1;
}

int AS_IsEmpty( ArrayStack* Stack )
{
    return (Stack->Top == -1);
}

int AS_IsFull( ArrayStack* Stack )
{
    return (Stack->Top + 1 == Stack->Capacity);
}