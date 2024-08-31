#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElementType;

typedef struct _CQNode
{
    ElementType Data;
} CQNode;

typedef struct _CQ
{
    int Capacity;
    int Front;
    int Rear;

    CQNode* CQNodes;
} CQ;

void CreateCQ( CQ** Queue, int cap );
void CQEnqueue( CQ* Queue, ElementType data );
ElementType CQDequeue( CQ* Queue );
void DestroyCQ( CQ* Queue );

#define MAX_LEN 2000000

int main( void )
{
    int n;
    scanf( "%d", &n );

    CQ* Q;
    CreateCQ( &Q, MAX_LEN );

    char command[6];
    int num;
    while ( n-- )
    {
        scanf( "%s", command );
        if ( !strcmp( command, "push" ) )
        {
            scanf( "%d", &num );
            CQEnqueue( Q, num );
        }
        else if ( !strcmp( command, "pop" ) )
        {
            if ( Q->Front == Q->Rear )
                printf( "%d\n", -1 );
            else
                printf( "%d\n", CQDequeue( Q ) );
        }
        else if ( !strcmp( command, "size" ) )
            printf( "%d\n", Q->Rear - Q->Front );
        else if ( !strcmp( command, "empty" ) )
            printf( "%d\n", Q->Front == Q->Rear );
        else if ( !strcmp( command, "front" ) )
        {
            if ( Q->Front == Q->Rear )
                printf( "%d\n", -1 );
            else
                printf( "%d\n", Q->CQNodes[Q->Front].Data );
        }
        else if ( !strcmp( command, "back" ) )
        {
            if ( Q->Front == Q->Rear )
                printf( "%d\n", -1 );
            else
                printf( "%d\n", Q->CQNodes[Q->Rear-1].Data );
        }
    }

    return 0;
}

void CreateCQ( CQ** Queue, int cap )
{
    (*Queue) = (CQ*)malloc( sizeof( CQ ) );
    
    (*Queue)->CQNodes = (CQNode*)malloc( sizeof( CQNode ) * ( cap + 1 ) );
    (*Queue)->Capacity = cap;
    (*Queue)->Front = 0;
    (*Queue)->Rear = 0;
}

void CQEnqueue( CQ* Queue, ElementType data )
{
    int pos = Queue->Rear;
    if ( Queue->Rear == Queue->Capacity )
        Queue->Rear = 0;
    else
        Queue->Rear++;

    Queue->CQNodes[pos].Data = data;
}
ElementType CQDequeue( CQ* Queue )
{
    int pos = Queue->Front;
    if ( Queue->Front == Queue->Capacity )
        Queue->Front = 0;
    else
        Queue->Front++;

    return Queue->CQNodes[pos].Data;
}

void DestroyCQ( CQ* Queue )
{
    free( Queue->CQNodes );
    free( Queue );
}