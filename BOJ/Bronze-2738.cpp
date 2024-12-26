#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;

    int arr[a][b];
    int arr2[a][b];
    int i, j;
    for ( i = 0; i < a; i++ )
    {
        for ( j = 0; j < b; j++ )
        {
            std::cin >> arr[i][j];
        }
    }
    for ( i = 0; i < a; i++ )
    {
        for ( j = 0; j < b; j++ )
        {
            std::cin >> arr2[i][j];
        }
    }

    
    for ( i = 0; i < a; i++ )
    {
        for ( j = 0; j < b; j++ )
        {
            std::cout << arr[i][j] + arr2[i][j] << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}