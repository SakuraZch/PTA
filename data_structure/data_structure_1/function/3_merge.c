
// 2020/3/17 //

#include <stdio.h>
#include <stdlib.h>

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

void Delete(List L)
{
    List curr = L;
    while(curr != NULL)
    {
        List temp = curr;
        curr = curr->Next;
        free(temp);
    }
}

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);

    Delete(L1);
    Delete(L2);
    Delete(L);

    system("pause");
    return 0;
}

/* 你的代码将被嵌在这里 */
List Merge( List L1, List L2 )
{
    List dummy = (List)malloc(sizeof(struct Node));
    dummy->Data = -1;
    dummy->Next = NULL;

    List curr1 = L1->Next, curr2 = L2->Next, currD = dummy;
    while(curr1 != NULL && curr2 != NULL)
    {
        if(curr1->Data <= curr2->Data)
        {
            currD->Next = curr1;
            curr1 = curr1->Next;
            currD = currD->Next;
            currD->Next = NULL;
        }
        else if(curr2->Data < curr1->Data)
        {
            currD->Next = curr2;
            curr2 = curr2->Next;
            currD = currD->Next;
            currD->Next = NULL;
        }
    }
    if(curr1 == NULL)
    {
        currD->Next = curr2;
    }
    else if(curr2 == NULL)
    {
        currD->Next = curr1;
    }
    L1->Next = NULL;
    L2->Next = NULL;

    return dummy;
}
