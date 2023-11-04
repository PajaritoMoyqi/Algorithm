#include <CQ.h>

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