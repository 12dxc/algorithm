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
        // ��ѯp��q�Ĺ������Ƚڵ㣬��Ҫ��ѯ����[p,q]�����Ԫ��
        if (root->val > p->val && root->val > q->val) // ���val��p��q��������С���������
            return lowestCommonAncestor(root->left, p, q);
        if (root->val < p->val && root->val < q->val) // ���val��p��q��С�����������ұ���
            return lowestCommonAncestor(root->right, p, q);
        else // ��val������p��q��q��p֮�䣬������ͬʱ���ڻ�С��p��q
            return root;
    }
};