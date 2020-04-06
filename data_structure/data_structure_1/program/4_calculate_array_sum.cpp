
// 2020/3/22 //

#include <iostream>
#include <cstdlib>
#include <vector>

const int MaxLen = 100000;

int main()
{
    std::vector<int> res(MaxLen, 0);
    int num = 0, len = 0;
    std::cin >> num >> len;

    if(len == 0)
    {
        std::cout << "0" << std::endl;
        system("pause");
        return 0;
    }

    int tempSum = 0, reminder = 0, ind = 0;
    for(ind = 0; ind < len; ind++)
    {
        tempSum = num * (len - ind) + reminder;
        res[ind] = tempSum % 10;
        reminder = tempSum / 10;
    }
    if(reminder != 0)
    {
        res[ind] = reminder;
    }
    else
    {
        ind--;
    }

    while(ind >= 0)
    {
        std::cout << res[ind];
        ind--;
    }
    std::cout << std::endl;

    system("pause");
    return 0;
}