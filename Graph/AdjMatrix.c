#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define INFINITY 100   //浠ｆ寚鏃犵┓涔熷氨鏄簩鑰呬笉杩烇拷?
#define Max_VERTEX_NUM 20
/*
鏈浠ｇ爜瀹炵幇鍥剧殑閭绘帴鐭╅樀浠ュ強鐩稿叧鐨勪竴浜涙搷浣滐細锛堟棤鍚戝浘锟�?
1.瀛樺偍缁撴瀯锛氬寘鎷《鐐归泦vexs锟�?
           椤剁偣鏁皏exnum,
           杈规暟arcnum,
           閭绘帴鐭╅樀arcs(姣忎釜缁撶偣瀛樺偍鐫€椤剁偣涓庨《鐐逛箣闂寸殑鍏崇郴锛堢敤0锟�?1琛ㄧず锛夋湁鏉冨浘鍒欏彲鍐嶅瓨鍌ㄦ潈锟�?)锟�?
2.鍩烘湰鎿嶄綔锛氬垱寤哄浘缁撴瀯CreateGraph()
           鎵惧埌鎸囧畾缁撶偣浣嶇疆LocateVex()
           杩斿洖鎸囧畾缁撶偣鐨勫€糋etVex()
           淇敼鎸囧畾缁撶偣鐨勫€糚utVex()
           鍒ゆ柇杈箈y鏄惁瀛樺湪Adjacent()
           鍒楀嚭涓庣粨鐐箈閭绘帴鐨勬墍鏈夐《鐐筃eighbor()
           鎵惧埌涓巟閭绘帴鐨勭涓€涓《鐐笷irstAdjVex()
           鎵惧埌x鐩稿浜巠鐨勪笅涓€涓偦鎺ラ《鐐筃extAdjvex()
           娣诲姞鏂伴《鐐笽nsertVex()
           鍒犻櫎椤剁偣DeleteVex()->娉ㄦ剰涓庝箣鐩稿叧鐨勮竟涔熷緱鍒犻櫎
           娣卞害浼樺厛閬嶅巻DFSTraverse()
           骞垮害浼樺厛閬嶅巻BFSTraverse()
           鑾峰緱杈规潈鍊糋etEdgeValue()
           璁剧疆杈规潈鍊糞etEdgeValue()
           鏈€灏忕敓鎴愭爲MiniSoanTree_PRIM()
*/
//閭绘帴鐭╅樀姣忎釜缁撶偣
typedef struct ArcCell
{
    bool adj;
    int weight;
}ArcCell;
//鍒涘缓锟�?
typedef struct Graph
{
    char vex[Max_VERTEX_NUM];
    ArcCell arcs[Max_VERTEX_NUM][Max_VERTEX_NUM];
    int vexnum,arcnum;          //椤剁偣鏁板拰杈规暟
}Graph;
void CreateGraph(Graph *G)
{
    G->vexnum = 0;
    G->arcnum = 0;
    char x;
    scanf(" %c",&x);
    while(x!='#')
    {
        G->vex[(G->vexnum)++] = x;
        scanf(" %c",&x);
    }
    for(int i=0;i<G->vexnum;i++)
    {
        for(int j=0;j<G->vexnum;j++)
        {
            //scanf("%d",&(G->arcs[i][j].adj));
            scanf("%d",&G->arcs[i][j].weight);
            if(G->arcs[i][j].weight!=0)
            {
                G->arcnum++;
            }
        }
    }
}
//鎵惧埌鎸囧畾缁撶偣鐨勪綅锟�?
int LocateVex(Graph G,char x)
{
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vex[i]==x)
        {
            return i;
        }
    }
    return -1;
}
//杩斿洖鎸囧畾浣嶇疆鐨勭粨鐐圭殑锟�?
char GetVex(Graph G,int i)
{
    if(i<0||i>=G.vexnum)
    {
        return '\0';
    }
    return G.vex[i];
}
//淇敼鏌愮粨鐐逛笂鐨勶拷?
void UpdateVex(Graph *G,int i,char x)
{
    G->vex[i] = x;
}
//鍒ゆ柇杈箈y鏄惁瀛樺湪
bool Adjacent(Graph G,int i,int j)
{
    if(G.arcs[i][j].adj==1)
    {
        return true;
    }else
    {
        return false;
    }
}
//鎵惧埌涓巟鐩搁偦鐨勭涓€涓《锟�?
int FirstAdjVex(Graph G,int x)
{
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.arcs[x][i].adj==1)
        {
            return i;
        }
    }
    return -1;
}
//鎵惧埌x鐩稿浜巠鐨勪笅涓€涓偦鎺ラ《锟�?
int NextAdjVex(Graph G,int x,int y)
{
    for(int i=y+1;i<G.vexnum;i++)
    {
        if(G.arcs[x][i].adj==1)
        {
            return i;
        }
    }
    return -1;
}
//娣诲姞鏂伴《锟�?
void InsertVex(Graph *G,char x)
{
    G->vex[G->vexnum++] = x;
    for(int i=0;i<G->vexnum;i++)
    {
        scanf("%d",&G->arcs[G->vexnum-1][i].adj);
        G->arcs[i][G->vexnum-1].adj = G->arcs[G->vexnum-1][i].adj;
        scanf("%d",G->arcs[i][G->vexnum-1].weight);
        G->arcs[i][G->vexnum-1].weight = G->arcs[G->vexnum-1][i].weight;
    }
}
//鍒犻櫎椤剁偣
bool DeleteVex(Graph *G,int x)
{
    if(G->vex[x]=='#')
    {
        return false;
    }
    G->vex[x] = '#';
    for(int i=0;i<G->vexnum;i++)
    {
        G->arcs[i][x].adj = 0;
        G->arcs[x][i].adj = 0;
    }
    return true;
}
//娣卞害浼樺厛閬嶅巻
bool visited[Max_VERTEX_NUM];
void DFSTraverse(Graph G)
{
    //灏唙isited鏁扮粍鍒濆鍖栦负false
    for(int i=0;i<G.vexnum;i++)
    {
        visited[i] = false;
    }
    //
    for(int i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
        {
            DFS(G,i);
        }
    }
}
//浠巌寮€濮嬬殑娣卞害浼樺厛閬嶅巻
void DFS(Graph G,int i)
{
    printf("%c ",G.vex[i]);
    visited[i] = true;
    for(int j = FirstAdjVex(G,i);j>=0;j=NextAdjVex(G,i,j))
    {
        if(!visited[j])
        {
            DFS(G,j);
        }
    }
}
//骞垮害浼樺厛閬嶅巻
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
//浠庣i涓《鐐瑰嚭鍙戠殑骞垮害浼樺厛閬嶅巻
void BFS(Graph G,int i)
{
    int Queue[Max_VERTEX_NUM];
    int front = -1;
    int rear = -1;
    Queue[0] = i;
    front = 0;
    rear = 1;
    printf("%c ",G.vex[i]);
    visited[i] = true;
    while(rear!=front)
    {
        int u = Queue[front++];
        for(int j=FirstAdjVex(G,u);j>=0;j=NextAdjVex(G,u,j))
        {
            if(!visited[j])
            {
                printf("%c ",G.vex[j]);
                visited[j] = true;
                Queue[rear++] = j;
            }
        }
    }
}
//鑾峰彇杈规潈锟�?
int GetEdgeValue(Graph G,int x,int y)
{
    return G.arcs[x][y].weight;
}
//璁剧疆杈规潈锟�?
void SetEdgeValue(Graph *G,int x,int y,int w)
{
    G->arcs[x][y].weight = w;
}   
//鐢╬rim绠楁硶姹傚緱鐨勬渶灏忕敓鎴愭爲
typedef struct closedeg
{
    char adjvex;         //T涓殑锟�?
    int lowcost         //璇ョ偣涓庢湭杩炲叆T鐨勭偣涓渶鐭殑璺濈
}CloseDeg;

void MiniSpanTree_PRIM(Graph G,char x)
{
    int k = LocateVex(G,x);
    CloseDeg closedeg[Max_VERTEX_NUM];
    for(int i=0;i<G.vexnum;i++)
    {
        if(i!=k)
        {
            //i璁板綍浜嗗姬澶寸粨鐐圭殑浣嶇疆,x鍒欐槸寮у熬缁撶偣鐨勶拷?
            closedeg[i].adjvex = x;
            closedeg[i].lowcost = GetEdgeValue(G,k,i);
        }
    }
    closedeg[k].lowcost = 0;
    for(int i=1;i<G.vexnum;i++)
    {
        k = Minimum(G,closedeg);
        printf("(%c,%c),",closedeg[k].adjvex,G.vex[k]);
        //鍔犺繘T鍚庢妸寮уご缁撶偣鍔犲叆鐢熸垚鏍戜腑
        closedeg[k].lowcost = 0;
        for(int j=0;j<G.vexnum;j++)
        {
            if(G.arcs[k][j].weight<closedeg[j].lowcost)
            {
                closedeg[j].lowcost = G.arcs[k][j].weight;
                closedeg[j].adjvex = G.vex[k];
            }
        }
    }
}
int Minimum(Graph G,CloseDeg *closedeg)
{
    int i=0;
    int min;
    while(i<=G.vexnum)
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
//鎺ヤ笅鏉ュ疄鐜版渶鐭矾寰勭殑涓変釜绠楁硶
/*
1.BFS
璇ョ畻娉曢€傚悎浜庢棤鏉冨浘鏈€鐭矾寰勭殑姹傝В锛屾槸鍦˙FS鐨勫熀纭€涓婂姞涓奷[]鍜宲ath[]涓や釜鏁扮粍
鍏朵腑d[]鐢ㄤ簬璁板綍start椤剁偣鍒板悇涓粨鐐圭殑鏈€鐭矾寰勯暱
path[]鐢ㄤ簬璁板綍鏈€鐭矾寰勪笂鐨勫墠椹辩粨鐐癸紝閫氳繃瀵筽ath鐨勯€掑綊鏌ユ壘鍙互杩樺師鍑烘渶鐭矾锟�?
*/
void ShortestPath_BFSTraverse(Graph g,int x)
{
    bool visited[g.vexnum];
    memset(visited,false,sizeof(visited));
    int d[g.vexnum];
    memset(d,0,sizeof(d));
    int path[g.vexnum];
    memset(path,-1,sizeof(path));
    ShortestPath_BFS(g,x,d,path);
    printf("distance:%d  ",d[4]);
    PrintPath(g,path,4);
}
void PrintPath(Graph g,int *path,int k)
{
    if(k!=-1)
    {
        PrintPath(g,path,path[k]);
        printf("%c ",g.vex[k]);
    }
}
void ShortestPath_BFS(Graph g,int x,int *d,int *path)
{
    int Queue[g.vexnum];
    int rear,front;
    Queue[0] = x;
    rear = 1;
    front = 0;
    visited[x] = true;
    while(front!=rear)
    {
        int k = Queue[front++];
        for(int i=FirstAdjVex(g,k);i>=0;i=NextAdjVex(g,k,i))
        {
            if(!visited[i])
            {
                Queue[rear++] = i;
                visited[i] = true;
                path[i] = k;
                d[i] = d[k]+1;
            }
        }
    }
}
/*
2.dijkstra
璇ョ畻娉曢€傜敤浜庤В鍐冲甫鏉冨浘鐨勫崟婧愭渶鐭矾寰勯棶棰�(涓嶉€傚悎璐熺粨鐐�),璁炬湁杈呭姪鏁扮粍isfinal,d,path
isfinal璁板綍鐨勬槸璇ョ粨鐐规槸鍚﹀凡缁忔壘鍒版渶鐭矾寰�
d璁板綍鐨勬槸璇ョ粨鐐圭殑鏈€鐭矾寰勯暱搴�
path璁板綍鐨勬槸璇ョ粨鐐圭殑鏈€鐭矾寰勪笂鐨勫墠椹辩粨鐐�
鍏蜂綋姝ラ濡備笅锛�
棣栧厛鍒濆鍖栦笁涓暟缁刬sfinal涓篺alse,d涓�0锛宲ath涓�-1
鎺ョ潃鎵惧埌杩樻湭琚闂殑缁撶偣涓窛绂绘渶灏忕殑鐐箆锛屽皢鍏秈sfinal璁句负true
鐒跺悗閬嶅巻缁撶偣濡傛灉浠庤缁撶偣鍑哄彂姣攄[i]灏�,鍒欒缃甦[i]涓鸿璺濈锛宲ath[i]涓簐
*/
void ShortestPath_Dijkstra(Graph g,int x,int y)
{
    bool isfinal[g.vexnum];
    int d[g.vexnum];
    int path[g.vexnum];
    memset(isfinal,false,sizeof(isfinal));
    memset(d,0,sizeof(d));
    memset(path,-1,sizeof(path));
    isfinal[x] = true;
    for(int i=0;i<g.vexnum;i++)
    {
        if(g.arcs[x][i].weight!=0)
        {
            d[i] = g.arcs[x][i].weight;
            path[i] = x;
        }
    }
    for(int i=1;i<g.vexnum;i++)
    {
        int v;
        int min = INFINITY;
        for(int j=0;j<g.vexnum;j++)
        {
            if(!isfinal[j])
            {
                if(d[j]<min&&d[j]!=0)
                {
                    v = j;
                    min = d[j];
                }
            }
        }
        isfinal[v] = true;
        for(int j=0;j<g.vexnum;j++)
        {
            if(!isfinal[j]&&d[j]>min+g.arcs[v][j].weight)
            {
                d[j] = d[v]+g.arcs[v][j].weight;
                path[j] = v;
            }
        }
    }
    printf("distance=%d ",d[y]);
    PrintPath(g,path,y);
}
/*
3.Floyd绠楁硶
璇ョ畻娉曠敤浜庢眰姣忎竴瀵归《鐐逛箣闂寸殑鏈€鐭矾寰勶紝鍙В鍐冲甫璐熸潈鍊肩殑鍥撅紝浣嗚В鍐充笉浜嗗甫璐熸潈鍥炶矾鐨勫浘
璁炬湁浜岀淮鏁扮粍path鍜宒ist
path鐢ㄤ簬瀛樺偍浠巌鍒癹鐨勪腑杞偣
dist鐢ㄤ簬瀛樺偍i鍒癹鐨勬渶鐭矾寰�
鍏蜂綋姝ラ濡備笅锛�
棣栧厛鍒濆鍖杙ath鍜宒ist鏁扮粍path鍒濆涓�-1锛宒ist鍒濆涓洪偦鎺ョ煩闃�
*/
void ShortestPath_Floyd(Graph g)
{
    int path[g.vexnum][g.vexnum];
    int dist[g.vexnum][g.vexnum];
    for(int i=0;i<g.vexnum;i++)
    {
        memset(path[i],-1,sizeof(path[i]));
    }
    for(int i=0;i<g.vexnum;i++)
    {
        for(int j=0;j<g.vexnum;j++)
        {
            dist[i][j] = g.arcs[i][j].weight;
        }
    }
    for(int i=0;i<g.vexnum;i++)
    {
        for(int j=0;j<g.vexnum;j++)
        {
            for(int k=0;k<g.vexnum;k++)
            {
                if(dist[j][k]>dist[j][i]+dist[i][k])
                {
                    dist[j][k] = dist[j][i]+dist[i][k];
                    path[j][k] = i;
                }
            }
        }
    }
    printf("distance=%d ",dist[0][5]);
    PrintPath1(g,path,0,5);
}
void PrintPath1(Graph g,int (*path)[g.vexnum],int x,int y)
{
    if(path[x][y]!=-1)
    {
        PrintPath1(g,path,x,path[x][y]);
        printf("%c ",g.vex[y]);
    }else
    {
        printf("%c %c ",g.vex[x],g.vex[y]);
    }
}
int main()
{
    Graph *G = (Graph*)malloc(sizeof(Graph));
    CreateGraph(G);
    ShortestPath_Dijkstra(*G,0,5);
    printf("\n");
    ShortestPath_Floyd(*G);
}