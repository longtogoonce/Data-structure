/*最小生成树的Kruskal算法的实现依据与数据权的排序以及对于是否成环的判断
这里借助快排对数据进行排序，然后通过并查集对是否成环进行判断*/

#include <stdio.h>

/*数据的实现*/
#define num 10
typedef struct Node{
    int begin;
    int end;
    int weight;
}NodeMGraph;

NodeMGraph L[num];

/*快排的代码实现，当前函数API需要NodeMGraph变量为全局变量*/
void quicksort(int left,int right)
{
    int i=left,j=right;
    NodeMGraph temp;
    if(left>right)
        return ;

    while(i!=j)
    {
        while(i<j&&L[j].weight<L[left].weight)
            j--;
        while(i<j&&L[i].weight>L[left].weight)
            i++;
        if(i<j)
        {
            temp.weight=L[i].weight;
            L[i].weight=L[j].weight;
            L[j].weight=temp.weight;
        }
    }
    temp.weight=L[left].weight;
    L[left].weight=L[i].weight;
    L[i].weight=temp.weight;

    quicksort(left,i-1);
    quicksort(i+1,right);
    return ;
}

/*并查集的代码实现*/
int f[num]; //储存每一个顶点的组织

int getf(int v)//并查集寻找组织
{
    if(f[v]==v)
        return v;
    else
    {
        f[v]=getf(f[v]);
        return f[v];
    }
}

int merge(int v,int u)//并查集合并子组织
{
    int i=getf(v);
    int j=getf(u);
    if(i!=j){
        f[j]=i;
        return 1;
    }
    return 0;
}

int main()
{
    int n,m,i,sum=0,count=0;
    scanf("%d %d",&n,&m);//输入顶点数与边数

    for(i=1;i<=m;i++)//初始化边数
        scanf("%d %d %d",&L[i].begin,&L[i].end,&L[i].weight);

    quicksort(1,m);//快排

    for(i=1;i<=n;i++)//初始化f[v]数组  
        f[i]=i;

    /*Kruskal代码的实现*/
    for(i=1;i<m;i++)
    {
        if(merge(L[i].begin,L[i].end))
        {
            sum+=L[i].weight;
            count++;
        }
        if(count==n-1)
            break;
    }
    printf("%d",sum);
    return 0;
}