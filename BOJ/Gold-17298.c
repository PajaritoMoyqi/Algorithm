#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagStack {
    int* Stack;
    int Size;
} CustomStack;

void Push( CustomStack* S, int data )
{
    S->Stack[S->Size++] = data;
}
int Pop( CustomStack* S )
{
    return S->Stack[--(S->Size)];
}
int Top( CustomStack *S )
{
    return S->Stack[S->Size-1];
}
int IsEmpty( CustomStack *S )
{
    return ( S->Size == 0 );
}

int* Arr;
int* Ans;

int main( void )
{
    CustomStack S;

    int n, i;
    scanf( "%d", &n );

    S.Stack = (int*)calloc( n, sizeof( int ) );
    S.Size = 0;
    Arr = (int*)calloc( n, sizeof( int ) );
    Ans = (int*)calloc( n, sizeof( int ) );
    
    for ( i = 0; i < n; i++ )
    {
        scanf( "%d", &Arr[i] );
        Ans[i] = -1;
    }

    for ( i = 0; i < n; i++ )
    {
        while( !IsEmpty( &S ) && Arr[Top( &S )] < Arr[i] )
            Ans[Pop( &S )] = Arr[i];

        Push( &S, i );
    }

    for ( i = 0; i < n; i++ )
        printf( "%d ", Ans[i] );
    
    free(Arr);
    free(Ans);

    return 0;
}