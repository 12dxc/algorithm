#define SIZE 13
int UFSets[SIZE]; // 集合元素数组

// 初始化并查集
void Initial(int s[])
{
    for (int i = 0; i != SIZE; ++i)
    {
        s[i] = -1;
    }
}

// Find “查”操作，找x所属集合（返回x所属根节点）
// int Find(int s[], int x)
// {
//     while (s[x] >= 0) // 循环寻找x的根
//         x = s[x];
//     return x; // 根的s[]小于0
// }

// Union “并”操作，将两个集合合并为一个
// void Union(int s[], int root1, int root2)
// {
//     // 要求root1与root2是不同的集合
//     if (root1 == root2)
//         return;
//     // 将root2来连接到另一根roo1下面
//     s[root2] = root1;
// }

/*并查集的优化的核心思路就是：尽可能让树变矮*/
// Union “并”操作，小树合并到大树
void Union(int s[], int root1, int root2)
{
    if (root1 == root2)
        return;
    if (s[root2] > s[root1]) // root2结点数更少
    {
        s[root1] += s[root2]; // 累加结点总数
        s[root2] = root1;     // 小树合并到大树
    }
    else
    {
        s[root2] += s[root1]; // 累加结点总数
        s[root1] = root2;     // 小树合并到大树
    }
}

// Find “查”操作优化，先找到根节点，再进行“压缩路径”
int Find(int s[], int x)
{
    int root = x;
    while (s[root] >= 0) // 循环找到根
        root = s[root];
    while (x != root) // 压缩路径
    {
        int t = s[x]; // t指向x的父节点
        s[x] = root;  // x直接挂到根节点下
        x = t;
    }
    return root; // 返回根节点编号
}

int main()
{

    return 0;
}