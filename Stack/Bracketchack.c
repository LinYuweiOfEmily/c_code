#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/*通过栈实现括号的匹配
1.建立一个数组储存需要匹配的所有括号，以及初始化一个栈
2.进行括号匹配：左括号入栈，遇到右括号出栈，若两个括号不配对视为匹配失??
3.当数组中的所有括号均检测完，检查栈是否为空，若非空则匹配失败；
或者栈已为空而数组中仍有括号未被匹配到，视为匹配失败??
其余情况视为匹配成功
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
        printf("匹配成功");
    }else
    {
        printf("匹配失败");
    }
}
//初始化栈
bool InitStack(Sqstack *S)
{
    S->top = -1;
    return true;
}
//判空
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
//入栈
void Push(Sqstack *S,char x)
{
    S->top++;
    S->bracket[S->top] = x;
}
//出栈
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