#include <stdio.h>
#include <stdlib.h>
#define MAXN 10

double f(int n, double a[], double x)
{
    double res = 0.0;
    double tempPow = 1.0;
    for(int i = 0; i <= n; i++)
    {
        res += a[i] * tempPow;
        tempPow *= x;
    }

    return res;
}

int main()
{
    int n, i;
    double a[MAXN], x;
	
    scanf("%d %lf", &n, &x);
    for ( i=0; i<=n; i++ )
        scanf("%lf", &a[i]);
    printf("%.1f\n", f(n, a, x));
    system("pause");
    return 0;
}

