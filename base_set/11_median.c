
// 2020/3/8 //

#include <stdio.h>
#include <stdlib.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N )
{
    int i, j, inc;
    ElementType temp;
    for(inc = N / 2; inc > 0; inc /= 2)
    {
        for(i = inc; i < N; i++)
        {
            temp = A[i];
            for(j = i; j >= inc; j -= inc)
            {
                if(temp < A[j - inc])
                {
                    A[j] = A[j - inc];
                }
                else
                {
                    break;
                }
            }
            A[j] = temp;
        }
    }

    return A[ N / 2 ];  
}

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    system("pause");
    return 0;
}