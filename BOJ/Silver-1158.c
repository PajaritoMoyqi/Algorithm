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
    int n, k, i;
    scanf( "%d%d", &n, &k );

    LQ* Queue = NULL;
    CreateLQ( &Queue );

    LQNode* N;
    for ( i = 1; i <= n; i++ )
    {
        // printf( "for statement\n" );
        N = CreateLQNode( i );
        LQEnqueue( Queue, N );
    }

    int cnt;
    LQNode* Tmp = NULL;
    printf( "<" );
    
    while ( Queue->Front != NULL )
    {
        cnt = 0;
        while ( cnt != k )
        {
            cnt++;
            Tmp = LQDequeue( Queue );

            if ( !Queue->Cnt )
                goto end;

            if ( cnt == k )
                printf( "%d, ", Tmp->Data );
            else
                LQEnqueue( Queue, Tmp );
        }
    }

    end:
        printf( "%d>", Tmp->Data );

    return 0;
}