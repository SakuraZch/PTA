
// 2020/3/21 //

#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void CreateTree(BinTree* T)
{
    ElementType e;
    scanf("%d", &e);
    if(e == -1)
    {
        *T = NULL;
    }
    else
    {
        *T = (BinTree)malloc(sizeof(struct TNode));
        (*T)->Data = e;
        CreateTree((*T)->Left);
        CreateTree((*T)->Right);
    }
}

BinTree BuildTree()
{
    BinTree root = NULL;
    CreateTree(&root);

    return root;
}

bool IsBST ( BinTree T );

int main()
{
    BinTree T;

    T = BuildTree();
    if ( IsBST(T) ) printf("Yes\n");
    else printf("No\n");

    return 0;
}
/* 你的代码将被嵌在这里 */
ElementType FindMin(BinTree T)
{
    ElementType min = __INT64_MAX__;
    if(T == NULL)
    {
        return min;
    }
    if(T->Data < FindMin(T->Left))
    {
        min = T->Data;
    }
    if(T->Data < FindMin(T->Left))
    {
        min = T->Data;
    }
}
bool IsBST ( BinTree T )
{
    bool tag = true;
    if(T == NULL)
    {
        return true;
    }
    if(T->Left != NULL && T->Left->Data >= T->Data)
    {
        return false;
    }
    if(T->Right != NULL && T->Right->Data <= T->Data)
    {
        return false;
    }
    tag = IsBST(T->Left);
    tag = IsBST(T->Right);
    return tag;
}