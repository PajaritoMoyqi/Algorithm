#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    int money;
    if ( a == b && b == c )
    {
        money = 10000 + a*1000;
    }
    else if ( a == b || b == c || c == a )
    {
        int same;
        if ( a == b || a == c )
        {
            same = a;
        }
        else
        {
            same = b;
        }

        money = 1000 + same*100;
    }
    else
    {
        int max;
        max = a;
        if ( max < b )
            max = b;
        if ( max < c )
            max = c;

        money = max*100;
    }

    std::cout << money;

    return 0;
}