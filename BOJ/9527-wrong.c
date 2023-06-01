#include <stdio.h>
#include <math.h>

int returnDigit( long long int n );
void changeSum( long long int n, long long int* answer );

int main()
{    
    long long int value1, value2;
    long long int answer1 = 0;
    long long int answer2 = 0;

    scanf( "%lld %lld", &value1, &value2 );

    changeSum( value1 - 1, &answer1 );
    changeSum( value2, &answer2 );

    printf( "%lld", answer2-answer1 );

    return 0;
}


int returnDigit( long long int n )
{   
    long long int count = 0;

    while ( n >= 2 )
    {
        count++;
        n /= 2;
    }

    return count;
}

void changeSum( long long int n, long long int* answer )
{
    long long int digit = returnDigit( n );
    long long int poweredNum = 1 << digit;

    if ( n == 1 )
        *answer += 1; // g(1)
    else if ( n == 2 )
        *answer += 2; // g(2)
    else
    {
        *answer += ( digit * ( 1 << ( digit - 1 ) ) + 1 ); // g(4), g(8), g(16), ...
        *answer += n%poweredNum; // + m

        if ( n%poweredNum != 0 )
            changeSum( n%poweredNum, answer );
    }
}