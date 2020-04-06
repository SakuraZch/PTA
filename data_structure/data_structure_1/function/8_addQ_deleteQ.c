
// 2020/3/17 //

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR -1
typedef int ElementType;
//typedef enum { addq, delq, end } Operation;
typedef int Operation;
//typedef enum { false, true } bool;
typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
    ElementType *Data;  /* 存储元素的数组   */
    Position Front;     /* 队列的头、尾指针 */
    int Count;          /* 队列中元素个数   */
    int MaxSize;        /* 队列最大容量     */
};
typedef PtrToQNode Queue; 

Queue CreateQueue( int MaxSize )
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    Q->Front = 0;
    Q->Count = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

bool AddQ( Queue Q, ElementType X );
ElementType DeleteQ( Queue Q );

Operation GetOp()
{
    Operation op;
    scanf("%d", &op);
    return op;
}

int main()
{
    ElementType X;
    Queue Q;
    int N, done = 0;

    scanf("%d", &N);
    Q = CreateQueue(N);
    while ( !done ) {
        switch( GetOp() ) {
        case 0: 
            scanf("%d", &X);
            AddQ(Q, X);
            break;
        case 1:
            X = DeleteQ(Q);
            if ( X!=ERROR ) printf("%d is out\n", X);
            break;
        case 2:
            while (Q->Count) printf("%d ", DeleteQ(Q));
            done = 1;
            break;
        }
    }

    system("pause");
    return 0;
}

/* 你的代码将被嵌在这里 */
bool AddQ( Queue Q, ElementType X )
{
    if(Q->Count == Q->MaxSize)
    {
        printf("Queue Full\n");
        return false;
    }
    else
    {
        Q->Count++;
        int ind = (Q->Front + Q->Count) % Q->MaxSize;
        Q->Data[ind] = X;
        return true;
    }    
}

ElementType DeleteQ( Queue Q )
{
    if(Q->Count == 0)
    {
        printf("Queue Empty\n");
        return ERROR;
    }
    else
    {
        Q->Count--;
        Q->Front = (Q->Front + 1) % Q->MaxSize;
        return Q->Data[Q->Front];
    }
}