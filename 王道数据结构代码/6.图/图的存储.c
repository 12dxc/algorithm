#define MaxVertexNum 100     // 顶点的最大数目
#define INFINITY 最大的int值 // 宏定义常量无穷
typedef char VertexType;     // 顶点的数据类型
typedef int EdgeType;        // 带权图中边上权值的数据类型

// 邻接矩阵法存储图
//  typedef struct
//  {
//      VertexType Vex[MaxVertexNum];               //顶点表
//      EdgeType Edge[MaxVertexNum][MaxVertexNum]; //邻接矩阵，边表
//      int vexnum, arcnum;                   //图的当前顶点数和边数、弧数
//  } MGraph;

// 邻接表法存储图
// 边/弧
typedef struct ArcNode
{
    int adjvex;           // 边/弧指向哪个结点
    struct ArcNode *next; // 指向下一条弧的指针
    // InfoType info       //边权值
} ArcNode;

// 顶点
typedef struct VNode
{
    VertexType data; // 顶点信息
    ArcNode *first;  // 第一条边/弧
} VNode, AdjList[MaxVertexNum];
// 邻接表图
typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

int main()
{

    return 0;
}