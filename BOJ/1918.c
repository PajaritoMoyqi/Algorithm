#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[101];
int idx = -1;

typedef enum
{
    ADD = '+', SUB = '-', DIV = '/', MUL = '*',
    L_PAREN = '(', R_PAREN = ')'
} SYMBOL;

void AS_Push( char val );
char AS_Pop();
int AS_IsEmpty();
char AS_Top();
int AS_Priority( char operator );

int main( void )
{
    // get infix expression
    char infixExpression[101];
    scanf( "%s", infixExpression );

    for ( int i = 0; i < strlen( infixExpression ); i++ )
    {
        // if char is operand
        if ( infixExpression[i] >= 'A' && infixExpression[i] <= 'Z' )
            printf( "%c", infixExpression[i] );

        // if char is left parenthesis
        else if ( infixExpression[i] == L_PAREN )
            AS_Push( infixExpression[i] );

        // if char is right parenthesis
        else if ( infixExpression[i] == R_PAREN )
        {
            // if operator is not left parenthesis
            // also not right parenthesis because it is impossible
            while ( AS_Top() != L_PAREN )
                printf( "%c", AS_Pop() );

            // just pop and doen't print left parenthesis
            AS_Pop();
        }

        else // if char is normal operator(ADD, MUL, DIV, SUB)
        {
            // print all operators sequentially
            // while stack is not empty
            // and priority of the operator in stack is same of higher than the operator in infix expression
            while ( ! AS_IsEmpty() && AS_Priority( AS_Top() ) >= AS_Priority( infixExpression[i] ) )
                printf( "%c", AS_Pop() );

            // after the process, push the operator in infix expression without print
            AS_Push( infixExpression[i] );
        }
    }

    // pop all of the operators in stack
    // after nothing left in infix expression to see
    while ( ! AS_IsEmpty() )
        printf( "%c", AS_Pop() );
}

void AS_Push( char val )
{
	  stack[++idx] = val;
}
char AS_Pop()
{
    if ( idx < 0 ) // when there is nothing left in stack
        return -1;
    else
        return stack[idx--]; // return stack[idx] and idx--;
}
int AS_IsEmpty()
{
    if ( idx < 0 ) // when there is nothing left in stack
        return 1;
    else
        return 0;
}
char AS_Top()
{
    if ( idx < 0 ) // when there is nothing left in stack
        return 0;
    else
        return stack[idx];
}
int AS_Priority( char operator )
{
    if ( operator == L_PAREN ) // lowest priority
        return 0;
    else if ( operator == ADD || operator == SUB )
        return 1;
    else // operator MUL or DIV
        return 2;
}