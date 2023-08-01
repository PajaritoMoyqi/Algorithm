#include <stdio.h>

int main( void )
{
    int A, B;
    scanf( "%d%d", &A, &B );

    int C = A ^ B;
    printf( "%d", C );

    return 0;
}