/*搜索二叉树借助左子节点<当前节点<右子节点，在数据的搜索方面能节约很多时间*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *lch,*rch;
}Node,*searchlist;


/*搜索二叉树的插入操作*/
Node *insert(Node *L, int data)
{
    if(L==NULL){
        L=(Node *)malloc(sizeof(Node));
        L->data=data;
        L->lch=L->rch=NULL;
    }
    else
    {
        if(data>L->data)    L->rch=insert(L->rch,data);
        else if(data<L->data)   L->lch=insert(L->lch,data);   
    }
    return L;
}

/*搜索二叉树的查找操作*/
Node *find(Node *L,int data)
{
    if(L==NULL) return NULL ;
    else if(data>L->data)   return find(L->rch,data);
    else if(data<L->data)   return find(L->lch,data);
    else
        return L;
}