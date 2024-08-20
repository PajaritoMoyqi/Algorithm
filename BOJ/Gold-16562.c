#include <stdio.h>
#include <stdlib.h>

#define MAX_PERSON 10000
#define MAX_PAYMENT 10000000

typedef struct _Student
{
    int parent;
    long long payment;
} Student;

Student S[MAX_PERSON+1];
int Visited[MAX_PERSON+1];
int Payment[MAX_PERSON+1];

int FindParent( int idx );
void Union( int x, int y );
int Cmp( const void* a, const void* b );

int main( void )
{
    int studentNum, relNum;
    long long money;
    scanf( "%d%d%lld", &studentNum, &relNum, &money );

    int i;
    for ( i = 1; i <= studentNum; i++ )
        S[i].parent = i;

    for ( i = 1; i <= studentNum; i++ )
    {
        scanf( "%lld", &S[i].payment );
        Payment[i] = (long long)MAX_PAYMENT;
    }

    int a, b;
    for ( i = 1; i <= relNum; i++ )
    {
        scanf( "%d%d", &a, &b );
        int parA = FindParent( a );
        int parB = FindParent( b );
        // printf( "Before - (parA : %d, parB : %d)\n", parA, parB );

        if ( parA != parB )
            Union( a, b );
        // printf( "After - (parA : %d, parB : %d)\n", FindParent( a ), FindParent( b ) );
    }
    
    // for ( i = 1; i <= studentNum; i++ )
    // {
    //     printf( "%d ", S[i].parent );
    //     printf( "%d ", S[i].payment );
    //     puts( "" );
    // }
    // puts( "" );

    // qsort( S, studentNum+1, sizeof( Student ), Cmp );

    int currParent;
    for ( i = 1; i <= studentNum; i++ )
    {
        currParent = FindParent( i );
        if ( !Visited[currParent] )
            Visited[currParent] = 1;

        Payment[currParent] = Payment[currParent] < S[i].payment ? Payment[currParent] : S[i].payment;
    }

    long long totalPayment = 0;
    for ( i = 1; i <= studentNum; i++ )
    {
        if ( Visited[i] )
            totalPayment += Payment[i];
    }

    if ( totalPayment > money )
        printf( "Oh no" );
    else
        printf( "%lld", totalPayment );

    return 0;
}

int FindParent( int idx )
{
    if ( S[idx].parent == idx ) return idx;
    else return S[idx].parent = FindParent( S[idx].parent );
}
void Union( int x, int y )
{
    int xParent = FindParent( x );
    int yParent = FindParent( y );

    if ( xParent != yParent )
    {
        if ( xParent < yParent )
            S[yParent].parent = xParent;
        else
            S[xParent].parent = yParent;
    }
}

int Cmp( const void* a, const void* b )
{
    Student* elem1 = (Student*)a;
    Student* elem2 = (Student*)b;

    if ( elem1->parent < elem2->parent)
    {
        return -1;
    }
    else if (elem1->parent > elem2->parent)
    {
        return 1;
    }
    else
    {
        if ( elem1->payment < elem2->payment)
        {
            return -1;
        }
        else if (elem1->payment > elem2->payment)
        {
            return 1;
        }
    }
}