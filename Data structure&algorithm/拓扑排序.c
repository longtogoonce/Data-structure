/*拓扑排序的关键在于依据邻接表，将所有入度为0的顶点输出，并删去*/
/*依托于：邻接表，栈*/
#include <stdio.h>
#include <stdlib.h>

typedef struct stack{   //栈结构
    int *stacklist;
    int top;
}stack;

typedef struct Edge{    //边表结构
    int adjvex;
    struct Edge *next;
}Edge;

typedef struct Vertex{  //顶点结构
    int in;  //入度
    int data;
    Edge *firstNode;
}Vertex;

typedef struct GMraph{  //图结构
    int numVex;
    int numEdge;
    Vertex *Vexlist;
}GMraph;

GMraph InitGMraph(void)    //初始化邻接表
{
    int i;
    GMraph G;
    Edge *e;
    scanf("%d %d",&G.numVex,&G.numEdge);
    for(i=0;i<G.numVex;i++){
        scanf("%d",&G.Vexlist[i].data);
        G.Vexlist[i].firstNode=NULL;
        G.Vexlist[i].in=0;
    }

    for(i=0;i<G.numEdge;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        e=(Edge*)malloc(sizeof(Edge));
        e->adjvex=b;
        e->next=G.Vexlist[a].firstNode;
        G.Vexlist[a].firstNode=e;
        G.Vexlist[a].in++;
    }
    return G;
}

stack Initstack(int num)    //初始化栈
{
    stack T;
    T.stacklist=(int *)malloc(num*sizeof(int));
    T.top=-1;
    return T;
}

int main()
{
    int i,gettop,count=0;
    Edge *e;
    GMraph G=InitGMraph();
    stack T=Initstack(G.numVex+1);

    /*拓扑排序核心代码*/
    for(i=0;i<G.numVex;i++)
    {
        if(G.Vexlist[i].in==0)
            T.stacklist[++T.top]=i;
        count++;
        while(T.top>=0)
        {
            gettop=T.stacklist[T.top--];
            printf("%d",gettop);
        }
        for(e=G.Vexlist[gettop].firstNode;e;e=e->next)
        {
            if(!(--G.Vexlist[e->adjvex].in))
                T.stacklist[++T.top]=e->adjvex;
        }
    }
    if(count<G.numVex)
        printf("Having a ring");
    return 0;
}



