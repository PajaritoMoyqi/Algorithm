#ifndef ARRAYSTACK_H
# define ARRAYSTACK_H

# include <stdio.h>
# include <stdlib.h>

typedef int Element;

typedef struct ASNode
{
    Element Data;
} ASNode;

typedef struct ArrayStack
{
    int Capacity;
    int Top;
    ASNode* Nodes;
} ArrayStack;

// declarations
void CreateAS( ArrayStack** Stack, int capacity );
void ASPush( ArrayStack* Stack, Element data );
Element ASPop( ArrayStack* Stack );
void DestroyAS( ArrayStack* Stack );

#endif