#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct DNode
{
    int data;
    struct DNode *prior,*next;
}DNode ,*DLinkList;
bool InitDList(DLinkList *L);
bool InsertDNode(DLinkList L,int i);
int GetElem(DLinkList L,int i);
int main()
{
    //定义头指针
    DLinkList L = NULL;
    //对头指针初始化即创建头节点
    InitDList(&L);
    // for(int i = 0;i<L->data;i++)
    // {
    //     printf("%d ",GetElem(L,i+1));
    // }

}
//创建一个双链表(尾插法)
bool InitDList(DLinkList *L)
{
    *L = (DLinkList)malloc(sizeof(DNode));
    //定义一个尾部指针并让他指向尾部
    DNode *t = *L;
    (*L)->next = NULL;
    (*L)->prior = NULL;
    (*L)->data = 0;
    while (t->next!=NULL)
    {
        t = t->next;
    }
    int x;
    scanf("%d",&x);
    while (x!=9999)
    {
        DNode *s = (DLinkList)malloc(sizeof(DNode));
        s->data = x;
        s->prior = t;
        s->next = t->next;
        t->next = s;
        t = s;
        (*L)->data++;
        scanf("%d",&x);
    }
    
    return true;
}
//实现插入操作(按位序插入)
bool InsertDNode(DLinkList L,int i)
{
    if(i<0 || i>L->data)
    {
        return false;
    }
    //要插入的结点
    DNode * p = (DLinkList)malloc(sizeof(DNode));
    int x;
    scanf("%d",&x);
    p->data = x;
    //扫描指针
    DNode * s = L;
    int j = 0;
    while (s!=NULL && j<i)
    {
        s = s->next;
        j++;
    }
    p->next = s->next;
    s->next = p;
    p->prior = s;
    if(s->next!=NULL)
    {
        s->next->prior = p;
    }
    L->data++;
    return true;
}
//实现按位序查找
int GetElem(DLinkList L,int i)
{
    //定义扫描指针
    DNode *p = L;
    int j = 0;
    while (p!=NULL && j<i)
    {
        p = p->next;
        j++;
    }
    return p->data;
}