#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*ͨ��ջʵ�����ŵ�ƥ��
1.����һ�����鴢����Ҫƥ����������ţ��Լ���ʼ��һ��ջ
2.��������ƥ�䣺��������ջ�����������ų�ջ�����������Ų������Ϊƥ��ʧ??
3.�������е��������ž�����꣬���ջ�Ƿ�Ϊ�գ����ǿ���ƥ��ʧ�ܣ�
����ջ��Ϊ�ն���������������δ��ƥ�䵽����Ϊƥ��ʧ��??
���������Ϊƥ��ɹ�
*/
#define MaxSize 100
typedef struct Sqstack
{
    char bracket[MaxSize];
    int top;
}Sqstack;
bool InitStack(Sqstack *S);
bool StackEmpty(Sqstack S);
void Push(Sqstack *S,char x);
char Pop(Sqstack *S);
bool BracketChack(char brackets[],Sqstack S,int cnt);
int main()
{
    char brackets[MaxSize];
    Sqstack S;
    InitStack(&S);
    char x;
    scanf(" %c",&x);
    int cnt = 0;
    for (int i = 0; i < MaxSize && x!='0'; i++)
    {
        brackets[i] = x;
        scanf(" %c",&x);
        cnt++;
    }
    if (BracketChack(brackets,S,cnt))
    {
        printf("ƥ��ɹ�");
    }else
    {
        printf("ƥ��ʧ��");
    }
}
//��ʼ��ջ
bool InitStack(Sqstack *S)
{
    S->top = -1;
    return true;
}
//�п�
bool StackEmpty(Sqstack S)
{
    if(S.top == -1)
    {
        return true;
    }else
    {
        return false;
    }
}
//��ջ
void Push(Sqstack *S,char x)
{
    S->top++;
    S->bracket[S->top] = x;
}
//��ջ
char Pop(Sqstack *S)
{
    if(StackEmpty(*S))
    {
        return '0';
    }
    return S->bracket[S->top--];
}
bool BracketChack(char brackets[],Sqstack S,int cnt)
{
    if(cnt%2!=0)
    {
        return false;
    }
    for (int i = 0; i < cnt; i++)
    {   
        char x = brackets[i];
        if(x=='(' || x=='{'|| x=='[')
        {
            Push(&S,x);
        }else
        {
            char y = Pop(&S);
            if((x==')'&&y=='(')||(x==']'&&y=='[')||(x=='}'&&y=='{'))
            {
                continue;
            }else
            {
                return false;
            }
        }
    }
    if(!StackEmpty(S))
    {
        return false;
    }else
    {
        return true;
    }
}