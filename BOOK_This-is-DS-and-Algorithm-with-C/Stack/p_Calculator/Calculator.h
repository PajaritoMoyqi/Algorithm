#ifndef CALCULATOR_H
#define CALCULATOR_H

# include <stdlib.h>
# include "LinkedListStack.h"

// typedef enum is used
typedef enum
{
    LEFT_PARENTHESIS = '(', RIGHT_PARENTHESIS = ')',
    PLUS = '+', MINUS = '-', MULTIPLY = '*', DIVIDE = '/',
    SPACE = ' ', OPERAND
} SYMBOL;

// declaration of functions
int IsNumber( char Cipher );
unsigned int GetNextToken( char* Expression, char* Token, int* TYPE );
int IsPrior( char OperatorInStack, char OperatorInToken );

void GetPostfix( char* InfixExpression, char* PostfixExpression );

double Calculate( char* PostfixExpression );

#endif