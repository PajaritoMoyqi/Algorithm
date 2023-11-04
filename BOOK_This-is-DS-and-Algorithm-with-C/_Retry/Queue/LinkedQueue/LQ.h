#ifndef LINKEDQUEUE_H
# define LINKEDQUEUE_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct LQNode
{
    char* Data;
    struct LQNode* Next;
} LQNode;

typedef struct LQ
{
    LQNode* Front;
    LQNode* Rear;
    int Cnt;
} LQ;

// declarations
void CreateLQ( LQ** Queue );
LQNode* CreateLQNode( char* data );
void LQEnqueue( LQ* Queue, LQNode* N );
LQNode* LQDequeue( LQ* Queue );
void DestroyLQNode( LQNode* N );
void DestroyLQ( LQ* Queue );


#endif