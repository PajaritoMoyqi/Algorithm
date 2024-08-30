#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct _CLLNode
{
    Element Data;
    struct _CLLNode* PrevCLLNode;
    struct _CLLNode* NextCLLNode;
} CLLNode;

CLLNode* CreateCLLNode( Element data );
void AppendCLLNode( CLLNode** Head, CLLNode* New );
void InsertCLLNode( CLLNode* Target, CLLNode* New );
void RemoveCLLNode( CLLNode** Head, CLLNode* Target );
CLLNode* SearchCLL( CLLNode* Head, int idx );
int LengthCLL( CLLNode* Head );
void DestroyCLLNode( CLLNode* Node );

int main( void )
{
    int len, n;
    scanf( "%d%d", &len, &n );

    CLLNode* List = NULL;

    int i;
    for ( i = 1; i <= len; i++ )
    {
        CLLNode* NewNode = CreateCLLNode( i );
        AppendCLLNode( &List, NewNode );
    }

    CLLNode* Target = SearchCLL( List, 0 );
    CLLNode* Tmp;
    int cnt = 0;
    for ( i = 0; i < n; i++ )
    {
        int targetIdx;
        scanf( "%d", &targetIdx );
        int currentIdx = Target->Data;

        // printf( "targetIdx: %d, currentIdx: %d\n", targetIdx, currentIdx );

        if ( targetIdx == currentIdx )
        {
            Tmp = Target;
            Target = Target->NextCLLNode;
            RemoveCLLNode( &List, Tmp );
            len--;
            continue;
        }

        int forward = 0, backward = 0;
        while ( Target->Data != targetIdx )
        {
            Target = Target->NextCLLNode;
            forward++;
        }
        backward = len - forward;

        int movement = forward > backward ? backward : forward;
        int dir = forward > backward ? 0 : 1;
        cnt += movement;
        
        // printf( "remove: %d\n", Target->Data );
        Tmp = Target;
        Target = Target->NextCLLNode;
        RemoveCLLNode( &List, Tmp );
        len--;
        // printf( "len: %d, Target: %d - goto next\n", len, Target->Data );
    }

    printf( "%d", cnt );

    return 0;
}

CLLNode* CreateCLLNode( Element data )
{
    CLLNode* Head = (CLLNode*)malloc( sizeof( CLLNode ) );

    Head->Data = data;
    Head->PrevCLLNode = NULL;
    Head->NextCLLNode = NULL;

    return Head;
}

void AppendCLLNode( CLLNode** Head, CLLNode* New )
{
    if ( (*Head) == NULL )
    {
        *Head = New;
        (*Head)->PrevCLLNode = *Head;
        (*Head)->NextCLLNode = *Head;
    }
    else
    {
        CLLNode* Tail = (*Head)->PrevCLLNode;

        Tail->NextCLLNode->PrevCLLNode = New;
        Tail->NextCLLNode = New;

        New->NextCLLNode = (*Head);
        New->PrevCLLNode = Tail;
    }
}

void InsertCLLNode( CLLNode* Target, CLLNode* New )
{
    New->NextCLLNode = Target->NextCLLNode;
    New->PrevCLLNode = Target;

    if ( Target->NextCLLNode != NULL )
    {
        Target->NextCLLNode->PrevCLLNode = New;
        Target->NextCLLNode = New;
    }
}

void RemoveCLLNode( CLLNode** Head, CLLNode* Target )
{
    if ( (*Head) == Target )
    {
        (*Head)->PrevCLLNode->NextCLLNode = Target->NextCLLNode;
        (*Head)->NextCLLNode->PrevCLLNode = Target->PrevCLLNode;

        *Head = Target->NextCLLNode;
    }
    else
    {
        Target->PrevCLLNode->NextCLLNode = Target->NextCLLNode;
        Target->NextCLLNode->PrevCLLNode = Target->PrevCLLNode;
    }

    Target->PrevCLLNode = NULL;
    Target->NextCLLNode = NULL;
}

CLLNode* SearchCLL( CLLNode* Head, int idx )
{
    CLLNode* Candidate = Head;
    while( Candidate != NULL && (--idx) >= 0 )
        Candidate = Candidate->NextCLLNode;

    return Candidate;
}
int LengthCLL( CLLNode* Head )
{
    int cnt = 0;

    CLLNode* Current = Head;
    while ( Current != NULL && Current != Head )
    {
        Current = Current->NextCLLNode;
        cnt++;
    }

    return cnt;
}

void DestroyCLLNode( CLLNode* Node )
{
    free( Node );
}