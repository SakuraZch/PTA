
// 2020/3/8 //

#include <stdio.h>
#include <stdlib.h>

int num[3000];

void Print_Factorial ( const int N )
{
    if(N < 0)
    {
        printf("Invalid input\n");
        return ;
    }
    else if(N == 0 || N == 1)
    {
        printf("1\n");
        return ;
    }

    num[1] = 1;
    int len = 1, temp = 0;
    for(int i = 2; i <= N; i++)
    {
        int step = 0;
        for(int j = 1; j <= len; j++)
        {
            temp = num[j] * i + step;
            printf("num[j]1: %d\n", num[j]);
            printf("tp: %d\n", temp);
            num[j] = temp % 10;
            printf("num[j]2: %d\n", num[j]);
            step = temp / 10;
            if(j >= len && step != 0)
            {
                len++;
            }
        }
    }
    for(int i = len; i >= 1; i--)
    {
        printf("%d", num[i]);
    }
    printf("\n");
}

int main()
{
    int N;
	
    scanf("%d", &N);
    Print_Factorial(N);

    system("pause");
    return 0;
}