// 1026.Maximum Difference Between Node and Ancestor
// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/?envType=daily-question&envId=2024-01-11

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int m = 0;
        dfs(root, m);
        return m;
    }

private:
    pair<int, int> dfs(TreeNode* root, int& m) {
        if (root == NULL) {
            return {INT_MAX, INT_MIN};
        }

        auto left = dfs(root->left, m);
        auto right = dfs(root->right, m);

        int minVal = min(root->val, min(left.first, right.first));
        int maxVal = max(root->val, max(left.second, right.second));

        m = max({m,abs(minVal - root->val), abs(maxVal - root->val)});

        return {minVal, maxVal};
    }
};


