#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*
本次代码用于实现树的链式存储结构及二叉树的相关函数实现

*/
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,* BiTree;
void CreateBiTree(BiTree *T);
void PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);
void LevelOrderTraverse(BiTree T);
int main()
{
    BiTree T;
    CreateBiTree(&T);
    PreOrderTraverse(T);
    printf("\n");
    InOrderTraverse(T);
    printf("\n");
    PostOrderTraverse(T);
    printf("\n");
    LevelOrderTraverse(T);
}
void InitBiTree(BiTree *T)
{
    *T = (BiTree)malloc(sizeof(BiTNode));
    (*T)->lchild = NULL;
    (*T)->rchild = NULL;
}
bool BiTreeEmpty(BiTree T)
{
    if(T->lchild==NULL && T->rchild==NULL)
    {
        return true;
    }
    return false;
}
int BiTreeDepth(BiTree T)
{
    int m,n;
    if(T!=NULL)
    {
        m = BiTreeDepth(T->lchild);
        n = BiTreeDepth(T->rchild);
        if(m>n)
        {
            return m+1;
        }else
        {
            return n+1;
        }
    }else
    {
        return 0;
    }
}
BiTNode *root(BiTree T)
{
    return T;
}
int value(BiTree T,BiTNode *e)
{
    if(!BiTreeEmpty(T))
    {
        return 0;
    }
    return e->data;
}
void Assign(BiTree T,BiTNode *e,int value)
{
    e->data = value;
}
BiTNode *LeftChild(BiTree T,BiTNode *e)
{
    return e->lchild;
}
BiTNode *RightChild(BiTree T,BiTNode *e)
{
    return e->rchild;
}
void InsertChild(BiTree T,BiTNode *p,int LR,BiTNode *c)
{
    if(LR==0)
    {
        c->rchild = p->lchild;
        p->lchild = c;
    }else if(LR==1)
    {
        c->rchild = p->rchild;
        p->rchild = c;
    }
}
void PreOrderTraverse(BiTree T)
{
    if(T!=NULL)
    {
        printf("%d ",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
void InOrderTraverse(BiTree T)
{
    if(T!=NULL)
    {
        InOrderTraverse(T->lchild);
        printf("%d ",T->data);
        InOrderTraverse(T->rchild);
    }
}
void PostOrderTraverse(BiTree T)
{
    if(T!=NULL)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%d ",T->data);
    }
}
void LevelOrderTraverse(BiTree T)
{
    BiTree Queue[100];
    int front = -1,rear = -1;
    Queue[0] = T;
    front = 0,rear = 1;
    while(front!=rear)
    {
        BiTNode * Node = Queue[front++];
        printf("%d ",Node->data);
        if(Node->lchild!=NULL)
        {
            Queue[rear++] = Node->lchild;
        }
        if(Node->rchild!=NULL)
        {
            Queue[rear++] = Node->rchild;
        }
    }
}
void CreateBiTree(BiTree *T)
{
    int ch;
    scanf("%d",&ch);
    if(ch == -1)
    {
        *T = NULL;
    }else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = ch;
        CreateBiTree(&((*T)->lchild));
        CreateBiTree(&((*T)->rchild));
    }
}