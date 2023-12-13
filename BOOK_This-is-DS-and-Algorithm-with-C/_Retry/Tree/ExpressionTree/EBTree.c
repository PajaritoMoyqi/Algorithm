#include "EBTree.h"

EBTNode* CreateNode( ElemType data )
{
    EBTNode* NewNode = (EBTNode*)malloc( sizeof( EBTNode ) );

    NewNode->Data = data;
    NewNode->Left = NULL;
    NewNode->Right = NULL;

    return NewNode;
}

void DestroyTree( EBTNode* N )
{
    if ( N == NULL ) return;

    DestroyTree( N->Left );
    DestroyTree( N->Right );
    free( N );
}

void PreorderPrintEBT( EBTNode* N )
{
    if ( N == NULL ) return;

    printf( " %c", N->Data );
    PreorderPrintEBT( N->Left );
    PreorderPrintEBT( N->Right );
}

void InorderPrintEBT( EBTNode* N )
{
    if ( N == NULL ) return;

    InorderPrintEBT( N->Left );
    printf( " %c", N->Data );
    InorderPrintEBT( N->Right );
}

void PostorderPrintEBT( EBTNode* N )
{
    if ( N == NULL ) return;

    PreorderPrintEBT( N->Left );
    PreorderPrintEBT( N->Right );
    printf( " %c", N->Data );
}

void BuildExpressionTree( char* PostfixExpression, EBTNode** N )
{
    int length = strlen( PostfixExpression );
    char Token = PostfixExpression[length-1];
    PostfixExpression[length-1] = '\0';

    switch( Token )
    {
        case '+': case '-': case '*': case '/':
            (*N) = CreateNode( Token );

            BuildExpressionTree( PostfixExpression, &(*N)->Right );
            BuildExpressionTree( PostfixExpression, &(*N)->Left );

            break;

        default:
            (*N) = CreateNode( Token );
            break;
    }
}

double Evaluate( EBTNode* Tree )
{
    char Tmp[2];

    double Left = 0;
    double Right = 0;
    double Result = 0;

    if ( Tree == NULL ) return 0;

    switch( Tree->Data )
    {
        case '+': case '-': case '*': case '/':
            Left = Evaluate( Tree->Left );
            Right = Evaluate( Tree->Right );

            if ( Tree->Data == '+' ) Result = Left + Right;
            else if ( Tree->Data == '-' ) Result = Left - Right;
            else if ( Tree->Data == '*' ) Result = Left * Right;
            else if ( Tree->Data == '/' ) Result = Left / Right;

            break;

        default:
            memset( Tmp, 0, sizeof( Tmp ) );
            Tmp[0] = Tree->Data;
            Result = atof( Tmp );

            break;
    }

    return Result;
}