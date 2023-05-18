#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#define MaxSize 20
/*
���δ���ʵ�ֵ����������ʽ��ֵ����Ҫ�Ĳ���Ϊ��
1.��ʼ������ջ���ֱ�Ϊ������ջ�������ջ��
2.ɨ��������׺���ʽ�����������������
��1��������������ѹ�������ջ�У�
��2���������������ջ�е��������������ǿ�ջ�Ļ����Ƚ����ȼ��������ȼ����ڻ����Ҫѹ���������򵯳�ջ�����е���������������3��
��3����������������ѹ�������ջ�У�ֱ��������֮��ƥ��ġ������󽫡�����֮��������ѹ��ջ�е����������ջ�����е���������������3��
3.��������������������ջ����ջ�����������Ԫ�ؽ�������Ȼ��������ѹ�������ջ����
*/
//�����ջ
typedef struct Sqstack
{
    char operator[MaxSize];
    int top;
}Sqstack;
//������ջ
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
    //��ʼ������ջ�ֱ�Ϊ�����ջ�Ͳ�����ջ
    Sqstack OPTR;
    Initstack(&OPTR);
    Sqstack1 OPED;
    Initstack1(&OPED);
    //���������ʽ
    char op[MaxSize];
    scanf("%s",op);
    int count = strlen(op);
    printf("%d",EvaluateExpression(OPTR,OPED,op,count));
}
//��ʼ��ջ
void Initstack(Sqstack *s)
{
    s->top = -1;
}
void Initstack1(Sqstack1 *s)
{
    s->top = -1;
}
//��ջ
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
//��ջ
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
//�ж��Ƿ�Ϊ�ձ�
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
//ʵ�ֱ��ʽ��ֵ�Ĺ���(����s�����������p���������)
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
//ʵ�ֱ��ʽ��ʵ������
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
    //��cѹ��ջ��
    Push1(p,c);              
}