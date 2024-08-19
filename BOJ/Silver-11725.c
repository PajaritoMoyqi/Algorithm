#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100000

int Node_Cnt[MAX_LEN+1];
int Parent[MAX_LEN+1];

typedef struct _Node
{
    int data;
    struct _Node* next;
} Node;

Node* Nodes[MAX_LEN+1];

void DFS ( int n );

int main(void)
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 1; i <= n; i++ )
    {
        Nodes[i] = (Node*)malloc( sizeof( Node ) );
        Nodes[i]->next = NULL;
    }

    int j;
    for ( i = 0; i < n-1; i++ )
    {
        int x, y;
        scanf( "%d %d", &x, &y );
        
        Node* Curr;

        Node_Cnt[x]++;
        Node_Cnt[y]++;

        Curr = Nodes[x];
        for ( j = 0; j < Node_Cnt[x]-1; j++ )
        {
            Curr = Curr->next;
        }
        Curr->next = (Node*)malloc( sizeof( Node ) );
        Curr->next->data = y;
        Curr->next->next = NULL;

        Curr = Nodes[y];
        for ( j = 0; j < Node_Cnt[y]-1; j++ )
        {
            Curr = Curr->next;
        }
        Curr->next = (Node*)malloc( sizeof( Node ) );
        Curr->next->data = x;
        Curr->next->next = NULL;
    }

    DFS( 1 );

    for ( i = 2; i <= n; i++ )
    {
        printf( "%d\n", Parent[i] );
    }

    return 0;
}

void DFS ( int n )
{
    int i;
    Node* Curr;

    Curr = Nodes[n];

    for ( i = 1; i <= Node_Cnt[n]; i++ )
    {
        Curr = Curr->next;
        if ( Parent[Curr->data] == 0 )
        {
            Parent[Curr->data] = n;
            DFS( Curr->data );
        }
    }
}