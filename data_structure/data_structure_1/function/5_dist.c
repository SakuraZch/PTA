
// 2020/3/17 //

#include <stdio.h>
#include <stdlib.h>
#define TOL 1E-2

double dist( double h, double p );

int main()
{
    double h, p, d;
    scanf("%lf %lf", &h, &p);
    d = dist(h, p);
    printf("%.6f\n", d);

    system("pause");
    return 0;
}

/* 你的代码将被嵌在这里 */
double dist( double h, double p )
{
    if(h - 0.0 < TOL)
    {
        return h;
    }
    double sum = h, curr = h * p;
    while(curr >= TOL)
    {
        sum += curr * 2;
        curr *= p;
    }

    return sum;
}
