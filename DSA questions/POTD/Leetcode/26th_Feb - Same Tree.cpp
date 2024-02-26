// 200. Same Tree
// https://leetcode.com/problems/same-tree/description/?envType=daily-question&envId=2024-02-26

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p || !q)    return p==q;

        return (p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
