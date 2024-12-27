#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;
    int arr[a+1];

    int i;
    for ( i = 1; i <= a; i++ )
    {
        arr[i] = i;
    }

    while ( b-- )
    {
        int j, k;
        std::cin >> j >> k;
        for ( i = 0; i <= k; i++ )
        {
            if ( j + i == k - i || j + i > k - i )
            {
                break;
            }
            
            int tmp = arr[j+i];
            arr[j+i] = arr[k-i];
            arr[k-i] = tmp;
        }
    }

    for ( i = 1; i <= a; i++ )
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}