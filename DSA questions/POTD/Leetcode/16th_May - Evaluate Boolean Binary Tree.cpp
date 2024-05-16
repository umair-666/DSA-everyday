// 2331. Evaluate Boolean Binary Tree
// https://leetcode.com/problems/evaluate-boolean-binary-tree/description/?envType=daily-question&envId=2024-05-16

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (!root->left && !root->right)
            return root->val;
        
        bool evaluateLeftSubtree = evaluateTree(root->left);
        bool evaluateRightSubtree = evaluateTree(root->right);
        
        bool evaluateRoot;
        if (root->val == 2)
            evaluateRoot = evaluateLeftSubtree | evaluateRightSubtree;
        else
            evaluateRoot = evaluateLeftSubtree & evaluateRightSubtree;

        return evaluateRoot;
    }
};
