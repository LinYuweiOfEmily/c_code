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
           最小生成树去MiniSpanTree_PRIM()
*/