
// 2020/3/22 //

#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
    int len = 0;
    std::cin >> len;
    
    std::vector<int> vec(len, 0);
    for(int i = 0; i < len; i++)
    {
        std::cin >> vec[i];
    }

    int maxSum = vec[0], temp = vec[0];
    for(int i = 1; i < len; i++)
    {
        if(temp <= 0)
        {
            temp = vec[i];
        }
        else
        {
            temp += vec[i];
        }

        if(maxSum < temp)
        {
            maxSum = temp;
        }
    }

    std::cout << maxSum << std::endl;

    system("pause");
    return 0;
}