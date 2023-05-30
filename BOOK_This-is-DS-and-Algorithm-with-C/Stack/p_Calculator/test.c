#include <stdio.h>
#include <string.h>
#include "Calculator.h"

int main()
{
    char InfixExpression[100];
    char PostfixExpression[100];

    double Result;

    memset( InfixExpression, 0, sizeof( InfixExpression ) );
    memset( PostfixExpression, 0, sizeof( PostfixExpression ) );

    printf( "Enter Infix Expression: " );
    scanf( "%s", InfixExpression );

    GetPostfix( InfixExpression, PostfixExpression );

    printf( "Infix: %s\n, Postfix: %s\n", InfixExpression, PostfixExpression );

    Result = Calculate( PostfixExpression );

    printf( "Calculation Result: %f\n", Result );

    return 0;
}