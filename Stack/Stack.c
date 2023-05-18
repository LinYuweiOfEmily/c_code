#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//储存空间的初始分配量
#define STACK_INIT_SIZE 10
typedef struct 
{
    //定义一个静态数组
    int data[STACK_INIT_SIZE];
    //类似于静态链表的游标
    int top;
}SqStack;
bool InitStack(SqStack *s);
void ClearStack(SqStack *s);
bool StackEmpty(SqStack s);
int StackLength(SqStack s);
int GetTop(SqStack s);
bool Push(SqStack *s,int x);
int Pop(SqStack *s);
bool UpdateStack(SqStack *s,int x);
int main()
{
    //定义一个栈
    SqStack s;
    InitStack(&s);
    //对栈堆初始化
    int x;
    for (int i = 0; i < STACK_INIT_SIZE; i++)
    {
        scanf("%d",&x);
        Push(&s,x);
    }
    printf("%d",StackEmpty(s));
    ClearStack(&s);
    printf("%d",StackEmpty(s));
}
//建立一个空栈
bool InitStack(SqStack *s)
{
    s->top = -1;
    return true;
}
//清空栈
void ClearStack(SqStack *s)
{
    s->top = -1;
}
//判断是否为空栈
bool StackEmpty(SqStack s)
{
    if(s.top == -1)
    {
        return true;
    }else
    {
        return false;
    }
}
//查询栈的长度
int StackLength(SqStack s)
{
    if(s.top!=-1)
    {
        return s.top+1;
    }else
    {
        return s.top;
    }

}
//查询栈顶元素
int GetTop(SqStack s)
{
    if(s.top!=-1)
    {
        return s.data[s.top];
    }else
    {
        return s.top;
    }
}
//往栈顶加入元素x
bool Push(SqStack *s,int x)
{
    if(s->top == STACK_INIT_SIZE-1)
    {
        return false;
    }else
    {
        s->top++;
        s->data[s->top] = x;
        return true;
    }
}
//删除栈顶元素
int Pop(SqStack *s)
{
    s->top--;
    return s->data[s->top+1];   
}
//修改栈顶元素
bool UpdateStack(SqStack *s,int x)
{
    if (s->top == -1)
    {
        return false;
    }
    
    s->data[s->top] = x;
    return true;
}