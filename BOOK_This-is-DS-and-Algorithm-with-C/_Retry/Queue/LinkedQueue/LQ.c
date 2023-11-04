#include <LQ.h>

void CreateLQ( LQ** Queue )
{
    (*Queue) = ( LQ* )malloc( sizeof( LQ ) );

    (*Queue)->Front = NULL;
    (*Queue)->Rear = NULL;
    (*Queue)->Cnt = 0;
}
LQNode* CreateLQNode( char* data )
{
    LQNode* N = (LQNode*)malloc( sizeof( LQNode ) );
    
    N->Data = (char*)malloc( strlen( data ) + 1 );
    strcpy( N->Data, data );
    N->Next = NULL;

    return N;
}

void LQEnqueue( LQ* Queue, LQNode* N )
{
    if ( Queue->Front == NULL )
    {
        Queue->Front = N;
        Queue->Rear = N;
        Queue->Cnt++;
    }
    else
    {
        Queue->Rear->Next = N;
        Queue->Rear = N;
        Queue->Cnt++;
    }
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
    free( N->Data );
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