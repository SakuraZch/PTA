
// 2020/3/8 //

#include <stdio.h>
#include <stdlib.h>

void PrintN(int N)
{
    for(int i = 1; i <= N; i++)
    {
        printf("%d\n", i);
    }
}

int main()
{
    int N;

    scanf("%d", &N);
    PrintN(N);

    system("pause");
    return 0;
}