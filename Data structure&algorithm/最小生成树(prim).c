/*prim算法根据当前节点所对应的最小边进行选择
关键在于用一个mincost一维数组维护当前节点的可连接边*/

#include <stdio.h>

#define MAXNUM 100
#define INF 65535
typedef struct Node{
    int numnode;
    int edgenode;
    int arc[MAXNUM][MAXNUM];
}MGraph;

/*一般数据的输入会从1开始，所以节点开始为1*/
int main()
{
    MGraph L;
    int j,i,t1,t2,t3,sum=0;
    scanf("%d %d",&L.numnode,&L.edgenode);
    int mincost[L.numnode+1];

    /*初始化图*/
    for(i=1;i<=L.numnode;i++)
        for(j=1;j<=L.numnode;j++)    
            L.arc[i][j]=INF;

    /*无向图中加入边*/
    for(i=1;i<=L.edgenode;i++)
    {
        scanf("%d %d %d",&t1,&t2,&t3);
        L.arc[t1][t2]=t3;
        L.arc[t2][t1]=t3;
    }

    /*初始化完图后，初始化mincost数组,建立第一组数据*/
    mincost[1]=0;
    for(i=2;i<=L.numnode;i++)
        mincost[i]=L.arc[1][i];
    /*prim核心算法，比较当前维护数组mincoost中最小值*/
    int count=1;
    while((count++)<L.numnode)
    {
        int min=INF;
        int k;  //k记录当前最小值的数组下标
        for(i=1;i<=L.numnode;i++)
        {
            if(mincost[i]!=0&&mincost[i]<min)
            {
                min=mincost[i];
                k=i;
            }
        }
        mincost[k]=0;
        sum+=min;

        /*更新mincoust数组*/
        for(i=1;i<=L.numnode;i++)
            if(mincost[i]!=0&&mincost[i]>L.arc[k][i])
                mincost[i]=L.arc[k][i];
    }
    printf("%d",sum);
    return 0;
}   