#include <stdio.h>
#include <math.h>

int main( void )
{
    int a, n;

    if ( a & 1 ) ; // efficient 'a % 2'
    
    a >>= 1; // efficient 'a *= 2;'
    a >>= n; // efficient 'a = a * pow( 2, n );'

    a <<= 1; // efficient 'a /= 2;'
    a <<= n; // efficient 'a = a / pow( 2, n );'

    // efficient way to use limited array
    int a;
    int arr[(1<<20) + 1];

    int rest, idx;
    while ( scanf( "%d", &a ) != EOF )
    {
        idx = a / 32;
        rest = 1 << ( a % 32 );

        if ( !(arr[idx] & rest) )
        {
            arr[idx] += rest;
            printf( "%d ", a );  
        }
    }
    
    // Sieve of Eratosthenes
    const int MAX = 100000;

    int primes[MAX+1];
    primes[0] = primes[1] = 0;

    int i;
    for ( i = 2; i <= MAX; i++ )
        primes[i] = 1;

    for ( i = 2; i <= sqrt(MAX); i++ )
    {
        if ( primes[i] == 0 ) continue;

        int mult;
        for ( mult = 2; i*mult <= MAX; mult++ )
            primes[i*mult] = 0;
    }
}

int fibonacci( int cycle )
{
    int Latest, Current, Result;
    Current = 1, Latest = Result = 0;
    
    int i;
    for ( i = 0; i < cycle; i++ )
    {
        Latest = Current;
        Current = Result;
        Result = Latest + Current;
    }

    return Result;
}

void reverseArr( char arr[] )
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

char* bigIntAdd ( char A[], char B[]  ) // with reverseArr
{
    const int MAX = 10000;
    char res[MAX+2] = { 0 };

    reverseArr( A );
    reverseArr( B );

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

    if ( carry == 1 ) res[len] = '1';

    reverseArr( res );

    return res;
}

long long power3( long long number )
{
    if ( number == 0 ) return 1;
    else
        return 3 * power3( number - 1 );
}

char* mySubstr( char str[], int idx, int len )
{
    char* ss = (char*)malloc( sizeof( char ) * ( len + 1 ) );
    strncpy( ss, str + idx, len );
    ss[len] = '\0';
    return ss;
}

int cmp( const void* _elem1, const void* _elem2 )
{
    int* elem1 = (int*)_elem1;
    int* elem2 = (int*)_elem2;

    if ( *elem1 > *elem2 )
        return 1;
    else if ( *elem1 < *elem2 )
        return -1;
    else
        return 0;
}