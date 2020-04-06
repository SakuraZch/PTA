
// 2020/3/22 //

// #include <iostream>
// #include <cstdlib>
// #include <vector>
// #include <algorithm>
// #include <string>

// std::vector<int> vec = {1, 2, 3, 4, 5, 6 ,7, 8, 9};

// void Perm(std::vector<int> v, int k, int n)
// {
//     if(k == n - 1)
//     {
//         for(int i = 0; i < n; i++)
//         {
//             std::cout << v[i];
//         }
//         std::cout << std::endl;
//     }
//     else
//     {
//         for(int i = k; i < n; i++)
//         {
//             std::swap(v[i], v[k]);
//             Perm(v, k + 1, n);
//             std::swap(v[i], v[k]);
//         }
//     }
// }

// void Perm2(std::string str)
// {
//     std::sort(str.begin(), str.end());

//     do
//     {
//         std::cout << str << std::endl;
//     }while(std::next_permutation(str.begin(), str.end()));
    
// }

// int main()
// {
//     // int n = 0;
//     // std::cin >> n;

//     // if(n == 1)
//     // {
//     //     std::cout << "1" << std::endl;
//     // }
//     // else
//     // {
//     //     Perm(vec, 0, n);
//     // }

//     std::string str = "12345";
//     Perm2(str);
    
//     system("pause");
//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <vector>

std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void print_permutation(int n)
{
    while(1)
    {
        for(int i = 0; i < n; i++)
        {
            std::cout << vec[i];
        }
        std::cout << std::endl;

        int len = 1, pos = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            if(vec[i] > vec[i - 1])
            {
                pos = i - 1;
                break;
            }
            else
            {
                len++;
            }
        }

        if(len == n)
        {
            break;
        }

        int des = 0;
        for(int i = n - 1; i >= n - len; i--)
        {
            if(vec[i] > vec[pos])
            {
                des = i;
                break;
            }
        }

        std::swap(vec[pos], vec[des]);

        for(int i = 1; i <= len / 2; i++)
        {
            std::swap(vec[pos + i], vec[n - i]);
        }
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    print_permutation(n);

    return 0;
}