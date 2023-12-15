## Categorized Methods

### DP

#### Make sum array

```c
int isPrime[MAX+1];
int primeSum[MAX+1];
int FermatSum[MAX+1];

int main( void )
{
    int i;
    for ( i = 2; i <= MAX; i++ )
        isPrime[i] = 1;

    for ( i = 2; i <= sqrt(MAX); i++ )
    {
        if ( isPrime[i] == 0 )
            continue;
        
        int mult;
        for ( mult = 2; i*mult <= MAX; mult++ )
            isPrime[i*mult] = 0;
    }
    for ( i = 2; i <= MAX ; i++ )
    {
        if ( isPrime[i] ) primeSum[i] = primeSum[i-1] + 1;
        else primeSum[i] = primeSum[i-1];

        if ( isPrime[i] && ( i % 4 == 1 || i == 2 ) ) FermatSum[i] = FermatSum[i-1] + 1;
        else FermatSum[i] = FermatSum[i-1];
    }

    return 0;
}
```

#### use vector(C++)

```cpp

```

## Specific Methods

### string

#### substring

```c
char* mySubstr( char str[], int idx, int len )
{
    char* ss = (char*)malloc( sizeof( char ) * ( len + 1 ) );
    strncpy( ss, str + idx, len );
    ss[len] = '\0';
    return ss;
}
```

### Odd, even

```c
int a;

if ( a & 1 ) ; // efficient 'a % 2'
```

### Multiple 2, divide 2

#### Bit operation

```c
int a, n;

a >>= 1; // efficient 'a *= 2;'
a >>= n; // efficient 'a = a * pow( 2, n );'

a <<= 1; // efficient 'a /= 2;'
a <<= n; // efficient 'a = a / pow( 2, n );'
```

### power 3

```c
long long power3( long long number )
{
    long long result;
    if ( number == 0 ) return 1;
    else
        return 3 * power3( number - 1 );
}
```

### Fibonacci

#### Divide and Conquer

```c
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
```

```c
#include <stdio.h>

typedef struct tagMatrix2x2
{
    long long Data[2][2];
} Matrix2x2;

Matrix2x2 Matrix2x2Mul( Matrix2x2 A, Matrix2x2 B );
Matrix2x2 Matrix2x2Pow( Matrix2x2 A, long long n );
long long fib( long long n );

Matrix2x2 Matrix2x2Mul( Matrix2x2 A, Matrix2x2 B )
{
    Matrix2x2 C;

    C.Data[0][0] = (A.Data[0][0] * B.Data[0][0] + A.Data[0][1] * B.Data[1][0]);
    C.Data[0][1] = (A.Data[0][0] * B.Data[1][0] + A.Data[0][1] * B.Data[1][1]);
    C.Data[1][0] = (A.Data[1][0] * B.Data[0][0] + A.Data[1][1] * B.Data[1][0]);
    C.Data[1][1] = (A.Data[1][0] * B.Data[1][0] + A.Data[1][1] * B.Data[1][1]);

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
```

### Prime Number

#### Sieve of Eratosthenes

```c
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
```

### Big Integer

#### Add

```c
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
```

### qsort

#### compare function

```c
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
```

#### binary search

```c
int BSearch( int Set[], int len, int target )
{
    int leftIdx = 0, rightIdx = len, middle;
    while ( rightIdx > leftIdx )
    {
        middle = (leftIdx + rightIdx) / 2;
        Set[middle] > target ? rightIdx = middle : (leftIdx = middle + 1);
    }
    
    int tmp = rightIdx;
    leftIdx = 0, rightIdx = len;
    while ( rightIdx > leftIdx )
    {
        middle = (leftIdx + rightIdx) / 2;
        Set[middle] >= target ? rightIdx = middle : (leftIdx = middle + 1);
    }
    return tmp - rightIdx;
}
```

### Reverse array

```c
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
```

### BitMask

#### Efficient way to use array

```c
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
```