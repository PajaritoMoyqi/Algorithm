#ifndef EBTREE_H
#define EBTREE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef char ElemType;

typedef struct EBTNode
{
    struct EBTNode* Left;
    struct EBTNode* Right;

    ElemType Data;
} EBTNode;

// declarations

#endif