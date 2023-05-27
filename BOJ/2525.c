#include <stdio.h>

int main()
{
    int hour, minute, remainingMinute;

    scanf("%d %d %d", &hour, &minute, &remainingMinute);

    minute += remainingMinute;

    while ( minute >= 60 )
    {
        minute -= 60;

        if ( hour == 23 )
            hour = 0;
        else
            hour += 1;
    }

    printf("%d %d", hour, minute);

    return 0;
}