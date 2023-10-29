#ifndef LINKEDLIST_H
#define LINKEDLIST_H

# include <stdio.h>
# include <stdlib.h>

typedef int Element;

typedef struct LLNode
{
   Element Data;
   struct LLNode* NextLLNode;
} LLNode;

// declarations of method
LLNode* CreateLLNode( Element data );
void AppendLLNode( LLNode** Head, LLNode* New );
void InsertLLNode( LLNode* Target, LLNode* New );
void InsertLLHead( LLNode** Head, LLNode* New );
void RemoveLLNode( LLNode** Head, LLNode* Target );
LLNode* SearchLLNode( LLNode* Head, int idx );
int LengthLL( LLNode* Head );
void DestroyLLNode( LLNode* Node );

#endif