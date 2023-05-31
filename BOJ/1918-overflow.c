#include <stdio.h> // scanf, printf
#include <string.h> // strlen
# include <stdlib.h> // malloc

// Making structure of stack and its nodes
typedef struct tagNode
{
    char* Data; // The address of Data of each node
    struct tagNode* NextNode; // The address of next node
} Node;
typedef struct tagLinkedListStack
{
    Node* List; // The address of start point of the stack
    Node* Top; // The address of last point of the stack
} LLStack;

typedef enum
{
    ADD = '+', SUB = '-', DIV = '/', MUL = '*',
    L_PAREN = '(', R_PAREN = ')'
} SYMBOL;

// declaration of function

int main( void )
{
    char infixExpression[102];
    unsigned int infixPosition = 0;
    unsigned int postfixPosition = 0;
    unsigned int exprssionLength;
    char postfixExpression[102];

    // get given infix expression
    scanf( "%s", infixExpression );

    exprssionLength = strlen( infixExpression );

    // make stack
    LLStack* Stack = (LLStack*)malloc(sizeof(LLStack));
    Stack->Top = NULL;
    Stack->List = NULL;

    while ( infixPosition <= exprssionLength )
    {
        char temp = infixExpression[infixPosition];

        // check whether there are more operators in stack
        if ( infixPosition == exprssionLength && Stack->Top != NULL )
        {
            while ( infixPosition >= postfixPosition )
            {
                // remove Stack
                Node* TopNode = Stack->Top;

                char operandInStack = TopNode->Data[0];
                // printf("left stack: %c\n", operandInStack);

                // add operators, which were in parenthesis, to postfix expression
                postfixExpression[postfixPosition] = operandInStack;
                postfixPosition++;
                
                // printf("pE: %s\n", postfixExpression);

                Node* NextTop = Stack->List;
                
                while ( NextTop != NULL && NextTop->NextNode != Stack->Top )
                {
                    // printf( "loop\n" );
                    
                    if ( TopNode != Stack->List )
                        NextTop = NextTop->NextNode;
                    else
                        break;
                }

                // if ( NextTop->Data[0] != NULL )
                //     printf("next left stack: %c\n", NextTop->Data[0]);
                // printf("next stack's next: %p\n", NextTop->NextNode);

                NextTop->NextNode = NULL;
                
                if ( TopNode == Stack->List )
                {
                    // printf("kkk\n");
                    free(TopNode->Data);
                    free(TopNode);

                    Stack->List = NULL;
                    Stack->Top = NULL;

                    free(Stack);

                    break;
                }
                else
                {
                    free(TopNode->Data);
                    free(TopNode);
                    
                    Stack->Top = NextTop;
                }
            }
        }

        if ( temp == R_PAREN )
        {
            // printf( "R Paren\n" );

            // printf( "Stack Top: %c\n", Stack->Top->Data );
            // printf( "Stack Top: %p\n", Stack->Top );

            while ( Stack->Top->Data[0] != L_PAREN && Stack->Top != NULL )
            {
                char operandInStack = Stack->Top->Data[0];
                // printf("%c", operandInStack);

                // add operators, which were in parenthesis, to postfix expression
                postfixExpression[postfixPosition] = operandInStack;
                postfixPosition++;

                // remove Stack
                Node* NextTop = Stack->List;
                
                while ( NextTop != NULL && NextTop->NextNode != Stack->Top )
                    NextTop = NextTop->NextNode;

                NextTop->NextNode = NULL;

                // you only can free the space of heap thourgh giving pointer to free() function.
                free(Stack->Top->Data);
                free(Stack->Top);

                Stack->Top = NextTop;
            }

            if ( Stack->Top->Data[0] == L_PAREN )
            {
                // remove Stack
                Node* NextTop = Stack->List;
                
                while ( NextTop != NULL && NextTop->NextNode != Stack->Top )
                    NextTop = NextTop->NextNode;

                NextTop->NextNode = NULL;

                free(Stack->Top->Data);
                free(Stack->Top);

                Stack->Top = NextTop;
            }
        }
        else if ( temp == L_PAREN || temp == ADD || temp == SUB || temp == DIV || temp == MUL ) // add a operator to stack
        {
            // printf( "operator\n" );
            if ( temp == SUB || temp == ADD )
            {   
                while ( Stack->Top != NULL )
                {
                    if ( Stack->Top->Data[0] == L_PAREN )
                        break;

                    
                    Node* TopNode = Stack->Top;

                    char operandInStack = TopNode->Data[0];
                    // printf("left stack: %c\n", operandInStack);

                    // add operators, which were in parenthesis, to postfix expression
                    postfixExpression[postfixPosition] = operandInStack;
                    postfixPosition++;
                    
                    // printf("pE: %s\n", postfixExpression);

                    Node* NextTop = Stack->List;
                    
                    while ( NextTop != NULL && NextTop->NextNode != Stack->Top )
                    {
                        // printf( "loop\n" );
                        
                        if ( TopNode != Stack->List )
                            NextTop = NextTop->NextNode;
                        else
                            break;
                    }

                    // if ( NextTop->Data[0] != NULL )
                    //     printf("next left stack: %c\n", NextTop->Data[0]);
                    // printf("next stack's next: %p\n", NextTop->NextNode);

                    NextTop->NextNode = NULL;
                    
                    if ( TopNode == Stack->List )
                    {
                        // printf("kkk\n");
                        free(TopNode->Data);
                        free(TopNode);

                        Stack->List = NULL;
                        Stack->Top = NULL;

                        // free(Stack);

                        break;
                    }
                    else
                    {
                        free(TopNode->Data);
                        free(TopNode);
                        
                        Stack->Top = NextTop;
                    }
                }
            }

            Node* NewNode = (Node*)malloc( sizeof( Node ) );
            NewNode->Data = (char*)malloc( sizeof( char ) );
            
            // Attention! NewNode->Data = &temp is not working!
            strcpy( NewNode->Data, &temp );
            NewNode->NextNode = NULL;

            // %s needs char*, %c needs char
            // printf( "new node's data: %c\n", NewNode->Data[0] );

            if ( Stack->List == NULL && Stack->Top == NULL )
            {
                Stack->List = NewNode;
                Stack->Top = NewNode;
            }
            else
            {
                Stack->Top->NextNode = NewNode;
                Stack->Top = NewNode;
            }
        }
        else
        {
            // printf( "operand\n" );
            postfixExpression[postfixPosition] = temp;
            postfixPosition++;
        }

        infixPosition++;
    }
    
    // printf( "infix length: %d\n", exprssionLength );
    // printf( "position: %d\n", infixPosition );
    // printf( "infix: %s\n", infixExpression );
    printf( "%s", postfixExpression );
    // printf( "Stack top: %c\n", Stack->Top->Data[0] );
    // printf( "Stack 2nd: %c\n", Stack->List->NextNode->Data );
    // printf( "Stack bottom: %c\n", Stack->List->Data[0] );

    // Node* tempNode = Stack->List;

    // printf( "Stack: " );

    // while ( 1 )
    // {
    //     printf( "%c", tempNode->Data[0] );

    //     if ( tempNode->NextNode == NULL )
    //     {
    //         printf( "\n" );
    //         break;
    //     }

    //     tempNode = tempNode->NextNode;
    // }

    return 0;
}
