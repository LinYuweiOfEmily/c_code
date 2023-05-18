#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Sqstack
{
    int data;
    struct Sqstack *next;
}Sqstack,*Listack;
bool InitStack(Listack *S);
bool InsertStack(Listack *S,int x);
int main()
{
    Listack S;
    InitStack(&S);
    for (int i = 0; i < 5; i++)
    {
        InsertStack(&S,i+1);
    }
}
//初始化栈
bool InitStack(Listack *S)
{
    *S = NULL;
    return true;
}
//插入元素
bool InsertStack(Listack *S,int x)
{
    Sqstack *p = (Listack)malloc(sizeof(Sqstack));
    if (!p)
    {
        return false;
    }
    
    p->next = *S;
    p->data = x;
    *S = p;
    return true;
}
//删除元素
int DeleteStack(Listack *S)
{
    int x = (*S)->data;
    Sqstack *p = *S;
    *S = p->next;
    free(p);
    return x;
}
//查找栈顶
int GetTop(Listack S)
{
    return S->data;    
}
//遍历栈
void StackTraverse(Listack S)
{
    //扫描指针
    Sqstack *p = S;
    while (p!=NULL)
    {
        printf("%d",p->data);
        p = p->next;
    }
}
