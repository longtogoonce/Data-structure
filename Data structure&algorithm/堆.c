#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*堆的构建是对于完全二叉树的利用，即父节点的值总不小于子节点的值
  且由于完全二叉树的特性，使得其使用数组可以储存*/

#define MAXELEM 10000; 
typedef struct Node{
    int *data;   //堆对应的数组
    int size;    //当前的大小
    int maxsize; //数组对应的大小
}Node,*Heaplist;

Heaplist creatHeap(int maxsize)
{
    Heaplist L =(Heaplist)malloc(sizeof(Node));
    L->data=(int *)malloc(sizeof(int)*(maxsize+1));
    L->maxsize=maxsize;
    L->size=0;
    L->data[0]=MAXELEM; //哨兵位，方便处理插入等操作

    return L;
}

void Insert (Heaplist L,int elem)
{
    if(L->size==L->maxsize){  //已满
        printf("max");
        return ;
    }   
    int i=++L->size;    //先插入末尾
    for(;L->data[i/2]<elem;i/=2)   //向上逐层比较
        L->data[i]=L->data[i/2];
    L->data[i]=elem;    //插入
}

void Delete (Heaplist L)    //删去最大值（根节点）  取出最大值
{
    if(L->size==0){
        printf("已空");
        return ;
    }

    int temp=L->data[L->size--];
    int parent,child;

    for(parent=1;parent*2<=L->maxsize;parent=child){
        child=parent*2;
        if(child!=L->maxsize&&L->data[child]<L->data[child+1]) //以parent为基，先找到子节点大的那一个
            child++;
        if(temp>L->data[child]) //比较temp与当前子节点（向下遍历）
            break;
        else
            L->data[parent]=L->data[child];
    }
    L->data[parent]=temp;
}

void addheaplist (int i,int len,Heaplist L)     //建造堆的两个函数
{
    int temp=L->data[i];
    for(int j=2*i;j<len;j*=2)
    {
        if(j<len-1&&L->data[j]<L->data[j+1])
            j++;
        if(temp>=L->data[j])
            break;
        else
            L->data[i]=L->data[j];
    }
    L->data[i]=temp;
}

void Creatheaplist (Heaplist L)
{
    int number[10]={1,5,3,2,4,8,6,9,7,15};
    Heaplist L=creatHeap(10);
    L->data=number;
    for(int i=strlen(number)/2;i>0;i--){
        addheaplist(i,strlen(number),L);
    }
    return ;                                                                    
}                                               // 

int main()
{
    int maxsize=8;
    Heaplist L=creatHeap(maxsize);
}