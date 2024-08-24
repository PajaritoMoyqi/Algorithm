#include <stdio.h>

#define LEN 5
#define MAX_N 8
#define MOD 1000000007

typedef struct _Matrix2x2
{
    long long Data[MAX_N][MAX_N];
} Matrix2x2;

Map[8][8] = {
    { 0, 1, 1, 0, 0, 0, 0, 0 },
    { 1, 0, 1, 1, 0, 0, 0, 0 },
    { 1, 1, 0, 1, 1, 0, 0, 0 },
    { 0, 1, 1, 0, 1, 1, 0, 0 },
    { 0, 0, 1, 1, 0, 1, 1, 0 },
    { 0, 0, 0, 1, 1, 0, 0, 1 },
    { 0, 0, 0, 0, 1, 0, 0, 1 },
    { 0, 0, 0, 0, 0, 1, 1, 0 }
};
Limit[LEN] = { 0, 2, 4, 6, 7 };

Matrix2x2 Matrix2x2Mul( Matrix2x2 A, Matrix2x2 B, long long n, long long mod );
Matrix2x2 Matrix2x2Pow( Matrix2x2 A, long long exponent, long long n, long long mod );

Matrix2x2 M[1+1];

int main( void )
{
    long long d;
    scanf( "%lld", &d );

    int i, j;
    for ( i = 0; i < MAX_N; i++ )
    {
        for ( j = 0; j < MAX_N; j++ )
        {
            if ( i == j )
                M[0].Data[i][j] = 1;
            else
                M[0].Data[i][j] = 0;
        }
    }
    for ( i = 0; i < MAX_N; i++ )
    {
        for ( j = 0; j < MAX_N; j++ )
        {
            M[1].Data[i][j] = Map[i][j];
        }
    }

    Matrix2x2 Pow = Matrix2x2Pow( M[1], d, 8, MOD );
    M[0] = Matrix2x2Mul( M[0], Pow, MAX_N, MOD );

    printf( "%lld", M[0].Data[0][0] );

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