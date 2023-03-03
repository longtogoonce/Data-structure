#include <stdio.h>
#include <stdlib.h>

/*对于邻接矩阵的建立，需要建立一个记录结构就行，本质上是通过边的关系进行记录*/

#define MAXVEX 100
typedef struct Node{
    int data[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numnode,numedge;
}MGraph;

/*返回一个初始化的图*/
MGraph *initMGraph(int maxnum)
{
    MGraph *L=(MGraph *)malloc(sizeof(MGraph));
    L->numedge=0;
    L->numnode=maxnum;
    for(int i=0;i<maxnum;i++)
        for(int j=0;j<maxnum;j++)
            L->arc[i][j]=0;
    return L;
}

/*建立一个有权的无向图*/
MGraph *creatMGraph(void)
{
    int numedge,i,j,W;
    int numnode =5;
    MGraph *L =initMGraph(numnode);
    
    scanf("%d",&numedge);
    for(int k=0;k<numedge;k++)
    {
        scanf("%d %d %d",&i,&j,&W);
        L->arc[i][j]=W;
        L->arc[j][i]=W;
    }
    return L;
}

/*平时建图*/
#define INF 100
int arc[MAXVEX][MAXVEX];
void creatMGraph2(void)
{
    int numedge,i,j,W,numnode;
    scanf("%d %d",&numedge,&numnode);
   
   for(int a;a<numnode;a++)
    for(int b;b<numnode;b++)
        arc[a][b]=INF;

    for(int k=0;k<numedge;k++)
    {
        scanf("%d %d %d",&i,&j,W);
        arc[i][j]=W;
        arc[j][i]=W;
    }
    return ;
}
