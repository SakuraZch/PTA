
// 2020/3/24 //

#include <iostream>
#include <cstdlib>
#include <string>

int main()
{
    int sum = 0, size = 0;
    std::cin >> sum >> size;

    while(sum--)
    {
        std::string str;
        std::cin >> str;
        int SSum = 0, XSum = 0, tempEle = 0;
        bool flag = true;
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == 'S')
            {
                tempEle++;
                if(tempEle > size)
                {
                    flag = false;
                    break;
                }
                SSum++;
            }
            else if(str[i] == 'X')
            {
                tempEle--;
                if(tempEle < 0)
                {
                    flag = false;
                    break;
                }
                XSum++;
            }
        }
        if(flag == false || SSum != XSum)
        {
            std::cout << "NO" << std::endl;
            continue;
        }
        std::cout << "YES" << std::endl;
    }

    system("pause");
    return 0;
}