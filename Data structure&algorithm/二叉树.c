/*树属于一种一对多的数据结构
顺序存储方式在内存占用等方面存在弊端，而链序存储在具体的指针个数既空间有许多的浪费与不足
所以对于树的研究，通常采用二叉树这种数据结构，通常具有一个数据域和两个指针域
而在具体的实现方面常常采用递归调用的形式，在每一个节点的结构体实现本质上与队列与栈并无不同*/

/*对于数据结构的研究，无非不是关于创建，消除，增加，消减，查询，搜索等方面的探讨*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElemTyPe;
typedef struct BiNode
{
    ElemTyPe data;
    struct BiNode *lchild,*rchild;
}BiNode,*BiTree;

/*首先是对于一个二叉树的创建*/

/*由于二叉树的实现是通过链状结构递归实现的，所以要有一定的终止条件*/
int index;
void CreatBiTree(BiTree *T)
{
    char str[]="AB#D##C##";
    char *ch=str[index++];
    if(*ch=='\0'){
        return ;
    }
    if(ch!='#'){
        *T=(BiTree)malloc(sizeof(BiNode));
        if(!*T)
            exit(0);
        (*T)->data=ch;
        CreatBiTree(&(*T)->lchild);
        CreatBiTree(&(*T)->rchild);
    }
    else
        *T=NULL;
}

