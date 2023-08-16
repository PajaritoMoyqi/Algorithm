#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10001

void reverse( char arr[] );

int main(void) {
    char A[MAX+1] = { 0 }, B[MAX+1] = { 0 }, res[MAX+2] = { 0 };

    scanf( "%s%s", A, B );
    reverse( A );
    reverse( B );

    int len = strlen( A ) > strlen( B ) ? strlen( A ) : strlen( B );

    int carry = 0, i;
    for ( i = 0; i < len; i++ )
    {
        int sum = (A[i] - '0') + (B[i] - '0') + carry;

        while ( sum < 0 )
            sum += '0';
        if (sum > 9)
            carry = 1;
        else
            carry = 0;

        res[i] = sum % 10 + '0';
    }

    if (carry == 1) res[len] = '1';

    reverse(res);
    printf("%s", res);

    return 0;
}

void reverse( char arr[] )
{
    int len = strlen( arr );

    int i;
    char tmp;
    for ( i = 0; i < len/2; i++ )
    {
        tmp = arr[i];
        arr[i] = arr[len-1-i];
        arr[len-1-i] = tmp;
    }
}