# include <stdio.h>
# include <stdlib.h>

typedef char Element;

typedef struct DLLNode
{
   Element Data;
   struct DLLNode* PrevDLLNode;
   struct DLLNode* NextDLLNode;
} DLLNode;

DLLNode* CreateDLLNode( Element data )
{
    DLLNode* Head = (DLLNode*)malloc( sizeof( DLLNode ) );

    Head->Data = data;
    Head->PrevDLLNode = NULL;
    Head->NextDLLNode = NULL;

    return Head;
}

void AppendDLLNode( DLLNode* Target, DLLNode** Head, DLLNode* New )
{
    // printf( "Append\n, New: %c", New->Data );
    if ( (*Head) == NULL )
        *Head = New;
    else
    {
        Target->NextDLLNode = New;
        New->PrevDLLNode = Target;
    }
    // printf( " --- Append Done\n" );
}

void InsertDLLNode( DLLNode* Target, DLLNode** Head, DLLNode* New )
{
    // printf( "Insert\n" );
    if ( Target == NULL )
    {
        New->NextDLLNode = (*Head);
        (*Head)->PrevDLLNode = New;
        *Head = New;
    }
    else
    {
        if ( Target->NextDLLNode != NULL )
            New->NextDLLNode = Target->NextDLLNode;
       
        New->PrevDLLNode = Target;

        if ( Target->NextDLLNode != NULL )
            Target->NextDLLNode->PrevDLLNode = New;

        Target->NextDLLNode = New;
    }
}
void RemoveDLLNode( DLLNode* Target, DLLNode** Head )
{
    // printf( "Remove\n" );
    if ( Target == NULL )
    {
        return;
    }

    if ( (*Head) == Target )
    {
        *Head = Target->NextDLLNode;
        if ( (*Head) != NULL )
            (*Head)->PrevDLLNode = NULL;
    }
    else
    {
        if ( Target->PrevDLLNode != NULL )
            Target->PrevDLLNode->NextDLLNode = Target->NextDLLNode;

        if ( Target->NextDLLNode != NULL )
            Target->NextDLLNode->PrevDLLNode = Target->PrevDLLNode;
    }

    Target->PrevDLLNode = NULL;
    Target->NextDLLNode = NULL;
}

void PrintDLL( DLLNode* Head )
{
    DLLNode* Current = Head;
    while ( Current != NULL )
    {
        printf( "%c", Current->Data );
        Current = Current->NextDLLNode;
    }
    printf( "\n" );
}

void DestroyDLLNode( DLLNode* Node )
{
    free( Node );
}

int main( void )
{
    int n, length = 0;
    char c;
    DLLNode* Head = NULL;
    DLLNode* N = NULL;
    DLLNode* Target = NULL;

    while ( (c = getchar()) != '\n' )
    {
        // printf( "%c is comming...\n", c );
        N = CreateDLLNode( c );
        AppendDLLNode( Target, &Head, N );
        length++;
        Target = N;
        // printf( "Inserted Data: %c\n", N->Data );
        // if ( N->PrevDLLNode )
        //     printf( "Inserted prev Data: %c\n", N->PrevDLLNode->Data );
    }
    // printf( "init length: %d\n", length );

    scanf( "%d", &n );
    // printf( "we have %d request(s).\n", n );
    while ( n-- )
    {
        scanf( " %c", &c );
        // printf( "%c is comming...\n", c );

        // printf( "Target: %d\n", Target );

        if ( c == 'P' )
        {
            scanf( " %c", &c );
            // printf( "let's insert %c...\n", c );
            N = CreateDLLNode( c );
            // printf( "N is created...\n" );
            InsertDLLNode( Target, &Head, N );
            // printf( "Insert N into Linked List...\n" );
            
            length++;
            if ( Target != NULL )
                Target = N;
            else
                Target = Head;
        }
        else if ( c == 'L' )
        {
            // printf( "Go to Left\n" );
            if ( Target != NULL ) Target = Target->PrevDLLNode;
        }
        else if ( c == 'D' )
        {
            // printf( "Go to Right\n" );
            if ( Target == NULL ) Target = Head;
            else if ( Target->NextDLLNode != NULL ) Target = Target->NextDLLNode;
        }
        else if ( c == 'B' )
        {
            if ( Target != NULL )
            {
                // printf( "Go to Remove\n" );
                DLLNode* Tmp = Target->PrevDLLNode;
                RemoveDLLNode( Target, &Head );
                length--;
                Target = Tmp;
            }
        }
        // printf( "idx: %d, length: %d\n", idx, length );
        // PrintDLL( Head );
        // if ( Target != NULL )
        //     printf( "Target Data: %c\n", Target->Data );
    }

    PrintDLL( Head );

    return 0;
}