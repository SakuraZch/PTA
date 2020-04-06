
// 2020/3/17 //

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput()
{
    List L = (List)malloc(sizeof(struct LNode));
    int len = 0;
    scanf("%d", &len);
    for(int i = 0; i < len; i++)
    {
        scanf("%d", &L->Data[i]);
    }
    L->Last = len - 1;

    return L;
}

void PrintList( List L )
{
    for(int i = 0; i <= L->Last; i++)
    {
        printf("%d ", L->Data[i]);
    }
    printf("\n");
}

List Delete( List L, ElementType minD, ElementType maxD );

int main()
{
    List L;
    ElementType minD, maxD;
    int i;

    L = ReadInput();
    scanf("%d %d", &minD, &maxD);
    L = Delete( L, minD, maxD );
    PrintList( L );

    free(L);

    system("pause");
    return 0;
}

/* 你的代码将被嵌在这里 */
// List Delete( List L, ElementType minD, ElementType maxD )
// {
//     for(int i = 0; i <= L->Last; i++)
//     {
//         if(minD < L->Data[i] && L->Data[i] < maxD)
//         {
//             for(int j = i; j <= L->Last; j++)
//             {
//                 L->Data[j] = L->Data[j + 1];
//             }
//             L->Last--;
//             i--;
//         }
//     }

//     return L;
// }

List Delete( List L, ElementType minD, ElementType maxD )
{
    List newL = (List)malloc(sizeof(struct LNode));
    newL->Last = -1;
    for(int i = 0; i <= L->Last; i++)
    {
        if(minD >= L->Data[i] || L->Data[i] >= maxD)
        {
            newL->Data[++newL->Last] = L->Data[i];
        }
    }

    free(L);
    return newL;
}