#ifndef CIRCULARQUEUE_H
# define CIRCULARQUEUE_H

# include <stdio.h>
# include <stdlib.h>

typedef int ElementType;

typedef struct CQNode
{
    ElementType Data;
} CQNode;

typedef struct CQ
{
    int Capacity;
    int Front;
    int Rear;

    CQNode* CQNodes;
} CQ;

// declarations

#endif