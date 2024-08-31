#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _LQNode
{
    int Data;
    struct _LQNode* Next;
} LQNode;

typedef struct _LQ
{
    LQNode* Front;
    LQNode* Rear;
    int Cnt;
} LQ;

void CreateLQ( LQ** Queue );
LQNode* CreateLQNode( int data );
void LQEnqueue( LQ* Queue, LQNode* N );
LQNode* LQDequeue( LQ* Queue );
void DestroyLQNode( LQNode* N );
void DestroyLQ( LQ* Queue );

#define MAX_LEN 20

LQ* Q[MAX_LEN+1];

int main( void )
{
    int n, windowSize;
    scanf( "%d%d", &n, &windowSize );

    int i;
    for ( i = 1; i <= MAX_LEN; i++ )
        CreateLQ( &Q[i] );

    char str[MAX_LEN+1];
    long long cnt = 0;
    for ( i = 0; i < n; i++ )
    {
        scanf( "%s", str );
        int len = strlen( str );

        LQNode* NewNode = CreateLQNode( i );
        while ( Q[len]->Cnt && i - Q[len]->Front->Data > windowSize )
            LQDequeue( Q[len] );

        cnt += Q[len]->Cnt;
        LQEnqueue( Q[len], NewNode );
    }

    printf( "%lld", cnt );

    return 0;
}

void CreateLQ( LQ** Queue )
{
    (*Queue) = ( LQ* )malloc( sizeof( LQ ) );

    (*Queue)->Front = NULL;
    (*Queue)->Rear = NULL;
    (*Queue)->Cnt = 0;
}
LQNode* CreateLQNode( int data )
{
    LQNode* N = (LQNode*)malloc( sizeof( LQNode ) );
    
    N->Data = data;
    N->Next = NULL;

    return N;
}

void LQEnqueue( LQ* Queue, LQNode* N )
{
    if ( Queue->Front == NULL )
    {
        Queue->Front = N;
        Queue->Rear = N;
    }
    else
    {
        Queue->Rear->Next = N;
        Queue->Rear = N;
    }
    
    Queue->Cnt++;
}
LQNode* LQDequeue( LQ* Queue )
{
    LQNode* Front = Queue->Front;

    if ( Queue->Front->Next == NULL )
    {
        Queue->Front = NULL;
        Queue->Rear = NULL;
    }
    else
        Queue->Front = Queue->Front->Next;

    Queue->Cnt--;

    return Front;
}

void DestroyLQNode( LQNode* N )
{
    free( N );
}
void DestroyLQ( LQ* Queue )
{
    while ( Queue->Front != NULL )
    {
        LQNode* Popped = LQDequeue( Queue );
        DestroyLQNode( Popped );
    }

    free( Queue );
}