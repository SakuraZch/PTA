
// 2020/3/21 //

#include <stdio.h>
#include <stdlib.h>

#define MAXTABLESIZE 100000  /* 允许开辟的最大散列表长度 */
typedef int ElementType;     /* 关键词类型用整型 */
typedef int Index;           /* 散列地址类型 */
typedef Index Position;      /* 数据所在位置与散列地址是同一类型 */
/* 散列单元状态类型，分别对应：有合法元素、空单元、有已删除元素 */
typedef enum { Legitimate, Empty, Deleted } EntryType;

typedef struct HashEntry Cell; /* 散列表单元类型 */
struct HashEntry{
    ElementType Data; /* 存放元素 */
    EntryType Info;   /* 单元状态 */
};

typedef struct TblNode *HashTable; /* 散列表类型 */
struct TblNode {   /* 散列表结点定义 */
    int TableSize; /* 表的最大长度 */
    Cell *Cells;   /* 存放散列单元数据的数组 */
};

HashTable BuildTable()
{
    int len = 0;
    scanf("%d", &len);
    HashTable H = (HashTable)malloc(sizeof(struct TblNode));
    H->TableSize = len;
    H->Cells = (Cell*)malloc(sizeof(Cell) * len);
    for(int i = 0; i < len; i++)
    {
        scanf("%d", &H->Cells[i]);
        if(H->Cells[i].Data == -1)
        {
            H->Cells[i].Info = Empty;
        }
        else if(H->Cells[i].Data != -1)
        {
            H->Cells[i].Info = Legitimate;
        }
    }
    return H;
}

Position Hash( ElementType Key, int TableSize )
{
    return (Key % TableSize);
}

#define ERROR -1
Position Find( HashTable H, ElementType Key );

int main()
{
    HashTable H;
    ElementType Key;
    Position P;

    H = BuildTable(); 
    scanf("%d", &Key);
    P = Find(H, Key);
    if (P==ERROR)
        printf("ERROR: %d is not found and the table is full.\n", Key);
    else if (H->Cells[P].Info == Legitimate)
        printf("%d is at position %d.\n", Key, P);
    else
        printf("%d is not found.  Position %d is returned.\n", Key, P);

    free(H->Cells);
    free(H);

    system("pause");
    return 0;
}

/* 你的代码将被嵌在这里 */
Position Find( HashTable H, ElementType Key )
{
    int len = H->TableSize, start = Key % len;

    for(int i = start; i < len; i++)
    {
        if(H->Cells[i].Data == Key)
        {
            return i;
        }
    }

    for(int i = start; i < len; i++)
    {
        if(H->Cells[i].Data == -1)
        {
            return i;
        }
    }
    for(int i = 0; i < start; i++)
    {
        if(H->Cells[i].Data == -1)
        {
            return i;
        }
    }

    return ERROR;
}