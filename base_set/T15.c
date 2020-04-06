
// 2020/3/16 //

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1 = 0, num2 = 0, num3 = 0;

    scanf("%d %d %d", &num1, &num2, &num3);

    int sum = num1 + num2 + num3;
    double avg = sum / 3.0;
    int max = 0;
    if(num2 <= num1 && num3 <= num1)
    {
        max = num1;
    }
    else if(num1 <= num2 && num3 <= num2)
    {
        max = num2;
    }
    else if(num1 <= num3 && num2 <= num3)
    {
        max = num3;
    }

    int min = 0;
    if(num2 >= num1 && num3 >= num1)
    {
        min = num1;
    }
    else if(num1 >= num2 && num3 >= num2)
    {
        min = num2;
    }
    else if(num1 >= num3 && num2 >= num3)
    {
        min = num3;
    }
	
    printf("Three numbers: %d, %d, %d\n", num1, num2, num3);
    printf("Sum: %d\n", sum);
    printf("Average: %.2lf\n", avg);
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);

    system("pause");
    return 0;
}

