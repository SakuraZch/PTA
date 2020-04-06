#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int lower = 0, upper = 0;
    scanf("%d %d", &lower, &upper);

    if(lower > upper)
    {
        printf("Invalid.\n");
    }
    else
    {
        printf("fahr celsius\n");
        for(int i = lower; i <= upper; i += 2)
        {
            printf("%d%6.1lf\n", i, 5.0 * (i - 32) / 9);
        }
    }

    system("pause");
    return 0;
}