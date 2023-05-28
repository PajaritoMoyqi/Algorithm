#include "ArrayStack.h"

int main()
{
    int i = 0;
    ArrayStack* Stack = NULL;

    AS_CreateStack(&Stack, 10);

    AS_Push(Stack, 3);
    AS_Push(Stack, 37);
    AS_Push(Stack, 11);
    AS_Push(Stack, 12);

    printf( "Capacity: %d, Size: %d, Top: %d\n\n", Stack->Capacity, AS_GetSize( Stack ), Stack->Top );

    for ( i = 0; i < 4; i++ )
    {
        if ( AS_IsEmpty( Stack ) )
            break;
        
        printf( "Popped: %d   ", AS_Pop( Stack ) );

        if ( ! AS_IsEmpty( Stack ) )
            printf( "Current Top: %d\n", AS_Top( Stack ) );
        else
            printf( "Stack is now empty." );
    }

    AS_DestroyStack( Stack );

    return 0;
}