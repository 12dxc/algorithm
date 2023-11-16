#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "LinkQueue.h"

// 设置二叉树元素类型
#define ElemType int

// 链表实现二叉树
typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag; // 左、右线索标志
} ThreadNode, *ThreadTree;

ThreadNode *pre = NULL; // 指向当前访问结点的前驱

// 访问结点q
void visit(ThreadNode *q)
{
    if (q->lchild = NULL)
    { // 左子树为空，建立前驱线索
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL)
    {
        pre->rchild = q; // 建立前驱结点的后继线索
        pre->rtag = 1;
    }
    pre = q;
}

// 中序遍历二叉树，一边遍历一边线索化
void InThread(ThreadTree T)
{
    if (T != NULL)
    {
        InThread(T->lchild); // 中序遍历左子树
        visit(T);            // 访问根节点
        InThread(T->rchild); // 中序遍历右子树
    }
}

// 中序线索化二叉树T
void CreateInThread(ThreadTree T)
{
    pre = NULL;
    if (T != NULL)
    {
        InThread(T);
        if (pre->rchild == NULL)
            pre->rtag = 1; // 处理遍历的最后一个结点
    }
}

int main()
{
    system("chcp 65001");

    return 0;
}