#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#define MaxSize 20
/*
本次代码实现的是算数表达式求值，主要的步骤为：
1.初始化两个栈，分别为操作数栈和运算符栈。
2.扫描整个中缀表达式，将会有三种情况：
（1）遇到操作数则压入操作数栈中；
（2）遇到运算符则与栈中的运算符（如果不是空栈的话）比较优先级，若优先级高于或等于要压入的运算符则弹出栈，若有弹出的运算符则进行3；
（3）遇到‘（’则将其压入运算符栈中，直到遇到与之相匹配的‘）’后将‘（’之后及其自身压入栈中的运算符弹出栈，若有弹出的运算符则进行3。
3.将弹出的运算符与操作数栈中离栈顶最近的两个元素进行运算然后将运算结果压入操作数栈顶。
*/
//运算符栈
typedef struct Sqstack
{
    char operator[MaxSize];
    int top;
}Sqstack;
//操作数栈
typedef struct Sqstack1
{
    int numbers[MaxSize];
    int top;
}Sqstack1;
void Initstack(Sqstack *s);
void Initstack1(Sqstack1 *s);
bool Push(Sqstack *s,char x);
bool Push1(Sqstack1 *s,int x);
char Pop(Sqstack *s);
int Pop1(Sqstack1 *s);
bool StackEmpty(Sqstack s);
bool StackEmpty1(Sqstack1 s);
int EvaluateExpression(Sqstack s,Sqstack1 p,char op[],int count);
void Operate(Sqstack1 *p, char x);
int main()
{   
    //初始化两个栈分别为运算符栈和操作数栈
    Sqstack OPTR;
    Initstack(&OPTR);
    Sqstack1 OPED;
    Initstack1(&OPED);
    //输入待求表达式
    char op[MaxSize];
    scanf("%s",op);
    int count = strlen(op);
    printf("%d",EvaluateExpression(OPTR,OPED,op,count));
}
//初始化栈
void Initstack(Sqstack *s)
{
    s->top = -1;
}
void Initstack1(Sqstack1 *s)
{
    s->top = -1;
}
//入栈
bool Push(Sqstack *s,char x)
{
    if (s->top==MaxSize-1)
    {
        return false;
    }   
    s->top++;
    s->operator[s->top] = x;
    return true;
}
bool Push1(Sqstack1 *s,int x)
{
    if (s->top==MaxSize-1)
    {
        return false;
    }   
    s->top++;
    s->numbers[s->top] = x;
    return true;
}
//出栈
char Pop(Sqstack *s)
{
    if (s->top==-1)
    {
        return -1;
    }
    return s->operator[s->top--];
}
int Pop1(Sqstack1 *s)
{
    if (s->top==-1)
    {
        return -1;
    }
    return s->numbers[s->top--];
}
//判断是否为空表
bool StackEmpty(Sqstack s)
{
    if(s.top == -1)
    {
        return true;
    }
    return false;
}
bool StackEmpty1(Sqstack1 s)
{
    if(s.top == -1)
    {
        return true;
    }
    return false;
}
//实现表达式求值的功能(其中s储存运算符，p储存操作数)
int EvaluateExpression(Sqstack s,Sqstack1 p,char op[],int count)
{
    for (int i = 0; i < count; i++)
    {
        char op1[MaxSize*2];
        int l = 0;
        if(isdigit(op[i])||(op[i]=='-'&&(op[i-1]<48||op[i-1]>57)&&i!=0)||(op[i]=='-'&&i==0))
        {
            for (int k = i; k <= count; k++)
            {
                op1[l++] = op[k];
            }
            Push1(&p,atoi(op1));
            int j=i+1;
            while (op[j]!='\0'&&op[j]>=48&&op[j]<=57)
            {
                j++;
            }
            i = j-1;
        }else
        {
            char x = op[i];
            if (!StackEmpty(s))
            {
                int j = s.top;
                while (j==s.top && s.top>=0)
                {
                    char y = s.operator[j];
                    switch (x)
                    {
                    case '+':
                        if (y!='(')
                        {
                            Operate(&p,Pop(&s));
                        }
                        j--;    
                        break;
                    case '-':
                        if (y!='(')
                        {
                            Operate(&p,Pop(&s));
                        }
                        j--;
                        break;
                    case '*':
                        if (y=='*' || y=='/')
                        {
                            Operate(&p,Pop(&s));
                        }
                        j--;
                        break;
                    case '/':
                        if (y=='*' || y=='/')
                        {
                            Operate(&p,Pop(&s));
                        }
                        j--;
                        break;
                    case ')':
                        if (y!='(')
                        {
                            Operate(&p,Pop(&s));
                            j--;
                        }else
                        {
                            Pop(&s);
                        }
                        break;
                    default:
                        j--;
                        break;
                    }
                }
                if (x!=')')
                {
                    Push(&s,x);
                }
            }else
            {
                Push(&s,x);
            }
        }
    }
    while (!StackEmpty(s))
    {
        Operate(&p,Pop(&s));
    }
    return p.numbers[p.top];
}
//实现表达式的实际运算
void Operate(Sqstack1 *p, char x)
{
    int a,b,c;
    a = Pop1(p);
    b = Pop1(p);
    if (x == '+')
    {
        c = a + b;
    }else if (x == '-')
    {
        c = b - a;
    }else if (x == '*')
    {
        c = b * a;
    }else if (x == '/')
    {
        if (a!=0)
        {
            c = b/a;
        }
        
        c = b / a;
    }
    //将c压入栈中
    Push1(p,c);              
}