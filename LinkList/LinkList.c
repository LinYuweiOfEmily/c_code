#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//定义一个结构体指针
typedef struct Lnode
{
    int data;
    struct Lnode *next;
}LNode,*LinkList;
bool InitList(LinkList *L);
bool InsertNode(LinkList L,int i,int x);
bool GetAll(LinkList L);
LNode * GetElem(LinkList L,int i);
int DeleteNode(LinkList L,int i);
LNode * LocateElem(LinkList L,int x);
int main()
{
    //定义头指针
    LinkList L = NULL;
    int x;
    InitList(&L);
    //利用链表的插入操作实现初始化
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&x);
        InsertNode(L,L->data,x);
    }
    // GetAll(L);
    // printf("%d",GetElem(L,3)->data);
    // printf("%d",DeleteNode(L,3));
    free(L);
}
//建立一个链表（尾插法）
bool TailInitList(LinkList *L)
{
    //申请一个空间
    *L = (LNode*)malloc(sizeof(LNode));
    (*L)->next = NULL;
    //内存不足则结束
    if (*L == NULL)
    {
        return false;
    }
    //定义一个尾部指针
    LNode *r = *L;
    int x;
    scanf("%d",&x);
    while (x!=9999)
    {
        LNode *s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d",x);
    }
    r->next = NULL;
    
    (*L)->data = 0;
    return true;
}
//建立一个链表（头插法）
bool HeadInitList(LinkList *L)
{
    //创建一个链表并初始化
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    int x;
    scanf("%d",&x);
    while (x!=9999)
    {
        LNode* s = (LinkList)malloc(sizeof(LNode));
        s->data = x;
        s->next = (*L)->next;
        (*L)->next = s;
        scanf("%d",&x);
    }
}
//在第i个元素的位置插入结点
bool InsertNode(LinkList L,int i,int x)
{
    //为要插入的结点申请空间
    if(i<0 || i>L->data)
    {
        return false;
    }
    LNode *s = (LNode*)malloc(sizeof(LNode));
    //输入data
    LNode *p = L;
    int j = 0;                  //当前代码指向第几个结点
    while (p->next!=NULL && j<i)
    {
        p = p->next;
        j++;
    }
    s->data = x;
    //不能反
    s->next = p->next;
    p->next = s;
    //链表的长度增加
    L->data++;
    return true;
}
//得到所有结点数据
bool GetAll(LinkList L)
{
    LNode *p = NULL;
    p = L->next;
    do
    {
        printf("%d ",p->data);
        p = p->next;
    } while (p!=NULL);
    

    return true;
}
//查找第i个元素
LNode * GetElem(LinkList L,int i)
{
    if(i<0 || i>L->data)
    {
        return NULL;
    }
    //扫描指针
    LNode *p = L;
    int j = 0;
    while (j!=i)
    {
        p = p->next;
        j++;
    }
    return p;
}
//删除指定位置（第i个）的结点
int DeleteNode(LinkList L,int i)
{
    if (i<0 || i>L->data)
    {
        return false;
    }
    //扫描指针
    LNode *p = L;
    //记录下扫描指针在链表中的位序
    int j = 0;
    while (p!=NULL && j<i-1)
    {
        p = p->next;
        j++;
    }
    LNode * q = p->next;
    p->next = q->next;
    int x = q->data;
    free(q);
    return x;
}
//按值查找
LNode * LocateElem(LinkList L,int x)
{
    //扫描指针
    LNode *p = L->next;
    while (p!=NULL && p->data != x)
    {
        p = p->next;
    }
    return p;
}
//往p中后插一个结点
// bool InsertNextNode