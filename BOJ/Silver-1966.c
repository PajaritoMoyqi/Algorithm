# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct tagNode
{
    int Index;
    int Data; // to save string, not 1 chararacter
    struct tagNode* NextNode;
} Node;

typedef struct tagLinkedQueue
{
    Node* Front;
    Node* Rear;
    int Count;
} LinkedQueue;

void LQ_CreateQueue( LinkedQueue** Queue )
{
    (*Queue) = (LinkedQueue*)malloc( sizeof( LinkedQueue ) );

    (*Queue)->Count = 0;
    (*Queue)->Front = NULL;
    (*Queue)->Rear = NULL;
}
Node* LQ_CreateNode( int NewData, int idx )
{
    Node* NewNode = (Node*)malloc( sizeof( Node ) );
    
    NewNode->Data = NewData;
    NewNode->NextNode = NULL;
    NewNode->Index = idx;

    return NewNode;
}

void LQ_Enqueue( LinkedQueue* Queue, Node* NewNode )
{
    if ( Queue->Front == NULL )
    {
        Queue->Front = NewNode;
        Queue->Rear = NewNode;
    }
    else
    {
        Queue->Rear->NextNode = NewNode;
        Queue->Rear = NewNode;
    }
    
    Queue->Count++;
}
Node* LQ_Dequeue( LinkedQueue* Queue )
{
    Node* Front = Queue->Front;

    if ( Queue->Front->NextNode == NULL )
    {
        Queue->Front = NULL;
        Queue->Rear = NULL;
    }
    else
        Queue->Front = Queue->Front->NextNode;

    Queue->Count--;

    return Front;
}

void LQ_DestroyNode( Node* _Node )
{
    free( _Node->Data );
    free( _Node );
}
int LQ_IsEmpty( LinkedQueue* Queue )
{
    return ( Queue->Front == NULL );
}
void LQ_DestroyQueue( LinkedQueue* Queue )
{
    while ( ! LQ_IsEmpty( Queue ) )
    {
        Node* Popped = LQ_Dequeue( Queue );
        LQ_DestroyNode( Popped );
    }

    free( Queue );
}

int cmp( const void* _elem1, const void* _elem2 )
{
    int* elem1 = (int*)_elem1;
    int* elem2 = (int*)_elem2;

    if ( *elem1 < *elem2 )
        return 1;
    else if ( *elem1 > *elem2 )
        return -1;
    else
        return 0;
}

int main( void )
{
    int n;
    scanf( "%d", &n );
    
    while ( n-- )
    {
        // printf( "n: %d\n", n );
        int m, target;
        scanf( "%d%d", &m, &target );

        LinkedQueue* LQ;
        int Stack[m];
        LQ_CreateQueue( &LQ );
        int i, priority;
        for ( i = 0; i < m; i++ )
        {
            // printf( "for statement - %d(total %d times)\n", i, m );
            scanf( "%d", &priority );
            Node* N = LQ_CreateNode( priority, i );
            LQ_Enqueue( LQ, N );

            Stack[i] = priority;
        }
        // printf( "before qsort\n" );
        qsort( Stack, m, sizeof( int ), cmp );
        // printf( "after qsort\n" );

        // for ( i = 0; i < m; i++ )
        //     printf( "%d ", Stack[i] );
        // puts( "" );

        int idx = 0, cnt = 0;
        while ( 1 )
        {
            // for ( i = idx; i < m; i++ )
            //     printf( "%d ", Stack[i] );
            // puts( "" );
            Node* Candidate = LQ_Dequeue( LQ );

            if ( Stack[idx] == Candidate->Data )
            {
                idx++;
                cnt++;
                if ( Candidate->Index == target )
                {
                    printf( "%d\n", cnt );
                    break;
                }
            }
            else
                LQ_Enqueue( LQ, Candidate );
        }
    }

    return 0;
}