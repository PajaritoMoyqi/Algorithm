#include <stdio.h>

int main()
{
    int ff, fm;

    while ( 1 )
    {
        scanf("%d %d", &fm, &ff);
        if ( !fm && !ff )
            break;

        printf("%d", fm+ff);
    }

    return 0;
}