#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;
struct Node *readlist()
{
	struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
	dummy->Data = -1;
	dummy->Next = NULL;

	struct Node* temp = dummy;
	int num = 0;
	scanf("%d", &num);
	while(num != -1)
	{
		struct Node* newNd = (struct Node*)malloc(sizeof(struct Node));
		newNd->Next = NULL;
		newNd->Data = num;
		temp->Next = newNd;
		temp = temp->Next;
		scanf("%d", &num);
	}

	struct Node* head = dummy->Next;
	free(dummy);
	return head;
}
void printlist( struct Node *L )
{
     struct Node *p = L;
     while (p) {
           printf("%d ", p->Data);
           p = p->Next;
     }
     printf("\n");
}

List Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    L = readlist();
	printlist(L);
    scanf("%d", &X);
    L = Insert(L, X);
    printlist(L);

	system("pause");
    return 0;
}

List Insert( List L, ElementType X )
{
    // if(X < L->Data)
    // {
    //     PtrToNode newNode = (PtrToNode)malloc(sizeof(struct Node));
    //     newNode->Data = X;
    //     newNode->Next = L;
    //     return newNode;
    // }
    // PtrToNode ptr = L;
    // while(ptr->Next != NULL)
    // {
    //     ptr = ptr->Next;
    // }
    // if(X > ptr->Data)
    // {
    //     PtrToNode newNode = (PtrToNode)malloc(sizeof(struct Node));
    //     newNode->Data = X;
    //     newNode->Next = L;
    //     ptr->Next = newNode;
    //     return L;
    // }

    PtrToNode dummy = (PtrToNode)malloc(sizeof(struct Node));
    dummy->Data = -100;
    dummy->Next = L;

    PtrToNode prev = dummy;
    PtrToNode curr = dummy->Next;

	int tag = 0;
    while(curr != NULL)
    {
        if(prev->Data <= X && curr->Data >= X)
        {
            PtrToNode newNode = (PtrToNode)malloc(sizeof(struct Node));
            newNode->Data = X;
            newNode->Next = curr;
            prev->Next = newNode;
            prev = prev->Next;
			prev->Next = curr;
			tag = 1;
			break;
        }
        else
        {
            prev = curr;
            curr = curr->Next;
        }
    }

	if(tag == 0)
	{
		PtrToNode newNode = (PtrToNode)malloc(sizeof(struct Node));
		newNode->Data = X;
		newNode->Next = NULL;
		prev->Next = newNode;
	}

    PtrToNode newL = dummy->Next;
    free(dummy);
    return newL;
}
