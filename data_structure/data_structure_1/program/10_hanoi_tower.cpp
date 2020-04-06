
// 2020/3/24 //

#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>

// recursion
// void hanoi(int N, std::string a, std::string b, std::string c)
// {
//     if(N == 1)
//     {
//         std::cout << a << " -> " << c << std::endl;
//     }
//     else
//     {
//         hanoi(N - 1, a, c, b);
//         std::cout << a << " -> " << c << std::endl;
//         hanoi(N - 1, b, a, c);
//     }
// }

// iteration
struct Quad
{
    int num_;
    std::string a_, b_, c_;

    Quad();
    Quad(int num, std::string a, std::string b, std::string c):
        num_(num), a_(a), b_(b), c_(c){}
};

void hanoi(int num, std::string a, std::string b, std::string c)
{
    std::stack<Quad> S;
    S.push(Quad(num, a, b, c));
    while(!S.empty())
    {
        Quad temp = S.top();
        S.pop();
        num = temp.num_;
        a = temp.a_;
        b = temp.b_;
        c = temp.c_;
        if(num == 1)
        {
            std::cout << temp.a_ << " -> " << temp.c_ << std::endl;
        }
        else
        {
            S.push(Quad(num - 1, b, a, c));
            S.push(Quad(1, a, b, c));
            S.push(Quad(num - 1, a, c, b));
        }
    }
}

int main()
{
    int N = 0;
    std::cin >> N;
    hanoi(N, "a", "b", "c");

    system("pause");
    return 0;
}


// // 2020/3/24 //

// #include <iostream>
// #include <cstdlib>
// #include <string>
// #include <stack>

// // iteration
// struct Quad
// {
//     int num_;
//     char a_, b_, c_;

//     Quad();
//     Quad(int num, char a, char b, char c):
//         num_(num), a_(a), b_(b), c_(c){}
// };

// int main()
// {
//     int num = 0;
//     std::cin >> num;
//     std::stack<Quad> S;
//     Quad temp(num, 'a', 'b', 'c');
//     S.push(temp);
//     while(!S.empty())
//     {
//         Quad temp = S.top();
//         S.pop();
//         if(temp.num_ == 1)
//         {
//             std::cout << temp.a_ << " -> " << temp.c_ << std::endl;
//         }
//         else
//         {
//             S.push(Quad(temp.num_ - 1, temp.b_, temp.a_, temp.c_));
//             S.push(Quad(1, temp.a_, temp.b_, temp.c_));
//             S.push(Quad(temp.num_ - 1, temp.a_, temp.c_, temp.b_));
//         }
//     }

//     system("pause");
//     return 0;
// }