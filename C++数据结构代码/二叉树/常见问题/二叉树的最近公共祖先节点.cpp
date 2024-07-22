#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 查询p、q的公共祖先节点，即要查询满足[p,q]区间的元素
        if (root->val > p->val && root->val > q->val) // 如果val比p、q都大，则缩小，往左遍历
            return lowestCommonAncestor(root->left, p, q);
        if (root->val < p->val && root->val < q->val) // 如果val比p、q都小，则增大，往右遍历
            return lowestCommonAncestor(root->right, p, q);
        else // 即val满足在p、q或q、p之间，而不是同时大于或小于p、q
            return root;
    }
};