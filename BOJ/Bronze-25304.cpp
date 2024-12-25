#include <iostream>

int main()
{
    int total;
    std::cin >> total;

    int t;
    std::cin >> t;
    while ( t-- )
    {
        int amount, price;
        std::cin >> price >> amount;

        total -= price*amount;
    }

    if ( !total )
        std::cout << "Yes";
    else
        std::cout << "No";

    return 0;
}