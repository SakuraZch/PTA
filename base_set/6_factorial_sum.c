
// 2020/3/8 //

#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
    int Data; /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int FactorialSum( List L )
{
    int res = 0;
    List curr = L;
    while(curr != NULL)
    {
        int temp = 1;
        for(int i = 1; i <= curr->Data; i++)
        {
            temp *= i;
        }
        res += temp;
        List freeNd = curr;
        curr = curr->Next;
        free(freeNd);
    }

    return res;
}

int main()
{
    int N, i;
    List L, p;

    scanf("%d", &N);
    L = NULL;
    for ( i=0; i<N; i++ ) {
        p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = L;  L = p;
    }
    printf("%d\n", FactorialSum(L));

    system("pause");
    return 0;
}
