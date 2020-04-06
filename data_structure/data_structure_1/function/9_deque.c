
// 2020/3/21 //

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR -1
typedef int ElementType;
typedef enum { push, pop, inject, eject, end } Operation;
typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
    ElementType *Data;      /* 存储元素的数组   */
    Position Front, Rear;   /* 队列的头、尾指针 */
    int MaxSize;            /* 队列最大容量     */
};
typedef PtrToQNode Deque; 

Deque CreateDeque( int MaxSize )
{   /* 注意：为区分空队列和满队列，需要多开辟一个空间 */
    Deque D = (Deque)malloc(sizeof(struct QNode));
    MaxSize++;
    D->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    D->Front = D->Rear = 0;
    D->MaxSize = MaxSize;
    return D;
}

bool Push( ElementType X, Deque D );
ElementType Pop( Deque D );
bool Inject( ElementType X, Deque D );
ElementType Eject( Deque D );

Operation GetOp()
{
    Operation op;
    scanf("%d", &op);
    return op;
}

void PrintDeque( Deque D )
{
    for(int i = (D->Front + 1) % D->MaxSize; i != D->Rear; i++)
    {
        if(i == D->MaxSize)
        {
            i = 0;
        }
        printf("%d ", D->Data[i]);
    }
    printf("\n");
}

int main()
{
    ElementType X;
    Deque D;
    int N, done = 0;

    scanf("%d", &N);
    D = CreateDeque(N);
    while (!done) {
        switch(GetOp()) {
        case push: 
            scanf("%d", &X);
            if (!Push(X, D)) printf("Deque is Full!\n");
            break;
        case pop:
            X = Pop(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            else printf("%d is out\n", X);
            break;
        case inject: 
            scanf("%d", &X);
            if (!Inject(X, D)) printf("Deque is Full!\n");
            break;
        case eject:
            X = Eject(D);
            if ( X==ERROR ) printf("Deque is Empty!\n");
            else printf("%d is out\n", X);
            break;
        case end:
            PrintDeque(D);
            done = 1;
            break;
        }
    }

    system("pause");
    return 0;
}

/* 你的代码将被嵌在这里 */
// bool Push( ElementType X, Deque D )
// {
//     if((D->Front + D->MaxSize - 1) % D->MaxSize == D->Rear)
//     {
//         return false;
//     }
//     else
//     {
//         D->Data[D->Front] = X;
//         D->Front = (D->Front + D->MaxSize - 1) % D->MaxSize;
//         return true;
//     }
// }

// ElementType Pop( Deque D )
// {
//     if(D->Rear == D->Front)
//     {
//         return ERROR;
//     }
//     else
//     {
//         D->Front = (D->Front + 1) % D->MaxSize;
//         return D->Data[D->Front];
//     }
// }

// bool Inject( ElementType X, Deque D )
// {
//     if((D->Rear + 1) % D->MaxSize == D->Front)
//     {
//         return false;
//     }
//     else
//     {
//         D->Rear = (D->Rear + 1) % D->MaxSize;
//         D->Data[D->Rear] = X;
//         return true;
//     }   
// }

// ElementType Eject( Deque D )
// {
//     if(D->Front == D->Rear)
//     {
//         return ERROR;
//     }
//     else
//     {
//         int res = D->Data[D->Rear];
//         D->Rear = (D->Rear + D->MaxSize - 1) % D->MaxSize;
//         return res;
//     }
// }

bool Push( ElementType X, Deque D )
{
    if((D->Front + D->MaxSize - 1) % D->MaxSize == D->Rear)
    {
        return false;
    }
    else
    {
        D->Front = (D->Front - 1 + D->MaxSize) % D->MaxSize;
        D->Data[D->Front] = X;
        return true;
    }
}

ElementType Pop( Deque D )
{
    if(D->Rear == D->Front)
    {
        return ERROR;
    }
    else
    {
        int res = D->Data[D->Front];
        D->Front = (D->Front + 1) % D->MaxSize;
        return res;
    }
}

bool Inject( ElementType X, Deque D )
{
    if((D->Rear + 1) % D->MaxSize == D->Front)
    {
        return false;
    }
    else
    {
        D->Data[D->Rear] = X;
        D->Rear = (D->Rear + 1) % D->MaxSize;
        return true;
    }   
}

ElementType Eject( Deque D )
{
    if(D->Front == D->Rear)
    {
        return ERROR;
    }
    else
    {
        D->Rear = (D->Rear + D->MaxSize - 1) % D->MaxSize;
        return D->Data[D->Rear];
    }
}