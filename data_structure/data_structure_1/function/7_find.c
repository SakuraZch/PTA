
// 2020/3/17 //

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read()
{
    List head = (List)malloc(sizeof(struct Node));
    head->Data = -1;
    head->Next = NULL;

    List curr = head;
    ElementType data;
    scanf("%d", &data);
    while(data != -1)
    {
        List newNode = (List)malloc(sizeof(struct Node));
        newNode->Data = data;
        newNode->Next = NULL;
        curr->Next = newNode;
        curr = curr->Next;
        scanf("%d", &data);
    }

    return head;
}

void Print( List L )
{
    if(L == NULL)
    {
        printf("ERROR!\n");
        return ;
    }
    if(L->Next == NULL)
    {
        printf("NULL\n");
        return ;
    }

    List curr = L->Next;
    while(curr != NULL)
    {
        printf("%d ", curr->Data);
        curr = curr->Next;
    }
    printf("\n");
}

ElementType Find( List L, int m );

int main()
{
    List L;
    int m;
    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L,m));
    Print(L);

    system("pause");
    return 0;
}

/* 你的代码将被嵌在这里 */
ElementType Find( List L, int m )
{
    List curr = L, target = L;
    int ind = 0;
    while(curr != NULL)
    {
        if(ind == m)
        {
            curr = curr->Next;
            target = target->Next;
        }
        else
        {
            curr = curr->Next;
            ind++;
        }
    }

    if(ind < m)
    {
        return ERROR;
    }
    else
    {
        return target->Data;
    }
}