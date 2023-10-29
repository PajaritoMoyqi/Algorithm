#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

# include <stdio.h>
# include <stdlib.h>

typedef int Element;

typedef struct CLLNode
{
   Element Data;
   struct CLLNode* PrevCLLNode;
   struct CLLNode* NextCLLNode;
} CLLNode;

// declarations of method
CLLNode* CreateCLLNode( Element data );
void AppendCLLNode( CLLNode** Head, CLLNode* New );
void InsertCLLNode( CLLNode* Target, CLLNode* New );
void RemoveCLLNode( CLLNode** Head, CLLNode* Target );
CLLNode* SearchCLLNode( CLLNode* Head, int idx );
int LengthCLL( CLLNode* Head );
void DestroyCLLNode( CLLNode* Node );

#endif