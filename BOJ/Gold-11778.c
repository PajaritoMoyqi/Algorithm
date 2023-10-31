#include <stdio.h>

typedef struct tagMatrix2x2
{
    long long Data[2][2];
} Matrix2x2;

Matrix2x2 Matrix2x2Mul( Matrix2x2 A, Matrix2x2 B );
Matrix2x2 Matrix2x2Pow( Matrix2x2 A, long long n );
long long fib( long long n );
long long getGCD( long long a, long long b );

int main( void )
{
    long long a, b;
    scanf( "%lld%lld", &a, &b );

    long long gcd = getGCD( a, b );

    printf( "%lld", fib( gcd ) );
    return 0;
}

Matrix2x2 Matrix2x2Mul( Matrix2x2 A, Matrix2x2 B )
{
    Matrix2x2 C;

    C.Data[0][0] = (A.Data[0][0] * B.Data[0][0] + A.Data[0][1] * B.Data[1][0]) % 1000000007;
    C.Data[0][1] = (A.Data[0][0] * B.Data[1][0] + A.Data[0][1] * B.Data[1][1]) % 1000000007;
    C.Data[1][0] = (A.Data[1][0] * B.Data[0][0] + A.Data[1][1] * B.Data[1][0]) % 1000000007;
    C.Data[1][1] = (A.Data[1][0] * B.Data[1][0] + A.Data[1][1] * B.Data[1][1]) % 1000000007;

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
    Matrix2x2 A;
    A.Data[0][0] = 1;
    A.Data[1][0] = 1;
    A.Data[0][1] = 1;
    A.Data[1][1] = 0;

    A = Matrix2x2Pow( A, n );

    return A.Data[0][1];
}

long long getGCD( long long a, long long b )
{
    long long big = (a >= b) ? a : b;
    long long small = (a >= b) ? b : a; 
    long long mod = big % small;

    if ( mod == 0 )
        return small;
    else
        return getGCD( small, mod );
}