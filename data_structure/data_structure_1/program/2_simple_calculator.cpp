
// 2020/3/22 //

#include <iostream>
#include <cstdlib>

int main()
{
    int num = 0, res = 0;
    char op = '0';

    std::cin >> num;
    res = num;

    while(true)
    {
        std::cin >> op;
        if(op == '=')
        {
            break;
        }

        std::cin >> num;
        if(op == '+')
        {
            res += num;
        }
        else if(op == '-')
        {
            res -= num;
        }
        else if(op == '*')
        {
            res *= num;
        }
        else if(op == '/')
        {
            if(num == 0)
            {
                printf("ERROR\n");
                system("pause");
                return 0;
            }
            res /= num;
        }
        else
        {
            printf("ERROR\n");
            system("pause");
            return 0;
        }
        
    }

    std::cout << res << std::endl;

    system("pause");
    return 0;
}