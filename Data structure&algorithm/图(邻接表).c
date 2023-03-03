#include <stdio.h>
#include <stdlib.h>

/*对于邻接表的建立，要创建边表节点，顶点节点，记录结构*/
/*与邻接矩阵记录边的关系不同，邻接表更倾向于找到下一个相邻节点*/

#define MAXNUM 100
typedef struct EdgeNode{    /*建立边表节点*/
    int vertex; //顶点下标
    int info; //权位
    struct EdgeNode *next;
}EdgeNode;

typedef struct vertexNode{  /*建立顶点节点*/
    int data; //记录数据
    EdgeNode *firstEdge; //指向第一个邻节点
}vertexNode;

typedef struct MGraph{  /*建立记录结构*/
    int numnode;
    int numedge;
    vertexNode MGraphlist[MAXNUM];
}MGraph;

/*该结构主要针对于无向表的创建*/

void Creatlist(MGraph *L)
{
    EdgeNode *e;
    scanf("%d %d",&L->numnode,&L->numedge);

    for(int i=0;i<L->numnode;i++)
    {
        scanf("%d",&L->MGraphlist[i].data);
        L->MGraphlist[i].firstEdge=NULL;
    }

    for(int j=0;j<L->numedge;j++)
    {
        int a,b;
        scanf("%d %d",&a,&b);    //表示链接(a.b)
        e=(EdgeNode *)malloc(sizeof(EdgeNode)); //链接a到b
        e->vertex=b;
        e->next=L->MGraphlist[a].firstEdge;
        L->MGraphlist[a].firstEdge=e;
        e=(EdgeNode *)malloc(sizeof(EdgeNode)); //连接b到a；
        e->vertex=a;
        e->next=L->MGraphlist[b].firstEdge;
        L->MGraphlist[b].firstEdge=e;
    }
}

