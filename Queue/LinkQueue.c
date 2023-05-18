#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
本次代码主要实现队列的链式存储结构。
其中需要特别注意的点（带头节点）：
1.删除节点时要注意如果是最后一个节点要将rear指针指向头节点并记得释放内存。
2.因为链表形式要求长需一个一个遍历，所以如果需要频繁使用长度的话可以另外设一个length变量，用来表示长度
*/
typedef struct LNode
{
    int data;  
    struct LNode *next;
}LNode,*LinkList;
typedef struct LinkQueue
{
    LinkList front,rear;
}LinkQueue;
bool InitQueue(LinkQueue *q);
bool QueueEmpty(LinkQueue q);
bool EnQueue(LinkQueue *q,int x);
bool DeQueue(LinkQueue *q,int *x);
bool DestroyQueue(LinkQueue *q);
int QueueLength(LinkQueue q);
int main()
{
    LinkQueue q;
}
//初始化队列
bool InitQueue(LinkQueue *q)
{
    q->front = q->rear = (LinkList)malloc(sizeof(LNode));    
    if (!q->front)
    {
        return false;
    }
    q->front->next = NULL;
    return true;
}
//判空
bool QueueEmpty(LinkQueue q)
{
    if(q.front==q.rear)
    {
        return true;
    }
}
//入队
bool EnQueue(LinkQueue *q,int x)
{ 
    LNode *p = (LinkList)malloc(sizeof(LNode));
    if(!p)
    {
        return false;
    }
    p->data = x;
    p->next = q->rear->next;
    q->rear->next = p;
    q->rear = p;
    return true;
}
//出队
bool DeQueue(LinkQueue *q,int *x)
{
    if(QueueEmpty(*q))
    {
        return false;
    }
    LNode*p = q->front->next;
    *x = p->data;
    q->front->next = p->next;
    if(q->front->next == q->rear)
    {
        q->rear = q->front;
    }
    free(p);
    return true;
}
//销毁队列
bool DestroyQueue(LinkQueue *q)
{
    while(q->front!=NULL)
    {
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }
    return true;
}
//求长
int QueueLength(LinkQueue q)
{
    LNode *p = q.front->next;
    int j = 1;
    while (p!=q.rear)
    {
        p = p->next;
        j++;
    }
    return j;
    
}