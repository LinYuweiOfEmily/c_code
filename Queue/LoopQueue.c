#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 10
/*
本次代码实现的是循环队列的相关操作:
所实现的功能与普通队列相同，不同的是实现的方法，下面列出与普通队列不同的点：
1.循环队列是逻辑结构上循环，物理上仍与普通队列相同。可以通过求余运算实现（rear %= MaxSize;q.data[rear]）
2.计算队列长度以及判空和判满时可通过多加一个变量size来算出长度,或者通过（q.rear-q.front+MaxSize）%MaxSize
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
    if(q.size == 0)
    {
        return true ;
    }
    return false;
}
//求长
int QueueLength(SqQueue q)
{
    return q.size;
}
//入队
bool EnQueue(SqQueue *q,int x)
{
    if (q->size==MaxSize)
    {
        return false;
    }
    q->data[q->rear] = x;
    q->rear++;
    q->rear %= MaxSize;
    q->size++;
    return true;
}
//出队
bool DeQueue(SqQueue *q,int *x)
{
    if (q->size==0)
    {
        return false;
    }
    *x = q->data[q->front++];
    q->front %= MaxSize;
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
//获得队首元素
int GetHead(SqQueue q)
{
    return q.data[q.front];
}