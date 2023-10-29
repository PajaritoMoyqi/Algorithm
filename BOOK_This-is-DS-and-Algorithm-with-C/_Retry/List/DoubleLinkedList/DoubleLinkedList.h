#ifndef LINKEDLIST_H
#define LINKEDLIST_H

# include <stdio.h>
# include <stdlib.h>

typedef int Element;

typedef struct DLLNode
{
   Element Data;
   struct DLLNode* PrevDLLNode;
   struct DLLNode* NextDLLNode;
} DLLNode;

// declarations of method
DLLNode* CreateDLLNode( Element data );
void AppendDLLNode( DLLNode** Head, DLLNode* New );
void InsertDLLNode( DLLNode* Target, DLLNode* New );
void InsertDLLHead( DLLNode** Head, DLLNode* New );
void RemoveDLLNode( DLLNode** Head, DLLNode* Target );
DLLNode* SearchDLLNode( DLLNode* Head, int idx );
int LengthDLL( DLLNode* Head );
void DestroyDLLNode( DLLNode* Node );

#endif