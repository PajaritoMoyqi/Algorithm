#include <stdio.h>

int main()
{
    char str[1001];
    int idx;
    
    scanf("%s", &str);
    scanf("%d", &idx);
    printf("%c\n", str[idx-1]);

    return 0;
}