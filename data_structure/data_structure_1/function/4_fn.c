
// 2020/3/17 //

#include <stdio.h>
#include <stdlib.h>

double fn( double x, int n );

int main()
{
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    printf("%.2f\n", fn(x,n));

    return 0;
}

/* 你的代码将被嵌在这里 */
double fn( double x, int n )
{
    if(n == 1)
    {
        return x;
    }
    else
    {
        int sign = (n % 2 == 0) ? -1 : 1;
        double pow = 1.0;
        for(int i = 0; i < n; i++)
        {
            pow *= x;
        }
        pow *= sign;

        return pow + fn(x, n - 1);
    }
}
