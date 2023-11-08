#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct LQNode
{
    int Data;
    struct LQNode* Next;
} LQNode;

typedef struct LQ
{
    LQNode* Front;
    LQNode* Rear;
    int Cnt;
} LQ;

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

int main( void )
{
    int n, i;
    scanf( "%d", &n );

    LQ* Queue = NULL;
    CreateLQ( &Queue );

    LQNode* N;
    for ( i = 1; i <= n; i++ )
    {
        // printf( "for statement\n" );
        N = CreateLQNode( i );
        LQEnqueue( Queue, N );
    }

    LQNode* Tmp = NULL;
    while ( Queue->Front != NULL )
    {
        // printf( "while statement\n" );
        // printf( "Queue->Front->Data: %d\n", Queue->Front->Data );
        Tmp = LQDequeue( Queue );
        printf( "%d ", Tmp->Data );

        if ( !Queue->Cnt )
            goto end;

        Tmp = LQDequeue( Queue );
        if ( !Queue->Cnt )
        {
            printf( "%d ", Tmp->Data );
            goto end;
        }
        else
            LQEnqueue( Queue, Tmp );
    }

    printf( "%d", Tmp->Data );

    end:
        return 0;
}