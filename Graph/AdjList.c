#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define INFINITY INT_MAX  //代指无穷大
#define Max_VERTEX_NUM 20
/*
本次代码实现图的邻接矩阵以及相关的一些操作：（无向图）
1.存储结构：包括顶点集VNode->包括顶点信息和指向第一条依附于该顶点的边的指针
           顶点数vexnum,
           边数arcnum,
           邻接表的结点ArcNode->每个结点中包含该结点上所存储结点的位置,指向下一个结点的指针，以及权值
           邻接表ArcList
2.基本操作：创建图结构CreateGraph()
           找到指定结点位置LocateVex()
           返回指定结点的值GetVex()
           修改指定结点的值PutVex()
           判断边xy是否存在Adjacent()
           列出与结点x邻接的所有顶点Neighbor()
           找到与x邻接的第一个顶点FirstAdjVex()
           找到x相对于y的下一个邻接顶点NextAdjvex()
           添加新顶点InsertVex()
           删除顶点DeleteVex()->注意与之相关的边也得删除
           深度优先遍历DFSTraverse()
           广度优先遍历BFSTraverse()
           获得边权值GetEdgeValue()
           设置边权值SetEdgeValue()
*/
typedef struct ArcNode
{
    int ajdvex;
    struct ArcNode *nextarc;
    int weight;
}ArcNode;
typedef struct VNode
{
    char data;
    ArcNode* firstarc;
    int indegree;
}VNode;
typedef struct Graph
{
    VNode vexs[Max_VERTEX_NUM];
    int vexnum,arcnum;
}Graph;
typedef struct MGraph
{
    char vexs[Max_VERTEX_NUM];
    int arcs[Max_VERTEX_NUM][Max_VERTEX_NUM];
    int arcnum,vexnum;
}MGraph;
//创建Graph
void CreateGraph(Graph *G)
{
    G->vexnum = 0;
    G->arcnum = 0;
    char x;
    scanf(" %c",&x);
    while (x!='#')
    {
        G->vexs[G->vexnum].indegree = 0;
        G->vexs[G->vexnum++].data = x;
        scanf(" %c",&x);
    }
    for(int i=0;i<G->vexnum;i++)
    {
        G->vexs[i].firstarc = NULL;
        int j;
        int weight;
        scanf("%d",&j);
        while(j!=-1)
        {
            ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));
            p->ajdvex = j;
            G->vexs[j].indegree++;
            scanf("%d",&weight);
            p->weight = weight;
            p->nextarc = G->vexs[i].firstarc;
            G->vexs[i].firstarc = p;
            scanf("%d",&j);
        }
    }
}
void CreateMGraph(Graph G)
{
    MGraph *MG = (MGraph*)malloc(sizeof(MGraph));
    MG->vexnum = G.vexnum;
    for(int i=0;i<G.vexnum;i++)
    {
        memset(MG->arcs[i],0,sizeof(MG->arcs[i]));
    }
    for(int i=0;i<G.vexnum;i++)
    {
        MG->vexs[i] = G.vexs[i].data;
        for(int j=0;j<G.vexnum;j++)
        {
            ArcNode*p = G.vexs[i].firstarc;
            while(p!=NULL)
            {
                MG->arcs[i][p->ajdvex] = p->weight;
                p = p->nextarc;
            }
        }
    }
    for(int i=0;i<G.vexnum;i++)
    {
        for(int j=0;j<G.vexnum;j++)
        {
            printf("%d ",MG->arcs[i][j]);
        }
        printf("\n");
    } 
}
//找到指定结点的位置
int LocateVex(Graph G,char x)
{
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i].data==x)
        {
            return i;
        }
    }
    return -1;
}
//返回指定结点的值
char GetVex(Graph G,int x)
{
    if(x<0||x>=G.vexnum)
    {
        return '\0';
    }
    return G.vexs[x].data;
}
//修改指定节点的值
void PutVex(Graph *G,int i,char x)
{
    G->vexs[i].data = x;
}
//判断xy之间是否存在边
bool AdjAcent(Graph G,int x,int y)
{
    ArcNode *p = G.vexs[x].firstarc;
    while(p!=NULL)
    {
        if(p->ajdvex==y)
        {
            return true;
        }
        p = p->nextarc;
    }
    return false;
}
//列出与结点x邻接的所有顶点
void Neighbor(Graph G,int x)
{
    ArcNode *p = G.vexs[x].firstarc;
    while (p!=NULL)
    {
        printf("%d ",p->ajdvex);
        p = p->nextarc;
    }
    
}
//找到与结点x邻接的第一个顶点
int FirstAdjVex(Graph G,int x)
{
    return G.vexs[x].firstarc->ajdvex;
}
//找到与x邻接的相对于y的下一个邻接顶点
int NextAdjVex(Graph G,int x,int y)
{
    ArcNode *p = G.vexs[x].firstarc;
    while(p->ajdvex!=y)
    {
        p = p->nextarc;
    }
    if(p==NULL||p->nextarc==NULL)
    {
        return -1;
    }else
    {
        return p->nextarc->ajdvex;
    }
}
//添加新顶点
void InsertVex(Graph *G,char x)
{
    G->vexs[G->vexnum++].data = x;
    G->vexs[G->vexnum-1].firstarc = NULL;
    int j;
    scanf("%d",&j);
    while(j!=-1)
    {
        ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));
        p->ajdvex = x;
        p->nextarc = G->vexs[G->vexnum-1].firstarc;
        G->vexs[G->vexnum-1].firstarc = p;
        scanf("%d",&j);
    }

}
//删除顶点
void DeleteVex(Graph *G,int x)
{
    G->vexs[x].data = '#';
    for(int i=0;i<G->vexnum;i++)
    {
        ArcNode *p = G->vexs[i].firstarc;
        if(p->ajdvex==x)
        {
            G->vexs[i].firstarc = p->nextarc;
            continue;
        }
        while(p->nextarc!=NULL)
        {
            if(p->nextarc->ajdvex==x)
            {
                ArcNode *q = p->nextarc;
                p->nextarc = q->nextarc;
                free(q);
            }
        }
    }
}
//深度优先遍历
bool visited[Max_VERTEX_NUM];
void DFS(Graph G,int i)
{
    printf("%c ",G.vexs[i].data);
    visited[i] = true;
    for(int j=FirstAdjVex(G,i);j>=0;j=NextAdjVex(G,i,j))
    {
        if(!visited[j])
        {
            DFS(G,j);
        }
    }
}
void DFSTraverse(Graph G)
{
    for(int i=0;i<G.vexnum;i++)
    {
        visited[i] = false;
    }
    for(int i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
        {
            DFS(G,i);
        }
    }
}
//深度优先遍历————非递归版
void  DFSTraverse1(Graph G,int v)
{
    memset(visited,false,sizeof(visited));
    DFS1(G,v);
    for(int i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
        {
            DFS1(G,i);
        }
    }
}
void DFS1(Graph G,int v)
{
    int Stack[G.vexnum];
    int top = -1;
    Stack[++top] = v;
    while(top!=-1)
    {
        int u = Stack[top];
        if(!visited[u])
        {
            visited[u] = true;
            printf("%c ",G.vexs[u].data);
        }
        for(int w=FirstAdjVex(G,u);w>=-1;w=NextAdjVex(G,u,w))
        {
            if(w==-1)
            {
                top--;
                break;            
            }
            if(!visited[w])
            {
                Stack[++top] = w;
                break;
            }
        }
    }
}
//广度优先遍历
void BFS(Graph G,int i)
{
    int Queue[Max_VERTEX_NUM];
    int front=-1,rear = -1;
    Queue[0] = i;
    front = 0;
    rear = 1;
    visited[i] = true;
    printf("%c ",G.vexs[i].data);
    while(front!=rear)
    {
        int j = Queue[front++];
        for(int k = FirstAdjVex(G,j);k>=0;k = NextAdjVex(G,j,k))
        {
            if(!visited[k])
            {
                visited[k] = true;
                printf("%c ",G.vexs[k].data);
                Queue[rear++] = k;
            }
        }
    }
}
int GetEdgeValue(Graph G,int x,int y)
{
    ArcNode *p = G.vexs[x].firstarc;
    while(p!=NULL)
    {
        if(p->ajdvex==y)
        {
            break;
        }
        p = p->nextarc;
    }
    if(p==NULL)
    {
        return 100;
    }
    return p->weight;
}
void BFSTraverse(Graph G)
{
    for(int i=0;i<G.vexnum;i++)
    {
        visited[i] = false;
    }
    for(int i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
        {
            BFS(G,i);
        }
    }
}
void SetEdgeValue(Graph G,int x,int y,int w)
{
    ArcNode *p = G.vexs[x].firstarc;
    while(p!=NULL)
    {
        if(p->ajdvex==y)
        {
            p->weight = w;
            break;
        }
    }
}
typedef struct CloseDeg
{
    char adjvex;
    int lowcost;
}CloseDeg;
int Minimum(Graph G,CloseDeg closedeg[])
{
    int i=0;
    int min;
    while(i<G.vexnum)
    {
        if(closedeg[i].lowcost>0)
        {
            min = i;
            break;
        }
        i++;
    }
    for(i=0;i<G.vexnum;i++)
    {
        if(closedeg[i].lowcost>0&&closedeg[i].lowcost<=closedeg[min].lowcost)
        {
            min = i;
        }
    }
    return min;
}
void MiniSpanTree_PRIM(Graph G,char x)
{
    CloseDeg closedeg[Max_VERTEX_NUM];
    int k = LocateVex(G,x);
    for(int i=0;i<G.vexnum;i++)
    {
        if(i!=k)
        {
            closedeg[i].adjvex = x;
            closedeg[i].lowcost = GetEdgeValue(G,k,i);
        }
    }
    closedeg[k].lowcost =  0;
    for(int i=1;i<G.vexnum;i++)
    {
        k = Minimum(G,closedeg);
        printf("(%c,%c) ",closedeg[k].adjvex,G.vexs[k].data);
        closedeg[k].lowcost = 0;
        for(int j=0;j<G.vexnum;j++)
        {
            if(GetEdgeValue(G,k,j)<closedeg[j].lowcost)
            {
                closedeg[j].lowcost = GetEdgeValue(G,k,j);
                closedeg[j].adjvex = G.vexs[k].data;
            }
        }
    }
}
void Indegree(Graph G,int *Indegree)
{
    for(int i=0;i<G.vexnum;i++)
    {
        ArcNode *p = G.vexs[i].firstarc;
        while(p!=NULL)
        {   
            Indegree[p->ajdvex]++;
            p = p->nextarc;
        }
    }
}
// 实现拓扑排序和逆拓扑排序：
/*
1.拓扑排序：图中没有前驱结点的顶点就加入拓扑排序中，然后删除该顶点和所有以它为尾的弧
代码实现思路：我们采用邻接表作有向图的存储结构，
            并在头节点中增加一个存放顶点入度的数组indegree，
            入度为0的点即为没有前驱的顶点，
            而删除结点和所有以它为尾的弧则改成入度减1
*/
int ve[Max_VERTEX_NUM];
int vl[Max_VERTEX_NUM];
bool TopologicalSort(Graph G,int T[])
{
    memset(ve,0,sizeof(ve));
    int Stack[G.vexnum];
    int Top=-1;
    int top=-1;
    int count=0;
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i].indegree==0)
        {
            Stack[++top] = i;
        }
    }
    while(top!=-1)
    {
        int u = Stack[top--];
        T[++Top] = u;
        count++;
        ArcNode *p = G.vexs[u].firstarc;
        while(p!=NULL)
        {
            G.vexs[p->ajdvex].indegree--;
            if(G.vexs[p->ajdvex].indegree==0)
            {
                Stack[++top] = p->ajdvex;
            }
            if(ve[u]+p->weight>ve[p->ajdvex])
            {
                ve[p->ajdvex]=ve[u]+p->weight;
            }
            p = p->nextarc;
        }
        
    }
    if(count==G.vexnum)
    {
        return true;
    }else
    {
        return false;
    }
}

/*
2.逆拓扑排序
对图进行DFS则按退出的先后顺序就是逆向的拓扑排序(可以通过在if之外加上printf或者用一个数组记录下来)
假设从第x个结点为开始结点
*/
bool visited[Max_VERTEX_NUM];
void AntiTopulogicalSort(Graph G,int x)
{
    memset(visited,false,sizeof(visited));
    DFS2(G,x);
}
void DFS2(Graph G,int x)
{
    visited[x] = true;
    for(int i=FirstAdjVex(G,x);i>=0;i=NextAdjVex(G,x,i))
    {
        if(!visited[i])
        {
            DFS2(G,i);
        }
    }
    printf("%c ",G.vexs[x]);
}

/*
实现关键路径：
*/
void CriticalPath(Graph G)
{
    int T[Max_VERTEX_NUM];
    int top=G.vexnum-1;
    TopologicalSort(G,T);
    memset(vl,ve[G.vexnum-1],sizeof(vl));
    while(top!=-1)
    {
        int u = T[top--];
        ArcNode *p = G.vexs[u].firstarc;
        while(p!=NULL)
        {
            int k = p->ajdvex;
            if(vl[k]-p->weight<vl[u])
            {
                vl[u] = vl[k]-p->weight;
            }
        }
    }
    for(int i=0;i<G.vexnum;i++)
    {
        for(ArcNode*p=G.vexs[i].firstarc;p!=NULL;p = p->nextarc)
        {
            int k = p->ajdvex;
            int ee = ve[i];
            int el = vl[k] - p->weight;
            char tag = (ee==el)?'*':' ';
            //接下来就是打印出关键路径
        }
    }
}

/*
求uv之间是否有长度为k的路径：
首先，定义一个矩阵A表示uv之间是否有边（1表示有，0表示没有）
接着按照以下规则进行矩阵的乘法计算：
*/
int visited[Max_VERTEX_NUM];
//出发点为i，终点为j，长度为k 
int exist_path_len(Graph G,int i,int j,int k) 
{
	if(i==j&&k==0)
		return 1;
	else if(k>0)
	{
		visited[i]=1;
		for(ArcNode *p=G.vexs[i].firstarc;p;p=p->nextarc)
		{
			int temp=p->ajdvex;
			if(!visited[temp]&&exist_path_len(G,temp,j,k-1))
				return 1; 
		} 
		visited[i]=0;
//这里需要把已经访问的点重新置为0，因为如果当前不存在长度为k
//到达j点，那么这个点还是可以使用的，因为有可能从其他点出发
//可以到达j点并且长度为k 
	} 
	return 0;
} 
int main()
{
    Graph *G = (Graph*)malloc(sizeof(Graph));
    CreateGraph(G);
    DFSTraverse(*G);
    printf("\n");
    DFSTraverse1(*G,0);
}