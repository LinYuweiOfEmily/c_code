#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
本次代码实现线索二叉树的几个功能：
1.前中后序的线索化
2.前中后序的前驱后继
*/
typedef struct BiThrNode
{
    int data;
    struct BiThrNode *lchild,*rchild;
    int lTag,rTag;
}BiThrNode,*BiThrTree;
BiThrNode *pre = NULL;
int main()
{

}
/*首先是对树的前中后序线索化主要利用的是二叉树一定会有n+1个空指针域来实现
具体实现过程如下：
1.仿照前中后序遍历的方法对该树进行遍历，在遍历的过程中顺便线索化
2.线索化的主要操作为：该结点的左子树是否为空，为空则令T.lchild = pre并令lTag=1,如果pre的右孩子为空则令其右孩子为T并令rTag=1最后让pre指向T,然后完成线索化
需要注意事项如下：
1.先序遍历线索化的时候要T.ltag==0才能访问其左孩子不然会造成“爱的魔力转圈圈”的现象
2.该操作并不能包含对最后一个结点右孩子的操作所以记得在调用这个函数的时候对最后一个结点线索化
*/
void PreOrderThreading(BiThrTree T)
{
    visit(T);
    if(T->lTag==0)
    {
        PreOrderThreading(T->lchild);
    }
    PreOrderThreading(T->rchild);
}
void InOrderThreading(BiThrTree T)
{
    InOrderThreading(T->lchild);
    visit(T);
    InOrderThreading(T->rchild);
}
void PostOrderThreading(BiThrTree T)
{
    PostOrderThreading(T->lchild);
    PostOrderThreading(T->rchild);
    visit(T);
}
void visit(BiThrTree T)
{
    if(T->lchild==NULL)
    {
        T->lchild = pre;
        T->lTag = 1;
    }
    if(pre!=NULL && pre->rchild==NULL)
    {
        pre->rchild = T;
        pre->rTag = 1;
    }
    pre = T;
}
/*
接着实现的是线索化完该结点后寻找前驱后继的操作
一、先序：（根左右）
1.找p前驱：（不做代码实现）
由于本次的树类型是二叉链表，所以无法找到p的父节点，也就是p的前驱结点（用三叉链表就可以），
我们假设可以找到p的父节点，则可以分成以下三种情况讨论：
（1）p为左节点则p的前驱结点即为它的父节点
（2）p为右节点但其父节点无左孩子，则p的前驱结点仍为它的父节点
（3）p为右节点且其父节点有左孩子，则p的前驱结点为其左兄弟的最右边的结点(其左兄弟一直往右孩子方向找即可)
2.找p的后继：
（1）左孩子存在（lTag==0），左孩子为它的后继
（2）左孩子不存在则无论右孩子存不存在，其后继均为其右孩子上的结点
二、中序：（左根右）
1.找p的前驱：
（1）左孩子不存在（lTag==1），则左孩子上的结点即为它的前驱
（2）左孩子存在（lTag==0）,则找到其左孩子的最右边的结点
2.找p的后继：
（1）右孩子不存在（RTag==1）,则右孩子上的结点即为它的后继
（2）右孩子存在（RTag==0）,则找到其右孩子最左的子孙结点
三、后序：（左右根）
1.找p的前驱：
（1）右孩子存在（rTag==0）,则右孩子为它的前驱
（2）右孩子不存在（rTag==1）,则其前驱为其右孩子上的结点
2.找p的后继：
与找前序遍历的前驱类似
*/
BiThrNode* PreNode(BiThrTree p)
{
    if(p->lTag==1)
    {
        return p->lchild;
    }
    if(p->lTag==0)
    {
        return LastNode(p->lchild);
    }
}
BiThrNode*LastNode(BiThrTree p)
{
    while(p->rTag==0)
    {
        p = p->rchild;
    }
    return p;
}
BiThrNode* NextNode(BiThrTree p)
{
    if(p->rTag==0)
    {
        return FirstNode(p->rchild);
    }else
    {
        return p->rchild;
    }
}
BiThrNode* FirstNode(BiThrTree p)
{
    while(p->lTag==0)
    {
        p = p->lchild;
    }
    return p;
}
BiThrNode* PreNode1(BiThrTree p)
{
    if(p->rTag==0)
    {
        return p->rchild;
    }else
    {
        return p->lchild;
    }
}
BiThrNode* NextNode(BiThrTree p)
{
    if(p->lTag==0)
    {
        return p->lchild;
    }else
    {
        return p->rchild;
    }
}