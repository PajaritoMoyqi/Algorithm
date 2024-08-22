#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Element;

typedef struct _DLLNode
{
    Element Data;
    struct _DLLNode* PrevDLLNode;
    struct _DLLNode* NextDLLNode;
} DLLNode;

#define MAX_LEN 1000000

int main( void )
{
    int n;
    scanf( "%d", &n );

    while ( n-- )
    {
        DLLNode* Head, * Tail, * Target;

        Head = (DLLNode*)malloc( sizeof( DLLNode ) );
        Tail = (DLLNode*)malloc( sizeof( DLLNode ) );

        Head->PrevDLLNode = Head;
        Head->NextDLLNode = Tail;
        Tail->PrevDLLNode = Head;
        Tail->NextDLLNode = Tail;
        Target = Head;

        char string[MAX_LEN+1];
        scanf( "%s", string );
        int len = strlen( string );

        int i;
        int flag = 0;
        for ( i = 0; i < len; i++ )
        {
            char str = string[i];
            if ( str == '\0' )
                break;

            if ( str == '<' || str == '>' )
            {
                if ( str == '<' )
                    if ( Target != Head )
                        Target = Target->PrevDLLNode;

                if ( str == '>' )
                    if ( Target != Tail->PrevDLLNode )
                        Target = Target->NextDLLNode;
            }
            else if ( str == '-' )
            {
                if ( Target != Head )
                {
                    DLLNode* Tmp = Target;
                    Target = Target->PrevDLLNode;
                    Target->NextDLLNode = Tmp->NextDLLNode;
                    Target->NextDLLNode->PrevDLLNode = Target;
                    free( Tmp );
                }
            }
            else
            {
                DLLNode* NewNode = (DLLNode*)malloc( sizeof( DLLNode ) );
                NewNode->Data = str;
            
                NewNode->NextDLLNode = Target->NextDLLNode;
                Target->NextDLLNode->PrevDLLNode = NewNode;
                Target->NextDLLNode = NewNode;
                NewNode->PrevDLLNode = Target;
            
                Target = Target->NextDLLNode;
            }
        }

        DLLNode* Candidate = Head;
        while ( Candidate != NULL )
        {
            if ( Candidate != Head && Candidate != Tail )
                printf( "%c", Candidate->Data );

            if ( Candidate == Tail )
                break;

            Candidate = Candidate->NextDLLNode;
        }
        puts( "" );
    }

    return 0;
}