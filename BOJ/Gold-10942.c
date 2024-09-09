#include <stdio.h>

#define MAX_N 2000

int Arr[MAX_N+1];
int Palindrome[MAX_N+1][MAX_N+1];

int main( void )
{
    int n;
    scanf( "%d", &n );

    int i;
    for ( i = 1; i <= n; i++ )
        scanf( "%d", &Arr[i] );

    for ( i = 1; i <= n-1; i++ )
    {
        Palindrome[i][i] = 1;
        if ( Arr[i] == Arr[i+1] )
            Palindrome[i][i+1] = 1;
    }
    Palindrome[n][n] = 1;
    for ( i = 1; i <= n-2; i++ )
    {
        if ( Arr[i] == Arr[i+2] )
            Palindrome[i][i+2] = 1;
    }

    int j;
    for ( i = n-3; i >= 1; i-- )
    {
        for ( j = i+3; j <= n; j++ )
        {
            if ( Arr[i] == Arr[j] && Palindrome[i+1][j-1] )
                Palindrome[i][j] = 1;
        }
    }

    // for ( i = 1; i <= n; i++ )
    // {
    //     for ( j = 1; j <= n; j++ )
    //         printf( "%d ", Palindrome[i][j] );
    //     puts( "" );
    // }

    int qN;
    scanf( "%d", &qN );
    while ( qN-- )
    {
        scanf( "%d%d", &i, &j );
        printf( "%d\n", Palindrome[i][j] );
    }

    return 0;
}