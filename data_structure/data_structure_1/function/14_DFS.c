
// 2020/3/22 //

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxVertexNum 10  /* 最大顶点数设为10 */
#define INFINITY 65535   /* ∞设为双字节无符号整数的最大值65535*/
typedef int Vertex;      /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;  /* 边的权值设为整型 */

typedef struct GNode* PtrToGNode;
struct GNode{
    int Nv;  /* 顶点数 */
    int Ne;  /* 边数   */
    WeightType G[MaxVertexNum][MaxVertexNum]; /* 邻接矩阵 */
};
typedef PtrToGNode MGraph; /* 以邻接矩阵存储的图类型 */
bool Visited[MaxVertexNum]; /* 顶点的访问标记 */

MGraph CreateGraph()
{
    MGraph Graph = (MGraph)malloc(sizeof(struct GNode));
    printf("Enter the number of vertex: ");
    scanf("%d", &Graph->Nv);
    printf("Enter the number of edge: ");
    
    for(int i = 0; i < Graph->Nv; i++)
    {
        for(int j = 0; j < Graph->Nv; j++)
        {
            Graph->G[i][j] = 0;
        }
    }
    scanf("%d", &Graph->Ne);
    printf("Enter the message of each vertex: ");
    for(int i = 0; i < Graph->Ne; i++)
    {
        int u = 0, v = 0;
        scanf("%d %d", &u, &v);
        Graph->G[u][v] = 1;
        Graph->G[v][u] = 1;
    }

    for(int i = 0; i < MaxVertexNum; i++)
    {
        Visited[i] = false;
    }

    return Graph;
}

void PrintMat(MGraph Graph)
{
    printf("Vertex Num: %d, Edge Num: %d\n", Graph->Nv, Graph->Ne);
    printf("Matrix:\n");
    for(int i = 0; i < Graph->Nv; i++)
    {
        for(int j = 0; j < Graph->Nv; j++)
        {
            printf("%d ", Graph->G[i][j]);
        }
        printf("\n");
    }
}

void Visit( Vertex V )
{
    printf(" %d", V);
}

void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) );

int main()
{
    MGraph G;
    Vertex V;

    G = CreateGraph();
    PrintMat(G);
    scanf("%d", &V);
    printf("DFS from %d:", V);
    DFS(G, V, Visit);

    free(G);
    system("pause");
    return 0;
}

/* 你的代码将被嵌在这里 */
void DFS( MGraph Graph, Vertex V, void (*Visit)(Vertex) )
{
    Visit(V);
    Visited[V] = true;
    for(int i = 0; i < Graph->Nv; i++)
    {
        if(Graph->G[V][i] == 1 && Visited[i] == false)
        {
            DFS(Graph, i, Visit);
        }
    }
}