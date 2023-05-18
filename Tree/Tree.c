#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define Maxsize 100
/*
本次代码主要实现树的顺序存储结构以及相关的一些基本操作:
(需注意的是第一个元素从1开始存储为了方便寻找元素)
InitBiTree()
BiTreeEmpty
BiTreeDepth //返回树的深度
Root  //返回树根
Value    //返回树的指定节点上的值
Assign   //给指定节点赋值
Parent   //返回双亲结点（需判断是否为根节点）
LeftChild(RightChild) //存在则返回左右孩子
leftSibling(Right)   //返回左右兄弟
Pre(In,Post)OrderTraverse //前中后序遍历
*/
typedef struct Tree
{
    char data[Maxsize];
}Tree;
void PreBiTreeTraverse(Tree T,int i);
void InitBiTree(Tree *biTree);
bool Assign(Tree *tree ,int i,char e);
void InBiTreeTraverse(Tree T,int i);
void PostBiTreeTraverse(Tree T,int i);
int main()
{
    Tree T;
    InitBiTree(&T);
    char x;
    int i = 1;
    do
    {
        scanf(" %c",&x);
        if(x!='#')
        {
            Assign(&T,i,x);
            i++;
        }
    } while (x!='#');
    PreBiTreeTraverse(T,1);
    printf("\n");
    InBiTreeTraverse(T,1);
    printf("\n");
    PostBiTreeTraverse(T,1);
    return 0;
}
//初始化二叉树
void InitBiTree(Tree *biTree)
{
    memset(biTree->data,0,sizeof(biTree->data));
}
bool Assign(Tree *tree ,int i,char e)
{
    if(i<1 || i>Maxsize-1)
    {
        return false;
    }
    tree->data[i] = e;
    return true;
}
bool Value(Tree tree,int i,char *e)
{
    if(i<1 || i>Maxsize-1)
    {
        return false;
    }
    *e = tree.data[i];
    return true;
}
bool BiTreeEmpty(Tree tree)
{
    if(tree.data[1]!=0)
    {
        return false;
    }
    return true;
}
char Root(Tree tree)
{
    if(!BiTreeEmpty(tree))
    {
        return tree.data[1];
    }
    return 0;
}
char LeftChild(Tree tree,int i)
{
    if(i<1 || 2*i>Maxsize-1)
    {
        return 0;
    }
    return tree.data[2*i];
}
char RightChild(Tree tree,int i)
{
    if(i<1 || 2*i>Maxsize -1)
    {
        return 0;
    }
    return tree.data[2*i+1];
}
char Parent(Tree tree,int i)
{
    if(i<1||i>Maxsize-1)
    {
        return 0;
    }
    return tree.data[i/2];
}
void PreBiTreeTraverse(Tree T,int i)
{
    if(T.data[i]!=0 || i>Maxsize-1)
    {
        printf("%c ",T.data[i]);
        PreBiTreeTraverse(T,2*i);
        PreBiTreeTraverse(T,2*i+1);
    }
}
void InBiTreeTraverse(Tree T,int i)
{
    if(T.data[i]!=0 || i>Maxsize-1)
    {
        InBiTreeTraverse(T,2*i);
        printf("%c ",T.data[i]);
        InBiTreeTraverse(T,2*i+1);
    }
}
void PostBiTreeTraverse(Tree T,int i)
{
    if(T.data[i]!=0 || i>Maxsize-1)
    {
        PostBiTreeTraverse(T,2*i);
        PostBiTreeTraverse(T,2*i+1);
        printf("%c ",T.data[i]);
    }
}