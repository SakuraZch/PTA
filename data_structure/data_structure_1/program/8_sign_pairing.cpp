
// 2020/3/24 //

#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <queue>
#include <map>

int main()
{
    std::map<char, char> M;
    std::stack<char> S;
    std::queue<char> Q;
    std::string sum, temp;

    M[')'] = '(';
    M[']'] = '[';
    M['}'] = '{';
    M['>'] = '<';

    int tag = 0;
    while(std::getline(std::cin, temp) && temp != ".")
    {
        sum += temp;
    }

    for(int i = 0; i < int(sum.size()); i++)
    {
        if(sum[i] == '(' || sum[i] == '[' || sum[i] == '{')
        {
            S.push(sum[i]);
        }
        else if(sum[i] == '/' && sum[i + 1] == '*')
        {
            S.push('<');
            i++;
        }
        else if(sum[i] == ')' || sum[i] == ']' || sum[i] == '}')
        {
            if(!S.empty() && S.top() == M[sum[i]])
            {
                S.pop();
            }
            else if(S.empty())
            {
                tag = 1;
                Q.push(sum[i]);
                break;
            }
            else if(!S.empty() && S.top() != M[sum[i]])
            {
                Q.push(sum[i]);
                break;
            }
        }
        else if(sum[i] == '*' && sum[i + 1] == '/')
        {
            if(!S.empty() && S.top() == '<')
            {
                S.pop();
            }
            else if(S.empty())
            {
                tag = 1;
                Q.push('>');
                break;
            }
            else if(!S.empty() && S.top() != '*')
            {
                Q.push('>');
                break;
            }
            i++;
        }
    }

    if(Q.empty() && S.empty())
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
        if(tag == 1)
        {
            if(!Q.empty() && Q.front() != '>')
            {
                std::cout << "?-" << Q.front() << std::endl;
            }
            else if(!Q.empty() && Q.front() == '>')
            {
                std::cout << "?-*/" << std::endl;
            }
        }
        else if(tag == 0)
        {
            char temp = S.top();
            if(temp != '<')
            {
                std::cout << temp << "-?" << std::endl;
            }
            else
            {
                std::cout << "/*-?" << std::endl;
            }
        }
    }

    system("pause");
    return 0;
}

// // 2020/3/24 //

// #include <iostream>
// #include <cstdlib>
// #include <stack>
// #include <string>
// #include <map>
// #include <algorithm>
// #include <vector>

// const std::string EndStr = ".";

// int main()
// {
//     std::string str;
//     std::vector<char> vec1(100, '0'), vec2(100, '0');
//     int ind1 = 0, ind2 = 0, flag = 1;
//     std::map<char, char> M;
//     M['('] = ')';
//     M['{'] = '}';
//     M['['] = ']';
//     M['<'] = '>';

//     // use vector to store symbols 
//     while(std::getline(std::cin, str) && str != EndStr)
//     {
//         for(int i = 0; i < str.size(); i++)
//         {
//             if(str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']' || str[i] == '{' || str[i] == '}')
//             {
//                 vec1[ind1++] = str[i];
//             }
//             else if(str[i] == '/' && str[i + 1] == '*')
//             {
//                 vec1[ind1++] = '<';
//                 i++;
//             }
//             else if(str[i] == '*' && str[i + 1] == '/')
//             {
//                 vec1[ind1++] = '>';
//                 i++;
//             }
//         }
//     }

//     // judge symbols stored
//     for(int i = 0; i < ind1; i++)
//     {
//         if(vec1[i] == '(' || vec1[i] == '[' || vec1[i] == '{' || vec1[i] == '<')
//         {
//             vec2[ind2++] = vec1[i];
//         }
//         else if(ind2 != 0 && M[vec2[ind2 - 1]] == vec1[i])
//         {
//             ind2--;
//         }
//         else
//         {
//             std::cout << "NO" << std::endl;
//             if(ind2 == 0)
//             {
//                 if(vec1[i] == '>')
//                 {
//                     std::cout << "?-*/" << std::endl;
//                 }
//                 else
//                 {
//                     std::cout << "?-" << vec1[i] << std::endl;
//                 }
//             }
//             else
//             {
//                 if(vec2[ind2 - 1] == '<')
//                 {
//                     std::cout << "/*-?" << std::endl;
//                 }
//                 else
//                 {
//                     std::cout << vec2[ind2 - 1] << "-?" << std::endl;
//                 }
//             }
//             flag = 0;
//             break;
//         }
//     }

//     if(flag != 0)
//     {
//         if(ind2 == 0)
//         {
//             std::cout << "YES" << std::endl;
//         }
//         else
//         {
//             std::cout << "NO" << std::endl;
//             if(vec2[ind2 - 1] == '<')
//             {
//                 std::cout << "/*-?" << std::endl;
//             }
//             else
//             {
//                 std::cout << vec2[ind2 - 1] << "-?" << std::endl;
//             }   
//         }   
//     }

//     system("pause");
//     return 0;
// }