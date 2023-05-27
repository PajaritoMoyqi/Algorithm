#include <stdio.h>

int main()
{
    typedef unsigned long long ll;
    ll a;
    ll b;
    ll c;

    scanf("%lld %lld %lld", &a, &b, &c);
    printf("%lld", a + b + c);

    return 0;
}