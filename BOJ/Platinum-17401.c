#include <stdio.h>

#define Max_N 20
#define Max_T 100
#define MOD 1000000007

typedef struct _Matrix2x2
{
    long long Data[Max_N][Max_N];
} Matrix2x2;

Matrix2x2 Matrix2x2Mul( Matrix2x2 A, Matrix2x2 B, long long n, long long mod );
Matrix2x2 Matrix2x2Pow( Matrix2x2 A, long long exponent, long long n, long long mod );

Matrix2x2 M[Max_T+1];

int main( void )
{
    long long t, n, d;
    scanf( "%lld%lld%lld", &t, &n, &d );

    int i, j;
    int row, col;
    for ( i = 1; i <= t; i++ )
    {
        int m;
        scanf( "%d", &m );
        
        while ( m-- )
        {
            long long ways;
            scanf( "%d%d", &row, &col );
            row--; col--;
            scanf( "%lld", &ways );
            M[i].Data[row][col] = ways;
        }
    }
    
    // int k;
    // for ( k = 1; k <= t; k++ )
    // {
    //     printf( "%d:\n", k );
    //     for ( i = 0; i < n; i++ )
    //     {
    //         for ( j = 0; j < n; j++ )
    //             printf( "%d ", M[k].Data[i][j] );

    //         puts( "" );
    //     }
    // }

    for ( i = 0; i < n; i++ )
        M[0].Data[i][i] = 1;

    for ( i = 1; i <= t; i++ )
        M[0] = Matrix2x2Mul( M[0], M[i], n, MOD );

    M[0] = Matrix2x2Pow( M[0], d/t, n, MOD );

    for ( i = 1; i <= d%t; i++ )
    		M[0] = Matrix2x2Mul( M[0], M[i], n, MOD );

    // printf( "rest\n" );
    for ( i = 0; i < n; i++ )
    {
        for ( j = 0; j < n; j++ )
            printf( "%lld ", M[0].Data[i][j] );

        puts( "" );
    }

    return 0;
}

Matrix2x2 Matrix2x2Mul( Matrix2x2 A, Matrix2x2 B, long long n, long long mod )
{
    Matrix2x2 C;
    int i, j, k;
		for ( i = 0; i < n; i++ )
    {
        for ( j = 0; j < n; j++ )
        {
            C.Data[i][j] = 0;
            for ( k = 0; k < n; k++ )
            {
                C.Data[i][j] += A.Data[i][k] * B.Data[k][j];
                C.Data[i][j] %= mod;
            }
        }
		}

    return C;
}
Matrix2x2 Matrix2x2Pow( Matrix2x2 A, long long exponent, long long n, long long mod )
{
    Matrix2x2 C;
    if ( exponent > 1 )
    {
        C = Matrix2x2Pow( A, exponent/2, n, mod );
        C = Matrix2x2Mul( C, C, n, mod );

        if ( exponent & 1 )
            C = Matrix2x2Mul( C, A, n, mod );
    }
    else if ( exponent == 1 )
    {
        C = A;
    }
    else
    {
        int i, j;
        for ( i = 0; i < n; i++ )
        {
            for ( j = 0; j < n; j++ )
            {
                if ( i == j )
                    C.Data[i][j] = 1;
                else
                    C.Data[i][j] = 0;
            }
        }
    }

    return C;
}