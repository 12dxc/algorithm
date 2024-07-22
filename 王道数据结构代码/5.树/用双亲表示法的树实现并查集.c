#define MaxTreeSize 100 // 书中最多结点数
#define ElemType int    // 并查集类型

// 用双亲表示法的树实现并查集

// 树的结点定义
typedef struct
{
    ElemType data; // 数据元素
    int parent;    // 双亲位置域
} PTNode;
// 树的类型定义
typedef struct
{
    PTNode nodes[MaxTreeSize]; // 双亲表示
    int n;                     // 结点数
} PTree;

int main()
{

    return 0;
}