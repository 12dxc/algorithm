#include <queue>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 设置二叉树元素类型
#define ElemType int

// 链表实现二叉树
typedef struct BitNode
{
    ElemType data;
    struct BitNode *lchild, *rchild;
} BitNode, *BiTree;
// 二叉树初始化
void Init(BiTree *root)
{
    // 定义一棵空树
    root = NULL;
    // 插入根节点
    root = (BiTree *)malloc(sizeof(BitNode));
    (*root)->data = 1;
    (*root)->lchild = NULL;
    (*root)->rchild = NULL;
}
// 插入新结点
void addTree(BiTree root, ElemType e)
{
    BitNode *p = (BitNode *)malloc(sizeof(BitNode));
    p->data = e;
    p->lchild = NULL;
    p->rchild = NULL;
    root->lchild = p; // 作为根节点的左孩子
}

void visit(BiTree T)
{
    printf("%d ", T->data);
}

// 先序遍历  根左右
void PreOreder(BiTree T)
{
    if (T != NULL)
    {
        visit(T);             // 访问根节点
        PreOreder(T->lchild); // 递归遍历左子树
        PreOreder(T->rchild); // 递归遍历右子树
    }
}
// 中序遍历  左根右
// void PreOreder(BiTree T)
// {
//     if (T != NULL)
//     {
//         PreOreder(T->lchild); // 递归遍历左子树
//         visit(T);             // 访问根节点
//         PreOreder(T->rchild); // 递归遍历右子树
//     }
// }

// 后序遍历  左右根
// void PreOreder(BiTree T)
// {
//     if (T != NULL)
//     {
//         PreOreder(T->lchild); // 递归遍历左子树
//         PreOreder(T->rchild); // 递归遍历右子树
//         visit(T);             // 访问根节点
//     }
// }

// 层次遍历
void LevelOrder(BiTree T)
{
    std::queue<BitNode *> que; // 因为懒得实现BitNode版的队列，故使用C++队列
    BitNode *p;
    que.push(T);
    while (!que.empty()) // 队列不空则循环
    {
        p = que.front();
        que.pop(); // 队头结点出队
        visit(p);  // 访问出对节点
        if (p->lchild != NULL)
            que.push(p->lchild); // 左孩子入队
        if (p->lchild != NULL)
            que.push(p->rchild); // 右孩子入队
    }
}

int main()
{

    return 0;
}