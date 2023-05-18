#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 10
/*
本次代码主要实现普通队列的相关内容
1.初始化
2.入队（EnQueue）
3.出队(DeQueue)
4.判空(QueueEmpty)
5.求长(QueueLength)
6.返回队头(GetHead)
7.销毁队列
8.清空队列
9.遍历队列（QueueTraverse）
*/
typedef struct SqQueue
{
    int data[MaxSize];
    int front,rear;
    int size;           //用于计算队列的长度
}SqQueue;
void InitQueue(SqQueue *q);
bool QueueEmpty(SqQueue q);
bool EnQueue(SqQueue *q,int x);
bool DeQueue(SqQueue *q,int *x);
bool ClearQueue(SqQueue *q);
int QueueLength(SqQueue q);
int GetHead(SqQueue q);
int main()
{
    SqQueue q;
    InitQueue(&q);
    int x;
    for (int i = 0; i < 5; i++)
    {
        EnQueue(&q,i+1);
    }
    for (int i = 0; i < 6; i++)
    {
        printf("%d %d\n",GetHead(q),QueueLength(q));
        x = DeQueue(&q,&x);
    }
    
}
//初始化队列
void InitQueue(SqQueue *q)
{
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}
//判空
bool QueueEmpty(SqQueue q)
{
    if(q.size==0)
    {
        return true;
    }
    return false;
}
//入队
bool EnQueue(SqQueue *q,int x)
{
    if (q->rear==MaxSize)
    {
        return false;
    }
    q->data[q->rear++]=x;
    q->size++;
    return true;
}
//出队
bool DeQueue(SqQueue *q,int *x)
{
    if (QueueEmpty(*q))
    {
        return false;
    }
    *x =q->data[q->front++];
    q->size--;
    return true;
}
//清空队列
bool ClearQueue(SqQueue *q)
{
    InitQueue(q);
    if (QueueEmpty(*q))
    {
        return true;
    }
    return false;
}
//求长
int QueueLength(SqQueue q)
{
    return q.size;
}
//返回队头元素
int GetHead(SqQueue q)
{
    if (QueueEmpty(q))
    {
        return -1;
    }
    return q.data[q.front];
}