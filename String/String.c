#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
/*
本次代码主要实现字符串的一些基本功能
1.subString;
2.
3.
*/
typedef struct String
{
    char string[100];
    int length;
}String;
int index(String s,String a);
int index1(String s,String a);
bool InitString(String *s);
bool SubString(String *a,String s,int pos,int length);
void GetNext(int next[],String a);
int main()
{
    String a,s;
    InitString(&a);
    InitString(&s);
    scanf("%s",s.string);
    s.length = strlen(s.string);
    SubString(&a,s,6,6);
    printf("%d",index1(s,a));
}
//初始化
bool InitString(String *s)
{
    s->length = 0;
}
//实现SubString
bool SubString(String *a,String s,int pos,int length)
{
    if(length<=0 || length >100-pos)
    {
        return false;
    }
    for (int i = pos; i <= pos + length; i++)
    {
        a->string[a->length+1] = s.string[i];
        a->length++;
    }
    
    return true;
}
/*
求子串位置；
1.朴素模式匹配算法：
该算法主要有以下几步：
1.定义k,i,j其中k表示s中的起始位置，i，j分别为s和a中的扫描数
2.令i=k，j=1开始循环直至找到子串位置或者i超出范围循环结束，其中如果循环过程中s[i]!=a[j]则k指向下一位重新循环
3.返回k的起始位置
*/

int index(String s,String a)
{
    int k = 1;     //指向当前的起始位置
    int i = k;   //从k处开始遍历
    int j = 1; //a的遍历指针
    while (i<=s.length && j<=a.length)
    {
        if(s.string[i]==a.string[j])
        {
            i++;
            j++;
        }else
        {
            k++;
            i = k;
            j = 1;
        }
    }
    if(j>a.length)
    {
        return k;
    }else
    {
        return 0;
    }
}
/*求子串位置：
2.KMP算法：
核心思想：主值i不回溯，通过改变j回溯的位置提高效率，而j回溯的位置则由与子串每个字符一一对应的next[j]决定,下面介绍next函数的求法
求next数组：
首先引入前后缀的概念：
前缀：包含第一个字符，但不包含最后一个字符
后缀：包含最后一个字符，但不包含第一个字符
根据规律我们知道next[j] = 最长公共前后缀+1且next[1] = 0且next[2] = 1
因此我们可以通过定义两个变量m,n(m遍历整个子串，n表示最大相等前后缀长度)，分别指向j前子串T的1和0处开始如果n为0或者T[m]==T[n]则mn自增并令next[m] = n否则n = next[n]直到j = a.length结束
接着开始求子串的位置，先定义两个变量分别指向s和a的0处开始循环然后当j=0或者s[i]=a[j]时,i和j自增
否则j回退到next[j]的位置，直至i>s.length&&j>a.length循环结束,最后返回子串的初始位置，没找到则返回0
*/
int index1(String s,String a)
{
    int next[a.length];
    GetNext(&next,a);
    int i=0,j=0;
    while (i<=s.length && j<=a.length)
    {
        if(j==0 || s.string[i]==a.string[j])
        {
            i++;
            j++;
        }else
        {
            j = next[j];
        }
    }
    if(j>a.length)
    {
        return i-j+1;
    }else
    {
        return 0;
    }
    
}
void GetNext(int next[],String a)
{
    int i=1,j=0;
    next[1] = 0;
    while (i<a.length)
    {   
        if(a.string[i] == a.string[j] || j==0)
        {
            i++;
            j++;
            next[i] = j;
        }else
        {
            j = next[j];
        }
    }
}