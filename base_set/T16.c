
// 2020/3/16 //

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1 = 0, num2 = 0;

    scanf("%d %d", &num1, &num2);

    if(num1 == num2)
    {
        printf("Number1 is equal to number2.\n");
    }
    else
    {
        printf("Number1 is not equal to number2.\n");
        if(num1 > num2)
        {
            printf("Number1 is bigger than number2.\n");
        }
        if(num1 < num2)
        {
            printf("Number1 is smaller than number2.\n");
        }
    }

    if(num1 % num2 == 0)
    {
        printf("Number1 can be exactly divided by Number2.\n");
    }
    if(num2 % num1 == 0)
    {
        printf("Number2 can be exactly divided by Number1.\n");
    }
    
    system("pause");
    return 0;
}