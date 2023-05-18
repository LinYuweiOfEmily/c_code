#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MaxSize 100
/*
本次代码要实现的是哈夫曼树的构造，其步骤如下：
1.用一个集合F存储初始的n个带权二叉树(每个二叉树上都只有一个带权的根节点)
2.选取两棵树结点权值最小的树作为左右子树构造一棵新的二叉树，且新的二叉树的根节点的权值为其左右子树上根节点的权值之和
3.在F中删除这两颗树，同时将新得到的树加入F中
*/
//1.链表+栈
typedef struct BiTreeNode
{
    char a[10];     //存储最佳前缀码
    int val;        //表示权值
    struct BiTreeNode *left,*right;
}BiTreeNode,*BiTree;
void CreateHuffmanTree(BiTree T)
{
    BiTreeNode* Stack[MaxSize];
    int top = 20;
    while(top!=0)
    {
        BiTreeNode *p,*q,*root;
        p = Stack[top--];
        q = Stack[top--]; 
        root = (BiTree)malloc(sizeof(BiTreeNode));
        root->left = p;
        root->right = q;
        root->val = p->val+q->val;
        Stack[++top] = root;
        int locate = top;
        for(int i=top-1;i>=0;i--)
        {
            if(Stack[locate]->val > Stack[i]->val)
            {
                BiTreeNode *temp = Stack[locate];
                Stack[locate] = Stack[i];
                Stack[i] = temp;
                locate = i;
            }else
            {
                break;
            }
        }
    }
}
//最佳前缀码的代码递归（往左为0，往右为1）
void HuffmanCoding(BiTree HT)
{
    if(HT!=NULL)
    {
        if(HT->left!=NULL)
        {
            strcpy(HT->left->a,HT->a);
            strcat(HT->left->a,"0");
            HuffmanCoding(HT->left);
        }
        if(HT->right!=NULL)
        {
            strcpy(HT->right->a,HT->a);
            strcat(HT->right->a,"1");
            HuffmanCoding(HT->right);
        }
    }
}
//2.顺序表
typedef struct HuffmanTreeNode
{
    int weight;   //权重
    int parent,left,right;   //
}HuffmanTreeNode,*HuffmanTree;
int main()
{

}