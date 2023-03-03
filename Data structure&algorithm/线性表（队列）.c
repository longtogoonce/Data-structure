#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
typedef struct Node{
    Elemtype data;
    struct Node *next;
}Node,*Queueptr;

typedef struct{
    struct Node *head,*tail;
}linklist;

/*
        栈的实现：
    typedef struct Node{
        Elemtype data;
        struct Node *next;
    }Node,*stackptr;

    typedef struct{
        stackptr top;
        int count;
    }linklist;
                        */


void initlist(linklist *);
void addlist(linklist *);
void Delist(linklist *);
void getlist(linklist *);

int main()
{
    linklist Q;
    initlist(&Q);
    addlist(&Q);
    getlist(&Q);
    printf("******\n");
    Delist(&Q);
    getlist(&Q);
}

void initlist(linklist *q)
{
    q->head=q->tail=(Queueptr)malloc(sizeof(Node));
    q->head->next=NULL;
    q->head->data=0;   
}

void addlist(linklist *q)
{
    int i=5;
    while(i--){
        Queueptr p=(Queueptr)malloc(sizeof(Node));
        p->data=i;
        p->next=NULL;
        q->tail->next=p;
        q->tail=p;
    }
}

void Delist(linklist *q)
{
    int i=2;
    while(i--){
        Queueptr p;
        p=q->head->next;
        q->head->next=p->next;
        if(q->tail==p)
            q->tail=q->head;
        free(p);
    }
}

void getlist(linklist *q)
{
    Queueptr p;
    p=q->head;
    while(p!=q->tail){
        printf("%d\n",p->data);
        p=p->next;
    }
}