#ifndef LINKEDLISTSTACK_H
# define LINKEDLISTSTACK_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct LLSNode
{
    char* Data;
    struct LLSNode* NextLLSNode;
} LLSNode;

typedef struct LLStack
{
    LLSNode* List;
    LLSNode* Top;
} LLStack;

// decalrations
void CreateLLS( LLStack** Stack );
LLSNode* CreateLLSNode( char* data );
void LLSPush( LLStack* Stack, LLSNode* New );
LLSNode* LLSPop( LLStack* Stack );
int LLSIsEmpty( LLStack* Stack );
void DestroyLLSNode( LLSNode* Target );
void DestroyLLS( LLStack* Stack );

#endif