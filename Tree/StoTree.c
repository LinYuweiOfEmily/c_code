#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MaxSize 100
/*
本次代码要实现的主要是树的三种存储结构：
1.双亲表示法（之后会用于归并集的实现）：该种方法是通过一片连续空间来存储树，每个结点储存自己本身所携带的数据以及其父节点的位置
            优点是找父节点方便；缺点是求结点的孩子的时候需要遍历整棵树找父节点是它的点
2.孩子表示法+双亲表示法：这种方法采用链表+顺序表的形式，顺序表的每个结点包含着以及其父节点的位置携带的数据以及其孩子链表的头指针(孩子结点中包含着其位置以及下一个结点的位置)
            该方法集合了孩子表示法和双亲表示法的优点，较为全面
3.兄弟孩子表示法：该方法采用了二叉树的数据结构，因此以该方法存储的树结构更方便我们操作，是一种极为重要的方法，其主要实现方法是二叉树的左孩子存储其第一个孩子，右孩子存储其兄弟结点

*/
//双亲表示法
typedef struct PTNode{
    int data;
    int parent;
}PTNode;
typedef struct PTree
{
    PTNode nodes[MaxSize];
    int r,n;        //根的位置和结点数 r定义的目的应该是为了终止树的遍历
}PTree;
//孩子双亲表示法
typedef struct CTNode{
    int child;          //孩子所在的位置
    struct CTNode *next;
}*ChildPtr;
typedef struct CTBox{
    int data;
    int parent;
    ChildPtr firstChild;
}CTBox;
typedef struct CTree{
    CTBox ctboxs[MaxSize];
    int r,n;      //即根节点的位置和总长度
}CTree;
//孩子兄弟表示法
typedef struct CSNode{
    int data;
    struct CSNode*firstchild,*nextsibling;
}CSNode,*CSTree;
int main()
{
    return 0;
}
/*
树的遍历主要有三种：
一种是先根遍历->与其二叉树的先序遍历相同
另一种是后根遍历->与其对应二叉树的中序遍历相同
最后一种是层序遍历->与其对应的二叉树的层序遍历相同
森林的遍历主要有两种：
一种是先序遍历->依次对各个树先根遍历->依次对各个对应二叉树先序遍历
一种是中序遍历->依次对各个树后根遍历->依次对各个对应二叉树中序遍历
*/

//孩子表示法的先序遍历
void TreePreTraverse(CTree T,CTBox *root)
{   
    if(root!=NULL)
    {
        while(root->firstChild->next!=NULL)
        {
            root = &T.ctboxs[root->firstChild->next->child];
            TreePreTraverse(T,root);
        }
        printf("%d",root->data);
    }
}
//孩子兄弟表示法的先序遍历（即为普通二叉树的遍历）