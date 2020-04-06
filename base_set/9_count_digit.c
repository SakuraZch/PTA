
// 2020/3/8 //

#include <stdio.h>
#include <stdlib.h>

int Count_Digit ( const int N, const int D )
{
    int tar = (N > 0) ? N : -N;
    int res = 0, quo = tar, mod = tar % 10;

    if(mod == D && N == 0)
    {
        res++;
    }

    while(quo > 0)
    {
        if(mod == D)
        {
            res++;
        }
        quo /= 10;
        mod = quo % 10;
    }

    return res;
}

int main()
{
    int N, D;
	
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));

    system("pause");
    return 0;
}