
// 2020/3/22 //

#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
    bool tag = false;
    int len = 0, maxTotal = 1, maxTemp = 1, endIndTotal = 0, endIndTemp = 0;
    
    std::cin >> len;
    std::vector<int> vec(len, 0);
    for(int i = 0; i < len; i++)
    {
        std::cin >> vec[i];
    }

    for(int i = 1; i < len; i++)
    {
        if(vec[i] > vec[i - 1])
        {
            maxTemp++;
            endIndTemp = i;
        }
        else
        {
            maxTemp = 1;
        }
        
        if(maxTemp > maxTotal)
        {
            maxTotal = maxTemp;
            endIndTotal = endIndTemp;
        }
    }

    for(int i = endIndTotal - maxTotal + 1; i < endIndTotal; i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << vec[endIndTotal] << std::endl;

    system("pause");
    return 0;
}

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n,r = 0,c = 1,maxi = 0;
//     int num[100000];
//     cin>>n;
//     for(int i = 0;i < n;i ++)
//     {
//         cin>>num[i];
//     }
//     for(int i = 1;i < n;i ++)
//     {
//         if(num[i] <= num[i - 1])
//         {
//             if(c > maxi)maxi = c,r = i - 1;
//             c = 1;
//             continue;
//         }
//         c ++;
//     }
//     if(c > maxi)maxi = c,r = n - 1;
//     for(int i = maxi - 1;i >= 0;i --)
//     {
//         if(i == maxi - 1)cout<<num[r - i];
//         else cout<<' '<<num[r - i];
//     }
//     system("pause");

//     return 0;
// }