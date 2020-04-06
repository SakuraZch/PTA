
// 2020/3/25 //

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stack>
#include <cctype>

int flag = 0;
void print()
{
    if(flag != 0)
    {
        std::cout << ' ';
    }
    flag = 1;

    return ;
}

int main()
{
    std::stack<char> S;
    std::string str;
    std::cin >> str;
    int len = str.size();
    for(int i = 0; i < len; i++)
    {
        // 1.signed number in the head / 2.signed number after the left bracket / 3.common number
        if(((str[i] == '+' || str[i] == '-') && (i == 0 || str[i - 1] == '(')) || isdigit(str[i]))
        {
            print();

            if(str[i] != '+') // ignore positive sign
            {
                std::cout << str[i];
            }

            // take decimals and integer with some bits into consideration  
            while(str[i + 1] == '.' || isdigit(str[i + 1]))
            {
                std::cout << str[++i];
            }
        }
        else // normal operation signs
        {
            if(str[i] == ')') // right bracket
            {
                // clear the part that upon the left bracket
                while(!S.empty() && S.top() != '(')
                {
                    print();
                    std::cout << S.top();
                    S.pop();
                }

                if(!S.empty()) // pop the left bracket, which need not output
                {
                    S.pop();
                }
            }
            else // other signs
            {
                if(S.empty()) // stack is empty, then fill it by sign
                {
                    S.push(str[i]);
                    continue;
                }

                // push according to the state of stack
                while(!S.empty() && S.top() != '(')
                {
                    // deal sign according to the priority and the present character
                    if(str[i] == '(' || ((str[i] == '*' || str[i] == '/') && (S.top() == '-' || S.top() == '+')))
                    {
                        break;
                    }
                    else
                    {
                        print();
                        std::cout << S.top();
                        S.pop();
                    }
                }

                S.push(str[i]);
            }
        }
    }

    // clear the stack
    while(!S.empty())
    {
        print();
        if(S.top() != '(')
        {
            std::cout << S.top();
        }
        S.pop();
    }

    system("pause");
    return 0;
}

// #include <map>
// #include <cmath>
// #include <stack>
// #include <string>
// #include <cstring>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int flag;

// void print() {
// 	if (flag) {
// 		putchar(' ');
// 	}
// 	flag = 1;

// 	return;
// }
// int main() {

// 	char str[110], p[110];

// 	cin >> str;
// 	int i, t, len;
// 	t = 0; 
// 	len = strlen(str);
// 	for (int i = 0; i < len; i++) {
// 		if ((str[i] == '+' || str[i] == '-') && (!i || str[i - 1] == '(') || (str[i] >= '0' && str[i] <= '9')) {
// 			print();

// 			if (str[i] != '+') {
// 				cout << str[i];
// 			}

// 			while (str[i + 1] == '.' || (str[i + 1] >= '0' && str[i + 1] <= '9')) {
// 				cout << str[++i];
// 			}
// 		}
// 		else {
// 			if (str[i] == ')') {
// 				while (t && p[t - 1] != '(') {
// 					print();
// 					cout << p[--t];
// 				}

// 				if (t) {
// 					--t;
// 				}
// 			}
// 			else {
// 				if (!t) {
// 					p[t++] = str[i];
// 					continue;
// 				}
				
// 				while (t && p[t - 1] != '(') {
// 					if (str[i] == '(' || ((str[i] == '*' || str[i] == '/') && (p[t - 1] == '-' || p[t - 1] == '+'))) {
// 						break;
// 					}

// 					print();
// 					cout << p[--t];
// 				}

// 				p[t++] = str[i];
// 			}
// 		}
// 	}
// 	while (t) {
// 		print();
// 		if (p[t - 1] != '(') {
// 			cout << p[t - 1];
// 		}
// 		t--;
// 	}

// 	system("pause");

// 	return 0;
// }
