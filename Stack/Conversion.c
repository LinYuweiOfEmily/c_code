#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 20
/*
本次代码主要通过栈实现数值转换：   
1.创建一个栈用于储存每位转换之后对应的数字
2.通过N = (N div d)*d + N mod d(div:整除运算,mod：求余运算)求出转换后的数并储存进栈中
3.输出打印栈中元素
*/
typedef struct Sqstack
{
    int data[MaxSize];
    int top;
}Sqstack;
void InitStack(Sqstack *s);
void Push(Sqstack *s,int x);
int Pop(Sqstack *s);
bool StackEmpty(Sqstack s);
void Conversion(Sqstack *s,int n);
int main()
{
    Sqstack conversion;
    InitStack(&conversion);
    int N;
    scanf("%d",&N);
    if (N<0)
    {
        N = -N;
        printf("-");
    }
    Conversion(&conversion,N);
    while (!StackEmpty(conversion))
    {
        printf("%d",Pop(&conversion));
    }
}
//初始化栈
void InitStack(Sqstack *s)
{
    s->top = -1;
}
//入栈
void Push(Sqstack *s,int x)
{
    s->top++;
    s->data[s->top] = x;
}
//出栈
int Pop(Sqstack *s)
{
    return s->data[s->top--];
}
//判空
bool StackEmpty(Sqstack s)
{
    if(s.top==-1)
    {
        return true;
    }else
    {
        return false;
    }
}
//实现数制转换
void Conversion(Sqstack *s,int n)
{
    while (n>7)
    {
        Push(s,n%8);
        n /= 8;
    }
    Push(s,n);
}