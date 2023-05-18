#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 10
typedef struct demo
{
    int La[MAXSIZE];
    int length;
}Demo;
//实现顺序表
bool ListInsert(Demo *L,int i,int e);
bool ListDelete(Demo *L,int i);
int main()
{
    Demo a;
    a.length =  0;
    for (int i = 0; i < 5; i++)
    {
        a.La[i] = i;
        a.length++;
    }
    ListInsert(&a,3,6);
    ListDelete(&a,2);
    for (int i = 0; i < a.length; i++)
    {
        printf("%d",a.La[i]);
    }
    
    return 0;
}
bool ListInsert(Demo *L,int i,int e)
{
    if (i<0 || i>L->length-1)
    {
        return false;
    }
    if(i>=MAXSIZE)
    {
        return false;
    }
    for (int j = L->length; j > i; j--)
    {
        (L->La)[j] = (L->La)[j-1];
    }
    (L->La)[i] = e;
    L->length++;
    return true;
}
bool ListDelete(Demo *L,int i)
{
    if(i<0 || i>L->length)
    {
        return false;
    }
    for (int j = i; j < L->length-1; j++)
    {
        (L->La)[j] = (L->La)[j+1];
    }
    L->length--;
    return true;
}