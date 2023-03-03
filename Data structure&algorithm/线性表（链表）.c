#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node *Next;
}Node,*Linklist;

int initlist(Linklist *);
int addlist(Linklist *);

int main()
{
    Linklist L,P;             /*如果想操作这个L，因为它是一个指向结构体的指针（这个指针具有内存，而指向对象没有内存）*/
    initlist(&L);           /*如果想在另一个函数中操作这个指针，传递这个指针的地址（*L），那么函数声明就需要是**类型*/
    P=L;
    addlist(&L);
    //printf("%d",(*L).data); /*然后在函数中使用（*L）这个解值变量进行对这个指针的操作*/
    while((*P).Next!=NULL){
        printf("%d\n",(*P).data);
        P=(*P).Next;
    }
    free(L);
    free(P);
    return 0;
}
int initlist(Linklist *L)
{
    *L=(Node*)malloc(sizeof(Node));
    (*L)->Next=NULL;
    return 0;
}

int addlist(Linklist *L)
{
    Node *ptr;
    int i=5;
    while(i--){
        ptr=(Node*)malloc(sizeof(Node));
        (*ptr).data=i;
        while((*L)->Next!=NULL){
            (*L)=(*L)->Next;
        }
        (*L)->Next=ptr;
        (*ptr).Next=NULL;
    }
}

