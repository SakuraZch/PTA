#include <stdio.h>
#include <stdlib.h>

typedef struct fruitStruct
{
    char name[7];
    double price;
}fruitStruct;

int main()
{
    fruitStruct fruits[4] = {
        {"apple", 3.00},
        {"pear", 2.50},
        {"orange", 4.10},
        {"grape", 10.20}
    };
    for(int i = 0; i < 4; i++)
    {
        printf("[%d] %s\n", i + 1, fruits[i].name);
    }
    printf("[0] exit\n");

    int times = 0, ind = 0;
    scanf("%d", &ind);
    while(times < 5)
    {
        if(1 <= ind && ind <= 4)
        {
            printf("price = %.2lf\n", fruits[ind - 1].price);
        }
        else if(ind == 0)
        {
            break;
        }
        else
        {
            printf("price = 0.00\n");
        }
        times++;
        scanf("%d", &ind);
    }

    while(scanf("%d", &ind) != EOF){ }

    system("pause");
    return 0;
}