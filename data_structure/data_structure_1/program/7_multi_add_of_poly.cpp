
// 2020/3/23 //

#include <iostream>
#include <cstdlib>
#include <vector>

void PrintVec(const std::vector<int>& vec)
{
    int len = vec.size(), ind = 0;
    for(int i = 0; i < len; i++)
    {
        if(vec[i] != 0)
        {
            ind = i;
            break;
        }
    }
    for(int i = len - 1; i != ind; i--)
    {
        if(vec[i] != 0)
        {
            std::cout << vec[i] << " " << i << " ";
        }
    }
    std::cout << vec[ind] << " " << ind << std::endl;
}

void multi(const std::vector<int>& poly1, const std::vector<int>& poly2)
{
    int lenFull = poly1[1] + poly2[1] + 1, len1 = poly1.size() / 2, len2 = poly2.size() / 2;
    if((len1 == 1 && poly1[0] == 0 && poly1[1] == 0) || (len2 == 1 && poly2[0] == 0 && poly2[1] == 0))
    {
        std::cout << "0 0" << std::endl;
        return ;
    }

    std::vector<int> res(lenFull, 0);
    for(int i = 0; i < 2 * len1; i += 2)
    {
        for(int j = 0; j < 2 * len2; j += 2)
        {
            res[poly1[i + 1] + poly2[j + 1]] += poly1[i] * poly2[j];
        }
    }

    PrintVec(res);
}

void add(const std::vector<int>& poly1, const std::vector<int>& poly2)
{
    int lenFull = (poly1[1] + 1 >= poly2[1] + 1) ? poly1[1] + 1 : poly2[1] + 1, len1 = poly1.size() / 2, len2 = poly2.size() / 2;

    std::vector<int> res(lenFull, 0);
    for(int i = 0; i < 2 * len1 ; i += 2)
    {
        res[poly1[i + 1]] += poly1[i];
    }
    for(int i = 0; i < 2 * len2 ; i += 2)
    {
        res[poly2[i + 1]] += poly2[i];
    }

    PrintVec(res);
}

int main()
{
    int len1 = 0, len2 = 0;
    std::cin >> len1;
    if(len1 == 0)
    {
        len1 = 1;
    }
    std::vector<int> poly1(2 * len1, 0);
    for(int i = 0; i < 2 * len1; i++)
    {
        std::cin >> poly1[i];
    }
    std::cin >> len2;
    if(len2 == 0)
    {
        len2 = 1;
    }
    std::vector<int> poly2(2 * len2, 0);
    for(int i = 0; i < 2 * len2; i++)
    {
        std::cin >> poly2[i];
    }

    multi(poly1, poly2);
    add(poly1, poly2);

    system("pause");
    return 0;
}

// #include <iostream>
// #include <map>
// #include <algorithm>
// using namespace std;
// struct poly
// {
//     int a,b;
// }r1[1000],r2[1000];
// int ans[1000000],ant = 0;
// int main()
// {
//     int a,b,flag = 0,e;
//     cin>>a;
//     for(int i = 0;i < a;i ++)
//     {
//         cin>>r1[i].a>>r1[i].b;
//     }
//     cin>>b;
//     for(int i = 0;i < b;i ++)
//     {
//         cin>>r2[i].a>>r2[i].b;
//     }
//     map<int,int>p,q;
//     for(int i = 0;i < a;i ++)
//     {
//         for(int k = 0;k < b;k ++)
//         {
//             if(p[r1[i].b + r2[k].b] == 0)ans[ant ++] = r1[i].b + r2[k].b;
//             p[r1[i].b + r2[k].b] += r1[i].a*r2[k].a;
//         }
//     }
//     e = 0;
//     sort(ans,ans+ant);
//     for(int i = ant - 1;i >= 0;i --)
//     if(p[ans[i]])
//     {
//         e ++;
//         if(flag)cout<<' '<<p[ans[i]]<<' '<<ans[i];
//         else
//         {
//             cout<<p[ans[i]]<<' '<<ans[i];
//             flag = 1;
//         }
//     }
//     if(e == 0)cout<<0<<' '<<0;
//     cout<<endl;
//     ant = 0;
//     e = 0;
//     for(int i = 0;i < a;i ++)
//     {
//         if(q[r1[i].b] == 0)ans[ant ++] = r1[i].b;
//         q[r1[i].b] += r1[i].a;
//     }
//     for(int i = 0;i < b;i ++)
//     {
//         if(q[r2[i].b] == 0)ans[ant ++] = r2[i].b;
//         q[r2[i].b] += r2[i].a;
//     }
//     if(ant == 0)cout<<0<<' '<<0;
//     sort(ans,ans+ant);
//     flag = 0;
//     for(int i = ant - 1;i >= 0;i --)
//     if(q[ans[i]])
//     {
//         e ++;
//         if(flag)cout<<' '<<q[ans[i]]<<' '<<ans[i];
//         else
//         {
//             flag = 1;
//             cout<<q[ans[i]]<<' '<<ans[i];
//         }
//     }
//     if(e == 0)cout<<0<<' '<<0;

//     system("pause");
//     return 0;
// }
 