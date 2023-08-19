#include <stdio.h>

int main( void )
{
    long long LLInt, p = 1LL, cnt = 0LL;
    char ans[1000001];
    scanf( "%lld", &LLInt );
    long long copy = LLInt;

    while ( copy )
    {
        p <<= 1; // 2 power number, next to LLInt
        copy >>= 1;
        cnt++;
    }

    long long dif = p - LLInt;
    // printf( "%lld %lld %lld %lld\n", p, LLInt, cnt, dif );
    
    if ( dif == 1 )
    {
        while ( cnt )
        {
            cnt--;
            ans[cnt] = '4';
            dif >>= 1;
        }
    }
    else
    { 
        dif = p/2 - dif + 1;
        cnt -= 1;

        while ( cnt )
        {
            cnt--;
            ans[cnt] = (dif & 1) ? '7' : '4';
            dif >>= 1;
        }
    }

    printf( "%s", ans );
}