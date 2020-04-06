#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int IsTheNumber ( const int N )
{
    int quo = N, mod = N % 10;
    int arr[10] = {0};
    int numTag = 0, sqrtTag = 0;
    while(quo != 0)
    {
        arr[mod]++;
        quo /= 10;
        mod = quo % 10;
    }
    
    for(int i = 0; i < 10; i++)
    {
        if(arr[i] >= 2)
        {
            numTag = 1;
        }
    }

    if(sqrt(N) - (int)sqrt(N) < 1e-5)
    {
        sqrtTag = 1;
    }

    if(numTag == 1 && sqrtTag == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n1, n2, i, cnt;
	
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    system("pause");
    return 0;
}