#include <stdio.h>

typedef struct tagMatrix2x2
{
    long long Data[2][2];
} Matrix2x2;

Matrix2x2 Matrix2x2Mul( Matrix2x2 A, Matrix2x2 B, long long div );
Matrix2x2 Matrix2x2Pow( Matrix2x2 A, long long n );
long long fib( long long n );

int main( void )
{
    long long ll;
    scanf( "%lld", &ll );

    printf( "%lld %lld", fib( ll ), ll - 2 );

    return 0;
}

Matrix2x2 Matrix2x2Mul( Matrix2x2 A, Matrix2x2 B, long long div )
{
    Matrix2x2 C;

    C.Data[0][0] = (A.Data[0][0] * B.Data[0][0] + A.Data[0][1] * B.Data[1][0]) % div;
    C.Data[0][1] = (A.Data[0][0] * B.Data[1][0] + A.Data[0][1] * B.Data[1][1]) % div;
    C.Data[1][0] = (A.Data[1][0] * B.Data[0][0] + A.Data[1][1] * B.Data[1][0]) % div;
    C.Data[1][1] = (A.Data[1][0] * B.Data[1][0] + A.Data[1][1] * B.Data[1][1]) % div;

    return C;
}
Matrix2x2 Matrix2x2Pow( Matrix2x2 A, long long n )
{
    if ( n > 1 )
    {
        A = Matrix2x2Pow( A, n/2 );
        A = Matrix2x2Mul( A, A, 1000000007 );

        if ( n & 1 )
        {
            Matrix2x2 B;
            B.Data[0][0] = 1;
            B.Data[1][0] = 1;
            B.Data[0][1] = 1;
            B.Data[1][1] = 0;

            A = Matrix2x2Mul( A, B, 1000000007 );
        }
    }

    return A;
}

long long fib( long long n )
{
    Matrix2x2 A;
    A.Data[0][0] = 1;
    A.Data[1][0] = 1;
    A.Data[0][1] = 1;
    A.Data[1][1] = 0;

    A = Matrix2x2Pow( A, n );

    // printf( "%lld-th, %lld, %lld, %lld, %lld\n", n, A.Data[0][0], A.Data[0][1], A.Data[1][0], A.Data[1][1] );

    return A.Data[0][1];
}