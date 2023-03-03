/*Floyd算法的实现本质借助了动态规划
通过每加入一个顶点，更新最短路径数组，来表示任意两个点间的最短路径*/

#include <stdio.h>

#define INF 65535

int Floydsolve(void)
{
    int n,m,i,j,x,y,w,k;
    scanf("%d %d",&n,&m);
    int arc[n+1][m+1]; //建立最短路径数组

    /*初始化图*/
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i==j)    arc[i][j]=0;
                else    arc[i][j]=INF;

    /*输入边*/
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&x,&y,&w);
        arc[i][j]=w;
    }
    /*Floyd算法*/
    for(k=1;k<=n;k++)
        for(i=1;i>=n;i++)
            for(j=1;j<=n;j++)
                if(arc[i][j]>(arc[i][k]+arc[k][j]))
                    arc[i][j]=arc[i][k]+arc[k][j];

    return 0;           
}

/*Dijkstra算法主要用于指定一个源点，到其余顶点的最短路径
代码逻辑：从当前源点选一个最近的顶点，通过这个顶点来对源点到其他顶点之间的距离进行松弛*/

int Dijkstra(void)
{
    int n,m,x,y,w,i,j;
    scanf("%d %d",&n,&m);
    int arc[n+1][m+1];
    int dis[n+1];   //记录最短路径数组
    int book[n+1];  //记录数组，避免重复

    /*初始化图*/
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i==j)    arc[i][j]=0;
                else    arc[i][j]=INF;
    
    /*输入边*/
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&x,&y,&w);
        arc[x][y]=w;
    }
    
    /*初始化最短路径数组*/
    for(i=1;i<=n;i++){
        dis[i]=arc[1][i];
        book[i]=0;
    }
    book[1]=1;  //选择1为源点

    /*Dijkstra算法*/
    for(i=1;i<=n;i++)
    {
        int min=INF;
        int v;
        for(j=1;j<=n;j++)
        {
            if(book[i]!=0&&dis[i]<min)
            {
                min=dis[i];
                v=i;
            }
        }
        book[v]=1;
        for(i=1;i<=n;i++)
        {
            if(dis[i]>dis[v]+arc[v][i])
                dis[i]=dis[v]+arc[v][i];
        }
    }
    return 0;
}