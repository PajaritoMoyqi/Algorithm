#include <stdio.h>

typedef struct tagMatrix2x2
{
    long long Data[2][2];
} Matrix2x2;

Matrix2x2 Matrix2x2Mul( Matrix2x2 A, Matrix2x2 B, long long modInt );
Matrix2x2 Matrix2x2Pow( Matrix2x2 A, long long n, long long modInt );
long long fib( long long n, long long modInt );

int main( void )
{
    long long ll, t, idx = 0;
    scanf( "%lld", &t );
    long long modInt;

    while ( idx++ != t )
    {
        scanf( "%lld%lld", &ll, &modInt );

        long long result = modInt == 1 ? 0 : fib( ll, modInt );

        printf( "Case #%lld: %lld\n", idx, result );
    }

    return 0;
}

Matrix2x2 Matrix2x2Mul( Matrix2x2 A, Matrix2x2 B, long long modInt )
{
    Matrix2x2 C;

    C.Data[0][0] = (A.Data[0][0] * B.Data[0][0] + A.Data[0][1] * B.Data[1][0]) % modInt;
    C.Data[0][1] = (A.Data[0][0] * B.Data[1][0] + A.Data[0][1] * B.Data[1][1]) % modInt;
    C.Data[1][0] = (A.Data[1][0] * B.Data[0][0] + A.Data[1][1] * B.Data[1][0]) % modInt;
    C.Data[1][1] = (A.Data[1][0] * B.Data[1][0] + A.Data[1][1] * B.Data[1][1]) % modInt;

    return C;
}
Matrix2x2 Matrix2x2Pow( Matrix2x2 A, long long n, long long modInt )
{
    if ( n > 1 )
    {
        A = Matrix2x2Pow( A, n/2, modInt );
        A = Matrix2x2Mul( A, A, modInt );

        if ( n & 1 )
        {
            Matrix2x2 B;
            B.Data[0][0] = 1;
            B.Data[1][0] = 1;
            B.Data[0][1] = 1;
            B.Data[1][1] = 0;

            A = Matrix2x2Mul( A, B, modInt );
        }
    }

    return A;
}

long long fib( long long n, long long modInt )
{
    if ( !n ) return 0;
    
    Matrix2x2 A;
    A.Data[0][0] = 1;
    A.Data[1][0] = 1;
    A.Data[0][1] = 1;
    A.Data[1][1] = 0;

    A = Matrix2x2Pow( A, n, modInt );

    printf( "%lld-th, %lld, %lld, %lld, %lld\n", n, A.Data[0][0], A.Data[0][1], A.Data[1][0], A.Data[1][1] );

    return A.Data[0][1];
}