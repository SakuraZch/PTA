
// 2020/3/22 //

#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
    int len = 0, step = 0;
    std::cin >> len >> step;

    step %= len;

    std::vector<int> vec(len, 0);
    for(int i = len - step; i < len; i++)
    {
        std::cin >> vec[i];
    }
    for(int i = 0; i < len - step; i++)
    {
        std::cin >> vec[i];
    }

    for(int i = 0; i < len - 1; i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << vec[len - 1] << std::endl;

    system("pause");
    return 0;
}