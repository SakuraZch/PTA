
// 2020/3/8 //

#include <stdio.h>
#include <stdlib.h>

int even( int n )
{
    return (n % 2 == 0) ? 1 : 0;
}

int main()
{    
    int n;

    scanf("%d", &n);
    if (even(n))
        printf("%d is even.\n", n);
    else
        printf("%d is odd.\n", n);

    system("pause");
    return 0;
}