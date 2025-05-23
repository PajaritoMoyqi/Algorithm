#include <stdio.h>

typedef struct tagMatrix2x2
{
    long long Data[2][2];
} Matrix2x2;

Matrix2x2 Matrix2x2Mul( Matrix2x2 A, Matrix2x2 B );
Matrix2x2 Matrix2x2Pow( Matrix2x2 A, long long n );
long long fib( long long n );

int main( void )
{
    long long ll;
    scanf( "%lld", &ll );

    while ( ~ll )
    {
        long long result = fib( ll );

        printf( "%lld\n", result );

        scanf( "%lld", &ll );
    }

    return 0;
}

Matrix2x2 Matrix2x2Mul( Matrix2x2 A, Matrix2x2 B )
{
    Matrix2x2 C;

    C.Data[0][0] = (A.Data[0][0] * B.Data[0][0] + A.Data[0][1] * B.Data[1][0]) % 10000;
    C.Data[0][1] = (A.Data[0][0] * B.Data[1][0] + A.Data[0][1] * B.Data[1][1]) % 10000;
    C.Data[1][0] = (A.Data[1][0] * B.Data[0][0] + A.Data[1][1] * B.Data[1][0]) % 10000;
    C.Data[1][1] = (A.Data[1][0] * B.Data[1][0] + A.Data[1][1] * B.Data[1][1]) % 10000;

    return C;
}
Matrix2x2 Matrix2x2Pow( Matrix2x2 A, long long n )
{
    if ( n > 1 )
    {
        A = Matrix2x2Pow( A, n/2 );
        A = Matrix2x2Mul( A, A );

        if ( n & 1 )
        {
            Matrix2x2 B;
            B.Data[0][0] = 1;
            B.Data[1][0] = 1;
            B.Data[0][1] = 1;
            B.Data[1][1] = 0;

            A = Matrix2x2Mul( A, B );
        }
    }

    return A;
}

long long fib( long long n )
{
    if ( !n ) return 0;
    
    Matrix2x2 A;
    A.Data[0][0] = 1;
    A.Data[1][0] = 1;
    A.Data[0][1] = 1;
    A.Data[1][1] = 0;

    A = Matrix2x2Pow( A, n );

    // printf( "%lld-th, %lld, %lld, %lld, %lld\n", n, A.Data[0][0], A.Data[0][1], A.Data[1][0], A.Data[1][1] );

    return A.Data[0][1];
}