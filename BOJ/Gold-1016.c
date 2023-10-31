#include <stdio.h>
#include <math.h>

int Arr[1000001];
int main( void )
{
    long long min, max, i, j, power;
    scanf( "%lld %lld", &min, &max );

    int sqMax = (int)sqrt(max), cnt = max - min + 1;
    for ( i = 2; i <= sqMax; i++ )
    {
        power = i*i;
        for ( j = ((min - 1) / power + 1) * power; j <= max; j += power )
            Arr[j-min] = 1;
    } 

    for ( i = 0; i < (max - min + 1); i++ )
        Arr[i] && cnt--;

    printf( "%d", cnt );

    return 0;
}